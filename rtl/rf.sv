// ============================================================================
// rf.sv - Register File for RV32I RISC-V Processor
// ============================================================================
// 32 general-purpose registers (x0-x31), each 32 bits.
// x0 is hardwired to zero: reads always return 0, writes are ignored.
// Two asynchronous read ports and one synchronous write port.
// ============================================================================

module rf (
    input  logic        clk,          // Clock
    input  logic        rst_n,        // Active-low reset
    input  logic [4:0]  rs1,          // Source register 1 address
    input  logic [4:0]  rs2,          // Source register 2 address
    input  logic [4:0]  rd,           // Destination register address
    input  logic [31:0] wr_data,      // Write data
    input  logic        wr_en,        // Write enable
    output logic [31:0] rs1_data,     // Read data 1
    output logic [31:0] rs2_data      // Read data 2
);

    // 32-entry register array
    logic [31:0] registers [0:31];

    integer i;

    // Synchronous write with reset
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < 32; i++) begin
                registers[i] <= 32'h0;
            end
        end else if (wr_en && (rd != 5'h0)) begin
            registers[rd] <= wr_data;
        end
    end

    // Asynchronous reads (x0 always returns 0)
    assign rs1_data = (rs1 == 5'h0) ? 32'h0 : registers[rs1];
    assign rs2_data = (rs2 == 5'h0) ? 32'h0 : registers[rs2];

endmodule