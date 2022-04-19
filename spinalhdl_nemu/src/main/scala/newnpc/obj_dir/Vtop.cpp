// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("top.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v4;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v5;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v6;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v7;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v8;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v9;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v10;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v11;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v12;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v13;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v14;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v15;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v16;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v17;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v18;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v19;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v20;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v21;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v22;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v23;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v24;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v25;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v26;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v27;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v28;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v29;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v30;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v31;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__register_file__DOT__mem__v32;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__mem__v32;
    QData/*63:0*/ __Vdlyvval__top__DOT__register_file__DOT__mem__v32;
    // Body
    __Vdlyvset__top__DOT__register_file__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v2 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v3 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v4 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v5 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v6 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v7 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v8 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v9 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v10 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v11 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v12 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v13 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v14 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v15 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v16 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v17 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v18 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v19 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v20 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v21 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v22 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v23 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v24 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v25 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v26 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v27 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v28 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v29 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v30 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v31 = 0U;
    __Vdlyvset__top__DOT__register_file__DOT__mem__v32 = 0U;
    vlTOPp->en = (1U & (~ (IData)(vlTOPp->rst)));
    vlTOPp->pc_addr = ((IData)(vlTOPp->rst) ? 0x80000000U
                        : ((IData)(1U) + vlTOPp->pc_addr));
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v0 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v1 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v2 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v3 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v4 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v5 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v6 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v7 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v8 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v9 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v10 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v11 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v12 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v13 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v14 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v15 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v16 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v17 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v18 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v19 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v20 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v21 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v22 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v23 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v24 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v25 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v26 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v27 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v28 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v29 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v30 = 1U;
    }
    if (vlTOPp->rst) {
        __Vdlyvset__top__DOT__register_file__DOT__mem__v31 = 1U;
    }
    if ((1U & (~ (IData)(vlTOPp->rst)))) {
        __Vdlyvval__top__DOT__register_file__DOT__mem__v32 
            = vlTOPp->top__DOT__result;
        __Vdlyvset__top__DOT__register_file__DOT__mem__v32 = 1U;
        __Vdlyvdim0__top__DOT__register_file__DOT__mem__v32 
            = vlTOPp->top__DOT__rd_EXU;
    }
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__rd_EXU = 0U;
        vlTOPp->top__DOT__result = 0ULL;
        vlTOPp->top__DOT__register_file__DOT___zz_mem_port1 = 0ULL;
    } else {
        vlTOPp->top__DOT__rd_EXU = (0x1fU & (vlTOPp->Inst 
                                             >> 7U));
        vlTOPp->top__DOT__result = ((QData)((IData)(
                                                    ((0xfffff000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlTOPp->Inst 
                                                                        >> 0x1fU)))) 
                                                         << 0xcU)) 
                                                     | (0xfffU 
                                                        & (vlTOPp->Inst 
                                                           >> 0x14U))))) 
                                    + vlTOPp->top__DOT__register_file__DOT___zz_mem_port1);
        vlTOPp->top__DOT__register_file__DOT___zz_mem_port1 
            = vlTOPp->top__DOT__register_file__DOT__mem
            [(0x1fU & (vlTOPp->Inst >> 0xfU))];
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v0) {
        vlTOPp->top__DOT__register_file__DOT__mem[0U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v1) {
        vlTOPp->top__DOT__register_file__DOT__mem[1U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v2) {
        vlTOPp->top__DOT__register_file__DOT__mem[2U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v3) {
        vlTOPp->top__DOT__register_file__DOT__mem[3U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v4) {
        vlTOPp->top__DOT__register_file__DOT__mem[4U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v5) {
        vlTOPp->top__DOT__register_file__DOT__mem[5U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v6) {
        vlTOPp->top__DOT__register_file__DOT__mem[6U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v7) {
        vlTOPp->top__DOT__register_file__DOT__mem[7U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v8) {
        vlTOPp->top__DOT__register_file__DOT__mem[8U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v9) {
        vlTOPp->top__DOT__register_file__DOT__mem[9U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v10) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xaU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v11) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xbU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v12) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xcU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v13) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xdU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v14) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xeU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v15) {
        vlTOPp->top__DOT__register_file__DOT__mem[0xfU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v16) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x10U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v17) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x11U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v18) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x12U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v19) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x13U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v20) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x14U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v21) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x15U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v22) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x16U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v23) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x17U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v24) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x18U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v25) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x19U] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v26) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1aU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v27) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1bU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v28) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1cU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v29) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1dU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v30) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1eU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v31) {
        vlTOPp->top__DOT__register_file__DOT__mem[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__top__DOT__register_file__DOT__mem__v32) {
        vlTOPp->top__DOT__register_file__DOT__mem[__Vdlyvdim0__top__DOT__register_file__DOT__mem__v32] 
            = __Vdlyvval__top__DOT__register_file__DOT__mem__v32;
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
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
