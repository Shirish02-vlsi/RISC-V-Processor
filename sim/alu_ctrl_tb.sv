// ============================================================================
// alu_ctrl_tb.sv - Self-Checking Testbench for the RV32I ALU Control Unit
// ============================================================================

module alu_ctrl_tb;

    logic [1:0] alu_op;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic [3:0] alu_control;

    alu_ctrl dut (.*);

    task check (
        input string name,
        input logic [1:0] op,
        input logic [2:0] f3,
        input logic [6:0] f7,
        input logic [3:0] expected
    );
        alu_op = op;
        funct3 = f3;
        funct7 = f7;
        #1;
        if (alu_control !== expected) begin
            $display("FAIL: %s (op=%b f3=%b f7=%b) alu_control=%b expected=%b",
                     name, op, f3, f7, alu_control, expected);
        end else begin
            $display("PASS: %s", name);
        end
    endtask

    initial begin
        $display("=== ALU Control Testbench Starting ===");

        // alu_op = 00 (Load/Store offset)
        check("LOAD/STORE", 2'b00, 3'b000, 7'b0000000, 4'b0000);

        // alu_op = 01 (Branch)
        check("BRANCH", 2'b01, 3'b000, 7'b0000000, 4'b0001);

        // alu_op = 10 (R-type / I-type arithmetic)
        // R-type instructions
        check("ADD",  2'b10, 3'b000, 7'b0000000, 4'b0000);
        check("SUB",  2'b10, 3'b000, 7'b0100000, 4'b0001);
        check("SLL",  2'b10, 3'b001, 7'b0000000, 4'b0101);
        check("SLT",  2'b10, 3'b010, 7'b0000000, 4'b1000);
        check("SLTU", 2'b10, 3'b011, 7'b0000000, 4'b1001);
        check("XOR",  2'b10, 3'b100, 7'b0000000, 4'b0100);
        check("SRL",  2'b10, 3'b101, 7'b0000000, 4'b0110);
        check("SRA",  2'b10, 3'b101, 7'b0100000, 4'b0111);
        check("OR",   2'b10, 3'b110, 7'b0000000, 4'b0011);
        check("AND",  2'b10, 3'b111, 7'b0000000, 4'b0010);

        // I-type arithmetic (same funct3, funct7[5]=0 for shifts)
        check("ADDI", 2'b10, 3'b000, 7'b0000000, 4'b0000);
        check("SLLI", 2'b10, 3'b001, 7'b0000000, 4'b0101);
        check("SLTI", 2'b10, 3'b010, 7'b0000000, 4'b1000);
        check("SLTIU",2'b10, 3'b011, 7'b0000000, 4'b1001);
        check("XORI", 2'b10, 3'b100, 7'b0000000, 4'b0100);
        check("SRLI", 2'b10, 3'b101, 7'b0000000, 4'b0110);
        check("SRAI", 2'b10, 3'b101, 7'b0100000, 4'b0111);
        check("ORI",  2'b10, 3'b110, 7'b0000000, 4'b0011);
        check("ANDI", 2'b10, 3'b111, 7'b0000000, 4'b0010);

        // Default case
        check("DEFAULT", 2'b11, 3'b000, 7'b0000000, 4'b0000);

        $display("=== TEST DONE ===");
        $finish;
    end
endmodule