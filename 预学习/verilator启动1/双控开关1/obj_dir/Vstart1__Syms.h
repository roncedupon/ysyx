// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSTART1__SYMS_H_
#define VERILATED_VSTART1__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vstart1.h"

// SYMS CLASS
class Vstart1__Syms : public VerilatedSyms {
  public:

    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;

    // SUBCELL STATE
    Vstart1*                       TOPp;

    // CREATORS
    Vstart1__Syms(VerilatedContext* contextp, Vstart1* topp, const char* namep);
    ~Vstart1__Syms();

    // METHODS
    inline const char* name() { return __Vm_namep; }

} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
