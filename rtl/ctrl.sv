// ============================================================================
// ctrl.sv - Control Unit for RV32I RISC-V Processor
// ============================================================================
// Decodes instructions based on opcode and funct fields to generate control 
// signals for the processor pipeline.
// ============================================================================

module ctrl (
    input  logic [6:0] opcode,
    input  logic [2:0] funct3,
    input  logic [6:0] funct7,
    output logic       reg_write,
    output logic       alu_src,
    output logic       mem_write,
    output logic       mem_to_reg,
    output logic       branch,
    output logic       jump,
    output logic [1:0] alu_op
);

    // Instruction opcodes
    localparam OP_RTYPE = 7'b0110011;
    localparam OP_ITYPE = 7'b0010011;
    localparam OP_LOAD  = 7'b0000011;
    localparam OP_STORE = 7'b0100011;
    localparam OP_BRANCH= 7'b1100011;
    localparam OP_JAL   = 7'b1101111;
    localparam OP_JALR  = 7'b1100111;

    always_comb begin
        // Default values
        reg_write  = 1'b0;
        alu_src    = 1'b0;
        mem_write  = 1'b0;
        mem_to_reg = 1'b0;
        branch     = 1'b0;
        jump       = 1'b0;
        alu_op     = 2'b00;

        case (opcode)
            OP_RTYPE: begin
                reg_write = 1'b1;
                alu_op    = 2'b10; // R-type uses funct
            end
            OP_ITYPE: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                mem_to_reg = 1'b0; // ALU result, not memory
                alu_op    = 2'b10; // I-type uses funct
            end
            OP_LOAD: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                mem_to_reg = 1'b1;
            end
            OP_STORE: begin
                alu_src   = 1'b1;
                mem_write = 1'b1;
            end
            OP_BRANCH: begin
                branch = 1'b1;
                alu_op = 2'b01; // Branch uses subtract
            end
            OP_JAL, OP_JALR: begin
                reg_write = 1'b1;
                jump      = 1'b1;
            end
        endcase
    end
endmodule