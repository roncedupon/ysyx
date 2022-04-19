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
            tracep->chgQData(oldp+0,(vlTOPp->top__DOT__register_file__DOT___zz_mem_port1),64);
            tracep->chgCData(oldp+2,(vlTOPp->top__DOT__rd_EXU),5);
            tracep->chgQData(oldp+3,(vlTOPp->top__DOT__result),64);
            tracep->chgQData(oldp+5,(vlTOPp->top__DOT__register_file__DOT__mem[0]),64);
            tracep->chgQData(oldp+7,(vlTOPp->top__DOT__register_file__DOT__mem[1]),64);
            tracep->chgQData(oldp+9,(vlTOPp->top__DOT__register_file__DOT__mem[2]),64);
            tracep->chgQData(oldp+11,(vlTOPp->top__DOT__register_file__DOT__mem[3]),64);
            tracep->chgQData(oldp+13,(vlTOPp->top__DOT__register_file__DOT__mem[4]),64);
            tracep->chgQData(oldp+15,(vlTOPp->top__DOT__register_file__DOT__mem[5]),64);
            tracep->chgQData(oldp+17,(vlTOPp->top__DOT__register_file__DOT__mem[6]),64);
            tracep->chgQData(oldp+19,(vlTOPp->top__DOT__register_file__DOT__mem[7]),64);
            tracep->chgQData(oldp+21,(vlTOPp->top__DOT__register_file__DOT__mem[8]),64);
            tracep->chgQData(oldp+23,(vlTOPp->top__DOT__register_file__DOT__mem[9]),64);
            tracep->chgQData(oldp+25,(vlTOPp->top__DOT__register_file__DOT__mem[10]),64);
            tracep->chgQData(oldp+27,(vlTOPp->top__DOT__register_file__DOT__mem[11]),64);
            tracep->chgQData(oldp+29,(vlTOPp->top__DOT__register_file__DOT__mem[12]),64);
            tracep->chgQData(oldp+31,(vlTOPp->top__DOT__register_file__DOT__mem[13]),64);
            tracep->chgQData(oldp+33,(vlTOPp->top__DOT__register_file__DOT__mem[14]),64);
            tracep->chgQData(oldp+35,(vlTOPp->top__DOT__register_file__DOT__mem[15]),64);
            tracep->chgQData(oldp+37,(vlTOPp->top__DOT__register_file__DOT__mem[16]),64);
            tracep->chgQData(oldp+39,(vlTOPp->top__DOT__register_file__DOT__mem[17]),64);
            tracep->chgQData(oldp+41,(vlTOPp->top__DOT__register_file__DOT__mem[18]),64);
            tracep->chgQData(oldp+43,(vlTOPp->top__DOT__register_file__DOT__mem[19]),64);
            tracep->chgQData(oldp+45,(vlTOPp->top__DOT__register_file__DOT__mem[20]),64);
            tracep->chgQData(oldp+47,(vlTOPp->top__DOT__register_file__DOT__mem[21]),64);
            tracep->chgQData(oldp+49,(vlTOPp->top__DOT__register_file__DOT__mem[22]),64);
            tracep->chgQData(oldp+51,(vlTOPp->top__DOT__register_file__DOT__mem[23]),64);
            tracep->chgQData(oldp+53,(vlTOPp->top__DOT__register_file__DOT__mem[24]),64);
            tracep->chgQData(oldp+55,(vlTOPp->top__DOT__register_file__DOT__mem[25]),64);
            tracep->chgQData(oldp+57,(vlTOPp->top__DOT__register_file__DOT__mem[26]),64);
            tracep->chgQData(oldp+59,(vlTOPp->top__DOT__register_file__DOT__mem[27]),64);
            tracep->chgQData(oldp+61,(vlTOPp->top__DOT__register_file__DOT__mem[28]),64);
            tracep->chgQData(oldp+63,(vlTOPp->top__DOT__register_file__DOT__mem[29]),64);
            tracep->chgQData(oldp+65,(vlTOPp->top__DOT__register_file__DOT__mem[30]),64);
            tracep->chgQData(oldp+67,(vlTOPp->top__DOT__register_file__DOT__mem[31]),64);
        }
        tracep->chgBit(oldp+69,(vlTOPp->clk));
        tracep->chgBit(oldp+70,(vlTOPp->rst));
        tracep->chgIData(oldp+71,(vlTOPp->Inst),32);
        tracep->chgBit(oldp+72,(vlTOPp->en));
        tracep->chgIData(oldp+73,(vlTOPp->pc_addr),32);
        tracep->chgCData(oldp+74,((0x1fU & (vlTOPp->Inst 
                                            >> 0xfU))),5);
        tracep->chgQData(oldp+75,((QData)((IData)((
                                                   (0xfffff000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->Inst 
                                                                      >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & (vlTOPp->Inst 
                                                         >> 0x14U)))))),64);
        tracep->chgCData(oldp+77,((0x1fU & (vlTOPp->Inst 
                                            >> 7U))),5);
        tracep->chgCData(oldp+78,((0x7fU & vlTOPp->Inst)),7);
        tracep->chgCData(oldp+79,((7U & (vlTOPp->Inst 
                                         >> 0xcU))),3);
        tracep->chgCData(oldp+80,((1U & (vlTOPp->Inst 
                                         >> 0x1eU))),3);
        tracep->chgCData(oldp+81,((0x1fU & (vlTOPp->Inst 
                                            >> 0x14U))),5);
        tracep->chgIData(oldp+82,(((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Inst 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | (0xfffU & (vlTOPp->Inst 
                                                >> 0x14U)))),32);
        tracep->chgIData(oldp+83,((0xfffff000U & vlTOPp->Inst)),32);
        tracep->chgIData(oldp+84,(((0xfff00000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Inst 
                                                                  >> 0x1fU)))) 
                                                   << 0x14U)) 
                                   | ((0xff000U & vlTOPp->Inst) 
                                      | ((0x800U & 
                                          (vlTOPp->Inst 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->Inst 
                                               >> 0x14U)))))),32);
        tracep->chgIData(oldp+85,(((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Inst 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | ((0x800U & (vlTOPp->Inst 
                                                 << 4U)) 
                                      | ((0x7e0U & 
                                          (vlTOPp->Inst 
                                           >> 0x14U)) 
                                         | (0x1eU & 
                                            (vlTOPp->Inst 
                                             >> 7U)))))),32);
        tracep->chgIData(oldp+86,(((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Inst 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | ((0xfe0U & (vlTOPp->Inst 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->Inst 
                                                  >> 7U))))),32);
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
