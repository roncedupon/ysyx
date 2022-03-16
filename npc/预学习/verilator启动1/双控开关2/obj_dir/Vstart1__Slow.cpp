// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstart1.h for the primary calling header

#include "Vstart1.h"
#include "Vstart1__Syms.h"

//==========

Vstart1::Vstart1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vstart1__Syms* __restrict vlSymsp = __VlSymsp = new Vstart1__Syms(_vcontextp__, this, name());
    Vstart1* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vstart1::__Vconfigure(Vstart1__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vstart1::~Vstart1() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vstart1::_eval_initial(Vstart1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstart1::_eval_initial\n"); );
    Vstart1* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstart1::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstart1::final\n"); );
    // Variables
    Vstart1__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstart1* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstart1::_eval_settle(Vstart1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstart1::_eval_settle\n"); );
    Vstart1* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vstart1::_ctor_var_reset(Vstart1* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstart1::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->a = VL_RAND_RESET_I(1);
    self->b = VL_RAND_RESET_I(1);
    self->f = VL_RAND_RESET_I(1);
}
