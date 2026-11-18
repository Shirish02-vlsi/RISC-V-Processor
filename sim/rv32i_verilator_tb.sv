// ============================================================================
// rv32i_verilator_tb.sv - Verilator Testbench with Manual Coverage
// ============================================================================
// Uses Verilator's built-in coverage (--coverage-line --coverage-toggle)
// Run with: verilator --cc --coverage --trace --language 1800-2012 rtl/*.sv sim/rv32i_verilator_tb.sv --top-module rv32i_verilator_tb
// ============================================================================

module rv32i_verilator_tb;

    logic clk;
    logic rst_n;
    logic [31:0] instr_if;
    logic [31:0] pc_if;

    rv32i dut (.*);

    // Clock
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Instruction memory - simple static program
    logic [31:0] imem [0:255];

    assign instr_if = imem[pc_if[9:2]];

    // ============================================================
    // MANUAL COVERAGE TRACKING
    // ============================================================
    // These arrays track coverage for key signals
    logic [6:0] opcode_cov [0:127];
    logic [3:0] alu_op_cov [0:15];
    logic [1:0] fwd_a_cov [0:3];
    logic [1:0] fwd_b_cov [0:3];
    logic reg_write_ex_cov, reg_write_mem_cov, reg_write_wb_cov;
    logic [4:0] rd_wb_cov [0:31];
    logic mem_write_ex_cov;
    logic branch_ex_cov;

    // Track coverage on each cycle
    always_ff @(posedge clk) begin
        if (rst_n) begin
            opcode_cov[dut.opcode_id] <= 1'b1;
            alu_op_cov[dut.alu_op_ex] <= 1'b1;
            fwd_a_cov[dut.forward_a] <= 1'b1;
            fwd_b_cov[dut.forward_b] <= 1'b1;
            reg_write_ex_cov <= dut.reg_write_ex;
            reg_write_mem_cov <= dut.reg_write_mem;
            reg_write_wb_cov <= dut.reg_write_wb;
            rd_wb_cov[dut.rd_wb] <= 1'b1;
            mem_write_ex_cov <= dut.mem_write_ex;
            branch_ex_cov <= dut.branch_ex;
        end
    end

    // ============================================================
    // ASSERTIONS FOR SIMULATION
    // ============================================================
    a_x0_zero: assert property (@(posedge clk) dut.rf_inst.registers[0] === 32'h0);
    a_ex_no_x: assert property (@(posedge clk) disable iff (!rst_n) !$isunknown(dut.alu_result_ex_int));
    a_fwd_valid_a: assert property (@(posedge clk) disable iff (!rst_n) dut.forward_a inside {2'b00, 2'b01, 2'b10});
    a_fwd_valid_b: assert property (@(posedge clk) disable iff (!rst_n) dut.forward_b inside {2'b00, 2'b01, 2'b10});

    // ============================================================
    // SIMPLE TEST SEQUENCE
    // ============================================================
    typedef enum logic [1:0] {
        S_RESET  = 2'd0,
        S_RUN    = 2'd1,
        S_DONE   = 2'd2
    } state_t;

    state_t state;
    int cycle_count;

    initial begin
        // Load simple test program
        imem[0] = 32'h00100093; // ADDI x1, x0, 1
        imem[1] = 32'h00200113; // ADDI x2, x0, 2
        imem[2] = 32'h00300193; // ADDI x3, x0, 3
        imem[3] = 32'h003100B3; // ADD  x1, x2, x3 (forwarding)
        imem[4] = 32'h00400113; // ADDI x2, x0, 4
        imem[5] = 32'h005100B3; // ADD  x1, x2, x3 (forwarding)
        imem[6] = 32'h405100B3; // SUB  x1, x2, x3
        imem[7] = 32'h005120B3; // SLL  x1, x2, x3
        for (int i = 8; i < 256; i++) begin
            imem[i] = 32'h00000013; // NOP
        end
    end

    always_ff @(posedge clk) begin
        case (state)
            S_RESET: begin
                rst_n <= 1'b0;
                cycle_count <= 0;
                state <= S_RUN;
            end
            
            S_RUN: begin
                rst_n <= 1'b1;
                cycle_count <= cycle_count + 1;
                if (cycle_count >= 30) begin
                    state <= S_DONE;
                end
            end
            
            S_DONE: begin
                $display("=== Test Complete ===");
                $display("Coverage collected via Verilator --coverage-line --coverage-toggle");
                $finish;
            end
        endcase
    end

endmodule