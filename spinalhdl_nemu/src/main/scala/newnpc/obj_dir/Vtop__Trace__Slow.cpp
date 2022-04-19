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
        tracep->declBit(c+70,"clk", false,-1);
        tracep->declBit(c+71,"rst", false,-1);
        tracep->declBus(c+72,"Inst", false,-1, 31,0);
        tracep->declBit(c+73,"en", false,-1);
        tracep->declBus(c+74,"pc_addr", false,-1, 31,0);
        tracep->declBit(c+70,"top clk", false,-1);
        tracep->declBit(c+71,"top rst", false,-1);
        tracep->declBus(c+72,"top Inst", false,-1, 31,0);
        tracep->declBit(c+73,"top en", false,-1);
        tracep->declBus(c+74,"top pc_addr", false,-1, 31,0);
        tracep->declBus(c+75,"top rs1", false,-1, 4,0);
        tracep->declQuad(c+1,"top src1_i", false,-1, 63,0);
        tracep->declQuad(c+1,"top src1_o", false,-1, 63,0);
        tracep->declQuad(c+76,"top Imm", false,-1, 63,0);
        tracep->declBus(c+78,"top rd_IDU", false,-1, 4,0);
        tracep->declBus(c+3,"top rd_EXU", false,-1, 4,0);
        tracep->declQuad(c+4,"top result", false,-1, 63,0);
        tracep->declBit(c+70,"top pc_reg clk", false,-1);
        tracep->declBit(c+71,"top pc_reg rst", false,-1);
        tracep->declBus(c+74,"top pc_reg pc", false,-1, 31,0);
        tracep->declBit(c+73,"top pc_reg en", false,-1);
        tracep->declBus(c+72,"top IDU Inst", false,-1, 31,0);
        tracep->declBus(c+79,"top IDU opcode", false,-1, 6,0);
        tracep->declBus(c+78,"top IDU rd", false,-1, 4,0);
        tracep->declBus(c+80,"top IDU func3", false,-1, 2,0);
        tracep->declBus(c+81,"top IDU func7", false,-1, 2,0);
        tracep->declBus(c+75,"top IDU rs1", false,-1, 4,0);
        tracep->declBus(c+82,"top IDU rs2", false,-1, 4,0);
        tracep->declQuad(c+76,"top IDU Imm", false,-1, 63,0);
        tracep->declQuad(c+1,"top IDU src1_i", false,-1, 63,0);
        tracep->declQuad(c+1,"top IDU src1_o", false,-1, 63,0);
        tracep->declBit(c+88,"top IDU I_type", false,-1);
        tracep->declBit(c+89,"top IDU U_type", false,-1);
        tracep->declBit(c+89,"top IDU J_type", false,-1);
        tracep->declBit(c+89,"top IDU B_type", false,-1);
        tracep->declBit(c+89,"top IDU S_type", false,-1);
        tracep->declBus(c+83,"top IDU I_imme", false,-1, 31,0);
        tracep->declBus(c+84,"top IDU U_imme", false,-1, 31,0);
        tracep->declBus(c+85,"top IDU J_imme", false,-1, 31,0);
        tracep->declBus(c+86,"top IDU B_imme", false,-1, 31,0);
        tracep->declBus(c+87,"top IDU S_imme", false,-1, 31,0);
        tracep->declBit(c+70,"top EXU clk", false,-1);
        tracep->declBit(c+71,"top EXU rst", false,-1);
        tracep->declBus(c+78,"top EXU rd_i", false,-1, 4,0);
        tracep->declQuad(c+1,"top EXU src1", false,-1, 63,0);
        tracep->declQuad(c+76,"top EXU Imm", false,-1, 63,0);
        tracep->declBus(c+3,"top EXU rd_o", false,-1, 4,0);
        tracep->declQuad(c+4,"top EXU result", false,-1, 63,0);
        tracep->declBit(c+88,"top register_file writeValid", false,-1);
        tracep->declBus(c+3,"top register_file writeAddress", false,-1, 4,0);
        tracep->declQuad(c+4,"top register_file writeData", false,-1, 63,0);
        tracep->declBit(c+88,"top register_file readValid_1", false,-1);
        tracep->declBus(c+75,"top register_file readAddress_1", false,-1, 4,0);
        tracep->declQuad(c+1,"top register_file readData_1", false,-1, 63,0);
        tracep->declBit(c+70,"top register_file clk", false,-1);
        tracep->declBit(c+71,"top register_file rst", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+6+i*2,"top register_file mem", true,(i+0), 63,0);}}
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
        tracep->fullQData(oldp+1,(vlTOPp->top__DOT__register_file__DOT___zz_mem_port1),64);
        tracep->fullCData(oldp+3,(vlTOPp->top__DOT__rd_EXU),5);
        tracep->fullQData(oldp+4,(vlTOPp->top__DOT__result),64);
        tracep->fullQData(oldp+6,(vlTOPp->top__DOT__register_file__DOT__mem[0]),64);
        tracep->fullQData(oldp+8,(vlTOPp->top__DOT__register_file__DOT__mem[1]),64);
        tracep->fullQData(oldp+10,(vlTOPp->top__DOT__register_file__DOT__mem[2]),64);
        tracep->fullQData(oldp+12,(vlTOPp->top__DOT__register_file__DOT__mem[3]),64);
        tracep->fullQData(oldp+14,(vlTOPp->top__DOT__register_file__DOT__mem[4]),64);
        tracep->fullQData(oldp+16,(vlTOPp->top__DOT__register_file__DOT__mem[5]),64);
        tracep->fullQData(oldp+18,(vlTOPp->top__DOT__register_file__DOT__mem[6]),64);
        tracep->fullQData(oldp+20,(vlTOPp->top__DOT__register_file__DOT__mem[7]),64);
        tracep->fullQData(oldp+22,(vlTOPp->top__DOT__register_file__DOT__mem[8]),64);
        tracep->fullQData(oldp+24,(vlTOPp->top__DOT__register_file__DOT__mem[9]),64);
        tracep->fullQData(oldp+26,(vlTOPp->top__DOT__register_file__DOT__mem[10]),64);
        tracep->fullQData(oldp+28,(vlTOPp->top__DOT__register_file__DOT__mem[11]),64);
        tracep->fullQData(oldp+30,(vlTOPp->top__DOT__register_file__DOT__mem[12]),64);
        tracep->fullQData(oldp+32,(vlTOPp->top__DOT__register_file__DOT__mem[13]),64);
        tracep->fullQData(oldp+34,(vlTOPp->top__DOT__register_file__DOT__mem[14]),64);
        tracep->fullQData(oldp+36,(vlTOPp->top__DOT__register_file__DOT__mem[15]),64);
        tracep->fullQData(oldp+38,(vlTOPp->top__DOT__register_file__DOT__mem[16]),64);
        tracep->fullQData(oldp+40,(vlTOPp->top__DOT__register_file__DOT__mem[17]),64);
        tracep->fullQData(oldp+42,(vlTOPp->top__DOT__register_file__DOT__mem[18]),64);
        tracep->fullQData(oldp+44,(vlTOPp->top__DOT__register_file__DOT__mem[19]),64);
        tracep->fullQData(oldp+46,(vlTOPp->top__DOT__register_file__DOT__mem[20]),64);
        tracep->fullQData(oldp+48,(vlTOPp->top__DOT__register_file__DOT__mem[21]),64);
        tracep->fullQData(oldp+50,(vlTOPp->top__DOT__register_file__DOT__mem[22]),64);
        tracep->fullQData(oldp+52,(vlTOPp->top__DOT__register_file__DOT__mem[23]),64);
        tracep->fullQData(oldp+54,(vlTOPp->top__DOT__register_file__DOT__mem[24]),64);
        tracep->fullQData(oldp+56,(vlTOPp->top__DOT__register_file__DOT__mem[25]),64);
        tracep->fullQData(oldp+58,(vlTOPp->top__DOT__register_file__DOT__mem[26]),64);
        tracep->fullQData(oldp+60,(vlTOPp->top__DOT__register_file__DOT__mem[27]),64);
        tracep->fullQData(oldp+62,(vlTOPp->top__DOT__register_file__DOT__mem[28]),64);
        tracep->fullQData(oldp+64,(vlTOPp->top__DOT__register_file__DOT__mem[29]),64);
        tracep->fullQData(oldp+66,(vlTOPp->top__DOT__register_file__DOT__mem[30]),64);
        tracep->fullQData(oldp+68,(vlTOPp->top__DOT__register_file__DOT__mem[31]),64);
        tracep->fullBit(oldp+70,(vlTOPp->clk));
        tracep->fullBit(oldp+71,(vlTOPp->rst));
        tracep->fullIData(oldp+72,(vlTOPp->Inst),32);
        tracep->fullBit(oldp+73,(vlTOPp->en));
        tracep->fullIData(oldp+74,(vlTOPp->pc_addr),32);
        tracep->fullCData(oldp+75,((0x1fU & (vlTOPp->Inst 
                                             >> 0xfU))),5);
        tracep->fullQData(oldp+76,((QData)((IData)(
                                                   ((0xfffff000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->Inst 
                                                                       >> 0x1fU)))) 
                                                        << 0xcU)) 
                                                    | (0xfffU 
                                                       & (vlTOPp->Inst 
                                                          >> 0x14U)))))),64);
        tracep->fullCData(oldp+78,((0x1fU & (vlTOPp->Inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+79,((0x7fU & vlTOPp->Inst)),7);
        tracep->fullCData(oldp+80,((7U & (vlTOPp->Inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+81,((1U & (vlTOPp->Inst 
                                          >> 0x1eU))),3);
        tracep->fullCData(oldp+82,((0x1fU & (vlTOPp->Inst 
                                             >> 0x14U))),5);
        tracep->fullIData(oldp+83,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->Inst 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (0xfffU 
                                                   & (vlTOPp->Inst 
                                                      >> 0x14U)))),32);
        tracep->fullIData(oldp+84,((0xfffff000U & vlTOPp->Inst)),32);
        tracep->fullIData(oldp+85,(((0xfff00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->Inst 
                                                     >> 0x1fU)))) 
                                      << 0x14U)) | 
                                    ((0xff000U & vlTOPp->Inst) 
                                     | ((0x800U & (vlTOPp->Inst 
                                                   >> 9U)) 
                                        | (0x7feU & 
                                           (vlTOPp->Inst 
                                            >> 0x14U)))))),32);
        tracep->fullIData(oldp+86,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->Inst 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0x800U 
                                                    & (vlTOPp->Inst 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlTOPp->Inst 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlTOPp->Inst 
                                                            >> 7U)))))),32);
        tracep->fullIData(oldp+87,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->Inst 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->Inst 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->Inst 
                                                         >> 7U))))),32);
        tracep->fullBit(oldp+88,(1U));
        tracep->fullBit(oldp+89,(0U));
    }
}
