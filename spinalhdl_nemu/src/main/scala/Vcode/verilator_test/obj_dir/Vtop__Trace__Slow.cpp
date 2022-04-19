// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+6,"clk", false,-1);
        tracep->declBus(c+7,"Inst", false,-1, 31,0);
        tracep->declBus(c+8,"opcode", false,-1, 6,0);
        tracep->declBus(c+9,"rd", false,-1, 4,0);
        tracep->declBus(c+10,"fun", false,-1, 2,0);
        tracep->declBus(c+11,"rs1", false,-1, 4,0);
        tracep->declBus(c+12,"Imm", false,-1, 11,0);
        tracep->declBit(c+13,"rst", false,-1);
        tracep->declBit(c+6,"top clk", false,-1);
        tracep->declBus(c+7,"top Inst", false,-1, 31,0);
        tracep->declBus(c+8,"top opcode", false,-1, 6,0);
        tracep->declBus(c+9,"top rd", false,-1, 4,0);
        tracep->declBus(c+10,"top fun", false,-1, 2,0);
        tracep->declBus(c+11,"top rs1", false,-1, 4,0);
        tracep->declBus(c+12,"top Imm", false,-1, 11,0);
        tracep->declBit(c+13,"top rst", false,-1);
        tracep->declBus(c+1,"top opcode_reg", false,-1, 6,0);
        tracep->declBus(c+2,"top rd_reg", false,-1, 4,0);
        tracep->declBus(c+3,"top fun_reg", false,-1, 2,0);
        tracep->declBus(c+4,"top rs1_reg", false,-1, 4,0);
        tracep->declBus(c+5,"top Imm_reg", false,-1, 11,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->top__DOT__opcode_reg),7);
        tracep->fullCData(oldp+2,(vlTOPp->top__DOT__rd_reg),5);
        tracep->fullCData(oldp+3,(vlTOPp->top__DOT__fun_reg),3);
        tracep->fullCData(oldp+4,(vlTOPp->top__DOT__rs1_reg),5);
        tracep->fullSData(oldp+5,(vlTOPp->top__DOT__Imm_reg),12);
        tracep->fullBit(oldp+6,(vlTOPp->clk));
        tracep->fullIData(oldp+7,(vlTOPp->Inst),32);
        tracep->fullCData(oldp+8,(vlTOPp->opcode),7);
        tracep->fullCData(oldp+9,(vlTOPp->rd),5);
        tracep->fullCData(oldp+10,(vlTOPp->fun),3);
        tracep->fullCData(oldp+11,(vlTOPp->rs1),5);
        tracep->fullSData(oldp+12,(vlTOPp->Imm),12);
        tracep->fullBit(oldp+13,(vlTOPp->rst));
    }
}
