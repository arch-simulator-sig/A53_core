// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrvcpu.h for the primary calling header

#include "verilated.h"

#include "Vrvcpu___024root.h"

VL_ATTR_COLD void Vrvcpu___024root___eval_static(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vrvcpu___024root___eval_initial(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vrvcpu___024root___eval_final(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vrvcpu___024root___eval_triggers__stl(Vrvcpu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__stl(Vrvcpu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___eval_stl(Vrvcpu___024root* vlSelf);

VL_ATTR_COLD void Vrvcpu___024root___eval_settle(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vrvcpu___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vrvcpu___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/rvcpu.v", 9, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vrvcpu___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__stl(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrvcpu___024root___stl_sequent__TOP__0(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->inst_addr = vlSelf->rvcpu__DOT__If_stage__DOT__pc;
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

VL_ATTR_COLD void Vrvcpu___024root___eval_stl(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vrvcpu___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__ico(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__act(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__nba(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrvcpu___024root___ctor_var_reset(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->inst_addr = VL_RAND_RESET_Q(64);
    vlSelf->inst_ena = VL_RAND_RESET_I(1);
    vlSelf->rvcpu__DOT__rs1_r_ena = VL_RAND_RESET_I(1);
    vlSelf->rvcpu__DOT__rd_w_addr = VL_RAND_RESET_I(5);
    vlSelf->rvcpu__DOT__inst_type = VL_RAND_RESET_I(5);
    vlSelf->rvcpu__DOT__rd_data = VL_RAND_RESET_Q(64);
    vlSelf->rvcpu__DOT__If_stage__DOT__pc = VL_RAND_RESET_Q(64);
    vlSelf->rvcpu__DOT__Id_stage__DOT__inst_addi = VL_RAND_RESET_I(1);
    vlSelf->rvcpu__DOT__Id_stage__DOT____VdfgTmp_h73314af3__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->rvcpu__DOT__Regfile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
