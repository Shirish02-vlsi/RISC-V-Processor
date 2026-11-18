// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrv32i_verilator_tb__Syms.h"


//======================

void Vrv32i_verilator_tb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vrv32i_verilator_tb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vrv32i_verilator_tb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vrv32i_verilator_tb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vrv32i_verilator_tb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+153,"rv32i_verilator_tb clk", false,-1);
        tracep->declBit(c+150,"rv32i_verilator_tb rst_n", false,-1);
        tracep->declBus(c+63,"rv32i_verilator_tb instr_if", false,-1, 31,0);
        tracep->declBus(c+64,"rv32i_verilator_tb pc_if", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+2+i*1,"rv32i_verilator_tb alu_op_cov", true,(i+0), 3,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+18+i*1,"rv32i_verilator_tb fwd_a_cov", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+22+i*1,"rv32i_verilator_tb fwd_b_cov", true,(i+0), 1,0);}}
        tracep->declBit(c+26,"rv32i_verilator_tb reg_write_ex_cov", false,-1);
        tracep->declBit(c+27,"rv32i_verilator_tb reg_write_mem_cov", false,-1);
        tracep->declBit(c+28,"rv32i_verilator_tb reg_write_wb_cov", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+29+i*1,"rv32i_verilator_tb rd_wb_cov", true,(i+0), 4,0);}}
        tracep->declBit(c+61,"rv32i_verilator_tb mem_write_ex_cov", false,-1);
        tracep->declBit(c+62,"rv32i_verilator_tb branch_ex_cov", false,-1);
        tracep->declBus(c+151,"rv32i_verilator_tb state", false,-1, 1,0);
        tracep->declBus(c+152,"rv32i_verilator_tb cycle_count", false,-1, 31,0);
        tracep->declBus(c+1,"rv32i_verilator_tb unnamedblk1 i", false,-1, 31,0);
        tracep->declBit(c+153,"rv32i_verilator_tb dut clk", false,-1);
        tracep->declBit(c+150,"rv32i_verilator_tb dut rst_n", false,-1);
        tracep->declBus(c+63,"rv32i_verilator_tb dut instr_if", false,-1, 31,0);
        tracep->declBus(c+64,"rv32i_verilator_tb dut pc_if", false,-1, 31,0);
        tracep->declBus(c+65,"rv32i_verilator_tb dut pc_id", false,-1, 31,0);
        tracep->declBus(c+66,"rv32i_verilator_tb dut instr_id", false,-1, 31,0);
        tracep->declBus(c+67,"rv32i_verilator_tb dut pc_ex", false,-1, 31,0);
        tracep->declBus(c+68,"rv32i_verilator_tb dut rs1_data_ex", false,-1, 31,0);
        tracep->declBus(c+69,"rv32i_verilator_tb dut rs2_data_ex", false,-1, 31,0);
        tracep->declBus(c+70,"rv32i_verilator_tb dut imm_ex", false,-1, 31,0);
        tracep->declBus(c+71,"rv32i_verilator_tb dut rs1_ex", false,-1, 4,0);
        tracep->declBus(c+72,"rv32i_verilator_tb dut rs2_ex", false,-1, 4,0);
        tracep->declBus(c+73,"rv32i_verilator_tb dut rd_ex", false,-1, 4,0);
        tracep->declBus(c+74,"rv32i_verilator_tb dut funct3_ex", false,-1, 2,0);
        tracep->declBus(c+75,"rv32i_verilator_tb dut funct7_ex", false,-1, 6,0);
        tracep->declBit(c+76,"rv32i_verilator_tb dut reg_write_ex", false,-1);
        tracep->declBit(c+77,"rv32i_verilator_tb dut alu_src_ex", false,-1);
        tracep->declBit(c+78,"rv32i_verilator_tb dut mem_write_ex", false,-1);
        tracep->declBit(c+79,"rv32i_verilator_tb dut mem_to_reg_ex", false,-1);
        tracep->declBit(c+80,"rv32i_verilator_tb dut branch_ex", false,-1);
        tracep->declBit(c+81,"rv32i_verilator_tb dut jump_ex", false,-1);
        tracep->declBus(c+82,"rv32i_verilator_tb dut alu_op_ex", false,-1, 1,0);
        tracep->declBus(c+83,"rv32i_verilator_tb dut alu_result_mem", false,-1, 31,0);
        tracep->declBus(c+84,"rv32i_verilator_tb dut rs2_data_mem", false,-1, 31,0);
        tracep->declBus(c+85,"rv32i_verilator_tb dut rd_mem", false,-1, 4,0);
        tracep->declBit(c+86,"rv32i_verilator_tb dut reg_write_mem", false,-1);
        tracep->declBit(c+87,"rv32i_verilator_tb dut mem_write_mem", false,-1);
        tracep->declBit(c+88,"rv32i_verilator_tb dut mem_to_reg_mem", false,-1);
        tracep->declBus(c+89,"rv32i_verilator_tb dut alu_result_wb", false,-1, 31,0);
        tracep->declBus(c+90,"rv32i_verilator_tb dut rd_wb", false,-1, 4,0);
        tracep->declBit(c+91,"rv32i_verilator_tb dut reg_write_wb", false,-1);
        tracep->declBit(c+92,"rv32i_verilator_tb dut mem_to_reg_wb", false,-1);
        tracep->declBus(c+93,"rv32i_verilator_tb dut opcode_id", false,-1, 6,0);
        tracep->declBus(c+94,"rv32i_verilator_tb dut rs1_id", false,-1, 4,0);
        tracep->declBus(c+95,"rv32i_verilator_tb dut rs2_id", false,-1, 4,0);
        tracep->declBus(c+96,"rv32i_verilator_tb dut rd_id", false,-1, 4,0);
        tracep->declBus(c+97,"rv32i_verilator_tb dut funct3_id", false,-1, 2,0);
        tracep->declBus(c+98,"rv32i_verilator_tb dut funct7_id", false,-1, 6,0);
        tracep->declBus(c+99,"rv32i_verilator_tb dut rs1_data_raw", false,-1, 31,0);
        tracep->declBus(c+100,"rv32i_verilator_tb dut rs2_data_raw", false,-1, 31,0);
        tracep->declBus(c+101,"rv32i_verilator_tb dut imm_id", false,-1, 31,0);
        tracep->declBit(c+102,"rv32i_verilator_tb dut reg_write_id", false,-1);
        tracep->declBit(c+103,"rv32i_verilator_tb dut alu_src_id", false,-1);
        tracep->declBit(c+104,"rv32i_verilator_tb dut mem_write_id", false,-1);
        tracep->declBit(c+105,"rv32i_verilator_tb dut mem_to_reg_id", false,-1);
        tracep->declBit(c+106,"rv32i_verilator_tb dut branch_id", false,-1);
        tracep->declBit(c+107,"rv32i_verilator_tb dut jump_id", false,-1);
        tracep->declBus(c+108,"rv32i_verilator_tb dut alu_op_id", false,-1, 1,0);
        tracep->declBus(c+109,"rv32i_verilator_tb dut alu_control_ex", false,-1, 3,0);
        tracep->declBus(c+110,"rv32i_verilator_tb dut alu_result_ex_int", false,-1, 31,0);
        tracep->declBit(c+111,"rv32i_verilator_tb dut zero_flag_ex", false,-1);
        tracep->declBus(c+112,"rv32i_verilator_tb dut forward_a", false,-1, 1,0);
        tracep->declBus(c+113,"rv32i_verilator_tb dut forward_b", false,-1, 1,0);
        tracep->declBus(c+114,"rv32i_verilator_tb dut operand_a_fwd", false,-1, 31,0);
        tracep->declBus(c+115,"rv32i_verilator_tb dut operand_b_fwd", false,-1, 31,0);
        tracep->declBit(c+153,"rv32i_verilator_tb dut rf_inst clk", false,-1);
        tracep->declBit(c+150,"rv32i_verilator_tb dut rf_inst rst_n", false,-1);
        tracep->declBus(c+94,"rv32i_verilator_tb dut rf_inst rs1", false,-1, 4,0);
        tracep->declBus(c+95,"rv32i_verilator_tb dut rf_inst rs2", false,-1, 4,0);
        tracep->declBus(c+90,"rv32i_verilator_tb dut rf_inst rd", false,-1, 4,0);
        tracep->declBus(c+89,"rv32i_verilator_tb dut rf_inst wr_data", false,-1, 31,0);
        tracep->declBit(c+91,"rv32i_verilator_tb dut rf_inst wr_en", false,-1);
        tracep->declBus(c+99,"rv32i_verilator_tb dut rf_inst rs1_data", false,-1, 31,0);
        tracep->declBus(c+100,"rv32i_verilator_tb dut rf_inst rs2_data", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+116+i*1,"rv32i_verilator_tb dut rf_inst registers", true,(i+0), 31,0);}}
        tracep->declBus(c+148,"rv32i_verilator_tb dut rf_inst i", false,-1, 31,0);
        tracep->declBus(c+93,"rv32i_verilator_tb dut ctrl_inst opcode", false,-1, 6,0);
        tracep->declBus(c+97,"rv32i_verilator_tb dut ctrl_inst funct3", false,-1, 2,0);
        tracep->declBus(c+98,"rv32i_verilator_tb dut ctrl_inst funct7", false,-1, 6,0);
        tracep->declBit(c+102,"rv32i_verilator_tb dut ctrl_inst reg_write", false,-1);
        tracep->declBit(c+103,"rv32i_verilator_tb dut ctrl_inst alu_src", false,-1);
        tracep->declBit(c+104,"rv32i_verilator_tb dut ctrl_inst mem_write", false,-1);
        tracep->declBit(c+105,"rv32i_verilator_tb dut ctrl_inst mem_to_reg", false,-1);
        tracep->declBit(c+106,"rv32i_verilator_tb dut ctrl_inst branch", false,-1);
        tracep->declBit(c+107,"rv32i_verilator_tb dut ctrl_inst jump", false,-1);
        tracep->declBus(c+108,"rv32i_verilator_tb dut ctrl_inst alu_op", false,-1, 1,0);
        tracep->declBus(c+154,"rv32i_verilator_tb dut ctrl_inst OP_RTYPE", false,-1, 6,0);
        tracep->declBus(c+155,"rv32i_verilator_tb dut ctrl_inst OP_ITYPE", false,-1, 6,0);
        tracep->declBus(c+156,"rv32i_verilator_tb dut ctrl_inst OP_LOAD", false,-1, 6,0);
        tracep->declBus(c+157,"rv32i_verilator_tb dut ctrl_inst OP_STORE", false,-1, 6,0);
        tracep->declBus(c+158,"rv32i_verilator_tb dut ctrl_inst OP_BRANCH", false,-1, 6,0);
        tracep->declBus(c+159,"rv32i_verilator_tb dut ctrl_inst OP_JAL", false,-1, 6,0);
        tracep->declBus(c+160,"rv32i_verilator_tb dut ctrl_inst OP_JALR", false,-1, 6,0);
        tracep->declBus(c+66,"rv32i_verilator_tb dut imm_gen_inst instr", false,-1, 31,0);
        tracep->declBus(c+101,"rv32i_verilator_tb dut imm_gen_inst imm", false,-1, 31,0);
        tracep->declBus(c+93,"rv32i_verilator_tb dut imm_gen_inst opcode", false,-1, 6,0);
        tracep->declBus(c+82,"rv32i_verilator_tb dut alu_ctrl_inst alu_op", false,-1, 1,0);
        tracep->declBus(c+74,"rv32i_verilator_tb dut alu_ctrl_inst funct3", false,-1, 2,0);
        tracep->declBus(c+75,"rv32i_verilator_tb dut alu_ctrl_inst funct7", false,-1, 6,0);
        tracep->declBus(c+109,"rv32i_verilator_tb dut alu_ctrl_inst alu_control", false,-1, 3,0);
        tracep->declBus(c+114,"rv32i_verilator_tb dut alu_inst operand_a", false,-1, 31,0);
        tracep->declBus(c+149,"rv32i_verilator_tb dut alu_inst operand_b", false,-1, 31,0);
        tracep->declBus(c+109,"rv32i_verilator_tb dut alu_inst alu_control", false,-1, 3,0);
        tracep->declBus(c+110,"rv32i_verilator_tb dut alu_inst alu_result", false,-1, 31,0);
        tracep->declBit(c+111,"rv32i_verilator_tb dut alu_inst zero_flag", false,-1);
    }
}

