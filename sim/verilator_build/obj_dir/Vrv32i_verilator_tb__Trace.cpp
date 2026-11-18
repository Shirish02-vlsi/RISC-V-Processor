// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrv32i_verilator_tb__Syms.h"


void Vrv32i_verilator_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vrv32i_verilator_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->rv32i_verilator_tb__DOT__unnamedblk1__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+1,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[0]),4);
            tracep->chgCData(oldp+2,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[1]),4);
            tracep->chgCData(oldp+3,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[2]),4);
            tracep->chgCData(oldp+4,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[3]),4);
            tracep->chgCData(oldp+5,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[4]),4);
            tracep->chgCData(oldp+6,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[5]),4);
            tracep->chgCData(oldp+7,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[6]),4);
            tracep->chgCData(oldp+8,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[7]),4);
            tracep->chgCData(oldp+9,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[8]),4);
            tracep->chgCData(oldp+10,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[9]),4);
            tracep->chgCData(oldp+11,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[10]),4);
            tracep->chgCData(oldp+12,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[11]),4);
            tracep->chgCData(oldp+13,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[12]),4);
            tracep->chgCData(oldp+14,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[13]),4);
            tracep->chgCData(oldp+15,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[14]),4);
            tracep->chgCData(oldp+16,(vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[15]),4);
            tracep->chgCData(oldp+17,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[0]),2);
            tracep->chgCData(oldp+18,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[1]),2);
            tracep->chgCData(oldp+19,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[2]),2);
            tracep->chgCData(oldp+20,(vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[3]),2);
            tracep->chgCData(oldp+21,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[0]),2);
            tracep->chgCData(oldp+22,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[1]),2);
            tracep->chgCData(oldp+23,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[2]),2);
            tracep->chgCData(oldp+24,(vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[3]),2);
            tracep->chgBit(oldp+25,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_ex_cov));
            tracep->chgBit(oldp+26,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_mem_cov));
            tracep->chgBit(oldp+27,(vlTOPp->rv32i_verilator_tb__DOT__reg_write_wb_cov));
            tracep->chgCData(oldp+28,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[0]),5);
            tracep->chgCData(oldp+29,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[1]),5);
            tracep->chgCData(oldp+30,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[2]),5);
            tracep->chgCData(oldp+31,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[3]),5);
            tracep->chgCData(oldp+32,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[4]),5);
            tracep->chgCData(oldp+33,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[5]),5);
            tracep->chgCData(oldp+34,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[6]),5);
            tracep->chgCData(oldp+35,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[7]),5);
            tracep->chgCData(oldp+36,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[8]),5);
            tracep->chgCData(oldp+37,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[9]),5);
            tracep->chgCData(oldp+38,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[10]),5);
            tracep->chgCData(oldp+39,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[11]),5);
            tracep->chgCData(oldp+40,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[12]),5);
            tracep->chgCData(oldp+41,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[13]),5);
            tracep->chgCData(oldp+42,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[14]),5);
            tracep->chgCData(oldp+43,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[15]),5);
            tracep->chgCData(oldp+44,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[16]),5);
            tracep->chgCData(oldp+45,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[17]),5);
            tracep->chgCData(oldp+46,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[18]),5);
            tracep->chgCData(oldp+47,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[19]),5);
            tracep->chgCData(oldp+48,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[20]),5);
            tracep->chgCData(oldp+49,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[21]),5);
            tracep->chgCData(oldp+50,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[22]),5);
            tracep->chgCData(oldp+51,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[23]),5);
            tracep->chgCData(oldp+52,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[24]),5);
            tracep->chgCData(oldp+53,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[25]),5);
            tracep->chgCData(oldp+54,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[26]),5);
            tracep->chgCData(oldp+55,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[27]),5);
            tracep->chgCData(oldp+56,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[28]),5);
            tracep->chgCData(oldp+57,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[29]),5);
            tracep->chgCData(oldp+58,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[30]),5);
            tracep->chgCData(oldp+59,(vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[31]),5);
            tracep->chgBit(oldp+60,(vlTOPp->rv32i_verilator_tb__DOT__mem_write_ex_cov));
            tracep->chgBit(oldp+61,(vlTOPp->rv32i_verilator_tb__DOT__branch_ex_cov));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+62,(vlTOPp->rv32i_verilator_tb__DOT__instr_if),32);
            tracep->chgIData(oldp+63,(vlTOPp->rv32i_verilator_tb__DOT__pc_if),32);
            tracep->chgIData(oldp+64,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id),32);
            tracep->chgIData(oldp+65,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id),32);
            tracep->chgIData(oldp+66,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex),32);
            tracep->chgIData(oldp+67,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex),32);
            tracep->chgIData(oldp+68,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex),32);
            tracep->chgIData(oldp+69,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex),32);
            tracep->chgCData(oldp+70,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex),5);
            tracep->chgCData(oldp+71,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex),5);
            tracep->chgCData(oldp+72,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex),5);
            tracep->chgCData(oldp+73,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex),3);
            tracep->chgCData(oldp+74,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex),7);
            tracep->chgBit(oldp+75,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex));
            tracep->chgBit(oldp+76,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex));
            tracep->chgBit(oldp+77,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex));
            tracep->chgBit(oldp+78,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex));
            tracep->chgBit(oldp+79,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex));
            tracep->chgBit(oldp+80,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_ex));
            tracep->chgCData(oldp+81,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex),2);
            tracep->chgIData(oldp+82,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem),32);
            tracep->chgIData(oldp+83,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem),32);
            tracep->chgCData(oldp+84,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem),5);
            tracep->chgBit(oldp+85,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem));
            tracep->chgBit(oldp+86,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem));
            tracep->chgBit(oldp+87,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem));
            tracep->chgIData(oldp+88,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb),32);
            tracep->chgCData(oldp+89,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb),5);
            tracep->chgBit(oldp+90,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb));
            tracep->chgBit(oldp+91,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb));
            tracep->chgCData(oldp+92,((0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)),7);
            tracep->chgCData(oldp+93,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+94,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+95,((0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                >> 7U))),5);
            tracep->chgCData(oldp+96,((7U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+97,((0x7fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                >> 0x19U))),7);
            tracep->chgIData(oldp+98,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw),32);
            tracep->chgIData(oldp+99,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw),32);
            tracep->chgIData(oldp+100,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id),32);
            tracep->chgBit(oldp+101,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id));
            tracep->chgBit(oldp+102,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id));
            tracep->chgBit(oldp+103,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id));
            tracep->chgBit(oldp+104,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id));
            tracep->chgBit(oldp+105,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id));
            tracep->chgBit(oldp+106,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id));
            tracep->chgCData(oldp+107,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id),2);
            tracep->chgCData(oldp+108,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex),4);
            tracep->chgIData(oldp+109,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int),32);
            tracep->chgBit(oldp+110,((0U == vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int)));
            tracep->chgCData(oldp+111,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a),2);
            tracep->chgCData(oldp+112,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b),2);
            tracep->chgIData(oldp+113,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd),32);
            tracep->chgIData(oldp+114,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd),32);
            tracep->chgIData(oldp+115,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0]),32);
            tracep->chgIData(oldp+116,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[1]),32);
            tracep->chgIData(oldp+117,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[2]),32);
            tracep->chgIData(oldp+118,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[3]),32);
            tracep->chgIData(oldp+119,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[4]),32);
            tracep->chgIData(oldp+120,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[5]),32);
            tracep->chgIData(oldp+121,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[6]),32);
            tracep->chgIData(oldp+122,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[7]),32);
            tracep->chgIData(oldp+123,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[8]),32);
            tracep->chgIData(oldp+124,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[9]),32);
            tracep->chgIData(oldp+125,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[10]),32);
            tracep->chgIData(oldp+126,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[11]),32);
            tracep->chgIData(oldp+127,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[12]),32);
            tracep->chgIData(oldp+128,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[13]),32);
            tracep->chgIData(oldp+129,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[14]),32);
            tracep->chgIData(oldp+130,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[15]),32);
            tracep->chgIData(oldp+131,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[16]),32);
            tracep->chgIData(oldp+132,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[17]),32);
            tracep->chgIData(oldp+133,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[18]),32);
            tracep->chgIData(oldp+134,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[19]),32);
            tracep->chgIData(oldp+135,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[20]),32);
            tracep->chgIData(oldp+136,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[21]),32);
            tracep->chgIData(oldp+137,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[22]),32);
            tracep->chgIData(oldp+138,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[23]),32);
            tracep->chgIData(oldp+139,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[24]),32);
            tracep->chgIData(oldp+140,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[25]),32);
            tracep->chgIData(oldp+141,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[26]),32);
            tracep->chgIData(oldp+142,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[27]),32);
            tracep->chgIData(oldp+143,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[28]),32);
            tracep->chgIData(oldp+144,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[29]),32);
            tracep->chgIData(oldp+145,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[30]),32);
            tracep->chgIData(oldp+146,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[31]),32);
            tracep->chgIData(oldp+147,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__i),32);
            tracep->chgIData(oldp+148,(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+149,(vlTOPp->rv32i_verilator_tb__DOT__rst_n));
            tracep->chgCData(oldp+150,(vlTOPp->rv32i_verilator_tb__DOT__state),2);
            tracep->chgIData(oldp+151,(vlTOPp->rv32i_verilator_tb__DOT__cycle_count),32);
        }
        tracep->chgBit(oldp+152,(vlTOPp->rv32i_verilator_tb__DOT__clk));
    }
}

void Vrv32i_verilator_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = static_cast<Vrv32i_verilator_tb__Syms*>(userp);
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
