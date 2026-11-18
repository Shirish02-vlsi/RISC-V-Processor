// ============================================================================
// pc.sv - Program Counter for RV32I RISC-V Processor
// ============================================================================
// Tracks the address of the current instruction. Supports sequential
// increment (PC + 4) and branch/jump targets.
// ============================================================================

module pc (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] next_pc,
    input  logic        pc_write,
    output logic [31:0] pc
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 32'h0;
        end else if (pc_write) begin
            pc <= next_pc;
        end
    end
endmodule