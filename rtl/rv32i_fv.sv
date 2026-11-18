// ============================================================================
// rv32i_fv.sv - Formal Verification Top-Level with Yosys Formal Assertions
// ============================================================================
// Uses $assert, $assume, $cover system tasks for Yosys SMTBMC
// Assertions are clock-agnostic - Yosys handles clocking internally
// ============================================================================

module rv32i_fv;

    logic clk;
    logic rst_n;

    // DUT instance
    rv32i dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .instr_if   (instr_if),
        .pc_if      (pc_if)
    );

    // Instruction memory (unconstrained for formal)
    logic [31:0] imem [0:255];
    logic [31:0] instr_if;
    logic [31:0] pc_if;

    assign instr_if = imem[pc_if[9:2]];

    // Clock generation
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Initial constraints for formal
    initial begin
        rst_n = 1'b0;
        #20;
        rst_n = 1'b1;
    end

    // ============================================================
    // FORMAL ASSERTIONS (Yosys style - no clock edge)
    // ============================================================

    // RF x0 hardwired to zero
    $assert(dut.rf_inst.registers[0] === 32'h00000000);

    // PC increment correctness (when not reset)
    $assert(!rst_n || (dut.pc_ex === dut.pc_id + 4));

    // ALU result not X (when not reset)
    $assert(!rst_n || ($isunknown(dut.alu_result_ex_int) === 1'b0));

    // RF write enable constraint (x0 not written, when not reset)
    $assert(!rst_n || ((dut.rd_wb === 5'h0) || (dut.reg_write_wb === 1'b0)));

    // Opcode decode (when not reset)
    $assert(!rst_n || (dut.opcode_id === dut.instr_id[6:0]));

    // Forwarding valid values (when not reset)
    $assert(!rst_n || (dut.forward_a == 2'b00 || dut.forward_a == 2'b01 || dut.forward_a == 2'b10));
    $assert(!rst_n || (dut.forward_b == 2'b00 || dut.forward_b == 2'b01 || dut.forward_b == 2'b10));

    // ============================================================
    // COVER POINTS
    // ============================================================

    // Pipeline stage writes
    $cover(!rst_n && dut.reg_write_ex && dut.rd_ex !== 5'h0);
    $cover(!rst_n && dut.reg_write_mem && dut.rd_mem !== 5'h0);
    $cover(!rst_n && dut.reg_write_wb && dut.rd_wb !== 5'h0);

    // Forwarding coverage
    $cover(!rst_n && dut.forward_a == 2'b01); // EX hazard
    $cover(!rst_n && dut.forward_a == 2'b10); // MEM hazard
    $cover(!rst_n && dut.forward_b == 2'b01);
    $cover(!rst_n && dut.forward_b == 2'b10);

    // ALU operations
    $cover(!rst_n && dut.alu_op_ex === 4'b0000); // ADD
    $cover(!rst_n && dut.alu_op_ex === 4'b0001); // SUB
    $cover(!rst_n && dut.alu_op_ex === 4'b0010); // SLL
    $cover(!rst_n && dut.alu_op_ex === 4'b0110); // SRL
    $cover(!rst_n && dut.alu_op_ex === 4'b0111); // SRA

endmodule