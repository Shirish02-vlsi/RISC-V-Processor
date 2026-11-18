// ============================================================================
// rf_tb.sv - Self-Checking Testbench for the RV32I Register File
// ============================================================================
// Verifies:
//   - Reset initializes all registers to 0
//   - Synchronous write + asynchronous read
//   - x0 hardwired to zero (read and write)
//   - Simultaneous reads on two ports
//   - Read/write to same address on different cycles
//   - Overwrite behavior
// ============================================================================

module rf_tb;

    // DUT interface signals
    logic        clk;
    logic        rst_n;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [4:0]  rd;
    logic [31:0] wr_data;
    logic        wr_en;
    logic [31:0] rs1_data;
    logic [31:0] rs2_data;

    // Error / test counters
    integer errors = 0;
    integer total  = 0;
    integer k;

    // Clock generation (10ns period)
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Instantiate device under test
    rf dut (
        .clk      (clk),
        .rst_n    (rst_n),
        .rs1      (rs1),
        .rs2      (rs2),
        .rd       (rd),
        .wr_data  (wr_data),
        .wr_en    (wr_en),
        .rs1_data (rs1_data),
        .rs2_data (rs2_data)
    );

    // --------------------------------------------------------------------------
    // check_read: verify rs1_data and/or rs2_data match expected
    // --------------------------------------------------------------------------
    task automatic check_read (
        input  string      name,
        input  logic [4:0] r1,
        input  logic [31:0] exp1,
        input  logic [4:0] r2,
        input  logic [31:0] exp2
    );
        total++;
        rs1 = r1;
        rs2 = r2;
        #1;  // settle
        if (rs1_data !== exp1 || rs2_data !== exp2) begin
            $display("FAIL: %s rs1(x%0d)=%h exp=%h rs2(x%0d)=%h exp=%h",
                     name, r1, rs1_data, exp1, r2, rs2_data, exp2);
            errors++;
        end else begin
            $display("PASS: %s rs1(x%0d)=%h rs2(x%0d)=%h",
                     name, r1, rs1_data, r2, rs2_data);
        end
    endtask

    // --------------------------------------------------------------------------
    // check_reset: all registers read as zero after reset
    // --------------------------------------------------------------------------
    task automatic check_reset (input string name);
        integer k;
        integer bad;
        bad = 0;
        for (k = 0; k < 32; k++) begin
            rs1 = k[4:0];
            rs2 = k[4:0];
            #1;
            if (rs1_data !== 32'h0) bad++;
        end
        total++;
        if (bad != 0) begin
            $display("FAIL: %s - %0d registers non-zero after reset", name, bad);
            errors++;
        end else begin
            $display("PASS: %s - all 32 registers zero after reset", name);
        end
    endtask

    // --------------------------------------------------------------------------
    // Main test sequence
    // --------------------------------------------------------------------------
    initial begin
        // Initialize stimulus
        rst_n   = 1'b0;
        rs1     = 5'h0;
        rs2     = 5'h0;
        rd      = 5'h0;
        wr_data = 32'h0;
        wr_en   = 1'b0;

        $display("=== RF Testbench Starting ===");

        // ---------------- Reset ----------------
        rst_n   = 1'b0;
        #20;
        rst_n   = 1'b1;
        #5;
        check_reset("RESET");
        @(posedge clk);

        // ---------------- Write to x1 ----------------
        rd      = 5'd1;
        wr_data = 32'h12345678;
        wr_en   = 1'b1;
        @(posedge clk);
        #1; wr_en = 1'b0;
        @(posedge clk);
        check_read("WRITE x1", 5'd1, 32'h12345678, 5'd1, 32'h12345678);

        // ---------------- Write to x2 ----------------
        rd      = 5'd2;
        wr_data = 32'hDEADBEEF;
        wr_en   = 1'b1;
        @(posedge clk);
        #1; wr_en = 1'b0;
        @(posedge clk);
        check_read("WRITE x2", 5'd2, 32'hDEADBEEF, 5'd1, 32'h12345678);

        // ---------------- Simultaneous reads x1, x2 ----------------
        check_read("READ x1,x2", 5'd1, 32'h12345678, 5'd2, 32'hDEADBEEF);

        // ---------------- Overwrite x1 ----------------
        rd      = 5'd1;
        wr_data = 32'hCAFEBABE;
        wr_en   = 1'b1;
        @(posedge clk);
        #1; wr_en = 1'b0;
        @(posedge clk);
        check_read("OVERWRITE x1", 5'd1, 32'hCAFEBABE, 5'd2, 32'hDEADBEEF);

        // ---------------- x0 always reads zero ----------------
        check_read("READ x0", 5'd0, 32'h0, 5'd0, 32'h0);

        // ---------------- Write to x0 is ignored ----------------
        rd      = 5'd0;
        wr_data = 32'hFFFF_FFFF;
        wr_en   = 1'b1;
        @(posedge clk);
        #1; wr_en = 1'b0;
        @(posedge clk);
        check_read("WRITE x0 ignored", 5'd0, 32'h0, 5'd1, 32'hCAFEBABE);

        // ---------------- Write enable low: no write occurs ----------------
        // Keep previous values; assert wr_en=0 with a new rd/wr_data
        rd      = 5'd3;
        wr_data = 32'hAAAABBBB;
        wr_en   = 1'b0;
        @(posedge clk);
        @(posedge clk);
        check_read("WR_EN low", 5'd3, 32'h0, 5'd1, 32'hCAFEBABE);

        // ---------------- Read x3 ----------------
        check_read("READ x3", 5'd3, 32'h0, 5'd3, 32'h0);

        // ---------------- Write all 32 registers with unique pattern ----------------
        for (k = 1; k < 32; k++) begin
            rd      = k[4:0];
            wr_data = 32'hFEDCBA98 + k;
            wr_en   = 1'b1;
            @(posedge clk);
            #1; wr_en   = 1'b0;
        end

        // Verify all 32 registers
        for (k = 1; k < 32; k++) begin
            check_read("SWEEP read xN", k[4:0], 32'hFEDCBA98 + k, k[4:0], 32'hFEDCBA98 + k);
        end

        // Verify x0 still zero
        check_read("SWEEP x0 zero", 5'd0, 32'h0, 5'd0, 32'h0);

        // ----------------------------------------------------------------------
        // Summary
        // ----------------------------------------------------------------------
        #5;
        if (errors == 0)
            $display("=== TEST PASSED: all %0d tests passed ===", total);
        else
            $display("=== TEST FAILED: %0d of %0d checks failed ===", errors, total);
        $finish;
    end

endmodule