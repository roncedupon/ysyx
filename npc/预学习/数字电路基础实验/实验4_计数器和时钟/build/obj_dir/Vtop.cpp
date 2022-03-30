// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ubuntu/Desktop/ysyx1/ysyx-daiyao/npc/\351\242\204\345\255\246\344\271\240/\346\225\260\345\255\227\347\224\265\350\267\257\345\237\272\347\241\200\345\256\236\351\252\214/\345\256\236\351\252\2144_\350\256\241\346\225\260\345\231\250\345\222\214\346\227\266\351\222\237/vsrc/top.v", 6, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("/home/ubuntu/Desktop/ysyx1/ysyx-daiyao/npc/\351\242\204\345\255\246\344\271\240/\346\225\260\345\255\227\347\224\265\350\267\257\345\237\272\347\241\200\345\256\236\351\252\214/\345\256\236\351\252\2144_\350\256\241\346\225\260\345\231\250\345\222\214\346\227\266\351\222\237/vsrc/top.v", 6, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vtableidx1;
    CData/*4:0*/ __Vtableidx2;
    CData/*3:0*/ __Vdly__top__DOT__counter_seg;
    IData/*31:0*/ __Vdly__top__DOT__counter;
    // Body
    __Vdly__top__DOT__counter = vlTOPp->top__DOT__counter;
    __Vdly__top__DOT__counter_seg = vlTOPp->top__DOT__counter_seg;
    __Vdly__top__DOT__counter = ((IData)(vlTOPp->rst)
                                  ? 0U : ((0x989680U 
                                           > vlTOPp->top__DOT__counter)
                                           ? ((IData)(1U) 
                                              + vlTOPp->top__DOT__counter)
                                           : 0U));
    __Vtableidx2 = (((IData)(vlTOPp->top__DOT__counter_seg) 
                     << 1U) | (IData)(vlTOPp->rst));
    vlTOPp->SEG_low = vlTOPp->__Vtable2_SEG_low[__Vtableidx2];
    if (vlTOPp->rst) {
        vlTOPp->SEG_high = 0U;
    }
    __Vtableidx1 = (((IData)(vlTOPp->top__DOT__counter_seg_high) 
                     << 1U) | (IData)(vlTOPp->rst));
    vlTOPp->SEG_high = vlTOPp->__Vtable1_SEG_high[__Vtableidx1];
    if (vlTOPp->rst) {
        vlTOPp->out_q = 0U;
        vlTOPp->top__DOT__counter_seg_high = 0U;
    } else {
        vlTOPp->out_q = (0xffU & ((IData)(vlTOPp->top__DOT__en)
                                   ? ((IData)(1U) + (IData)(vlTOPp->out_q))
                                   : ((0x62U == ((IData)(1U) 
                                                 + (IData)(vlTOPp->out_q)))
                                       ? 0U : (IData)(vlTOPp->out_q))));
        vlTOPp->top__DOT__counter_seg_high = (0xfU 
                                              & (((IData)(vlTOPp->top__DOT__en_seg_low) 
                                                  & (9U 
                                                     != 
                                                     ((IData)(1U) 
                                                      + (IData)(vlTOPp->top__DOT__counter_seg_high))))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__counter_seg_high))
                                                  : 
                                                 ((9U 
                                                   == 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->top__DOT__counter_seg_high)))
                                                   ? 0U
                                                   : (IData)(vlTOPp->top__DOT__counter_seg_high))));
    }
    if (vlTOPp->rst) {
        __Vdly__top__DOT__counter_seg = 0U;
        vlTOPp->top__DOT__en_seg_low = 0U;
    } else if (((IData)(vlTOPp->top__DOT__en) & (9U 
                                                 != 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__counter_seg))))) {
        __Vdly__top__DOT__counter_seg = (0xfU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->top__DOT__counter_seg)));
    } else if ((9U == ((IData)(1U) + (IData)(vlTOPp->top__DOT__counter_seg)))) {
        vlTOPp->top__DOT__en_seg_low = 1U;
        __Vdly__top__DOT__counter_seg = 0U;
    } else {
        __Vdly__top__DOT__counter_seg = vlTOPp->top__DOT__counter_seg;
        vlTOPp->top__DOT__en_seg_low = 0U;
    }
    vlTOPp->top__DOT__counter_seg = __Vdly__top__DOT__counter_seg;
    vlTOPp->top__DOT__en = ((~ (IData)(vlTOPp->rst)) 
                            & (0x989680U == ((IData)(1U) 
                                             + vlTOPp->top__DOT__counter)));
    vlTOPp->top__DOT__counter = __Vdly__top__DOT__counter;
    vlTOPp->en_o = vlTOPp->top__DOT__en;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
