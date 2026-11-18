// ============================================================================
// imm_gen_tb.sv - Self-Checking Testbench for the RV32I Immediate Generator
// ============================================================================

module imm_gen_tb;
    logic [31:0] instr;
    logic [31:0] imm;

    imm_gen dut (.*);

    task check (input string name, input logic [31:0] i, input logic [31:0] expected);
        instr = i;
        #1;
        if (imm !== expected) begin
            $display("FAIL: %s (instr=%h) imm=%h expected=%h", name, i, imm, expected);
        end else begin
            $display("PASS: %s", name);
        end
    endtask

    initial begin
        $display("=== Immediate Generator Testbench Starting ===");
        
        // I-type: addi x1, x2, 10
        check("I-type", 32'h00A10093, 32'd10);
        
        // S-type: sw x1, 4(x2)
        check("S-type", 32'h00112223, 32'd4);
        
        // B-type: beq x1, x2, 8
        check("B-type", 32'h00208463, 32'd8);
        
        // U-type: lui x1, 0x12345
        check("U-type (LUI)", 32'h123450B7, 32'h12345000);
        
        // J-type: jal x1, 20
        check("J-type", 32'h014000EF, 32'd20);
        
        $display("=== TEST DONE ===");
        $finish;
    end
endmodule
