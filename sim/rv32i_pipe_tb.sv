// ============================================================================
// rv32i_pipe_tb.sv - Testbench for 5-Stage Pipelined RV32I Processor
// ============================================================================

module rv32i_pipe_tb;

    logic        clk;
    logic        rst_n;
    logic [31:0] instr_if;
    logic [31:0] pc_if;

    rv32i dut (.*);

    // Clock generation (10ns period)
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Instruction memory
    logic [31:0] imem [0:31];

    // Drive instruction based on PC
    assign instr_if = (pc_if < 24) ? imem[pc_if[5:2]] : 32'h00000013; // NOP after valid

    // Debug: print WB stage each cycle
    always_ff @(posedge clk) begin
        if (rst_n && dut.reg_write_wb) begin
            $display("CYCLE WB: rd=%d, data=%h, pc_wb=%h", dut.rd_wb, dut.alu_result_wb, dut.pc_ex);
        end
    end

    initial begin
        $dumpfile("sim/waveform.vcd");
        $dumpvars(0, rv32i_pipe_tb);

        $display("=== 5-Stage Pipeline Testbench Starting ===");

        // Test program: Independent instructions
        imem[0] = 32'h00100093; // ADDI x1, x0, 1
        imem[1] = 32'h00200113; // ADDI x2, x0, 2
        imem[2] = 32'h00300193; // ADDI x3, x0, 3
        imem[3] = 32'h003100B3; // ADD  x1, x2, x3 (x1 = 5) - HAZARD!
        imem[4] = 32'h00000013; // NOP
        imem[5] = 32'h00000013; // NOP

        // Reset
        rst_n = 1'b0;
        #20;
        rst_n = 1'b1;

        // Run enough cycles
        repeat (12) @(posedge clk);
        @(negedge clk);

        // Check results
        $display("=== RF State ===");
        $display("x1 = %h", dut.rf_inst.registers[5'd1]);
        $display("x2 = %h", dut.rf_inst.registers[5'd2]);
        $display("x3 = %h", dut.rf_inst.registers[5'd3]);

        if (dut.rf_inst.registers[5'd1] !== 32'h5) begin
            $display("FAIL: x1 after ADD x1=%h expected=00000005", dut.rf_inst.registers[5'd1]);
        end else begin
            $display("PASS: x1 after ADD x1=00000005");
        end

        if (dut.rf_inst.registers[5'd2] !== 32'h2) begin
            $display("FAIL: x2 after ADDI x2=%h expected=00000002", dut.rf_inst.registers[5'd2]);
        end else begin
            $display("PASS: x2 after ADDI x2=00000002");
        end

        if (dut.rf_inst.registers[5'd3] !== 32'h3) begin
            $display("FAIL: x3 after ADDI x3=%h expected=00000003", dut.rf_inst.registers[5'd3]);
        end else begin
            $display("PASS: x3 after ADDI x3=00000003");
        end

        $display("=== TEST DONE ===");
        $finish;
    end
endmodule