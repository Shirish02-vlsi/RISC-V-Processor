// ============================================================================
// ctrl_tb.sv - Self-Checking Testbench for the RV32I Control Unit
// ============================================================================

module ctrl_tb;

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic       reg_write, alu_src, mem_write, mem_to_reg, branch, jump;
    logic [1:0] alu_op;

    ctrl dut (.*);

    task check (
        input string name,
        input logic [6:0] op,
        input logic expect_reg_write,
        input logic expect_alu_src,
        input logic expect_mem_write,
        input logic expect_mem_to_reg,
        input logic expect_branch,
        input logic expect_jump,
        input logic [1:0] expect_alu_op
    );
        opcode = op;
        #1;
        if (reg_write !== expect_reg_write || alu_src !== expect_alu_src ||
            mem_write !== expect_mem_write || mem_to_reg !== expect_mem_to_reg ||
            branch !== expect_branch || jump !== expect_jump || alu_op !== expect_alu_op) begin
            $display("FAIL: %s (opcode=%b)", name, op);
        end else begin
            $display("PASS: %s", name);
        end
    endtask

    initial begin
        $display("=== Control Unit Testbench Starting ===");
        check("R-TYPE",  7'b0110011, 1, 0, 0, 0, 0, 0, 2'b10);
        check("I-TYPE",  7'b0010011, 1, 1, 0, 0, 0, 0, 2'b10);
        check("LOAD",    7'b0000011, 1, 1, 0, 1, 0, 0, 2'b00);
        check("STORE",   7'b0100011, 0, 1, 1, 0, 0, 0, 2'b00);
        check("BRANCH",  7'b1100011, 0, 0, 0, 0, 1, 0, 2'b01);
        check("JAL",     7'b1101111, 1, 0, 0, 0, 0, 1, 2'b00);
        $display("=== TEST DONE ===");
        $finish;
    end
endmodule
