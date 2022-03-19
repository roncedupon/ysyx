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
            VL_FATAL_MT("/home/ubuntu/Desktop/ysyx1/ysyx-workbench/npc/\351\242\204\345\255\246\344\271\240/\346\225\260\345\255\227\347\224\265\350\267\257\345\237\272\347\241\200\345\256\236\351\252\214/\345\256\236\351\252\214\344\272\214_\347\274\226\347\240\201\345\231\2501/vsrc/top.v", 1, "",
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
            VL_FATAL_MT("/home/ubuntu/Desktop/ysyx1/ysyx-workbench/npc/\351\242\204\345\255\246\344\271\240/\346\225\260\345\255\227\347\224\265\350\267\257\345\237\272\347\241\200\345\256\236\351\252\214/\345\256\236\351\252\214\344\272\214_\347\274\226\347\240\201\345\231\2501/vsrc/top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->en_led = vlTOPp->en;
    if (vlTOPp->en) {
        vlTOPp->out = (((((((((0x80U == (0x80U & (IData)(vlTOPp->in))) 
                              | (0x40U == (0xc0U & (IData)(vlTOPp->in)))) 
                             | (0x20U == (0xe0U & (IData)(vlTOPp->in)))) 
                            | (0x10U == (0xf0U & (IData)(vlTOPp->in)))) 
                           | (8U == (0xf8U & (IData)(vlTOPp->in)))) 
                          | (4U == (0xfcU & (IData)(vlTOPp->in)))) 
                         | (2U == (0xfeU & (IData)(vlTOPp->in)))) 
                        | (1U == (IData)(vlTOPp->in)))
                        ? ((0x80U == (0x80U & (IData)(vlTOPp->in)))
                            ? 7U : ((0x40U == (0xc0U 
                                               & (IData)(vlTOPp->in)))
                                     ? 6U : ((0x20U 
                                              == (0xe0U 
                                                  & (IData)(vlTOPp->in)))
                                              ? 5U : 
                                             ((0x10U 
                                               == (0xf0U 
                                                   & (IData)(vlTOPp->in)))
                                               ? 4U
                                               : ((8U 
                                                   == 
                                                   (0xf8U 
                                                    & (IData)(vlTOPp->in)))
                                                   ? 3U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (0xfcU 
                                                     & (IData)(vlTOPp->in)))
                                                    ? 2U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (0xfeU 
                                                      & (IData)(vlTOPp->in)))
                                                     ? 1U
                                                     : 0U)))))))
                        : 0U);
        vlTOPp->SEG = ((4U & (IData)(vlTOPp->out)) ? 
                       ((2U & (IData)(vlTOPp->out))
                         ? ((1U & (IData)(vlTOPp->out))
                             ? 0x78U : 2U) : ((1U & (IData)(vlTOPp->out))
                                               ? 0xaU
                                               : 0xdU))
                        : ((2U & (IData)(vlTOPp->out))
                            ? ((1U & (IData)(vlTOPp->out))
                                ? 0x30U : 0x24U) : 
                           ((1U & (IData)(vlTOPp->out))
                             ? 0x79U : 0x78U)));
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
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
    if (VL_UNLIKELY((en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
