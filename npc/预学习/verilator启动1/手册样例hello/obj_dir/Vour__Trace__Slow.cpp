// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vour__Syms.h"


//======================

void Vour::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vour::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vour__Syms* __restrict vlSymsp = static_cast<Vour__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vour::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vour::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vour__Syms* __restrict vlSymsp = static_cast<Vour__Syms*>(userp);
    Vour* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vour::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vour__Syms* __restrict vlSymsp = static_cast<Vour__Syms*>(userp);
    Vour* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
}

void Vour::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}
