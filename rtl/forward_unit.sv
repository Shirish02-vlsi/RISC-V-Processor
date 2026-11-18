// ============================================================================
// forward_unit.sv - Data Forwarding Unit for RV32I 5-Stage Pipeline
// ============================================================================
// Resolves RAW hazards by forwarding operand values directly to EX stage from:
//   - EX/MEM stage (1 cycle latency)
//   - MEM/WB stage (2 cycle latency)
// ============================================================================

module forward_unit (
    input  logic [4:0] rs1_ex,
    input  logic [4:0] rs2_ex,
    input  logic [4:0] rd_mem,
    input  logic       reg_write_mem,
    input  logic [4:0] rd_wb,
    input  logic       reg_write_wb,
    output logic [1:0] forward_a, // 2'b00: ID/EX, 2'b10: EX/MEM, 2'b01: MEM/WB
    output logic [1:0] forward_b
);

    always_comb begin
        // Forward A (rs1)
        if (reg_write_mem && (rd_mem != 5'd0) && (rd_mem == rs1_ex)) begin
            forward_a = 2'b10; // Forward from EX/MEM
        end else if (reg_write_wb && (rd_wb != 5'd0) && (rd_wb == rs1_ex)) begin
            forward_a = 2'b01; // Forward from MEM/WB
        end else begin
            forward_a = 2'b00; // No forwarding
        end

        // Forward B (rs2)
        if (reg_write_mem && (rd_mem != 5'd0) && (rd_mem == rs2_ex)) begin
            forward_b = 2'b10; // Forward from EX/MEM
        end else if (reg_write_wb && (rd_wb != 5'd0) && (rd_wb == rs2_ex)) begin
            forward_b = 2'b01; // Forward from MEM/WB
        end else begin
            forward_b = 2'b00; // No forwarding
        end
    end

endmodule