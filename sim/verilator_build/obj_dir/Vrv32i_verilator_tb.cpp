// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i_verilator_tb.h for the primary calling header

#include "Vrv32i_verilator_tb.h"
#include "Vrv32i_verilator_tb__Syms.h"

//==========

void Vrv32i_verilator_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrv32i_verilator_tb::eval\n"); );
    Vrv32i_verilator_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/rv32i_verilator_tb.sv", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vrv32i_verilator_tb::_eval_initial_loop(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/rv32i_verilator_tb.sv", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vrv32i_verilator_tb::_combo__TOP__2(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_combo__TOP__2\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rst_n)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rst_n 
            = vlTOPp->rv32i_verilator_tb__DOT__rst_n;
    }
    vlTOPp->rv32i_verilator_tb__DOT__clk = (1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__clk)));
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__clk) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__clk 
            = vlTOPp->rv32i_verilator_tb__DOT__clk;
    }
}

VL_INLINE_OPT void Vrv32i_verilator_tb::_sequent__TOP__4(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_sequent__TOP__4\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_b_cov__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__fwd_b_cov__v0;
    CData/*4:0*/ __Vdlyvdim0__rv32i_verilator_tb__DOT__rd_wb_cov__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__rd_wb_cov__v0;
    CData/*1:0*/ __Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_a_cov__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__fwd_a_cov__v0;
    CData/*3:0*/ __Vdlyvdim0__rv32i_verilator_tb__DOT__alu_op_cov__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__alu_op_cov__v0;
    // Body
    vlTOPp->__Vdly__rv32i_verilator_tb__DOT__cycle_count 
        = vlTOPp->rv32i_verilator_tb__DOT__cycle_count;
    vlTOPp->__Vdly__rv32i_verilator_tb__DOT__state 
        = vlTOPp->rv32i_verilator_tb__DOT__state;
    __Vdlyvset__rv32i_verilator_tb__DOT__fwd_a_cov__v0 = 0U;
    __Vdlyvset__rv32i_verilator_tb__DOT__alu_op_cov__v0 = 0U;
    __Vdlyvset__rv32i_verilator_tb__DOT__fwd_b_cov__v0 = 0U;
    __Vdlyvset__rv32i_verilator_tb__DOT__rd_wb_cov__v0 = 0U;
    ++(vlSymsp->__Vcoverage[315]);
    ++(vlSymsp->__Vcoverage[325]);
    if ((0U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        ++(vlSymsp->__Vcoverage[320]);
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
                ++(vlSymsp->__Vcoverage[324]);
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
            ++(vlSymsp->__Vcoverage[323]);
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
            if (VL_LTES_III(1,32,32, 0x1eU, vlTOPp->rv32i_verilator_tb__DOT__cycle_count)) {
                ++(vlSymsp->__Vcoverage[321]);
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
            if (VL_GTS_III(1,32,32, 0x1eU, vlTOPp->rv32i_verilator_tb__DOT__cycle_count)) {
                ++(vlSymsp->__Vcoverage[322]);
            }
        }
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[313]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[314]);
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__branch_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__reg_write_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__mem_write_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        __Vdlyvset__rv32i_verilator_tb__DOT__fwd_a_cov__v0 = 1U;
        __Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_a_cov__v0 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        __Vdlyvset__rv32i_verilator_tb__DOT__alu_op_cov__v0 = 1U;
        __Vdlyvdim0__rv32i_verilator_tb__DOT__alu_op_cov__v0 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        __Vdlyvset__rv32i_verilator_tb__DOT__fwd_b_cov__v0 = 1U;
        __Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_b_cov__v0 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__reg_write_mem_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__reg_write_wb_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        __Vdlyvset__rv32i_verilator_tb__DOT__rd_wb_cov__v0 = 1U;
        __Vdlyvdim0__rv32i_verilator_tb__DOT__rd_wb_cov__v0 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__fwd_a_cov__v0) {
        vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov[__Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_a_cov__v0] = 1U;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__alu_op_cov__v0) {
        vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov[__Vdlyvdim0__rv32i_verilator_tb__DOT__alu_op_cov__v0] = 1U;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__fwd_b_cov__v0) {
        vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov[__Vdlyvdim0__rv32i_verilator_tb__DOT__fwd_b_cov__v0] = 1U;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__rd_wb_cov__v0) {
        vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov[__Vdlyvdim0__rv32i_verilator_tb__DOT__rd_wb_cov__v0] = 1U;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__branch_ex_cov) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__branch_ex_cov)) {
        ++(vlSymsp->__Vcoverage[312]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__branch_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__branch_ex_cov;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__reg_write_ex_cov) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_ex_cov)) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__reg_write_ex_cov;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__mem_write_ex_cov) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__mem_write_ex_cov)) {
        ++(vlSymsp->__Vcoverage[311]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__mem_write_ex_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__mem_write_ex_cov;
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[0U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [0U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [0U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[0U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [0U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [0U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[1U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [1U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [1U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[1U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [1U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [1U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[2U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [2U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [2U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[2U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [2U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [2U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[3U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [3U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [3U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[3U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov
                [3U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_a_cov
                         [3U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [0U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [0U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [0U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [0U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[1U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [1U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [1U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[1U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [1U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [1U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[1U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [1U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [1U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[1U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [1U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [1U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[2U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [2U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [2U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[2U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [2U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [2U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[2U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [2U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [2U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[2U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [2U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [2U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[3U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [3U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [3U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[3U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [3U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [3U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[3U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [3U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [3U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[3U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [3U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [3U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[4U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [4U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [4U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[4U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [4U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [4U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[4U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [4U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [4U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[4U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [4U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [4U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[5U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [5U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [5U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[5U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [5U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [5U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[5U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [5U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [5U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[5U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [5U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [5U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[6U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [6U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [6U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[6U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [6U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [6U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[6U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [6U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [6U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[6U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [6U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [6U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[7U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [7U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [7U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[7U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [7U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [7U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[7U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [7U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [7U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[7U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [7U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [7U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[8U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [8U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [8U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[8U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [8U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [8U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[8U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [8U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [8U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[8U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [8U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [8U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[9U] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [9U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [9U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[9U] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [9U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [9U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[9U] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [9U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [9U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[9U] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [9U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                         [9U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xaU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xaU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xaU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xaU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xaU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xaU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xaU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xaU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xaU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xaU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xaU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xaU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xbU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xbU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xbU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xbU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xbU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xbU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xbU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xbU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xbU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xbU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xbU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xbU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xcU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xcU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xcU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xcU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xcU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xcU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xcU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xcU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xcU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xcU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xcU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xcU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xdU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xdU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xdU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xdU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xdU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xdU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xdU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xdU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xdU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xdU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xdU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xdU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xeU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xeU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xeU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xeU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xeU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xeU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xeU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xeU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xeU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xeU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xeU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xeU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xfU] 
            = ((0xeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xfU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xfU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xfU] 
            = ((0xdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xfU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xfU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xfU] 
            = ((0xbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xfU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xfU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[0xfU] 
            = ((7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov
                [0xfU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__alu_op_cov
                           [0xfU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[0U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [0U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [0U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[0U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [0U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [0U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[1U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [1U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [1U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[1U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [1U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [1U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[2U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [2U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [2U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[2U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [2U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [2U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[3U] 
            = ((2U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [3U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [3U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[3U] 
            = ((1U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov
                [3U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__fwd_b_cov
                         [3U]));
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__reg_write_mem_cov) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_mem_cov)) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_mem_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__reg_write_mem_cov;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__reg_write_wb_cov) 
         ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_wb_cov)) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__reg_write_wb_cov 
            = vlTOPp->rv32i_verilator_tb__DOT__reg_write_wb_cov;
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [0U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [0U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [0U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0U]))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [0U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [0U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[1U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [1U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [1U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[1U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [1U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [1U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[1U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [1U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [1U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [1U]))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[1U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [1U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [1U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [1U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[1U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [1U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [1U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[2U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [2U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [2U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[2U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [2U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [2U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[2U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [2U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [2U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [2U]))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[2U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [2U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [2U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [2U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[2U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [2U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [2U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[3U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [3U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [3U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[3U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [3U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [3U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[3U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [3U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [3U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [3U]))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[3U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [3U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [3U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [3U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[3U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [3U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [3U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[4U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [4U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [4U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[4U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [4U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [4U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[4U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [4U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [4U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [4U]))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[4U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [4U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [4U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [4U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[4U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [4U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [4U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[5U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [5U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [5U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[5U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [5U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [5U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[5U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [5U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [5U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [5U]))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[5U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [5U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [5U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [5U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[5U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [5U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [5U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[6U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [6U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [6U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[6U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [6U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [6U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[6U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [6U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [6U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [6U]))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[6U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [6U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [6U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [6U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[6U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [6U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [6U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[7U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [7U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [7U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[7U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [7U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [7U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[7U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [7U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [7U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [7U]))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[7U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [7U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [7U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [7U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[7U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [7U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [7U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[8U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [8U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [8U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[8U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [8U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [8U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[8U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [8U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [8U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [8U]))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[8U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [8U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [8U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [8U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[8U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [8U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [8U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[9U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [9U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [9U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[9U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [9U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [9U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[9U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [9U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [9U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [9U]))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[9U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [9U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [9U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [9U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[9U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [9U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                         [9U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xaU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xaU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xaU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xaU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xaU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xaU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xaU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xaU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xaU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xaU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xaU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xaU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xaU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xaU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xaU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xaU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xbU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xbU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xbU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xbU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xbU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xbU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xbU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xbU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xbU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xbU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xbU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xbU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xbU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xbU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xbU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xbU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xcU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xcU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xcU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xcU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xcU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xcU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xcU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xcU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xcU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xcU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xcU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xcU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xcU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xcU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xcU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xcU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xdU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xdU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xdU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xdU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xdU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xdU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xdU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xdU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xdU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xdU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xdU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xdU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xdU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xdU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xdU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xdU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xeU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xeU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xeU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xeU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xeU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xeU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xeU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xeU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xeU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xeU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xeU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xeU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xeU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xeU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xeU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xeU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xfU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xfU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xfU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xfU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xfU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xfU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xfU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xfU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xfU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xfU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xfU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xfU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0xfU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0xfU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0xfU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                           [0xfU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x10U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x10U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x10U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x10U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x10U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x10U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x10U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x10U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x10U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x10U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x10U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x10U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x10U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x10U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x10U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x10U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x10U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x10U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x10U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x10U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x11U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x11U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x11U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x11U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x11U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x11U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x11U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x11U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x11U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x11U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x11U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x11U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x11U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x11U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x11U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x11U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x11U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x11U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x11U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x11U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x12U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x12U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x12U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x12U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x12U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x12U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x12U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x12U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x12U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x12U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x12U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x12U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x12U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x12U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x12U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x12U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x12U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x12U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x12U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x12U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x13U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x13U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x13U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x13U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x13U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x13U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x13U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x13U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x13U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x13U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x13U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x13U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x13U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x13U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x13U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x13U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x13U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x13U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x13U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x13U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x14U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x14U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x14U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x14U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x14U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x14U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x14U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x14U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x14U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x14U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x14U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x14U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x14U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x14U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x14U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x14U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x14U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x14U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x14U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x14U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x15U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x15U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x15U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x15U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x15U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x15U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x15U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x15U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x15U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x15U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x15U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x15U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x15U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x15U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x15U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x15U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x15U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x15U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x15U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x15U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x16U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x16U]))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x16U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x16U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x16U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x16U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x16U]))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x16U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x16U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x16U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x16U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x16U]))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x16U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x16U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x16U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x16U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x16U]))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x16U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x16U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x16U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x16U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x16U]))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x16U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x16U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x16U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x17U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x17U]))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x17U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x17U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x17U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x17U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x17U]))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x17U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x17U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x17U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x17U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x17U]))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x17U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x17U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x17U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x17U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x17U]))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x17U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x17U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x17U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x17U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x17U]))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x17U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x17U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x17U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x18U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x18U]))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x18U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x18U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x18U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x18U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x18U]))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x18U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x18U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x18U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x18U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x18U]))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x18U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x18U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x18U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x18U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x18U]))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x18U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x18U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x18U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x18U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x18U]))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x18U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x18U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x18U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x19U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x19U]))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x19U] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x19U]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x19U]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x19U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x19U]))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x19U] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x19U]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x19U]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x19U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x19U]))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x19U] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x19U]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x19U]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x19U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x19U]))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x19U] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x19U]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x19U]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x19U] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x19U]))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x19U] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x19U]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x19U]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1aU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1aU]))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1aU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1aU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1aU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1aU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1aU]))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1aU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1aU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1aU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1aU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1aU]))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1aU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1aU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1aU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1aU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1aU]))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1aU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1aU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1aU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1aU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1aU]))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1aU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1aU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1aU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1bU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1bU]))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1bU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1bU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1bU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1bU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1bU]))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1bU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1bU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1bU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1bU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1bU]))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1bU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1bU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1bU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1bU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1bU]))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1bU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1bU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1bU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1bU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1bU]))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1bU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1bU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1bU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1cU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1cU]))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1cU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1cU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1cU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1cU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1cU]))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1cU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1cU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1cU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1cU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1cU]))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1cU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1cU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1cU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1cU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1cU]))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1cU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1cU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1cU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1cU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1cU]))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1cU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1cU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1cU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1dU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1dU]))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1dU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1dU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1dU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1dU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1dU]))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1dU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1dU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1dU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1dU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1dU]))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1dU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1dU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1dU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1dU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1dU]))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1dU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1dU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1dU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1dU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1dU]))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1dU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1dU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1dU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1eU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1eU]))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1eU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1eU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1eU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1eU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1eU]))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1eU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1eU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1eU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1eU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1eU]))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1eU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1eU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1eU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1eU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1eU]))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1eU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1eU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1eU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1eU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1eU]))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1eU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1eU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1eU]));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1fU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1fU]))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1fU] 
            = ((0x1eU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1fU]) | (1U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1fU]));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1fU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1fU]))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1fU] 
            = ((0x1dU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1fU]) | (2U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1fU]));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1fU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1fU]))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1fU] 
            = ((0x1bU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1fU]) | (4U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1fU]));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
               [0x1fU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
               [0x1fU]))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1fU] 
            = ((0x17U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1fU]) | (8U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1fU]));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                  [0x1fU] ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                  [0x1fU]))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[0x1fU] 
            = ((0xfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov
                [0x1fU]) | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__rd_wb_cov
                            [0x1fU]));
    }
}

VL_INLINE_OPT void Vrv32i_verilator_tb::_sequent__TOP__5(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_sequent__TOP__5\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v1;
    IData/*31:0*/ __Vdly__rv32i_verilator_tb__DOT__pc_if;
    IData/*31:0*/ __Vdlyvval__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0;
    // Body
    __Vdly__rv32i_verilator_tb__DOT__pc_if = vlTOPp->rv32i_verilator_tb__DOT__pc_if;
    __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0 = 0U;
    __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v1 = 0U;
    ++(vlSymsp->__Vcoverage[664]);
    ++(vlSymsp->__Vcoverage[667]);
    ++(vlSymsp->__Vcoverage[774]);
    ++(vlSymsp->__Vcoverage[898]);
    ++(vlSymsp->__Vcoverage[901]);
    ++(vlSymsp->__Vcoverage[906]);
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[663]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[662]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[665]);
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[666]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[772]);
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[773]);
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[897]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[896]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[899]);
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        ++(vlSymsp->__Vcoverage[900]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[905]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        ++(vlSymsp->__Vcoverage[902]);
    }
    if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)))) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__i = 0x20U;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
             & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)))) {
            ++(vlSymsp->__Vcoverage[903]);
        }
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
                      & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)))))) {
            ++(vlSymsp->__Vcoverage[904]);
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id));
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id));
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex));
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem));
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id;
        __Vdly__rv32i_verilator_tb__DOT__pc_if = ((IData)(4U) 
                                                  + vlTOPp->rv32i_verilator_tb__DOT__pc_if);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex 
            = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id) 
               & 1U);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex 
            = (7U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                     >> 0xcU));
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex 
            = (0x7fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        >> 0x19U));
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex 
            = (0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        >> 0xfU));
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex 
            = (0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        >> 0x14U));
    } else {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex = 0U;
        __Vdly__rv32i_verilator_tb__DOT__pc_if = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex = 0U;
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
             & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)))) {
            __Vdlyvval__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0 
                = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb;
            __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0 = 1U;
            __Vdlyvdim0__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0 
                = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb;
        }
    } else {
        __Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v1 = 1U;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[__Vdlyvdim0__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0] 
            = __Vdlyvval__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v0;
    }
    if (__Vdlyvset__rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers__v1) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[1U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[2U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[3U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[4U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[5U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[6U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[7U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[8U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[9U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xaU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xbU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xcU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xdU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xeU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0xfU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x10U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x11U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x12U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x13U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x14U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x15U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x16U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x17U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x18U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x19U] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1aU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1bU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1cU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1dU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1eU] = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[0x1fU] = 0U;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_ex)) {
        ++(vlSymsp->__Vcoverage[547]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_ex;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_ex)) {
        ++(vlSymsp->__Vcoverage[548]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_ex;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_mem)) {
        ++(vlSymsp->__Vcoverage[621]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_mem 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem;
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id));
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_wb)) {
        ++(vlSymsp->__Vcoverage[661]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_wb 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb;
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex));
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[390]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[391]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[392]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[393]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[394]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[395]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[396]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[397]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[398]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[399]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[400]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[401]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[402]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[403]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[404]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[405]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[406]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[407]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[408]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[417]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[418]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[419]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[420]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex))) {
        ++(vlSymsp->__Vcoverage[421]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_ex));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? vlTOPp->rv32i_verilator_tb__DOT__pc_if
            : 0U);
    if ((0U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        ++(vlSymsp->__Vcoverage[921]);
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            ++(vlSymsp->__Vcoverage[922]);
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                ++(vlSymsp->__Vcoverage[934]);
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                ++(vlSymsp->__Vcoverage[935]);
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex))) {
        ++(vlSymsp->__Vcoverage[549]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex 
            = ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex))) {
        ++(vlSymsp->__Vcoverage[550]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex 
            = ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex)));
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_ex)) {
        ++(vlSymsp->__Vcoverage[544]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex;
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[495]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[496]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[497]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[498]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[499]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[500]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[501]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[502]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[503]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[504]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[505]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[506]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[507]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[508]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[509]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[510]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[511]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[512]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[513]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[514]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[515]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[516]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex))) {
        ++(vlSymsp->__Vcoverage[517]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[422]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[423]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[424]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[425]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[426]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[427]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[428]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[429]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[430]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[431]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[432]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[433]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[434]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[435]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[436]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[437]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[438]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[439]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[440]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[441]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[442]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[443]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[444]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[445]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[446]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[447]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[448]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[449]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[450]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[451]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[452]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex))) {
        ++(vlSymsp->__Vcoverage[453]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex))) {
        ++(vlSymsp->__Vcoverage[533]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex 
            = ((6U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex))) {
        ++(vlSymsp->__Vcoverage[534]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex 
            = ((5U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex))) {
        ++(vlSymsp->__Vcoverage[535]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex 
            = ((3U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)));
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[536]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x7eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[537]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x7dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[538]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x7bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[539]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x77U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[540]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x6fU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((0x20U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[541]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x5fU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((0x40U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex))) {
        ++(vlSymsp->__Vcoverage[542]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex 
            = ((0x3fU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex)) 
               | (0x40U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex)));
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[931]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[924]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[933]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            ++(vlSymsp->__Vcoverage[933]);
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[927]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            ++(vlSymsp->__Vcoverage[933]);
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[932]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[930]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[933]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[929]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[928]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[926]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))) {
                                ++(vlSymsp->__Vcoverage[925]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
            if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))) {
                if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex)))) {
                                ++(vlSymsp->__Vcoverage[923]);
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex 
        = ((0U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))
            ? 0U : ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))
                     ? 1U : ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex))
                              ? ((0x20U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct7_ex))
                                  ? ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                      ? ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                                   ? 7U
                                                   : 0U))
                                      : ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                                   ? 0U
                                                   : 1U)))
                                  : ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                      ? ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                          ? ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                              ? 2U : 3U)
                                          : ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                              ? 6U : 4U))
                                      : ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                          ? ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                              ? 9U : 8U)
                                          : ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__funct3_ex))
                                              ? 5U : 0U))))
                              : 0U)));
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[583]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[584]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[585]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[586]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[587]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[588]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[589]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[590]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[591]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[592]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[593]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[594]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[595]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[596]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[597]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[598]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[599]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[600]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[601]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[602]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[603]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[604]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[605]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[606]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[607]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[608]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[609]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[610]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[611]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[612]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[613]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem))) {
        ++(vlSymsp->__Vcoverage[614]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw
            : 0U);
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex))) {
        ++(vlSymsp->__Vcoverage[518]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex 
            = ((0x1eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex))) {
        ++(vlSymsp->__Vcoverage[519]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex 
            = ((0x1dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex))) {
        ++(vlSymsp->__Vcoverage[520]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex 
            = ((0x1bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex))) {
        ++(vlSymsp->__Vcoverage[521]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex 
            = ((0x17U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex))) {
        ++(vlSymsp->__Vcoverage[522]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex 
            = ((0xfU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)));
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex))) {
        ++(vlSymsp->__Vcoverage[523]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex 
            = ((0x1eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex))) {
        ++(vlSymsp->__Vcoverage[524]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex 
            = ((0x1dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex))) {
        ++(vlSymsp->__Vcoverage[525]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex 
            = ((0x1bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex))) {
        ++(vlSymsp->__Vcoverage[526]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex 
            = ((0x17U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex))) {
        ++(vlSymsp->__Vcoverage[527]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex 
            = ((0xfU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)));
    }
    if (vlTOPp->rv32i_verilator_tb__DOT__rst_n) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb 
            = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
               & 1U);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem;
    } else {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb = 0U;
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb = 0U;
    }
    vlTOPp->rv32i_verilator_tb__DOT__pc_if = __Vdly__rv32i_verilator_tb__DOT__pc_if;
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
            if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                    ++(vlSymsp->__Vcoverage[976]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)))) {
                    ++(vlSymsp->__Vcoverage[969]);
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                ++(vlSymsp->__Vcoverage[979]);
            }
        }
    }
    if ((8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
        if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
            ++(vlSymsp->__Vcoverage[979]);
        }
    }
    if ((8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)))) {
                    ++(vlSymsp->__Vcoverage[977]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                    ++(vlSymsp->__Vcoverage[972]);
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                    ++(vlSymsp->__Vcoverage[978]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
            if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)))) {
                    ++(vlSymsp->__Vcoverage[975]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                    ++(vlSymsp->__Vcoverage[974]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)))) {
                    ++(vlSymsp->__Vcoverage[973]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                if ((1U & (~ (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)))) {
                    ++(vlSymsp->__Vcoverage[971]);
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))) {
                    ++(vlSymsp->__Vcoverage[970]);
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex))) {
        ++(vlSymsp->__Vcoverage[775]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex 
            = ((0xeU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex))) {
        ++(vlSymsp->__Vcoverage[776]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex 
            = ((0xdU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex))) {
        ++(vlSymsp->__Vcoverage[777]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex 
            = ((0xbU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex))) {
        ++(vlSymsp->__Vcoverage[778]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex 
            = ((7U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex)));
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_ex)) {
        ++(vlSymsp->__Vcoverage[545]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_mem)) {
        ++(vlSymsp->__Vcoverage[622]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_mem 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem;
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id));
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__pc_id));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__pc_if) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__pc_if));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[454]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[455]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[456]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[457]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[458]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[623]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[624]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[625]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[626]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[627]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[628]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[629]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[630]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[631]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[632]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[633]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[634]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[635]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[636]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[637]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[638]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[639]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[640]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[641]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[642]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[643]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[644]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[645]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[646]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[647]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[648]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[649]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[650]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[651]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[652]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[653]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb))) {
        ++(vlSymsp->__Vcoverage[654]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int
            : 0U);
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_wb)) {
        ++(vlSymsp->__Vcoverage[660]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_wb 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb;
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex));
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb))) {
        ++(vlSymsp->__Vcoverage[655]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb 
            = ((0x1eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb))) {
        ++(vlSymsp->__Vcoverage[656]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb 
            = ((0x1dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb))) {
        ++(vlSymsp->__Vcoverage[657]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb 
            = ((0x1bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb))) {
        ++(vlSymsp->__Vcoverage[658]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb 
            = ((0x17U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb))) {
        ++(vlSymsp->__Vcoverage[659]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb 
            = ((0xfU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb)));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)
            : 0U);
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_ex)) {
        ++(vlSymsp->__Vcoverage[546]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex;
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[551]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[552]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[553]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[554]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[555]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[556]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[557]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[558]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[559]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[560]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[561]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[562]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[563]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[564]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[565]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[566]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[567]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[568]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[569]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[570]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[571]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[572]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[573]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[574]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[575]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[576]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[577]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[578]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[579]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[580]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[581]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem))) {
        ++(vlSymsp->__Vcoverage[582]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n) 
           & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id));
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_mem)) {
        ++(vlSymsp->__Vcoverage[620]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_mem 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem;
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? (0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        >> 7U)) : 0U);
    if ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
          & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
         & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
            == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))) {
        ++(vlSymsp->__Vcoverage[882]);
    }
    if ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
          & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
         & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
            == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))) {
        ++(vlSymsp->__Vcoverage[886]);
    }
    if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
                   & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
                  & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
                     == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))))) {
        if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
                       & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
                      & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                         == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))))) {
            ++(vlSymsp->__Vcoverage[881]);
        }
    }
    if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
                   & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
                  & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
                     == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))))) {
        if ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
              & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
             & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))) {
            ++(vlSymsp->__Vcoverage[880]);
        }
    }
    if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
                   & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
                  & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
                     == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))))) {
        if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
                       & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
                      & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                         == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))))) {
            ++(vlSymsp->__Vcoverage[885]);
        }
    }
    if ((1U & (~ (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
                   & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
                  & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
                     == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))))) {
        if ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
              & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
             & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))) {
            ++(vlSymsp->__Vcoverage[884]);
        }
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem))) {
        ++(vlSymsp->__Vcoverage[615]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem 
            = ((0x1eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem))) {
        ++(vlSymsp->__Vcoverage[616]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem 
            = ((0x1dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem))) {
        ++(vlSymsp->__Vcoverage[617]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem 
            = ((0x1bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem))) {
        ++(vlSymsp->__Vcoverage[618]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem 
            = ((0x17U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem))) {
        ++(vlSymsp->__Vcoverage[619]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem 
            = ((0xfU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem)));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a 
        = ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
             & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
            & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))
            ? 2U : ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
                      & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
                     & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                        == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_ex)))
                     ? 1U : 0U));
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b 
        = ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem) 
             & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem))) 
            & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_mem) 
               == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))
            ? 2U : ((((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb) 
                      & (0U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb))) 
                     & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_wb) 
                        == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_ex)))
                     ? 1U : 0U));
    if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))) {
        ++(vlSymsp->__Vcoverage[888]);
    }
    if ((2U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))) {
            ++(vlSymsp->__Vcoverage[889]);
        }
    }
    if ((2U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))) {
            ++(vlSymsp->__Vcoverage[890]);
        }
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a))) {
        ++(vlSymsp->__Vcoverage[812]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a 
            = ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a))) {
        ++(vlSymsp->__Vcoverage[813]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a 
            = ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a)));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
        = ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))
            ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem
            : ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_a))
                ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb
                : vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex));
    if ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))) {
        ++(vlSymsp->__Vcoverage[892]);
    }
    if ((2U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))) {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))) {
            ++(vlSymsp->__Vcoverage[893]);
        }
    }
    if ((2U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))) {
        if ((1U != (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))) {
            ++(vlSymsp->__Vcoverage[894]);
        }
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b))) {
        ++(vlSymsp->__Vcoverage[814]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b 
            = ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b))) {
        ++(vlSymsp->__Vcoverage[815]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b 
            = ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b)));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
        = ((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))
            ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem
            : ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__forward_b))
                ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb
                : vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex));
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_ex)) {
        ++(vlSymsp->__Vcoverage[543]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_ex 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex;
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex))) {
        ++(vlSymsp->__Vcoverage[528]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex 
            = ((0x1eU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex))) {
        ++(vlSymsp->__Vcoverage[529]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex 
            = ((0x1dU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)));
    }
    if ((4U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex))) {
        ++(vlSymsp->__Vcoverage[530]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex 
            = ((0x1bU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex)) 
               | (4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)));
    }
    if ((8U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex))) {
        ++(vlSymsp->__Vcoverage[531]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex 
            = ((0x17U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex)) 
               | (8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)));
    }
    if ((0x10U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex) 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex))) {
        ++(vlSymsp->__Vcoverage[532]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex 
            = ((0xfU & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex)) 
               | (0x10U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rd_ex)));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__rst_n)
            ? vlTOPp->rv32i_verilator_tb__DOT__instr_if
            : 0U);
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[816]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[817]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[818]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[819]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[820]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[821]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[822]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[823]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[824]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[825]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[826]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[827]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[828]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[829]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[830]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[831]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[832]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[833]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[834]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[835]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[836]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[837]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[838]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[839]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[840]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[841]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[842]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[843]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[844]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[845]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[846]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd))) {
        ++(vlSymsp->__Vcoverage[847]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[848]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[849]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[850]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[851]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[852]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[853]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[854]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[855]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[856]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[857]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[858]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[859]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[860]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[861]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[862]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[863]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[864]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[865]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[866]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[867]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[868]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[869]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[870]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[871]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[872]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[873]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[874]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[875]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[876]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[877]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[878]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd))) {
        ++(vlSymsp->__Vcoverage[879]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
        = ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex)
            ? vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_ex
            : vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd);
    vlTOPp->rv32i_verilator_tb__DOT__instr_if = vlTOPp->rv32i_verilator_tb__DOT__imem
        [(0xffU & (vlTOPp->rv32i_verilator_tb__DOT__pc_if 
                   >> 2U))];
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[937]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[938]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[939]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[940]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[941]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[942]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[943]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[944]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[945]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[946]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[947]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[948]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[949]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[950]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[951]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[952]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[953]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[954]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[955]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[956]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[957]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[958]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[959]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[960]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[961]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[962]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[963]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[964]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[965]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[966]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[967]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[968]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
        = ((8U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
            ? ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                ? 0U : ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                         ? 0U : ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                                  ? ((vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                                      < vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)
                                      ? 1U : 0U) : 
                                 (VL_LTS_III(1,32,32, vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd, vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)
                                   ? 1U : 0U)))) : 
           ((4U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
             ? ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                 ? ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                     ? VL_SHIFTRS_III(32,32,5, vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd, 
                                      (0x1fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b))
                     : (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        >> (0x1fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)))
                 : ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                     ? (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        << (0x1fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b))
                     : (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)))
             : ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                 ? ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                     ? (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        | vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)
                     : (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b))
                 : ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex))
                     ? (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        - vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)
                     : (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd 
                        + vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b)))));
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                  ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                   ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                    ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                     ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                      ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                       ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__instr_if 
                        ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__instr_if) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__instr_if));
    }
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                ++(vlSymsp->__Vcoverage[909]);
            }
        }
    }
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            ++(vlSymsp->__Vcoverage[908]);
        }
    }
    if ((0x33U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        ++(vlSymsp->__Vcoverage[907]);
    }
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        if (((0x6fU == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) 
                             | (0x67U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)))) {
                            ++(vlSymsp->__Vcoverage[912]);
                        }
                    }
                }
            }
        }
    }
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        ++(vlSymsp->__Vcoverage[911]);
                    }
                }
            }
        }
    }
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    ++(vlSymsp->__Vcoverage[910]);
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[917]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[915]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        ++(vlSymsp->__Vcoverage[919]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    ++(vlSymsp->__Vcoverage[919]);
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        ++(vlSymsp->__Vcoverage[919]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[917]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            ++(vlSymsp->__Vcoverage[919]);
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        ++(vlSymsp->__Vcoverage[919]);
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                ++(vlSymsp->__Vcoverage[919]);
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[916]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    ++(vlSymsp->__Vcoverage[919]);
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[918]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[914]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[914]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
            if ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    ++(vlSymsp->__Vcoverage[919]);
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                    ++(vlSymsp->__Vcoverage[919]);
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                        ++(vlSymsp->__Vcoverage[919]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                                ++(vlSymsp->__Vcoverage[914]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) {
                            if ((1U & (~ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                                ++(vlSymsp->__Vcoverage[919]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                      >> 1U)))) {
                            ++(vlSymsp->__Vcoverage[919]);
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id = 0U;
    if ((0x33U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id = 1U;
    } else {
        if ((0x13U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id = 1U;
        } else {
            if ((3U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id = 1U;
            } else {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        if (((0x6fU == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) 
                             | (0x67U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)))) {
                            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id = 0U;
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        if (((0x6fU == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)) 
                             | (0x67U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)))) {
                            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id = 0U;
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id = 0U;
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id = 0U;
        } else {
            if ((3U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id = 1U;
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id = 0U;
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id = 1U;
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id = 0U;
    if ((0x33U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        if ((0x13U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id = 1U;
        } else {
            if ((3U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id = 1U;
            } else {
                if ((0x23U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id = 1U;
                }
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id = 0U;
    if ((0x33U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id = 2U;
    } else {
        if ((0x13U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
            vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id = 2U;
        } else {
            if ((3U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                if ((0x23U != (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                    if ((0x63U == (0x7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id))) {
                        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id = 1U;
                    }
                }
            }
        }
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[361]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[362]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[363]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[364]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[365]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[366]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[367]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[368]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[369]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[370]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[371]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[372]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[373]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[374]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[375]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[376]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[377]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[378]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[379]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[380]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[381]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[382]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[383]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[384]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[385]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[386]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[387]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[388]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id))) {
        ++(vlSymsp->__Vcoverage[389]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id));
    }
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
        = ((0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
            ? ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                ? ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                    ? 0U : ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                             ? ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                 ? ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                     ? ((1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                         ? ((0xfff00000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                               >> 0x1fU)))) 
                                                << 0x14U)) 
                                            | ((0xff000U 
                                                & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id) 
                                               | ((0x800U 
                                                   & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                        >> 0x14U)))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                           ? ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                               ? ((1U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  ((0xfffff800U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                                      >> 0x1fU)))) 
                                                       << 0xbU)) 
                                                   | (0x7ffU 
                                                      & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                         >> 0x14U)))
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                               ? ((1U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  ((0xfffff000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                                      >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | ((0x800U 
                                                       & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                               >> 7U)))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                          ? ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                              ? ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                  ? 0U : ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                           ? ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                               ? ((1U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   : 0U)
                                               : 0U)
                                           : 0U)) : 
                             ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                               ? 0U : ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                        ? 0U : ((2U 
                                                 & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                  ? 
                                                 ((0xfffff800U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                                     >> 0x1fU)))) 
                                                      << 0xbU)) 
                                                  | ((0x7e0U 
                                                      & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                              ? ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                  ? 0U : ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                           ? ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                               ? ((1U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                               ? ((1U 
                                                   & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                   ? 
                                                  ((0xfffff800U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                                      >> 0x1fU)))) 
                                                       << 0xbU)) 
                                                   | (0x7ffU 
                                                      & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                         >> 0x14U)))
                                                   : 0U)
                                               : 0U)))
                              : ((8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                  ? 0U : ((4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                           ? 0U : (
                                                   (2U 
                                                    & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id)
                                                     ? 
                                                    ((0xfffff800U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                                        >> 0x1fU)))) 
                                                         << 0xbU)) 
                                                     | (0x7ffU 
                                                        & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                                                           >> 0x14U)))
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
        = ((0U == (0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                            >> 0xfU))) ? 0U : vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers
           [(0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 0xfU))]);
    vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
        = ((0U == (0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                            >> 0x14U))) ? 0U : vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers
           [(0x1fU & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__instr_id 
                      >> 0x14U))]);
    if (((0U == vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__zero_flag_ex)) {
        ++(vlSymsp->__Vcoverage[811]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__zero_flag_ex 
            = (0U == vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int);
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[779]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[780]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[781]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[782]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[783]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[784]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[785]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[786]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[787]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[788]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[789]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[790]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[791]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[792]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[793]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[794]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[795]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[796]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[797]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[798]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[799]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[800]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[801]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[802]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[803]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[804]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[805]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[806]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[807]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[808]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[809]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int))) {
        ++(vlSymsp->__Vcoverage[810]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int));
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_id)) {
        ++(vlSymsp->__Vcoverage[764]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__reg_write_id;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_id)) {
        ++(vlSymsp->__Vcoverage[769]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__jump_id;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_id)) {
        ++(vlSymsp->__Vcoverage[768]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__branch_id;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_id)) {
        ++(vlSymsp->__Vcoverage[767]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_id)) {
        ++(vlSymsp->__Vcoverage[766]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__mem_write_id;
    }
    if (((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id) 
         ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_id)) {
        ++(vlSymsp->__Vcoverage[765]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_id 
            = vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_src_id;
    }
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id))) {
        ++(vlSymsp->__Vcoverage[770]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id 
            = ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id) 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id))) {
        ++(vlSymsp->__Vcoverage[771]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id 
            = ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__alu_op_id)));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[732]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[733]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[734]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[735]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[736]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[737]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[738]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[739]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[740]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[741]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[742]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[743]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[744]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[745]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[746]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[747]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[748]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[749]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[750]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[751]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[752]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[753]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[754]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[755]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[756]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[757]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[758]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[759]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[760]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[761]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[762]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id))) {
        ++(vlSymsp->__Vcoverage[763]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__imm_id));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[668]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[669]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[670]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[671]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[672]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[673]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[674]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[675]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[676]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[677]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[678]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[679]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[680]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[681]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[682]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[683]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[684]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[685]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[686]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[687]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[688]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[689]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[690]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[691]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[692]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[693]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[694]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[695]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[696]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[697]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[698]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw))) {
        ++(vlSymsp->__Vcoverage[699]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw));
    }
    if ((1U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[700]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffffeU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (1U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((2U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[701]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffffdU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (2U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((4U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[702]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffffbU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (4U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((8U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
               ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[703]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffff7U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (8U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x10U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[704]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffffefU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x10U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x20U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[705]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffffdfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x20U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x40U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[706]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffffbfU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x40U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x80U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                  ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[707]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffff7fU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x80U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x100U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[708]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffeffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x100U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x200U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[709]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffdffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x200U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x400U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[710]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffffbffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x400U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x800U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                   ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[711]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffff7ffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x800U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x1000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[712]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffefffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x1000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x2000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[713]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffdfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x2000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x4000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[714]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffffbfffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x4000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x8000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                    ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[715]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffff7fffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x8000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x10000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[716]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffeffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x10000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x20000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[717]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffdffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x20000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x40000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[718]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfffbffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x40000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x80000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                     ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[719]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfff7ffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x80000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x100000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[720]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffefffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x100000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x200000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[721]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffdfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x200000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x400000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[722]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xffbfffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x400000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x800000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                      ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[723]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xff7fffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x800000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x1000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[724]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfeffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x1000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x2000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[725]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfdffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x2000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x4000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[726]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xfbffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x4000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x8000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                       ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[727]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xf7ffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x8000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x10000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[728]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xefffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x10000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x20000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[729]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xdfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x20000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x40000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[730]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0xbfffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x40000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
    if ((0x80000000U & (vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw 
                        ^ vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw))) {
        ++(vlSymsp->__Vcoverage[731]);
        vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw 
            = ((0x7fffffffU & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw) 
               | (0x80000000U & vlTOPp->rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw));
    }
}
