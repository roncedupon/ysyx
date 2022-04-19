// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__opcode_reg),7);
            tracep->chgCData(oldp+1,(vlTOPp->top__DOT__rd_reg),5);
            tracep->chgCData(oldp+2,(vlTOPp->top__DOT__fun_reg),3);
            tracep->chgCData(oldp+3,(vlTOPp->top__DOT__rs1_reg),5);
            tracep->chgSData(oldp+4,(vlTOPp->top__DOT__Imm_reg),12);
        }
        tracep->chgBit(oldp+5,(vlTOPp->clk));
        tracep->chgIData(oldp+6,(vlTOPp->Inst),32);
        tracep->chgCData(oldp+7,(vlTOPp->opcode),7);
        tracep->chgCData(oldp+8,(vlTOPp->rd),5);
        tracep->chgCData(oldp+9,(vlTOPp->fun),3);
        tracep->chgCData(oldp+10,(vlTOPp->rs1),5);
        tracep->chgSData(oldp+11,(vlTOPp->Imm),12);
        tracep->chgBit(oldp+12,(vlTOPp->rst));
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
