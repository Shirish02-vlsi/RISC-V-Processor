// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRV32I_VERILATOR_TB_H_
#define _VRV32I_VERILATOR_TB_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vrv32i_verilator_tb__Syms;
class Vrv32i_verilator_tb_VerilatedVcd;


//----------

VL_MODULE(Vrv32i_verilator_tb) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ rv32i_verilator_tb__DOT__clk;
    CData/*0:0*/ rv32i_verilator_tb__DOT__rst_n;
    CData/*0:0*/ rv32i_verilator_tb__DOT__reg_write_ex_cov;
    CData/*0:0*/ rv32i_verilator_tb__DOT__reg_write_mem_cov;
    CData/*0:0*/ rv32i_verilator_tb__DOT__reg_write_wb_cov;
    CData/*0:0*/ rv32i_verilator_tb__DOT__mem_write_ex_cov;
    CData/*0:0*/ rv32i_verilator_tb__DOT__branch_ex_cov;
    CData/*1:0*/ rv32i_verilator_tb__DOT__state;
    CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs1_ex;
    CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs2_ex;
    CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT__rd_ex;
    CData/*2:0*/ rv32i_verilator_tb__DOT__dut__DOT__funct3_ex;
    CData/*6:0*/ rv32i_verilator_tb__DOT__dut__DOT__funct7_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__reg_write_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_src_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_write_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__branch_ex;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__jump_ex;
    CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_op_ex;
    CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT__rd_mem;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__reg_write_mem;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_write_mem;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_mem;
    CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT__rd_wb;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__reg_write_wb;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_wb;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__reg_write_id;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_src_id;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_write_id;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__mem_to_reg_id;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__branch_id;
    CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT__jump_id;
    CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_op_id;
    CData/*3:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_control_ex;
    CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT__forward_a;
    CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT__forward_b;
    IData/*31:0*/ rv32i_verilator_tb__DOT__instr_if;
    IData/*31:0*/ rv32i_verilator_tb__DOT__pc_if;
    IData/*31:0*/ rv32i_verilator_tb__DOT__cycle_count;
    IData/*31:0*/ rv32i_verilator_tb__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__pc_id;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__instr_id;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__pc_ex;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs1_data_ex;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs2_data_ex;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__imm_ex;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_result_mem;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs2_data_mem;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_result_wb;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs1_data_raw;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rs2_data_raw;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__imm_id;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_result_ex_int;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__operand_a_fwd;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__operand_b_fwd;
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__i;
    IData/*31:0*/ rv32i_verilator_tb__DOT__imem[256];
    CData/*3:0*/ rv32i_verilator_tb__DOT__alu_op_cov[16];
    CData/*1:0*/ rv32i_verilator_tb__DOT__fwd_a_cov[4];
    CData/*1:0*/ rv32i_verilator_tb__DOT__fwd_b_cov[4];
    CData/*4:0*/ rv32i_verilator_tb__DOT__rd_wb_cov[32];
    IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__rf_inst__DOT__registers[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__clk;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__rst_n;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__reg_write_ex_cov;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__reg_write_mem_cov;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__reg_write_wb_cov;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__mem_write_ex_cov;
        CData/*0:0*/ rv32i_verilator_tb__DOT____Vtogcov__branch_ex_cov;
        CData/*1:0*/ rv32i_verilator_tb__DOT____Vtogcov__state;
        CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_ex;
        CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_ex;
        CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_ex;
        CData/*2:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct3_ex;
        CData/*6:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__funct7_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_ex;
        CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_ex;
        CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_mem;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_mem;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_mem;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_mem;
        CData/*4:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rd_wb;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_wb;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_wb;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__reg_write_id;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_src_id;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_write_id;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__mem_to_reg_id;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__branch_id;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__jump_id;
        CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_op_id;
        CData/*3:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_control_ex;
        CData/*0:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__zero_flag_ex;
        CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_a;
        CData/*1:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__forward_b;
        CData/*1:0*/ __Vdly__rv32i_verilator_tb__DOT__state;
        CData/*0:0*/ __VinpClk__TOP__rv32i_verilator_tb__DOT__clk;
        CData/*0:0*/ __VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__clk;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__rv32i_verilator_tb__DOT__rst_n;
        CData/*0:0*/ __Vchglast__TOP__rv32i_verilator_tb__DOT__clk;
        CData/*0:0*/ __Vchglast__TOP__rv32i_verilator_tb__DOT__rst_n;
        IData/*31:0*/ rv32i_verilator_tb__DOT____Vtogcov__instr_if;
        IData/*31:0*/ rv32i_verilator_tb__DOT____Vtogcov__pc_if;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vcellinp__alu_inst__operand_b;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_id;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__instr_id;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__pc_ex;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_ex;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_ex;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_ex;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_mem;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_mem;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_wb;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs1_data_raw;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__rs2_data_raw;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__imm_id;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__alu_result_ex_int;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_a_fwd;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT____Vtogcov__operand_b_fwd;
        IData/*31:0*/ rv32i_verilator_tb__DOT__dut__DOT__alu_inst__DOT____Vtogcov__operand_b;
    };
    struct {
        IData/*31:0*/ __Vdly__rv32i_verilator_tb__DOT__cycle_count;
        CData/*3:0*/ rv32i_verilator_tb__DOT____Vtogcov__alu_op_cov[16];
        CData/*1:0*/ rv32i_verilator_tb__DOT____Vtogcov__fwd_a_cov[4];
        CData/*1:0*/ rv32i_verilator_tb__DOT____Vtogcov__fwd_b_cov[4];
        CData/*4:0*/ rv32i_verilator_tb__DOT____Vtogcov__rd_wb_cov[32];
        CData/*0:0*/ __Vm_traceActivity[4];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vrv32i_verilator_tb__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vrv32i_verilator_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vrv32i_verilator_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vrv32i_verilator_tb();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vrv32i_verilator_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(Vrv32i_verilator_tb__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vrv32i_verilator_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__6(Vrv32i_verilator_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
