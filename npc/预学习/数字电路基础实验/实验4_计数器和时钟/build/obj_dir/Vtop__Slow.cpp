// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
VlUnpacked<CData/*6:0*/, 32> Vtop::__Vtable1_SEG_high;
VlUnpacked<CData/*6:0*/, 32> Vtop::__Vtable2_SEG_low;

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->en_o = vlTOPp->top__DOT__en;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop::_ctor_var_reset(Vtop* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clk = 0;
    self->en_o = 0;
    self->rst = 0;
    self->out_q = 0;
    self->SEG_low = 0;
    self->SEG_high = 0;
    self->top__DOT__en = 0;
    self->top__DOT__counter = 0;
    self->top__DOT__counter_seg = 0;
    self->top__DOT__en_seg_low = 0;
    self->top__DOT__counter_seg_high = 0;
    self->__Vtable1_SEG_high[0] = 0x40U;
    self->__Vtable1_SEG_high[1] = 0U;
    self->__Vtable1_SEG_high[2] = 0x79U;
    self->__Vtable1_SEG_high[3] = 0U;
    self->__Vtable1_SEG_high[4] = 0x24U;
    self->__Vtable1_SEG_high[5] = 0U;
    self->__Vtable1_SEG_high[6] = 0x19U;
    self->__Vtable1_SEG_high[7] = 0U;
    self->__Vtable1_SEG_high[8] = 0xaU;
    self->__Vtable1_SEG_high[9] = 0U;
    self->__Vtable1_SEG_high[10] = 0x12U;
    self->__Vtable1_SEG_high[11] = 0U;
    self->__Vtable1_SEG_high[12] = 2U;
    self->__Vtable1_SEG_high[13] = 0U;
    self->__Vtable1_SEG_high[14] = 0x78U;
    self->__Vtable1_SEG_high[15] = 0U;
    self->__Vtable1_SEG_high[16] = 0U;
    self->__Vtable1_SEG_high[17] = 0U;
    self->__Vtable1_SEG_high[18] = 0x10U;
    self->__Vtable1_SEG_high[19] = 0U;
    self->__Vtable1_SEG_high[20] = 0x40U;
    self->__Vtable1_SEG_high[21] = 0U;
    self->__Vtable1_SEG_high[22] = 0x40U;
    self->__Vtable1_SEG_high[23] = 0U;
    self->__Vtable1_SEG_high[24] = 0x40U;
    self->__Vtable1_SEG_high[25] = 0U;
    self->__Vtable1_SEG_high[26] = 0x40U;
    self->__Vtable1_SEG_high[27] = 0U;
    self->__Vtable1_SEG_high[28] = 0x40U;
    self->__Vtable1_SEG_high[29] = 0U;
    self->__Vtable1_SEG_high[30] = 0x40U;
    self->__Vtable1_SEG_high[31] = 0U;
    self->__Vtable2_SEG_low[0] = 0x40U;
    self->__Vtable2_SEG_low[1] = 0U;
    self->__Vtable2_SEG_low[2] = 0x79U;
    self->__Vtable2_SEG_low[3] = 0U;
    self->__Vtable2_SEG_low[4] = 0x24U;
    self->__Vtable2_SEG_low[5] = 0U;
    self->__Vtable2_SEG_low[6] = 0x30U;
    self->__Vtable2_SEG_low[7] = 0U;
    self->__Vtable2_SEG_low[8] = 0x19U;
    self->__Vtable2_SEG_low[9] = 0U;
    self->__Vtable2_SEG_low[10] = 0x12U;
    self->__Vtable2_SEG_low[11] = 0U;
    self->__Vtable2_SEG_low[12] = 2U;
    self->__Vtable2_SEG_low[13] = 0U;
    self->__Vtable2_SEG_low[14] = 0x78U;
    self->__Vtable2_SEG_low[15] = 0U;
    self->__Vtable2_SEG_low[16] = 0U;
    self->__Vtable2_SEG_low[17] = 0U;
    self->__Vtable2_SEG_low[18] = 0x10U;
    self->__Vtable2_SEG_low[19] = 0U;
    self->__Vtable2_SEG_low[20] = 0x40U;
    self->__Vtable2_SEG_low[21] = 0U;
    self->__Vtable2_SEG_low[22] = 0x40U;
    self->__Vtable2_SEG_low[23] = 0U;
    self->__Vtable2_SEG_low[24] = 0x40U;
    self->__Vtable2_SEG_low[25] = 0U;
    self->__Vtable2_SEG_low[26] = 0x40U;
    self->__Vtable2_SEG_low[27] = 0U;
    self->__Vtable2_SEG_low[28] = 0x40U;
    self->__Vtable2_SEG_low[29] = 0U;
    self->__Vtable2_SEG_low[30] = 0x40U;
    self->__Vtable2_SEG_low[31] = 0U;
}
