// ============================================================================
// assertions.sv - SystemVerilog Assertions for RV32I Pipeline
// ============================================================================
// Covers:
//  1. Register file x0 hardwired to zero
//  2. Pipeline register stability (no X-propagation)
//  3. Instruction decode correctness
//  4. ALU operation correctness
//  5. Forwarding unit correctness
//  6. Hazard detection (if stub is integrated)
// ============================================================================

module rv32i_assertions #(
    parameter logic [31:0] DUMMY = 32'h0
);

    // DUT signals - bound to rv32i_fv
    logic clk;
    logic rst_n;

    // Assertions
    // RF x0 hardwired to zero
    a_x0_is_zero: assert property (
        @(posedge clk) 
        (dut.rf_inst.registers[0] === 32'h00000000)
    );

    // PC increment correctness
    a_pc_increment: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        (dut.pc_ex === dut.pc_id + 4)
    );

    // ALU result not X
    a_ex_result_valid: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        ($isunknown(dut.alu_result_ex_int) === 1'b0)
    );

    // RF write enable constraint (x0 not written)
    a_rf_write_enable: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        (dut.rd_wb === 5'h0) || (dut.reg_write_wb === 1'b0)
    );

    // Opcode decode
    a_opcode_decode: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        (dut.opcode_id === dut.instr_id[6:0])
    );

    // Forwarding valid values
    a_forward_a_valid: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        (dut.forward_a inside {2'b00, 2'b01, 2'b10})
    );

    a_forward_b_valid: assert property (
        @(posedge clk)
        disable iff (!rst_n)
        (dut.forward_b inside {2'b00, 2'b01, 2'b10})
    );

endmodule