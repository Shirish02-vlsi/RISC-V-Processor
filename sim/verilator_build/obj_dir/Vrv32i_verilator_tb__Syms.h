// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VRV32I_VERILATOR_TB__SYMS_H_
#define _VRV32I_VERILATOR_TB__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vrv32i_verilator_tb.h"

// SYMS CLASS
class Vrv32i_verilator_tb__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vrv32i_verilator_tb*           TOPp;
    
    // COVERAGE
    uint32_t __Vcoverage[981];
    
    // CREATORS
    Vrv32i_verilator_tb__Syms(Vrv32i_verilator_tb* topp, const char* namep);
    ~Vrv32i_verilator_tb__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
