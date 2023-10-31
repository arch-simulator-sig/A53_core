// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrvcpu__Syms.h"


void Vrvcpu___024root__trace_chg_sub_0(Vrvcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vrvcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_chg_top_0\n"); );
    // Init
    Vrvcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrvcpu___024root*>(voidSelf);
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vrvcpu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vrvcpu___024root__trace_chg_sub_0(Vrvcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->rvcpu__DOT__rs1_r_ena));
        bufp->chgCData(oldp+1,(vlSelf->rvcpu__DOT__rd_w_addr),5);
        bufp->chgCData(oldp+2,(vlSelf->rvcpu__DOT__inst_type),5);
        bufp->chgCData(oldp+3,((((IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0) 
                                 << 4U) | (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0))),8);
        bufp->chgBit(oldp+4,(vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgQData(oldp+5,(vlSelf->rvcpu__DOT__If_stage__DOT__pc),64);
        bufp->chgQData(oldp+7,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[0]),64);
        bufp->chgQData(oldp+9,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[1]),64);
        bufp->chgQData(oldp+11,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[2]),64);
        bufp->chgQData(oldp+13,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[3]),64);
        bufp->chgQData(oldp+15,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[4]),64);
        bufp->chgQData(oldp+17,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[5]),64);
        bufp->chgQData(oldp+19,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[6]),64);
        bufp->chgQData(oldp+21,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[7]),64);
        bufp->chgQData(oldp+23,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[8]),64);
        bufp->chgQData(oldp+25,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[9]),64);
        bufp->chgQData(oldp+27,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[10]),64);
        bufp->chgQData(oldp+29,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[11]),64);
        bufp->chgQData(oldp+31,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[12]),64);
        bufp->chgQData(oldp+33,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[13]),64);
        bufp->chgQData(oldp+35,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[14]),64);
        bufp->chgQData(oldp+37,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[15]),64);
        bufp->chgQData(oldp+39,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[16]),64);
        bufp->chgQData(oldp+41,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[17]),64);
        bufp->chgQData(oldp+43,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[18]),64);
        bufp->chgQData(oldp+45,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[19]),64);
        bufp->chgQData(oldp+47,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[20]),64);
        bufp->chgQData(oldp+49,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[21]),64);
        bufp->chgQData(oldp+51,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[22]),64);
        bufp->chgQData(oldp+53,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[23]),64);
        bufp->chgQData(oldp+55,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[24]),64);
        bufp->chgQData(oldp+57,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[25]),64);
        bufp->chgQData(oldp+59,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[26]),64);
        bufp->chgQData(oldp+61,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[27]),64);
        bufp->chgQData(oldp+63,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[28]),64);
        bufp->chgQData(oldp+65,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[29]),64);
        bufp->chgQData(oldp+67,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[30]),64);
        bufp->chgQData(oldp+69,(vlSelf->rvcpu__DOT__Regfile__DOT__regs[31]),64);
    }
    bufp->chgBit(oldp+71,(vlSelf->clk));
    bufp->chgBit(oldp+72,(vlSelf->rst));
    bufp->chgIData(oldp+73,(vlSelf->inst),32);
    bufp->chgQData(oldp+74,(vlSelf->inst_addr),64);
    bufp->chgBit(oldp+76,(vlSelf->inst_ena));
    bufp->chgCData(oldp+77,(((IData)(vlSelf->rst) ? 0U
                              : ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                  ? (0x1fU & (vlSelf->inst 
                                              >> 0xfU))
                                  : 0U))),5);
    bufp->chgQData(oldp+78,(((IData)(vlSelf->rst) ? 0ULL
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
    bufp->chgQData(oldp+80,(((IData)(vlSelf->rst) ? 0ULL
                              : ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                  ? (((- (QData)((IData)(
                                                         (vlSelf->inst 
                                                          >> 0x1fU)))) 
                                      << 0xcU) | (QData)((IData)(
                                                                 (vlSelf->inst 
                                                                  >> 0x14U))))
                                  : 0ULL))),64);
    bufp->chgQData(oldp+82,(((IData)(vlSelf->rst) ? 0ULL
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
    bufp->chgQData(oldp+84,(((IData)(vlSelf->rst) ? 0ULL
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
                                         ? 0ULL : (
                                                   (0x10U 
                                                    & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (vlSelf->inst 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      (vlSelf->inst 
                                                                       >> 0x14U))))
                                                    : 0ULL)))
                                  : 0ULL))),64);
    bufp->chgCData(oldp+86,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+87,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+88,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+89,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgSData(oldp+90,((vlSelf->inst >> 0x14U)),12);
}

void Vrvcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root__trace_cleanup\n"); );
    // Init
    Vrvcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrvcpu___024root*>(voidSelf);
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
