// ============================================================================
// rv32i.sv - RV32I 5-Stage Pipelined Processor Top-Level
// ============================================================================
// Implements a complete 5-stage pipeline:
//   IF (Fetch) -> ID (Decode) -> EX (Execute) -> MEM (Memory) -> WB (Writeback)
// Features:
//   - Data forwarding (EX/MEM and MEM/WB to EX stage)
//   - Basic pipeline control (no hazard stalling yet)
//   - RV32I Base Integer ISA support
// ============================================================================

module rv32i (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] instr_if,
    output logic [31:0] pc_if
);

    // ------------------------------------------------------------
    // Pipeline Registers
    // ------------------------------------------------------------

    // IF/ID Pipeline Register
    logic [31:0] pc_id, instr_id;

    // ID/EX Pipeline Register
    logic [31:0] pc_ex, rs1_data_ex, rs2_data_ex, imm_ex;
    logic [4:0]  rs1_ex, rs2_ex, rd_ex;
    logic [2:0]  funct3_ex;
    logic [6:0]  funct7_ex;
    logic        reg_write_ex, alu_src_ex, mem_write_ex, mem_to_reg_ex, branch_ex, jump_ex;
    logic [1:0]  alu_op_ex;

    // EX/MEM Pipeline Register
    logic [31:0] alu_result_mem, rs2_data_mem;
    logic [4:0]  rd_mem;
    logic        reg_write_mem, mem_write_mem, mem_to_reg_mem;

    // MEM/WB Pipeline Register
    logic [31:0] alu_result_wb;
    logic [4:0]  rd_wb;
    logic        reg_write_wb, mem_to_reg_wb;

    // ------------------------------------------------------------
    // Stage: IF (Instruction Fetch)
    // ------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_if <= 32'h0;
        end else begin
            pc_if <= pc_if + 4;
        end
    end

    // IF/ID Pipeline Register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_id <= 32'h0;
            instr_id <= 32'h0;
        end else begin
            pc_id <= pc_if;
            instr_id <= instr_if;
        end
    end

    // ------------------------------------------------------------
    // Stage: ID (Instruction Decode)
    // ------------------------------------------------------------
    logic [6:0] opcode_id;
    logic [4:0] rs1_id, rs2_id, rd_id;
    logic [2:0] funct3_id;
    logic [6:0] funct7_id;
    logic [31:0] rs1_data_raw, rs2_data_raw;
    logic [31:0] imm_id;

    // ID stage control signals
    logic reg_write_id, alu_src_id, mem_write_id, mem_to_reg_id, branch_id, jump_id;
    logic [1:0] alu_op_id;

    assign opcode_id = instr_id[6:0];
    assign funct3_id = instr_id[14:12];
    assign funct7_id = instr_id[31:25];
    assign rs1_id    = instr_id[19:15];
    assign rs2_id    = instr_id[24:20];
    assign rd_id     = instr_id[11:7];

    rf rf_inst (
        .clk      (clk),
        .rst_n    (rst_n),
        .rs1      (rs1_id),
        .rs2      (rs2_id),
        .rd       (rd_wb),
        .wr_data  (mem_to_reg_wb ? alu_result_wb : alu_result_wb),
        .wr_en    (reg_write_wb),
        .rs1_data (rs1_data_raw),
        .rs2_data (rs2_data_raw)
    );

    ctrl ctrl_inst (
        .opcode    (opcode_id),
        .funct3    (funct3_id),
        .funct7    (funct7_id),
        .reg_write (reg_write_id),
        .alu_src   (alu_src_id),
        .mem_write (mem_write_id),
        .mem_to_reg(mem_to_reg_id),
        .branch    (branch_id),
        .jump      (jump_id),
        .alu_op    (alu_op_id)
    );

    imm_gen imm_gen_inst (
        .instr (instr_id),
        .imm   (imm_id)
    );

    // ID/EX Pipeline Register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_ex <= 32'h0;
            rs1_data_ex <= 32'h0;
            rs2_data_ex <= 32'h0;
            imm_ex <= 32'h0;
            rs1_ex <= 5'h0;
            rs2_ex <= 5'h0;
            rd_ex <= 5'h0;
            funct3_ex <= 3'h0;
            funct7_ex <= 7'h0;
            reg_write_ex <= 1'b0;
            alu_src_ex <= 1'b0;
            mem_write_ex <= 1'b0;
            mem_to_reg_ex <= 1'b0;
            branch_ex <= 1'b0;
            jump_ex <= 1'b0;
            alu_op_ex <= 2'b00;
        end else begin
            pc_ex <= pc_id;
            rs1_data_ex <= rs1_data_raw;
            rs2_data_ex <= rs2_data_raw;
            imm_ex <= imm_id;
            rs1_ex <= rs1_id;
            rs2_ex <= rs2_id;
            rd_ex <= rd_id;
            funct3_ex <= funct3_id;
            funct7_ex <= funct7_id;
            reg_write_ex <= reg_write_id;
            alu_src_ex <= alu_src_id;
            mem_write_ex <= mem_write_id;
            mem_to_reg_ex <= mem_to_reg_id;
            branch_ex <= branch_id;
            jump_ex <= jump_id;
            alu_op_ex <= alu_op_id;
        end
    end

    // ------------------------------------------------------------
    // Stage: EX (Execute)
    // ------------------------------------------------------------
    logic [3:0] alu_control_ex;
    logic [31:0] alu_result_ex_int;
    logic zero_flag_ex;

    // Forwarding muxes
    logic [1:0] forward_a, forward_b;
    logic [31:0] operand_a_fwd, operand_b_fwd;

    // Forward A (rs1)
    always_comb begin
        if (reg_write_mem && (rd_mem != 5'd0) && (rd_mem == rs1_ex)) begin
            forward_a = 2'b10; // EX/MEM
        end else if (reg_write_wb && (rd_wb != 5'd0) && (rd_wb == rs1_ex)) begin
            forward_a = 2'b01; // MEM/WB
        end else begin
            forward_a = 2'b00; // No forwarding
        end
    end

    // Forward B (rs2)
    always_comb begin
        if (reg_write_mem && (rd_mem != 5'd0) && (rd_mem == rs2_ex)) begin
            forward_b = 2'b10; // EX/MEM
        end else if (reg_write_wb && (rd_wb != 5'd0) && (rd_wb == rs2_ex)) begin
            forward_b = 2'b01; // MEM/WB
        end else begin
            forward_b = 2'b00; // No forwarding
        end
    end

    always_comb begin
        case (forward_a)
            2'b10: operand_a_fwd = alu_result_mem;
            2'b01: operand_a_fwd = alu_result_wb;
            default: operand_a_fwd = rs1_data_ex;
        endcase
    end

    always_comb begin
        case (forward_b)
            2'b10: operand_b_fwd = alu_result_mem;
            2'b01: operand_b_fwd = alu_result_wb;
            default: operand_b_fwd = rs2_data_ex;
        endcase
    end

    alu_ctrl alu_ctrl_inst (
        .alu_op      (alu_op_ex),
        .funct3      (funct3_ex),
        .funct7      (funct7_ex),
        .alu_control (alu_control_ex)
    );

    alu alu_inst (
        .operand_a   (operand_a_fwd),
        .operand_b   (alu_src_ex ? imm_ex : operand_b_fwd),
        .alu_control (alu_control_ex),
        .alu_result  (alu_result_ex_int),
        .zero_flag   (zero_flag_ex)
    );

    // EX/MEM Pipeline Register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            alu_result_mem <= 32'h0;
            rs2_data_mem <= 32'h0;
            rd_mem <= 5'h0;
            reg_write_mem <= 1'b0;
            mem_write_mem <= 1'b0;
            mem_to_reg_mem <= 1'b0;
        end else begin
            alu_result_mem <= alu_result_ex_int;
            rs2_data_mem <= rs2_data_ex;
            rd_mem <= rd_ex;
            reg_write_mem <= reg_write_ex;
            mem_write_mem <= mem_write_ex;
            mem_to_reg_mem <= mem_to_reg_ex;
        end
    end

    // ------------------------------------------------------------
    // Stage: MEM (Memory)
    // ------------------------------------------------------------
    // Memory access not implemented for simulation
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            alu_result_wb <= 32'h0;
            rd_wb <= 5'h0;
            reg_write_wb <= 1'b0;
            mem_to_reg_wb <= 1'b0;
        end else begin
            alu_result_wb <= alu_result_mem;
            rd_wb <= rd_mem;
            reg_write_wb <= reg_write_mem;
            mem_to_reg_wb <= mem_to_reg_mem;
        end
    end

endmodule