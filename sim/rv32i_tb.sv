// ============================================================================
// rv32i_tb.sv - Self-Checking Testbench for the RV32I Processor Top-Level
// ============================================================================

module rv32i_tb;

    logic        clk;
    logic        rst_n;
    logic [31:0] instr;
    logic [31:0] pc;
    logic [31:0] alu_result_out;

    rv32i dut (.*);

    // Clock generation (10ns period)
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Simple instruction memory model
    logic [31:0] imem [0:15];

    integer cycle = 0;

    // Track clock cycles
    always @(posedge clk) begin
        cycle <= cycle + 1;
    end

    // Drive instruction based on PC (combinational)
    assign instr = imem[pc[5:2]];

    task check (input string name, input logic [31:0] expected_pc);
        #1;
        if (pc !== expected_pc) begin
            $display("FAIL: %s (pc=%h) expected_pc=%h", name, pc, expected_pc);
        end else begin
            $display("PASS: %s (pc=%h)", name, pc);
        end
    endtask

    // Check register value via hierarchical reference
    task check_reg (input string name, input logic [4:0] reg_num, input logic [31:0] expected);
        #1;
        if (dut.rf_inst.registers[reg_num] !== expected) begin
            $display("FAIL: %s x%0d=%h expected=%h", name, reg_num, dut.rf_inst.registers[reg_num], expected);
        end else begin
            $display("PASS: %s x%0d=%h", name, reg_num, expected);
        end
    endtask

    initial begin
        $display("=== RV32I Processor Testbench Starting ===");

        // Initialize memory
        imem[0] = 32'h00100093; // ADDI x1, x0, 1
        imem[1] = 32'h00200113; // ADDI x2, x0, 2
        imem[2] = 32'h00300193; // ADDI x3, x0, 3
        imem[3] = 32'h003100B3; // ADD  x1, x2, x3 (x1 = 5)
        imem[4] = 32'h00000013; // NOP (ADDI x0, x0, 0)

        // Reset
        rst_n = 1'b0;
        #20;
        rst_n = 1'b1;
        @(negedge clk);
        check("RESET", 32'h0);

        // Cycle 0: Fetch ADDI x1, x0, 1
        // Cycle 1: Fetch ADDI x2, x0, 2
        // Cycle 2: Fetch ADDI x3, x0, 3
        // Cycle 3: Fetch ADD  x1, x2, x3 (x1 = 5)
        // Cycle 4: Fetch NOP

        // Let's run 5 cycles
        repeat (5) @(negedge clk);

        // Check final state
        #1;
        check_reg("x1 after ADD", 5'd1, 32'h5);
        check_reg("x2 after ADDI", 5'd2, 32'h2);
        check_reg("x3 after ADDI", 5'd3, 32'h3);
        $display("=== TEST DONE ===");
        $display("Final PC: %h", pc);
        $display("Final ALU result: %h", alu_result_out);
        $finish;
    end
endmodule