void Vrv32i_verilator_tb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vrv32i_verilator_tb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vrv32i_verilator_tb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->rv32i_verilator_tb__DOT__unnamedblk1__DOT__i),32);
        tracep->fullCData(oldp+2,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[0]),4);
        tracep->fullCData(oldp+3,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[1]),4);
        tracep->fullCData(oldp+4,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[2]),4);
        tracep->fullCData(oldp+5,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[3]),4);
        tracep->fullCData(oldp+6,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[4]),4);
        tracep->fullCData(oldp+7,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[5]),4);
        tracep->fullCData(oldp+8,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[6]),4);
        tracep->fullCData(oldp+9,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[7]),4);
        tracep->fullCData(oldp+10,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[8]),4);
        tracep->fullCData(oldp+11,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[9]),4);
        tracep->fullCData(oldp+12,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[10]),4);
        tracep->fullCData(oldp+13,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[11]),4);
        tracep->fullCData(oldp+14,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[12]),4);
        tracep->fullCData(oldp+15,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[13]),4);
        tracep->fullCData(oldp+16,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[14]),4);
        tracep->fullCData(oldp+17,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[15]),4);
        tracep->fullCData(oldp+18,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[0]),2);
        tracep->fullCData(oldp+19,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[1]),2);
        tracep->fullCData(oldp+20,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[2]),2);
        tracep->fullCData(oldp+21,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[3]),2);
        tracep->fullCData(oldp+22,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[0]),2);
        tracep->fullCData(oldp+23,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[1]),2);
        tracep->fullCData(oldp+24,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[2]),2);
        tracep->fullCData(oldp+25,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[3]),2);
        tracep->fullBit(oldp+26,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_ex_cov));
        tracep->fullBit(oldp+27,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_mem_cov));
        tracep->fullBit(oldp+28,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_wb_cov));
        tracep->fullCData(oldp+29,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[0]),5);
        tracep->fullCData(oldp+30,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[1]),5);
        tracep->fullCData(oldp+31,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[2]),5);
        tracep->fullCData(oldp+32,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[3]),5);
        tracep->fullCData(oldp+33,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[4]),5);
        tracep->fullCData(oldp+34,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[5]),5);
        tracep->fullCData(oldp+35,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[6]),5);
        tracep->fullCData(oldp+36,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[7]),5);
        tracep->fullCData(oldp+37,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[8]),5);
        tracep->fullCData(oldp+38,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[9]),5);
        tracep->fullCData(oldp+39,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[10]),5);
        tracep->fullCData(oldp+40,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[11]),5);
        tracep->fullCData(oldp+41,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[12]),5);
        tracep->fullCData(oldp+42,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[13]),5);
        tracep->fullCData(oldp+43,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[14]),5);
        tracep->fullCData(oldp+44,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[15]),5);
        tracep->fullCData(oldp+45,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[16]),5);
        tracep->fullCData(oldp+46,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[17]),5);
        tracep->fullCData(oldp+47,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[18]),5);
        tracep->fullCData(oldp+48,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[19]),5);
        tracep->fullCData(oldp+49,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[20]),5);
        tracep->fullCData(oldp+50,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[21]),5);
        tracep->fullCData(oldp+51,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[22]),5);
        tracep->fullCData(oldp+52,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[23]),5);
        tracep->fullCData(oldp+53,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[24]),5);
        tracep->fullCData(oldp+54,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[25]),5);
        tracep->fullCData(oldp+55,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[26]),5);
        tracep->fullCData(oldp+56,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[27]),5);
        tracep->fullCData(oldp+57,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[28]),5);
        tracep->fullCData(oldp+58,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[29]),5);
        tracep->fullCData(oldp+59,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[30]),5);
        tracep->fullCData(oldp+60,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[31]),5);
        tracep->fullBit(oldp+61,(vlTOPp->rv32i_verilator_tb__DOT__mem_write_ex_cov));
        tracep->fullBit(oldp+62,(vlTOPp->rv32i_verilator_tb__DOT__branch_ex_cov));
        tracep->fullIData(oldp+63,(vlTOPp->rv32i_verilator_tb__DOT__instr_if),32);
        tracep->fullIData(oldp+64,(vlTOPp->rv32i_verilator_tb__DOT__pc_if),32);
        tracep->fullIData(oldp+65,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id),32);
        tracep->fullIData(oldp+66,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id),32);
        tracep->fullIData(oldp+67,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex),32);
        tracep->fullIData(oldp+68,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex),32);
        tracep->fullIData(oldp+69,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex),32);
        tracep->fullIData(oldp+70,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex),32);
        tracep->fullCData(oldp+71,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex),5);
        tracep->fullCData(oldp+72,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex),5);
        tracep->fullCData(oldp+73,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex),5);
        tracep->fullCData(oldp+74,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex),3);
        tracep->fullCData(oldp+75,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex),7);
        tracep->fullBit(oldp+76,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex));
        tracep->fullBit(oldp+77,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex));
        tracep->fullBit(oldp+78,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex));
        tracep->fullBit(oldp+79,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex));
        tracep->fullBit(oldp+80,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex));
        tracep->fullBit(oldp+81,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_ex));
        tracep->fullCData(oldp+82,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex),2);
        tracep->fullIData(oldp+83,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem),32);
        tracep->fullIData(oldp+84,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem),32);
        tracep->fullCData(oldp+85,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem),5);
        tracep->fullBit(oldp+86,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem));
        tracep->fullBit(oldp+87,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem));
        tracep->fullBit(oldp+88,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem));
        tracep->fullIData(oldp+89,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb),32);
        tracep->fullCData(oldp+90,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb),5);
        tracep->fullBit(oldp+91,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb));
        tracep->fullBit(oldp+92,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb));
        tracep->fullCData(oldp+93,((0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)),7);
        tracep->fullCData(oldp+94,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+95,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+96,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                             >> 7U))),5);
        tracep->fullCData(oldp+97,((7U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+98,((0x7fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                             >> 0x19U))),7);
        tracep->fullIData(oldp+99,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw),32);
        tracep->fullIData(oldp+100,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw),32);
        tracep->fullIData(oldp+101,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id),32);
        tracep->fullBit(oldp+102,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id));
        tracep->fullBit(oldp+103,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id));
        tracep->fullBit(oldp+104,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id));
        tracep->fullBit(oldp+105,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id));
        tracep->fullBit(oldp+106,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id));
        tracep->fullBit(oldp+107,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id));
        tracep->fullCData(oldp+108,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id),2);
        tracep->fullCData(oldp+109,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex),4);
        tracep->fullIData(oldp+110,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int),32);
        tracep->fullBit(oldp+111,((0U == vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int)));
        tracep->fullCData(oldp+112,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a),2);
        tracep->fullCData(oldp+113,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b),2);
        tracep->fullIData(oldp+114,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd),32);
        tracep->fullIData(oldp+115,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd),32);
        tracep->fullIData(oldp+116,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0]),32);
        tracep->fullIData(oldp+117,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[1]),32);
        tracep->fullIData(oldp+118,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[2]),32);
        tracep->fullIData(oldp+119,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[3]),32);
        tracep->fullIData(oldp+120,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[4]),32);
        tracep->fullIData(oldp+121,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[5]),32);
        tracep->fullIData(oldp+122,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[6]),32);
        tracep->fullIData(oldp+123,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[7]),32);
        tracep->fullIData(oldp+124,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[8]),32);
        tracep->fullIData(oldp+125,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[9]),32);
        tracep->fullIData(oldp+126,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[10]),32);
        tracep->fullIData(oldp+127,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[11]),32);
        tracep->fullIData(oldp+128,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[12]),32);
        tracep->fullIData(oldp+129,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[13]),32);
        tracep->fullIData(oldp+130,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[14]),32);
        tracep->fullIData(oldp+131,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[15]),32);
        tracep->fullIData(oldp+132,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[16]),32);
        tracep->fullIData(oldp+133,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[17]),32);
        tracep->fullIData(oldp+134,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[18]),32);
        tracep->fullIData(oldp+135,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[19]),32);
        tracep->fullIData(oldp+136,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[20]),32);
        tracep->fullIData(oldp+137,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[21]),32);
        tracep->fullIData(oldp+138,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[22]),32);
        tracep->fullIData(oldp+139,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[23]),32);
        tracep->fullIData(oldp+140,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[24]),32);
        tracep->fullIData(oldp+141,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[25]),32);
        tracep->fullIData(oldp+142,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[26]),32);
        tracep->fullIData(oldp+143,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[27]),32);
        tracep->fullIData(oldp+144,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[28]),32);
        tracep->fullIData(oldp+145,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[29]),32);
        tracep->fullIData(oldp+146,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[30]),32);
        tracep->fullIData(oldp+147,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[31]),32);
        tracep->fullIData(oldp+148,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__i),32);
        tracep->fullIData(oldp+149,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b),32);
        tracep->fullBit(oldp+150,(vlTOPp->rv32i_verilator_tb__DOT__rst_n));
        tracep->fullCData(oldp+151,(vlTOPp->rv32i_verilator_tb__DOT__state),2);
        tracep->fullIData(oldp+152,(vlTOPp->rv32i_verilator_tb__DOT__cycle_count),32);
        tracep->fullBit(oldp+153,(vlTOPp->rv32i_verilator_tb__DOT__clk));
        tracep->fullCData(oldp+154,(0x33U),7);
        tracep->fullCData(oldp+155,(0x13U),7);
        tracep->fullCData(oldp+156,(3U),7);
        tracep->fullCData(oldp+157,(0x23U),7);
        tracep->fullCData(oldp+158,(0x63U),7);
        tracep->fullCData(oldp+159,(0x6fU),7);
        tracep->fullCData(oldp+160,(0x67U),7);
    }
}
