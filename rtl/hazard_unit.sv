// ============================================================================
// hazard_unit.sv - Hazard Detection Unit for RV32I 5-Stage Pipeline
// ============================================================================
// Detects:
// 1. Load-use data hazard (stall 1 cycle, hold PC & IF/ID, bubble to ID/EX)
// 2. Control hazard (branch/jump taken in EX stage -> flush IF/ID & ID/EX)
// ============================================================================

module hazard_unit (
    input  logic [4:0] rs1_id,
    input  logic [4:0] rs2_id,
    input  logic [4:0] rd_ex,
    input  logic       mem_to_reg_ex, // 1 when EX stage is a LOAD instruction
    input  logic       branch_taken_ex,
    output logic       pc_write,
    output logic       if_id_write,
    output logic       flush_id,      // Bubble inserted into ID/EX
    output logic       flush_if       // Flush IF/ID on branch/jump taken
);

    always_comb begin
        // Default: pipeline flows normally
        pc_write        = 1'b1;
        if_id_write     = 1'b1;
        flush_id        = 1'b0;
        flush_if        = 1'b0;

        // Load-use hazard detection
        if (mem_to_reg_ex && ((rd_ex == rs1_id) || (rd_ex == rs2_id)) && (rd_ex != 5'd0)) begin
            pc_write    = 1'b0; // Hold PC
            if_id_write = 1'b0; // Hold IF/ID register
            flush_id    = 1'b1; // Insert NOP bubble into ID/EX
        end

        // Control hazard (Branch/Jump taken in EX stage)
        if (branch_taken_ex) begin
            flush_if = 1'b1; // Flush IF/ID
            flush_id = 1'b1; // Flush ID/EX
        end
    end

endmodule