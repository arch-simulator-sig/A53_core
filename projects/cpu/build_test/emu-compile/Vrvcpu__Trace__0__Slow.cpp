// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrvcpu__Syms.h"


VL_ATTR_COLD void Vrvcpu___024root__trace_init_sub__TOP__0(Vrvcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declQuad(c+75,"inst_addr", false,-1, 63,0);
    tracep->declBit(c+77,"inst_ena", false,-1);
    tracep->pushNamePrefix("rvcpu ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declQuad(c+75,"inst_addr", false,-1, 63,0);
    tracep->declBit(c+77,"inst_ena", false,-1);
    tracep->declBit(c+1,"rs1_r_ena", false,-1);
    tracep->declBus(c+78,"rs1_r_addr", false,-1, 4,0);
    tracep->declBit(c+92,"rs2_r_ena", false,-1);
    tracep->declBus(c+93,"rs2_r_addr", false,-1, 4,0);
    tracep->declBit(c+1,"rd_w_ena", false,-1);
    tracep->declBus(c+2,"rd_w_addr", false,-1, 4,0);
    tracep->declBus(c+3,"inst_type", false,-1, 4,0);
    tracep->declBus(c+4,"inst_opcode", false,-1, 7,0);
    tracep->declQuad(c+79,"op1", false,-1, 63,0);
    tracep->declQuad(c+81,"op2", false,-1, 63,0);
    tracep->declQuad(c+83,"r_data1", false,-1, 63,0);
    tracep->declQuad(c+94,"r_data2", false,-1, 63,0);
    tracep->declBus(c+3,"inst_type_o", false,-1, 4,0);
    tracep->declQuad(c+85,"rd_data", false,-1, 63,0);
    tracep->pushNamePrefix("Exe_stage ");
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+3,"inst_type_i", false,-1, 4,0);
    tracep->declBus(c+4,"inst_opcode", false,-1, 7,0);
    tracep->declQuad(c+79,"op1", false,-1, 63,0);
    tracep->declQuad(c+81,"op2", false,-1, 63,0);
    tracep->declBus(c+3,"inst_type_o", false,-1, 4,0);
    tracep->declQuad(c+85,"rd_data", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Id_stage ");
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declQuad(c+83,"rs1_data", false,-1, 63,0);
    tracep->declQuad(c+94,"rs2_data", false,-1, 63,0);
    tracep->declBit(c+1,"rs1_r_ena", false,-1);
    tracep->declBus(c+78,"rs1_r_addr", false,-1, 4,0);
    tracep->declBit(c+92,"rs2_r_ena", false,-1);
    tracep->declBus(c+93,"rs2_r_addr", false,-1, 4,0);
    tracep->declBit(c+1,"rd_w_ena", false,-1);
    tracep->declBus(c+2,"rd_w_addr", false,-1, 4,0);
    tracep->declBus(c+3,"inst_type", false,-1, 4,0);
    tracep->declBus(c+4,"inst_opcode", false,-1, 7,0);
    tracep->declQuad(c+79,"op1", false,-1, 63,0);
    tracep->declQuad(c+81,"op2", false,-1, 63,0);
    tracep->declBus(c+87,"opcode", false,-1, 6,0);
    tracep->declBus(c+88,"rd", false,-1, 4,0);
    tracep->declBus(c+89,"func3", false,-1, 2,0);
    tracep->declBus(c+90,"rs1", false,-1, 4,0);
    tracep->declBus(c+91,"imm", false,-1, 11,0);
    tracep->declBit(c+5,"inst_addi", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("If_stage ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declQuad(c+75,"inst_addr", false,-1, 63,0);
    tracep->declBit(c+77,"inst_ena", false,-1);
    tracep->declQuad(c+6,"pc", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Regfile ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+2,"w_addr", false,-1, 4,0);
    tracep->declQuad(c+85,"w_data", false,-1, 63,0);
    tracep->declBit(c+1,"w_ena", false,-1);
    tracep->declBus(c+78,"r_addr1", false,-1, 4,0);
    tracep->declQuad(c+83,"r_data1", false,-1, 63,0);
    tracep->declBit(c+1,"r_ena1", false,-1);
    tracep->declBus(c+93,"r_addr2", false,-1, 4,0);
    tracep->declQuad(c+94,"r_data2", false,-1, 63,0);
    tracep->declBit(c+92,"r_ena2", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declQuad(c+8+i*2,"regs", true,(i+0), 63,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vrvcpu___024root__trace_init_top(Vrvcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_init_top\n"); );
    // Body
    Vrvcpu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vrvcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vrvcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vrvcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vrvcpu___024root__trace_register(Vrvcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vrvcpu___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vrvcpu___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vrvcpu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vrvcpu___024root__trace_full_sub_0(Vrvcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vrvcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_full_top_0\n"); );
    // Init
    Vrvcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrvcpu___024root*>(voidSelf);
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vrvcpu___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vrvcpu___024root__trace_full_sub_0(Vrvcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->rvcpu__DOT__rs1_r_ena));
    bufp->fullCData(oldp+2,(vlSelf->rvcpu__DOT__rd_w_addr),5);
    bufp->fullCData(oldp+3,(vlSelf->rvcpu__DOT__inst_type),5);
    bufp->fullCData(oldp+4,((((IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0) 
                              << 4U) | (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0))),8);
    bufp->fullBit(oldp+5,(vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi));
    bufp->fullQData(oldp+6,(vlSelf->rvcpu__DOT__If_stage__DOT__pc),64);
    bufp->fullQData(oldp+8,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[0]),64);
    bufp->fullQData(oldp+10,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[1]),64);
    bufp->fullQData(oldp+12,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[2]),64);
    bufp->fullQData(oldp+14,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[3]),64);
    bufp->fullQData(oldp+16,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[4]),64);
    bufp->fullQData(oldp+18,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[5]),64);
    bufp->fullQData(oldp+20,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[6]),64);
    bufp->fullQData(oldp+22,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[7]),64);
    bufp->fullQData(oldp+24,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[8]),64);
    bufp->fullQData(oldp+26,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[9]),64);
    bufp->fullQData(oldp+28,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[10]),64);
    bufp->fullQData(oldp+30,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[11]),64);
    bufp->fullQData(oldp+32,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[12]),64);
    bufp->fullQData(oldp+34,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[13]),64);
    bufp->fullQData(oldp+36,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[14]),64);
    bufp->fullQData(oldp+38,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[15]),64);
    bufp->fullQData(oldp+40,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[16]),64);
    bufp->fullQData(oldp+42,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[17]),64);
    bufp->fullQData(oldp+44,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[18]),64);
    bufp->fullQData(oldp+46,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[19]),64);
    bufp->fullQData(oldp+48,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[20]),64);
    bufp->fullQData(oldp+50,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[21]),64);
    bufp->fullQData(oldp+52,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[22]),64);
    bufp->fullQData(oldp+54,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[23]),64);
    bufp->fullQData(oldp+56,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[24]),64);
    bufp->fullQData(oldp+58,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[25]),64);
    bufp->fullQData(oldp+60,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[26]),64);
    bufp->fullQData(oldp+62,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[27]),64);
    bufp->fullQData(oldp+64,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[28]),64);
    bufp->fullQData(oldp+66,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[29]),64);
    bufp->fullQData(oldp+68,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[30]),64);
    bufp->fullQData(oldp+70,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[31]),64);
    bufp->fullBit(oldp+72,(vlSelf->clk));
    bufp->fullBit(oldp+73,(vlSelf->rst));
    bufp->fullIData(oldp+74,(vlSelf->inst),32);
    bufp->fullQData(oldp+75,(vlSelf->inst_addr),64);
    bufp->fullBit(oldp+77,(vlSelf->inst_ena));
    bufp->fullCData(oldp+78,(((IData)(vlSelf->rst) ? 0U
                               : ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                   ? (0x1fU & (vlSelf->inst 
                                               >> 0xfU))
                                   : 0U))),5);
    bufp->fullQData(oldp+79,(((IData)(vlSelf->rst) ? 0ULL
                               : ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                   ? ((IData)(vlSelf->rst)
                                       ? 0ULL : ((IData)(vlSelf->rvcpu__DOT__rs1_r_ena)
                                                  ? 
                                                 vlSelf->rvcpu__DOT__Regfile__DOT__regs
                                                 [((IData)(vlSelf->rst)
                                                    ? 0U
                                                    : 
                                                   ((0x10U 
                                                     & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                                     ? 
                                                    (0x1fU 
                                                     & (vlSelf->inst 
                                                        >> 0xfU))
                                                     : 0U))]
                                                  : 0ULL))
                                   : 0ULL))),64);
    bufp->fullQData(oldp+81,(((IData)(vlSelf->rst) ? 0ULL
                               : ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                   ? (((- (QData)((IData)(
                                                          (vlSelf->inst 
                                                           >> 0x1fU)))) 
                                       << 0xcU) | (QData)((IData)(
                                                                  (vlSelf->inst 
                                                                   >> 0x14U))))
                                   : 0ULL))),64);
    bufp->fullQData(oldp+83,(((IData)(vlSelf->rst) ? 0ULL
                               : ((IData)(vlSelf->rvcpu__DOT__rs1_r_ena)
                                   ? vlSelf->rvcpu__DOT__Regfile__DOT__regs
                                  [((IData)(vlSelf->rst)
                                     ? 0U : ((0x10U 
                                              & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                              ? (0x1fU 
                                                 & (vlSelf->inst 
                                                    >> 0xfU))
                                              : 0U))]
                                   : 0ULL))),64);
    bufp->fullQData(oldp+85,(((IData)(vlSelf->rst) ? 0ULL
                               : ((0x11U == (((IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0) 
                                              << 4U) 
                                             | (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0)))
                                   ? (((IData)(vlSelf->rst)
                                        ? 0ULL : ((0x10U 
                                                   & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                                   ? 
                                                  ((IData)(vlSelf->rst)
                                                    ? 0ULL
                                                    : 
                                                   ((IData)(vlSelf->rvcpu__DOT__rs1_r_ena)
                                                     ? 
                                                    vlSelf->rvcpu__DOT__Regfile__DOT__regs
                                                    [
                                                    ((IData)(vlSelf->rst)
                                                      ? 0U
                                                      : 
                                                     ((0x10U 
                                                       & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                                       ? 
                                                      (0x1fU 
                                                       & (vlSelf->inst 
                                                          >> 0xfU))
                                                       : 0U))]
                                                     : 0ULL))
                                                   : 0ULL)) 
                                      + ((IData)(vlSelf->rst)
                                          ? 0ULL : 
                                         ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                           ? (((- (QData)((IData)(
                                                                  (vlSelf->inst 
                                                                   >> 0x1fU)))) 
                                               << 0xcU) 
                                              | (QData)((IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x14U))))
                                           : 0ULL)))
                                   : 0ULL))),64);
    bufp->fullCData(oldp+87,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+88,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+89,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+90,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullSData(oldp+91,((vlSelf->inst >> 0x14U)),12);
    bufp->fullBit(oldp+92,(0U));
    bufp->fullCData(oldp+93,(0U),5);
    bufp->fullQData(oldp+94,(0ULL),64);
}
