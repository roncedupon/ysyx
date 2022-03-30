// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vour__Syms.h"


void Vour::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vour__Syms* __restrict vlSymsp = static_cast<Vour__Syms*>(userp);
    Vour* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
