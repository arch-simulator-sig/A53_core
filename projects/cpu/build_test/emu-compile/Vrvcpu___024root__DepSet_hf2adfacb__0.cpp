// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrvcpu.h for the primary calling header

#include "verilated.h"

#include "Vrvcpu___024root.h"

VL_INLINE_OPT void Vrvcpu___024root___ico_sequent__TOP__0(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi = 
        (1U & (IData)(((0x10U == (0x1cU & vlSelf->inst)) 
                       & (~ (IData)((0U != (0x7060U 
                                            & vlSelf->inst)))))));
    vlSelf->inst_ena = (1U & (~ (IData)(vlSelf->rst)));
    vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0 
        = ((IData)(vlSelf->inst_ena) & (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi));
    vlSelf->rvcpu__DOT__inst_type = ((0xfU & (IData)(vlSelf->rvcpu__DOT__inst_type)) 
                                     | (((IData)(vlSelf->inst_ena) 
                                         & (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi)) 
                                        << 4U));
    vlSelf->rvcpu__DOT__rs1_r_ena = ((IData)(vlSelf->inst_ena) 
                                     & ((IData)(vlSelf->rvcpu__DOT__inst_type) 
                                        >> 4U));
    if (vlSelf->rst) {
        vlSelf->rvcpu__DOT__rd_w_addr = 0U;
        vlSelf->rvcpu__DOT__rd_data = 0ULL;
    } else {
        vlSelf->rvcpu__DOT__rd_w_addr = ((0x10U & (IData)(vlSelf->rvcpu__DOT__inst_type))
                                          ? (0x1fU 
                                             & (vlSelf->inst 
                                                >> 7U))
                                          : 0U);
        vlSelf->rvcpu__DOT__rd_data = ((0x11U == (((IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0) 
                                                   << 4U) 
                                                  | (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0)))
                                        ? (((IData)(vlSelf->rst)
                                             ? 0ULL
                                             : ((0x10U 
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
                                               ? 0ULL
                                               : ((0x10U 
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
                                        : 0ULL);
    }
}

void Vrvcpu___024root___eval_ico(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vrvcpu___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vrvcpu___024root___eval_act(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vrvcpu___024root___nba_sequent__TOP__0(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v0;
    __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__rvcpu__DOT__Regfile__DOT__regs__v32;
    __Vdlyvdim0__rvcpu__DOT__Regfile__DOT__regs__v32 = 0;
    QData/*63:0*/ __Vdlyvval__rvcpu__DOT__Regfile__DOT__regs__v32;
    __Vdlyvval__rvcpu__DOT__Regfile__DOT__regs__v32 = 0;
    CData/*0:0*/ __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v32;
    __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v32 = 0;
    // Body
    __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->rvcpu__DOT__If_stage__DOT__pc = 0ULL;
        __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v0 = 1U;
    } else {
        vlSelf->rvcpu__DOT__If_stage__DOT__pc = (4ULL 
                                                 + vlSelf->rvcpu__DOT__If_stage__DOT__pc);
        if (((IData)(vlSelf->rvcpu__DOT__rs1_r_ena) 
             & (0U != (IData)(vlSelf->rvcpu__DOT__rd_w_addr)))) {
            __Vdlyvval__rvcpu__DOT__Regfile__DOT__regs__v32 
                = vlSelf->rvcpu__DOT__rd_data;
            __Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v32 = 1U;
            __Vdlyvdim0__rvcpu__DOT__Regfile__DOT__regs__v32 
                = vlSelf->rvcpu__DOT__rd_w_addr;
        }
    }
    if (__Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v0) {
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[1U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[2U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[3U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[4U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[5U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[6U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[7U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[8U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[9U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xaU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xbU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xcU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xdU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xeU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0xfU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x10U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x11U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x12U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x13U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x14U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x15U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x16U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x17U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x18U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x19U] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1aU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1bU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1cU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1dU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1eU] = 0ULL;
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__rvcpu__DOT__Regfile__DOT__regs__v32) {
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[__Vdlyvdim0__rvcpu__DOT__Regfile__DOT__regs__v32] 
            = __Vdlyvval__rvcpu__DOT__Regfile__DOT__regs__v32;
    }
    vlSelf->inst_addr = vlSelf->rvcpu__DOT__If_stage__DOT__pc;
}

VL_INLINE_OPT void Vrvcpu___024root___nba_sequent__TOP__1(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->rvcpu__DOT__rd_data = ((IData)(vlSelf->rst)
                                    ? 0ULL : ((0x11U 
                                               == (
                                                   ((IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0) 
                                                    << 4U) 
                                                   | (IData)(vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0)))
                                               ? (((IData)(vlSelf->rst)
                                                    ? 0ULL
                                                    : 
                                                   ((0x10U 
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
                                                  + 
                                                  ((IData)(vlSelf->rst)
                                                    ? 0ULL
                                                    : 
                                                   ((0x10U 
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
                                               : 0ULL));
}

void Vrvcpu___024root___eval_nba(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vrvcpu___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vrvcpu___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vrvcpu___024root___eval_triggers__ico(Vrvcpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__ico(Vrvcpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vrvcpu___024root___eval_triggers__act(Vrvcpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__act(Vrvcpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__nba(Vrvcpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vrvcpu___024root___eval(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vrvcpu___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vrvcpu___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/rvcpu.v", 9, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vrvcpu___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vrvcpu___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vrvcpu___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/rvcpu.v", 9, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vrvcpu___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vrvcpu___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/rvcpu.v", 9, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vrvcpu___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vrvcpu___024root___eval_debug_assertions(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
