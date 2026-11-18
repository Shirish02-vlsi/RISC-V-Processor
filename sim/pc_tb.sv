// ============================================================================
// pc_tb.sv - Self-Checking Testbench for the RV32I Program Counter
// ============================================================================

module pc_tb;

    logic        clk;
    logic        rst_n;
    logic [31:0] next_pc;
    logic        pc_write;
    logic [31:0] pc;

    pc dut (.*);

    // Clock generation (10ns period)
    initial clk = 1'b0;
    always #5 clk = ~clk;

    task check (input string name, input logic [31:0] expected);
        #1;
        if (pc !== expected) begin
            $display("FAIL: %s (pc=%h) expected=%h", name, pc, expected);
        end else begin
            $display("PASS: %s", name);
        end
    endtask

    initial begin
        $display("=== PC Testbench Starting ===");

        // Reset
        rst_n = 1'b0;
        next_pc = 32'h0;
        pc_write = 1'b0;
        @(posedge clk);
        check("RESET", 32'h0);

        // Hold
        rst_n = 1'b1;
        @(posedge clk);
        check("HOLD", 32'h0);

        // Write target
        next_pc = 32'h00000040;
        pc_write = 1'b1;
        @(posedge clk);
        check("WRITE 0x40", 32'h00000040);

        // Hold
        pc_write = 1'b0;
        @(posedge clk);
        check("HOLD after write", 32'h00000040);

        // Write another target
        next_pc = 32'h00001000;
        pc_write = 1'b1;
        @(posedge clk);
        check("WRITE 0x1000", 32'h00001000);

        // Reset again
        rst_n = 1'b0;
        @(posedge clk);
        check("RESET again", 32'h0);

        $display("=== TEST DONE ===");
        $finish;
    end
endmodule