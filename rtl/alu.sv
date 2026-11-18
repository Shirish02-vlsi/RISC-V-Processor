// ============================================================================
// alu.sv - Arithmetic Logic Unit for RV32I RISC-V Processor
// ============================================================================
// This module performs arithmetic and logical operations on two 32-bit operands
// based on the alu_control signal. It supports the RV32I base integer
// instruction set operations.
// ============================================================================

module alu (
    input  logic [31:0] operand_a,    // First operand
    input  logic [31:0] operand_b,    // Second operand
    input  logic [3:0]  alu_control,  // Operation selector
    output logic [31:0] alu_result,   // Computed result
    output logic        zero_flag      // Asserted when result is zero
);

    // Combinational logic for computing the ALU result
    always_comb begin
        case (alu_control)
            4'b0000: alu_result = operand_a + operand_b;                          // ADD
            4'b0001: alu_result = operand_a - operand_b;                          // SUB
            4'b0010: alu_result = operand_a & operand_b;                          // AND
            4'b0011: alu_result = operand_a | operand_b;                          // OR
            4'b0100: alu_result = operand_a ^ operand_b;                          // XOR
            4'b0101: alu_result = operand_a << operand_b[4:0];                    // SLL (Shift Left Logical)
            4'b0110: alu_result = operand_a >> operand_b[4:0];                    // SRL (Shift Right Logical)
            4'b0111: alu_result = $signed(operand_a) >>> operand_b[4:0];          // SRA (Shift Right Arithmetic)
            4'b1000: alu_result = ($signed(operand_a) < $signed(operand_b)) ? 32'h1 : 32'h0; // SLT (Set Less Than, signed)
            4'b1001: alu_result = (operand_a < operand_b) ? 32'h1 : 32'h0;        // SLTU (Set Less Than Unsigned)
            default: alu_result = 32'h0;                                          // Invalid operation
        endcase
    end

    // Zero flag is asserted when the result is zero
    assign zero_flag = (alu_result == 32'h0);

endmodule