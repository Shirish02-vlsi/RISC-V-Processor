// ============================================================================
// alu_ctrl.sv - ALU Control Unit for RV32I RISC-V Processor
// ============================================================================
// Translates the processor-level ALU operation code (alu_op) along with the
// instruction's funct3 and funct7 fields into the 4-bit control signal
// expected by the ALU module.
// ============================================================================

module alu_ctrl (
    input  logic [1:0] alu_op,
    input  logic [2:0] funct3,
    input  logic [6:0] funct7,
    output logic [3:0] alu_control
);

    always_comb begin
        case (alu_op)
            2'b00: alu_control = 4'b0000; // Load/Store offset → ADD
            2'b01: alu_control = 4'b0001; // Branch → SUB
            2'b10: begin
                case ({funct7[5], funct3})
                    // R-type / I-type arithmetic
                    4'b0000: alu_control = 4'b0000; // ADD
                    4'b1000: alu_control = 4'b0001; // SUB
                    4'b0001: alu_control = 4'b0101; // SLL
                    4'b0010: alu_control = 4'b1000; // SLT
                    4'b0011: alu_control = 4'b1001; // SLTU
                    4'b0100: alu_control = 4'b0100; // XOR
                    4'b0101: alu_control = 4'b0110; // SRL
                    4'b1101: alu_control = 4'b0111; // SRA
                    4'b0110: alu_control = 4'b0011; // OR
                    4'b0111: alu_control = 4'b0010; // AND
                    default: alu_control = 4'b0000;
                endcase
            end
            default: alu_control = 4'b0000;
        endcase
    end
endmodule