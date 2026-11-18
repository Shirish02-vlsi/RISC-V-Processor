// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i_verilator_tb.h for the primary calling header

#include "Vrv32i_verilator_tb.h"
#include "Vrv32i_verilator_tb__Syms.h"

VL_INLINE_OPT void Vrv32i_verilator_tb::_sequent__TOP__7(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_sequent__TOP__7\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
        vlTOPp->rv32i_verilator_tb__DOT__rst_n = 0U;
        vlTOPp->__Vdly__rv32i_verilator_tb__DOT__cycle_count = 0U;
        vlTOPp->__Vdly__rv32i_verilator_tb__DOT__state = 1U;
    } else {
        if ((1U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state))) {
            vlTOPp->__Vdly__rv32i_verilator_tb__DOT__cycle_count 
                = ((IData)(1U) + vlTOPp->rv32i_verilator_tb__DOT__cycle_count);
            vlTOPp->rv32i_verilator_tb__DOT__rst_n = 1U;
            if (VL_LTES_III(1,32,32, 0x1eU, vlTOPp->rv32i_verilator_tb__DOT__cycle_count)) {
                vlTOPp->__Vdly__rv32i_verilator_tb__DOT__state = 2U;
            }
        } else {
            if (VL_UNLIKELY((2U == (IData)(vlTOPp->rv32i_verilator_tb__DOT__state)))) {
                VL_WRITEF("=== Test Complete ===\nCoverage collected via Verilator --coverage-line --coverage-toggle\n");
                VL_FINISH_MT("/mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/rv32i_verilator_tb.sv", 109, "");
            }
        }
    }
    vlTOPp->rv32i_verilator_tb__DOT__cycle_count = vlTOPp->__Vdly__rv32i_verilator_tb__DOT__cycle_count;
    vlTOPp->rv32i_verilator_tb__DOT__state = vlTOPp->__Vdly__rv32i_verilator_tb__DOT__state;
    if ((1U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__state) 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state 
            = ((2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state)) 
               | (1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__state)));
    }
    if ((2U & ((IData)(vlTOPp->rv32i_verilator_tb__DOT__state) 
               ^ vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state 
            = ((1U & (IData)(vlTOPp->rv32i_verilator_tb__DOT____Vtogcov__state)) 
               | (2U & (IData)(vlTOPp->rv32i_verilator_tb__DOT__state)));
    }
}

void Vrv32i_verilator_tb::_eval(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_eval\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__clk 
        = vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n 
        = vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n;
    vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__clk 
        = vlTOPp->rv32i_verilator_tb__DOT__clk;
    vlTOPp->__VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n 
        = vlTOPp->rv32i_verilator_tb__DOT__rst_n;
}

VL_INLINE_OPT QData Vrv32i_verilator_tb::_change_request(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_change_request\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vrv32i_verilator_tb::_change_request_1(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_change_request_1\n"); );
    Vrv32i_verilator_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->rv32i_verilator_tb__DOT__clk ^ vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__clk)
         | (vlTOPp->rv32i_verilator_tb__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__rst_n));
    VL_DEBUG_IF( if(__req && ((vlTOPp->rv32i_verilator_tb__DOT__clk ^ vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__clk))) VL_DBG_MSGF("        CHANGE: /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/rv32i_verilator_tb.sv:10: rv32i_verilator_tb.clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->rv32i_verilator_tb__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__rst_n))) VL_DBG_MSGF("        CHANGE: /mnt/d/AI-Projects/VLSI-Projects/RISC-V-Processor/sim/rv32i_verilator_tb.sv:11: rv32i_verilator_tb.rst_n\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__clk 
        = vlTOPp->rv32i_verilator_tb__DOT__clk;
    vlTOPp->__Vchglast__TOP__rv32i_verilator_tb__DOT__rst_n 
        = vlTOPp->rv32i_verilator_tb__DOT__rst_n;
    return __req;
}

#ifdef VL_DEBUG
void Vrv32i_verilator_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_verilator_tb::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
