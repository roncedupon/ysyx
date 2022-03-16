// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vstart1__Syms.h"
#include "Vstart1.h"



// FUNCTIONS
Vstart1__Syms::~Vstart1__Syms()
{
}

Vstart1__Syms::Vstart1__Syms(VerilatedContext* contextp, Vstart1* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
