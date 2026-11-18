// ============================================================================
// alu_tb.sv - Self-Checking Testbench for the RV32I ALU
// ============================================================================
// Exercises every ALU operation with directed test vectors, including
// edge cases (shift-amount wrapping, signed vs. unsigned comparisons,
// arithmetic wrap-around, and zero-result zero_flag assertion).
// ============================================================================

module alu_tb;

    // DUT interface signals
    logic [31:0] operand_a;
    logic [31:0] operand_b;
    logic [3:0]  alu_control;
    logic [31:0] alu_result;
    logic        zero_flag;

    // Error / test counters
    integer errors = 0;
    integer total  = 0;

    // Instantiate device under test
    alu dut (
        .operand_a   (operand_a),
        .operand_b   (operand_b),
        .alu_control (alu_control),
        .alu_result  (alu_result),
        .zero_flag   (zero_flag)
    );

    // Waveform dumping (uncomment to generate alu_tb.vcd)
    // initial begin
    //     $dumpfile("alu_tb.vcd");
    //     $dumpvars(0, alu_tb);
    // end

    // --------------------------------------------------------------------------
    // check: drive inputs combinationally, settle for 1ns, compare alu_result
    //        and zero_flag against the expected values
    // --------------------------------------------------------------------------
    task automatic check (
        input  string      name,
        input  logic [3:0] op,
        input  logic [31:0] a,
        input  logic [31:0] b,
        input  logic [31:0] expected
    );
        total++;
        operand_a   = a;
        operand_b   = b;
        alu_control = op;
        #1;  // let combinational logic settle
        if (alu_result !== expected) begin
            $display("FAIL: %s (ctrl=%b a=%h b=%h) result=%h expected=%h",
                     name, op, a, b, alu_result, expected);
            errors++;
        end else begin
            $display("PASS: %s (ctrl=%b a=%h b=%h) result=%h",
                     name, op, a, b, alu_result);
        end
        // zero_flag must match whether the expected result is zero
        if (zero_flag !== (expected == 32'h0)) begin
            $display("FAIL: %s (ctrl=%b) zero_flag=%b expected=%b",
                     name, op, zero_flag, (expected == 32'h0));
            errors++;
        end
    endtask

    // --------------------------------------------------------------------------
    // Main test sequence
    // --------------------------------------------------------------------------
    initial begin
        $display("=== ALU Testbench Starting ===");

        // ---------------- ADD (4'b0000) ----------------
        check("ADD basic",        4'b0000, 32'd5,         32'd3,         32'd8);
        check("ADD overflow",     4'b0000, 32'h7FFFFFFF,  32'd1,         32'h80000000);
        check("ADD result zero",  4'b0000, 32'hFFFFFFF5,  32'd11,        32'd0);

        // ---------------- SUB (4'b0001) ----------------
        check("SUB basic",        4'b0001, 32'd10,        32'd3,         32'd7);
        check("SUB negative",     4'b0001, 32'd5,         32'd10,        32'hFFFFFFFB);
        check("SUB result zero",  4'b0001, 32'd5,         32'd5,         32'd0);

        // ---------------- AND (4'b0010) ----------------
        check("AND basic",        4'b0010, 32'hF0F0,      32'h0FF0,      32'h00F0);
        check("AND result zero",  4'b0010, 32'd0,         32'hFFFF_FFFF, 32'd0);

        // ---------------- OR (4'b0011) ----------------
        check("OR basic",         4'b0011, 32'h0FF0,      32'hF0F0,      32'hFFF0);
        check("OR identity",      4'b0011, 32'h12345678,  32'd0,         32'h12345678);

        // ---------------- XOR (4'b0100) ----------------
        check("XOR basic",        4'b0100, 32'hFF00,      32'h00FF,      32'hFFFF);
        check("XOR result zero",  4'b0100, 32'h12345678,  32'h12345678,  32'd0);

        // ---------------- SLL (4'b0101) ----------------
        check("SLL basic",        4'b0101, 32'd1,         32'd4,         32'd16);
        check("SLL amount wrap",  4'b0101, 32'd1,         32'd34,        32'd4);        // 34 & 31 = 2
        check("SLL amount 32",    4'b0101, 32'd1,         32'd32,        32'd1);        // 32 & 31 = 0

        // ---------------- SRL (4'b0110) ----------------
        check("SRL basic",        4'b0110, 32'h80000000,  32'd4,         32'h08000000);
        check("SRL all ones",     4'b0110, 32'hFFFFFFF0,  32'd4,         32'h0FFFFFFF);

        // ---------------- SRA (4'b0111) ----------------
        check("SRA sign extend",  4'b0111, 32'h80000000,  32'd4,         32'hF8000000);
        check("SRA positive",     4'b0111, 32'h00000010,  32'd1,         32'h00000008);

        // ---------------- SLT (4'b1000) signed ----------------
        check("SLT signed neg",   4'b1000, 32'hFFFF_FFFF, 32'd1,         32'd1);  // -1 < 1
        check("SLT signed pos",   4'b1000, 32'd1,         32'hFFFF_FFFF, 32'd0);  // 1 < -1
        check("SLT min int",      4'b1000, 32'h80000000,  32'd1,         32'd1);  // INT_MIN < 1

        // ---------------- SLTU (4'b1001) unsigned ----------------
        check("SLTU unsigned hi", 4'b1001, 32'h80000000,  32'd1,         32'd0);  // 0x80000000 > 1
        check("SLTU unsigned lo", 4'b1001, 32'd1,         32'h80000000,  32'd1);  // 1 < 0x80000000

        // ---------------- Invalid op (default) ----------------
        check("INVALID op",       4'b1111, 32'd1,         32'd2,         32'd0);

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
