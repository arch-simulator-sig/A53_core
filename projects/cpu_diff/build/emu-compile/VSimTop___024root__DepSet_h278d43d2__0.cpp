// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VSimTop__Syms.h"
#include "VSimTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__ico(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG

void VSimTop___024root___eval_triggers__ico(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSimTop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSimTop___024root___dump_triggers__act(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG

void VSimTop___024root___eval_triggers__act(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((~ (IData)(vlSelf->clock)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__clock));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSimTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VSimTop___024unit____Vdpiimwrap_v_difftest_CSRState_TOP____024unit(CData/*7:0*/ coreid, CData/*7:0*/ priviledgeMode, QData/*63:0*/ mstatus, QData/*63:0*/ sstatus, QData/*63:0*/ mepc, QData/*63:0*/ sepc, QData/*63:0*/ mtval, QData/*63:0*/ stval, QData/*63:0*/ mtvec, QData/*63:0*/ stvec, QData/*63:0*/ mcause, QData/*63:0*/ scause, QData/*63:0*/ satp, QData/*63:0*/ mip, QData/*63:0*/ mie, QData/*63:0*/ mscratch, QData/*63:0*/ sscratch, QData/*63:0*/ mideleg, QData/*63:0*/ medeleg);
void VSimTop___024unit____Vdpiimwrap_v_difftest_ArchIntRegState_TOP____024unit(CData/*7:0*/ coreid, QData/*63:0*/ gpr_0, QData/*63:0*/ gpr_1, QData/*63:0*/ gpr_2, QData/*63:0*/ gpr_3, QData/*63:0*/ gpr_4, QData/*63:0*/ gpr_5, QData/*63:0*/ gpr_6, QData/*63:0*/ gpr_7, QData/*63:0*/ gpr_8, QData/*63:0*/ gpr_9, QData/*63:0*/ gpr_10, QData/*63:0*/ gpr_11, QData/*63:0*/ gpr_12, QData/*63:0*/ gpr_13, QData/*63:0*/ gpr_14, QData/*63:0*/ gpr_15, QData/*63:0*/ gpr_16, QData/*63:0*/ gpr_17, QData/*63:0*/ gpr_18, QData/*63:0*/ gpr_19, QData/*63:0*/ gpr_20, QData/*63:0*/ gpr_21, QData/*63:0*/ gpr_22, QData/*63:0*/ gpr_23, QData/*63:0*/ gpr_24, QData/*63:0*/ gpr_25, QData/*63:0*/ gpr_26, QData/*63:0*/ gpr_27, QData/*63:0*/ gpr_28, QData/*63:0*/ gpr_29, QData/*63:0*/ gpr_30, QData/*63:0*/ gpr_31);
void VSimTop___024unit____Vdpiimwrap_ram_write_helper_TOP____024unit(QData/*63:0*/ wIdx, QData/*63:0*/ wdata, QData/*63:0*/ wmask, CData/*0:0*/ wen);
void VSimTop___024unit____Vdpiimwrap_v_difftest_TrapEvent_TOP____024unit(CData/*7:0*/ coreid, CData/*0:0*/ valid, CData/*7:0*/ code, QData/*63:0*/ pc, QData/*63:0*/ cycleCnt, QData/*63:0*/ instrCnt);
void VSimTop___024unit____Vdpiimwrap_v_difftest_InstrCommit_TOP____024unit(CData/*7:0*/ coreid, CData/*7:0*/ index, CData/*0:0*/ valid, QData/*63:0*/ pc, IData/*31:0*/ instr, CData/*7:0*/ special, CData/*0:0*/ skip, CData/*0:0*/ isRVC, CData/*0:0*/ scFailed, CData/*0:0*/ wen, CData/*7:0*/ wdest, QData/*63:0*/ wdata);
extern const VlUnpacked<CData/*7:0*/, 8> VSimTop__ConstPool__TABLE_h4b04e8c6_0;
void VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(CData/*0:0*/ en, QData/*63:0*/ rIdx, QData/*63:0*/ &ram_read_helper__Vfuncrtn);
extern const VlUnpacked<SData/*15:0*/, 16> VSimTop__ConstPool__TABLE_h7a2fd741_0;

VL_INLINE_OPT void VSimTop___024root___nba_sequent__TOP__0(VSimTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSimTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag;
    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag = 0;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v0;
    __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32;
    __Vdlyvdim0__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 = 0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32;
    __Vdlyvval__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 = 0;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32;
    __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 = 0;
    CData/*0:0*/ __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag;
    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag = 0;
    VlWide<6>/*191:0*/ __Vtemp_h36855522__0;
    VlWide<4>/*127:0*/ __Vtemp_he5b5d80c__0;
    VlWide<5>/*159:0*/ __Vtemp_hae92d67e__0;
    VlWide<11>/*351:0*/ __Vtemp_ha13240e2__0;
    VlWide<11>/*351:0*/ __Vtemp_h38b71ee5__0;
    VlWide<3>/*95:0*/ __Vtemp_h9befc343__0;
    VlWide<3>/*95:0*/ __Vtemp_ha4db1ee1__0;
    VlWide<3>/*95:0*/ __Vtemp_hae3cbe47__0;
    VlWide<3>/*95:0*/ __Vtemp_h54852520__0;
    VlWide<3>/*95:0*/ __Vtemp_h93336fe5__0;
    VlWide<5>/*159:0*/ __Vtemp_h4d85910c__0;
    // Body
    VSimTop___024unit____Vdpiimwrap_v_difftest_CSRState_TOP____024unit(0U, 3U, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    VSimTop___024unit____Vdpiimwrap_v_difftest_ArchIntRegState_TOP____024unit(0U, 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [1U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [2U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [3U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [4U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [5U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [6U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [7U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [8U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [9U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xaU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xbU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xcU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xdU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xeU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0xfU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x10U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x11U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x12U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x13U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x14U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x15U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x16U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x17U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x18U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x19U], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1aU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1bU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1cU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1dU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1eU], 
                                                                              vlSelf->SimTop__DOT__regs_diff
                                                                              [0x1fU]);
    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag;
    VSimTop___024unit____Vdpiimwrap_ram_write_helper_TOP____024unit(
                                                                    ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc 
                                                                      - 0x80000000ULL) 
                                                                     >> 3U), 0ULL, 0ULL, 0U);
    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag;
    VSimTop___024unit____Vdpiimwrap_ram_write_helper_TOP____024unit(
                                                                    ((vlSelf->SimTop__DOT__data_sram_addr 
                                                                      - 0x80000000ULL) 
                                                                     >> 3U), 
                                                                    ((0x200U 
                                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                      ? 
                                                                     (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                       << 0x38U) 
                                                                      | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                          << 0x30U) 
                                                                         | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                             << 0x28U) 
                                                                            | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                                << 0x20U) 
                                                                               | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                                << 0x18U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                                << 0x10U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                                << 8U) 
                                                                                | (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))))))))))
                                                                      : 
                                                                     ((0x400U 
                                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                       ? 
                                                                      (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                        << 0x30U) 
                                                                       | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                           << 0x20U) 
                                                                          | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))) 
                                                                              << 0x10U) 
                                                                             | (QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))))))
                                                                       : 
                                                                      ((0x800U 
                                                                        & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                        ? 
                                                                       (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)) 
                                                                         << 0x20U) 
                                                                        | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2)))
                                                                        : 
                                                                       ((0x1000U 
                                                                         & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                         ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2
                                                                         : 0ULL)))), (QData)((IData)(
                                                                                (0xffU 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                                >> 0xdU)))) 
                                                                                & ((0x200U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                 ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel)
                                                                                 : 
                                                                                ((0x400U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                 ? 
                                                                                ((0xc0U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 6U)))) 
                                                                                << 6U)) 
                                                                                | ((0x30U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 4U)))) 
                                                                                << 4U)) 
                                                                                | ((0xcU 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 2U)))) 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))))
                                                                                 : 
                                                                                ((0x800U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                 ? 
                                                                                ((0xf0U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 4U)))) 
                                                                                << 4U)) 
                                                                                | (0xfU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))
                                                                                 : 
                                                                                ((0x1000U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                 ? 
                                                                                (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))
                                                                                 : 0U)))))))), 
                                                                    ((0U 
                                                                      != 
                                                                      (0xffU 
                                                                       & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                                >> 0xdU)))) 
                                                                          & ((0x200U 
                                                                              & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                              ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel)
                                                                              : 
                                                                             ((0x400U 
                                                                               & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                               ? 
                                                                              ((0xc0U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 6U)))) 
                                                                                << 6U)) 
                                                                               | ((0x30U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 4U)))) 
                                                                                << 4U)) 
                                                                                | ((0xcU 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 2U)))) 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))))
                                                                               : 
                                                                              ((0x800U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                ? 
                                                                               ((0xf0U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                                >> 4U)))) 
                                                                                << 4U)) 
                                                                                | (0xfU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))
                                                                                : 
                                                                               ((0x1000U 
                                                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                                                 ? 
                                                                                (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))
                                                                                 : 0U))))))) 
                                                                     & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                        >> 0xeU)));
    VSimTop___024unit____Vdpiimwrap_v_difftest_TrapEvent_TOP____024unit(0U, (IData)(vlSelf->SimTop__DOT__trap), 
                                                                        (7U 
                                                                         & (IData)(vlSelf->SimTop__DOT__trap_code)), vlSelf->SimTop__DOT__cmt_pc, vlSelf->SimTop__DOT__cycleCnt, vlSelf->SimTop__DOT__instrCnt);
    __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v0 = 0U;
    __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 = 0U;
    if (vlSelf->SimTop__DOT__cmt_valid) {
        VSimTop___024unit____Vdpiimwrap_v_difftest_InstrCommit_TOP____024unit(0U, 0U, (IData)(vlSelf->SimTop__DOT__cmt_valid), vlSelf->SimTop__DOT__cmt_pc, vlSelf->SimTop__DOT__cmt_inst, 0U, 0U, 0U, 0U, (IData)(vlSelf->SimTop__DOT__cmt_wen), vlSelf->SimTop__DOT__cmt_wdest, vlSelf->SimTop__DOT__cmt_wdata);
    }
    if (vlSelf->reset) {
        __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v0 = 1U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r = 0ULL;
        __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag 
            = __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r = 0ULL;
        __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag 
            = __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[1U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[2U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[6U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[7U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[8U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[9U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xaU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xbU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xcU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xdU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xeU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xfU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x10U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x11U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x12U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xbU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xcU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xdU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xeU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xfU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x10U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x11U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x12U] = 0U;
    } else {
        if ((0x20U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])) {
            __Vdlyvval__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 
                = (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                    << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])));
            __Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 = 1U;
            __Vdlyvdim0__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32 
                = (0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]);
        }
        if ((8U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))) {
            if ((1U & (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag)))) {
                if ((IData)((0x18U == (0x18U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
                    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r 
                        = vlSelf->SimTop__DOT__data_sram_rdata;
                    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag = 1U;
                }
            }
        } else {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r 
                = vlSelf->SimTop__DOT__data_sram_rdata;
            __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag = 0U;
        }
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag 
            = __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag;
        if ((1U & (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall)))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid = 1U;
        }
        if ((2U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))) {
            if ((1U & (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag)))) {
                if ((IData)((6U == (6U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
                    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r 
                        = vlSelf->SimTop__DOT__inst_sram_rdata;
                    __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag = 1U;
                }
            }
        } else {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r 
                = vlSelf->SimTop__DOT__inst_sram_rdata;
            __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag = 0U;
        }
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag 
            = __Vdly__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag;
        if ((IData)((8U == (0x18U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[1U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[2U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[6U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[7U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[8U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[9U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xaU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xbU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xcU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xdU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xeU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xfU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x10U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x11U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x12U] = 0U;
        } else if ((1U & (~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                             >> 3U)))) {
            __Vtemp_h36855522__0[5U] = ((0x7f80U & 
                                         (((0x200U 
                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                            ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel)
                                            : ((0x400U 
                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                ? (
                                                   (0xc0U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                      >> 6U)))) 
                                                       << 6U)) 
                                                   | ((0x30U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                         >> 4U)))) 
                                                          << 4U)) 
                                                      | ((0xcU 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                            >> 2U)))) 
                                                             << 2U)) 
                                                         | (3U 
                                                            & (- (IData)(
                                                                         (1U 
                                                                          & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))))
                                                : (
                                                   (0x800U 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                    ? 
                                                   ((0xf0U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel) 
                                                                       >> 4U)))) 
                                                        << 4U)) 
                                                    | (0xfU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                                                     ? 
                                                    (- (IData)(
                                                               (1U 
                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel))))
                                                     : 0U)))) 
                                          << 7U)) | 
                                        ((0x40U & (
                                                   vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                   >> 1U)) 
                                         | (0x3fU & 
                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])));
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[1U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[2U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U] 
                = (IData)(((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                            ? (4ULL + (((QData)((IData)(
                                                        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U]))))
                            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result));
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U] 
                = (IData)((((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                             ? (4ULL + (((QData)((IData)(
                                                         vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U]))))
                             : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result) 
                           >> 0x20U));
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] 
                = ((0x3f8000U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                 << 7U)) | __Vtemp_h36855522__0[5U]);
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[6U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[7U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[8U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[9U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xaU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xbU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xcU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xdU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xeU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0xfU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x10U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x11U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0x12U] = 0U;
        }
        if ((IData)((4U == (0xcU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xbU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xcU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xdU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xeU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xfU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x10U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x11U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x12U] = 0U;
        } else {
            if ((1U & (~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                          >> 2U)))) {
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer 
                    = ((0x40U & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res) 
                                 << 5U)) | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we) 
                                             << 5U) 
                                            | (0x1fU 
                                               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                  >> 7U))));
            }
            if (((~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                     >> 2U)) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e))) {
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xbU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xcU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xdU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xeU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xfU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x10U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x11U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x12U] = 0U;
            } else if ((1U & (~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                                 >> 2U)))) {
                __Vtemp_he5b5d80c__0[3U] = ((0xffffff00U 
                                             & (((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0) 
                                                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                                                      | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                                                         | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                                                            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                                               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                                                                  | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we))))))) 
                                                  << 0xeU) 
                                                 | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we) 
                                                     << 0xdU) 
                                                    | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                                                         | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd)) 
                                                        << 0xcU) 
                                                       | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                                                            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                                               | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw))) 
                                                           << 0xbU) 
                                                          | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                                                               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                                                                  | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh))) 
                                                              << 0xaU) 
                                                             | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0) 
                                                                  | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb)) 
                                                                 << 9U) 
                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned) 
                                                                   << 8U))))))) 
                                                & ((- (IData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r))) 
                                                   << 8U))) 
                                            | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res) 
                                                << 6U) 
                                               | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r) 
                                                    & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we)) 
                                                   << 5U) 
                                                  | (0x1fU 
                                                     & ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                         >> 7U) 
                                                        & (- (IData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r))))))));
                __Vtemp_hae92d67e__0[3U] = ((0xff800000U 
                                             & ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu) 
                                                  | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu)) 
                                                 << 0x1fU) 
                                                | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll) 
                                                     | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli)) 
                                                    << 0x1eU) 
                                                   | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl) 
                                                        | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli)) 
                                                       << 0x1dU) 
                                                      | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra) 
                                                           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai)) 
                                                          << 0x1cU) 
                                                         | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw) 
                                                              | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw)) 
                                                             << 0x1bU) 
                                                            | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw) 
                                                                << 0x1aU) 
                                                               | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw) 
                                                                    | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw)) 
                                                                   << 0x19U) 
                                                                  | ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw) 
                                                                       | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw)) 
                                                                      << 0x18U) 
                                                                     | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw) 
                                                                         | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw)) 
                                                                        << 0x17U)))))))))) 
                                            | ((0xffff8000U 
                                                & ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal) 
                                                     << 0x16U) 
                                                    | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr) 
                                                        << 0x15U) 
                                                       | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq) 
                                                           << 0x14U) 
                                                          | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne) 
                                                              << 0x13U) 
                                                             | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt) 
                                                                 << 0x12U) 
                                                                | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge) 
                                                                    << 0x11U) 
                                                                   | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu) 
                                                                       << 0x10U) 
                                                                      | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu) 
                                                                         << 0xfU)))))))) 
                                                   & ((- (IData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r))) 
                                                      << 0xfU))) 
                                               | __Vtemp_he5b5d80c__0[3U]));
                __Vtemp_hae92d67e__0[4U] = (0x7fffffU 
                                            & ((0x7fffe0U 
                                                & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and) 
                                                    | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi)) 
                                                   << 5U)) 
                                               | ((0x7ffff0U 
                                                   & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or) 
                                                       | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori)) 
                                                      << 4U)) 
                                                  | ((0x7ffff8U 
                                                      & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor) 
                                                          | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori)) 
                                                         << 3U)) 
                                                     | ((0x7ffffcU 
                                                         & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add) 
                                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0))) 
                                                            << 2U)) 
                                                        | ((0x7ffffeU 
                                                            & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub) 
                                                               << 1U)) 
                                                           | ((0x7fffffU 
                                                               & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt) 
                                                                  | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti))) 
                                                              | ((0x7fffffU 
                                                                  & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu) 
                                                                      | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu)) 
                                                                     >> 1U)) 
                                                                 | ((0x7fffffU 
                                                                     & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll) 
                                                                         | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli)) 
                                                                        >> 2U)) 
                                                                    | ((0x7fffffU 
                                                                        & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl) 
                                                                            | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli)) 
                                                                           >> 3U)) 
                                                                       | ((0x7fffffU 
                                                                           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra) 
                                                                               | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai)) 
                                                                              >> 4U)) 
                                                                          | ((0x7fffffU 
                                                                              & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw)) 
                                                                                >> 5U)) 
                                                                             | ((0x7fffffU 
                                                                                & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw) 
                                                                                >> 6U)) 
                                                                                | ((0x7fffffU 
                                                                                & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw)) 
                                                                                >> 7U)) 
                                                                                | ((0x7fffffU 
                                                                                & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw)) 
                                                                                >> 8U)) 
                                                                                | (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw)) 
                                                                                >> 9U))))))))))))))));
                __Vtemp_ha13240e2__0[7U] = (((IData)(
                                                     ((0U 
                                                       != 
                                                       (0x1fU 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                           >> 0x14U)))
                                                       ? 
                                                      (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                         >> 5U) 
                                                        & ((0x1fU 
                                                            & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                               >> 0x14U)) 
                                                           == 
                                                           (0x1fU 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                        : 
                                                       vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                           >> 0x14U))])
                                                       : 0ULL)) 
                                             >> 0x1aU) 
                                            | ((IData)(
                                                       (((0U 
                                                          != 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0x14U)))
                                                          ? 
                                                         (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                            >> 5U) 
                                                           & ((0x1fU 
                                                               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                  >> 0x14U)) 
                                                              == 
                                                              (0x1fU 
                                                               & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                           ? 
                                                          (((QData)((IData)(
                                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                           : 
                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                          [
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0x14U))])
                                                          : 0ULL) 
                                                        >> 0x20U)) 
                                               << 6U));
                __Vtemp_ha13240e2__0[8U] = (((IData)(
                                                     (((0U 
                                                        != 
                                                        (0x1fU 
                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                            >> 0x14U)))
                                                        ? 
                                                       (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                          >> 5U) 
                                                         & ((0x1fU 
                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                >> 0x14U)) 
                                                            == 
                                                            (0x1fU 
                                                             & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                         ? 
                                                        (((QData)((IData)(
                                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                         : 
                                                        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                        [
                                                        (0x1fU 
                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                            >> 0x14U))])
                                                        : 0ULL) 
                                                      >> 0x20U)) 
                                             >> 0x1aU) 
                                            | ((IData)(
                                                       ((0U 
                                                         != 
                                                         (0x1fU 
                                                          & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                             >> 0xfU)))
                                                         ? 
                                                        (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                           >> 5U) 
                                                          & ((0x1fU 
                                                              & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                 >> 0xfU)) 
                                                             == 
                                                             (0x1fU 
                                                              & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                          : 
                                                         vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                         [
                                                         (0x1fU 
                                                          & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                             >> 0xfU))])
                                                         : 0ULL)) 
                                               << 6U));
                __Vtemp_ha13240e2__0[9U] = (((IData)(
                                                     ((0U 
                                                       != 
                                                       (0x1fU 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                           >> 0xfU)))
                                                       ? 
                                                      (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                         >> 5U) 
                                                        & ((0x1fU 
                                                            & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                               >> 0xfU)) 
                                                           == 
                                                           (0x1fU 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                        : 
                                                       vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                       [
                                                       (0x1fU 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                           >> 0xfU))])
                                                       : 0ULL)) 
                                             >> 0x1aU) 
                                            | ((IData)(
                                                       (((0U 
                                                          != 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0xfU)))
                                                          ? 
                                                         (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                            >> 5U) 
                                                           & ((0x1fU 
                                                               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                  >> 0xfU)) 
                                                              == 
                                                              (0x1fU 
                                                               & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                           ? 
                                                          (((QData)((IData)(
                                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                           : 
                                                          vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                          [
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0xfU))])
                                                          : 0ULL) 
                                                        >> 0x20U)) 
                                               << 6U));
                __Vtemp_h38b71ee5__0[0xaU] = ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0) 
                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
                                                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                                                      | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                                                         | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                                                            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
                                                               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                                                                  | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                                                     | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb) 
                                                                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh) 
                                                                           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw) 
                                                                              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw))))))))))))))))))))))))) 
                                               << 0x10U) 
                                              | ((0xf800U 
                                                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                     >> 4U)) 
                                                 | ((0x7c0U 
                                                     & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                        >> 0xeU)) 
                                                    | ((IData)(
                                                               (((0U 
                                                                  != 
                                                                  (0x1fU 
                                                                   & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                      >> 0xfU)))
                                                                  ? 
                                                                 (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                                                    >> 5U) 
                                                                   & ((0x1fU 
                                                                       & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                          >> 0xfU)) 
                                                                      == 
                                                                      (0x1fU 
                                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                                                   ? 
                                                                  (((QData)((IData)(
                                                                                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                                                   : 
                                                                  vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                                                  [
                                                                  (0x1fU 
                                                                   & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                      >> 0xfU))])
                                                                  : 0ULL) 
                                                                >> 0x20U)) 
                                                       >> 0x1aU))));
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0U] 
                    = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                       & (- (IData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r))));
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U] 
                    = (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r);
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U] 
                    = (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r 
                               >> 0x20U));
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                    = __Vtemp_hae92d67e__0[3U];
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                    = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm) 
                        << 6U) | __Vtemp_hae92d67e__0[4U]);
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U] 
                    = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm) 
                        >> 0x1aU) | ((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm 
                                              >> 0x20U)) 
                                     << 6U));
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U] 
                    = (((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm 
                                 >> 0x20U)) >> 0x1aU) 
                       | ((IData)(((0U != (0x1fU & 
                                           (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                            >> 0x14U)))
                                    ? (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                                         >> 5U) & (
                                                   (0x1fU 
                                                    & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                       >> 0x14U)) 
                                                   == 
                                                   (0x1fU 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
                                        ? (((QData)((IData)(
                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                                        : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
                                       [(0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                  >> 0x14U))])
                                    : 0ULL)) << 6U));
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U] 
                    = __Vtemp_ha13240e2__0[7U];
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U] 
                    = __Vtemp_ha13240e2__0[8U];
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U] 
                    = __Vtemp_ha13240e2__0[9U];
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                    = ((0xfffe0000U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui) 
                                        << 0x12U) | 
                                       ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc) 
                                        << 0x11U))) 
                       | __Vtemp_h38b71ee5__0[0xaU]);
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xbU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xcU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xdU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xeU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xfU] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x10U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x11U] = 0U;
                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0x12U] = 0U;
            }
        }
    }
    if (__Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v0) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[1U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[2U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[3U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[4U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[5U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[6U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[7U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[8U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[9U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xaU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xbU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xcU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xdU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xeU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0xfU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x10U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x11U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x12U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x13U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x14U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x15U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x16U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x17U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x18U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x19U] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1aU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1bU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1cU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1dU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1eU] = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf[__Vdlyvdim0__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32] 
            = __Vdlyvval__SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf__v32;
    }
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin 
        = ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
            >> 0x1fU) | (0U != (3U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
        [0U];
    if (vlSelf->reset) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r = 0ULL;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[6U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[7U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[8U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[9U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xaU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xbU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xcU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xdU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xeU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xfU] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x10U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x11U] = 0U;
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x12U] = 0U;
    } else {
        if ((IData)((2U == (6U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r = 0ULL;
        } else if (((~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                        >> 1U)) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r = 0ULL;
        } else if ((1U & (~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                             >> 1U)))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_valid_r 
                = vlSelf->SimTop__DOT__inst_sram_en;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc;
        }
        if ((IData)((0x10U == (0x30U & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall))))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[6U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[7U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[8U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[9U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xaU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xbU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xcU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xdU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xeU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xfU] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x10U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x11U] = 0U;
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x12U] = 0U;
        } else if ((1U & (~ ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall) 
                             >> 4U)))) {
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[1U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[2U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[3U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[4U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[5U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[6U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[6U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[7U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[7U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[8U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[8U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[9U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[9U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xaU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xaU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xbU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xbU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xcU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xcU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xdU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xdU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xeU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xeU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0xfU] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xfU];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x10U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x10U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x11U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x11U];
            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0x12U] 
                = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x12U];
        }
    }
    vlSelf->SimTop__DOT__inst_valid = ((0x80000000ULL 
                                        != (((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[2U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[1U])))) 
                                       | (0U != vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[0U]));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2 
        = (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] 
             >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]) 
                        == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                     >> 6U))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                                     >> 6U)))))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))
            : (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                 >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]) 
                            == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                         >> 6U))) & 
                           (0U != (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                            >> 6U)))))
                ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                    << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                : (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U])) 
                    << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[7U])) 
                                  << 0x1aU) | ((QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                                               >> 6U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
        = (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U] 
             >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]) 
                        == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                     >> 0xbU))) & (0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                                       >> 0xbU)))))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))
            : (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U] 
                 >> 5U) & (((0x1fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U]) 
                            == (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                         >> 0xbU))) 
                           & (0U != (0x1fU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU] 
                                              >> 0xbU)))))
                ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                    << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
                : (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])) 
                    << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[9U])) 
                                  << 0x1aU) | ((QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[8U])) 
                                               >> 6U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[1U] 
        = ((IData)((0x21U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [1U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[2U] 
        = ((IData)((0x22U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [2U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[3U] 
        = ((IData)((0x23U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [3U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[4U] 
        = ((IData)((0x24U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [4U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[5U] 
        = ((IData)((0x25U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [5U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[6U] 
        = ((IData)((0x26U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [6U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[7U] 
        = ((IData)((0x27U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [7U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[8U] 
        = ((IData)((0x28U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [8U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[9U] 
        = ((IData)((0x29U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [9U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xaU] 
        = ((IData)((0x2aU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xaU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xbU] 
        = ((IData)((0x2bU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xbU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xcU] 
        = ((IData)((0x2cU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xcU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xdU] 
        = ((IData)((0x2dU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xdU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xeU] 
        = ((IData)((0x2eU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xeU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0xfU] 
        = ((IData)((0x2fU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0xfU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x10U] 
        = ((IData)((0x30U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x10U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x11U] 
        = ((IData)((0x31U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x11U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x12U] 
        = ((IData)((0x32U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x12U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x13U] 
        = ((IData)((0x33U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x13U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x14U] 
        = ((IData)((0x34U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x14U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x15U] 
        = ((IData)((0x35U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x15U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x16U] 
        = ((IData)((0x36U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x16U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x17U] 
        = ((IData)((0x37U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x17U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x18U] 
        = ((IData)((0x38U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x18U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x19U] 
        = ((IData)((0x39U == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x19U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1aU] 
        = ((IData)((0x3aU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1aU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1bU] 
        = ((IData)((0x3bU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1bU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1cU] 
        = ((IData)((0x3cU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1cU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1dU] 
        = ((IData)((0x3dU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1dU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1eU] 
        = ((IData)((0x3eU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1eU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o[0x1fU] 
        = ((IData)((0x3fU == (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[5U])))
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[4U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_WB__DOT__mem2wb_bus_r[3U])))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_regfile__DOT__rf
           [0x1fU]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
        = ((0x10000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                              << 0x1aU) | ((QData)((IData)(
                                                           vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                           >> 6U)))
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__data_sram_addr = ((((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                                             << 0x3aU) 
                                            | (((QData)((IData)(
                                                                vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                                                << 0x1aU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                                  >> 6U))) 
                                           + vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
        = ((0x20000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
            ? (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U])))
            : ((0x40000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[0xaU])
                ? 0ULL : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2 
        = (0U != (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
                  ^ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2 
        = VL_LTS_IQQ(64, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2 
        = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src1 
           < vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__src2);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [1U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [2U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[3U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [3U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[4U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [4U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[5U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [5U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[6U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [6U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[7U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [7U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[8U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [8U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[9U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [9U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xaU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xaU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xbU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xbU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xcU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xcU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xdU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xdU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xeU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xeU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0xfU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0xfU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x10U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x10U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x11U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x11U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x12U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x12U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x13U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x13U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x14U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x14U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x15U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x15U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x16U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x16U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x17U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x17U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x18U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x18U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x19U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x19U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1aU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1bU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1cU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1dU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1eU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o[0x1fU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT____Vcellout__u_regfile__regs_o
        [0x1fU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin)
            ? (~ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)
            : vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2);
    vlSelf->__Vtableidx6 = (7U & (IData)(vlSelf->SimTop__DOT__data_sram_addr));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_lsu__DOT__byte_sel 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx6];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr 
        = ((IData)((0U != (0x5f8000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])))
            ? ((((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[6U])) 
                 << 0x3aU) | (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[5U])) 
                               << 0x1aU) | ((QData)((IData)(
                                                            vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])) 
                                            >> 6U))) 
               + (((QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[2U])) 
                   << 0x20U) | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[1U]))))
            : ((0x200000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                ? (0xfffffffeULL & vlSelf->SimTop__DOT__data_sram_addr)
                : 0ULL));
    if (vlSelf->reset) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc = 0x7ffffffcULL;
    } else if ((1U & (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall)))) {
        vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc 
            = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_nxt;
    }
    VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(
                                                                   (1U 
                                                                    & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                       >> 0xeU)), 
                                                                   ((vlSelf->SimTop__DOT__data_sram_addr 
                                                                     - 0x80000000ULL) 
                                                                    >> 3U), vlSelf->__Vfunc_ram_read_helper__2__Vfuncout);
    vlSelf->SimTop__DOT__data_sram_rdata = vlSelf->__Vfunc_ram_read_helper__2__Vfuncout;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
           >> (0x1fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result 
        = VL_SHIFTRS_III(32,32,5, (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1), 
                         (0x1fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
           + (((0x4000000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U])
                ? (~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))
                : (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
              + (1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                       >> 0x1aU))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e 
        = (1U & (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2)) 
                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                     >> 0x14U)) | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                     >> 0x13U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ne_rs2)) 
                                   | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                        >> 0x12U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2)) 
                                      | (((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                           >> 0x10U) 
                                          & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2)) 
                                         | (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_lt_rs2)) 
                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                >> 0x11U)) 
                                            | (((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_bru__DOT__rs1_ltu_rs2)) 
                                                & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                   >> 0xfU)) 
                                               | (IData)(
                                                         (0U 
                                                          != 
                                                          (0x600000U 
                                                           & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U]))))))))));
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [1U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [2U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[3U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [3U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[4U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [4U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[5U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [5U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[6U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [6U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[7U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [7U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[8U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [8U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[9U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [9U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xaU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xaU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xbU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xbU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xcU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xcU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xdU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xdU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xeU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xeU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0xfU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0xfU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x10U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x10U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x11U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x11U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x12U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x12U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x13U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x13U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x14U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x14U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x15U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x15U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x16U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x16U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x17U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x17U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x18U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x18U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x19U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x19U];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1aU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1bU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1cU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1dU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1eU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o[0x1fU] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellout__u_ID__regs_o
        [0x1fU];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result 
        = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
           + (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
              + (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__stall_flag)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__data_sram_rdata_r
            : vlSelf->SimTop__DOT__data_sram_rdata);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_nxt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__br_addr
            : (4ULL + vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc));
    vlSelf->SimTop__DOT__inst_sram_en = ((~ (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT____Vcellinp__u_ID__br_e)) 
                                         & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc_valid));
    vlSelf->SimTop__DOT__regs[0U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0U];
    vlSelf->SimTop__DOT__regs[1U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [1U];
    vlSelf->SimTop__DOT__regs[2U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [2U];
    vlSelf->SimTop__DOT__regs[3U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [3U];
    vlSelf->SimTop__DOT__regs[4U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [4U];
    vlSelf->SimTop__DOT__regs[5U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [5U];
    vlSelf->SimTop__DOT__regs[6U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [6U];
    vlSelf->SimTop__DOT__regs[7U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [7U];
    vlSelf->SimTop__DOT__regs[8U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [8U];
    vlSelf->SimTop__DOT__regs[9U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [9U];
    vlSelf->SimTop__DOT__regs[0xaU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xaU];
    vlSelf->SimTop__DOT__regs[0xbU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xbU];
    vlSelf->SimTop__DOT__regs[0xcU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xcU];
    vlSelf->SimTop__DOT__regs[0xdU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xdU];
    vlSelf->SimTop__DOT__regs[0xeU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xeU];
    vlSelf->SimTop__DOT__regs[0xfU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0xfU];
    vlSelf->SimTop__DOT__regs[0x10U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x10U];
    vlSelf->SimTop__DOT__regs[0x11U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x11U];
    vlSelf->SimTop__DOT__regs[0x12U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x12U];
    vlSelf->SimTop__DOT__regs[0x13U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x13U];
    vlSelf->SimTop__DOT__regs[0x14U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x14U];
    vlSelf->SimTop__DOT__regs[0x15U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x15U];
    vlSelf->SimTop__DOT__regs[0x16U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x16U];
    vlSelf->SimTop__DOT__regs[0x17U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x17U];
    vlSelf->SimTop__DOT__regs[0x18U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x18U];
    vlSelf->SimTop__DOT__regs[0x19U] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x19U];
    vlSelf->SimTop__DOT__regs[0x1aU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1aU];
    vlSelf->SimTop__DOT__regs[0x1bU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1bU];
    vlSelf->SimTop__DOT__regs[0x1cU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1cU];
    vlSelf->SimTop__DOT__regs[0x1dU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1dU];
    vlSelf->SimTop__DOT__regs[0x1eU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1eU];
    vlSelf->SimTop__DOT__regs[0x1fU] = vlSelf->SimTop__DOT____Vcellout__u_mycpu_pipeline__regs_o
        [0x1fU];
    __Vtemp_h9befc343__0[0U] = (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1);
    __Vtemp_h9befc343__0[1U] = (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                        >> 0x20U));
    __Vtemp_h9befc343__0[2U] = 0U;
    __Vtemp_ha4db1ee1__0[0U] = (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b);
    __Vtemp_ha4db1ee1__0[1U] = (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_b 
                                        >> 0x20U));
    __Vtemp_ha4db1ee1__0[2U] = 0U;
    __Vtemp_hae3cbe47__0[0U] = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_cin;
    __Vtemp_hae3cbe47__0[1U] = 0U;
    __Vtemp_hae3cbe47__0[2U] = 0U;
    VL_ADD_W(3, __Vtemp_h54852520__0, __Vtemp_ha4db1ee1__0, __Vtemp_hae3cbe47__0);
    VL_ADD_W(3, __Vtemp_h93336fe5__0, __Vtemp_h9befc343__0, __Vtemp_h54852520__0);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_result 
        = (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                      >> 5U))))) & 
            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
             & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
           | (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                         >> 4U))))) 
               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                  | vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
              | (((- (QData)((IData)((1U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U] 
                                            >> 3U))))) 
                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                     ^ vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)) 
                 | (((- (QData)((IData)((0U != (6U 
                                                & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U]))))) 
                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result) 
                    | (((- (QData)((IData)((1U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[4U])))) 
                        & (QData)((IData)((1U & (((~ (IData)(
                                                             (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
                                                              >> 0x3fU))) 
                                                  & (IData)(
                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                             >> 0x3fU))) 
                                                 | ((~ 
                                                     ((IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                               >> 0x3fU)) 
                                                      ^ (IData)(
                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2 
                                                                 >> 0x3fU)))) 
                                                    & (IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result 
                                                               >> 0x3fU)))))))) 
                       | (((- (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                               >> 0x1fU)))) 
                           & (QData)((IData)((1U & 
                                              (~ (1U 
                                                  & __Vtemp_h93336fe5__0[2U])))))) 
                          | (((- (QData)((IData)((1U 
                                                  & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                     >> 0x1eU))))) 
                              & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                 << (0x3fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                             | (((- (QData)((IData)(
                                                    (1U 
                                                     & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                        >> 0x1dU))))) 
                                 & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                    >> (0x3fU & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                                | (((- (QData)((IData)(
                                                       (1U 
                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                           >> 0x1cU))))) 
                                    & VL_SHIFTRS_QQI(64,64,6, vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1, 
                                                     (0x3fU 
                                                      & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2)))) 
                                   | (((- (QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (0xc000000U 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U]))))) 
                                       & (((QData)((IData)(
                                                           (- (IData)(
                                                                      (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w 
                                                                       >> 0x1fU))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__adder_result_w)))) 
                                      | (((- (QData)((IData)(
                                                             (1U 
                                                              & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                 >> 0x19U))))) 
                                          & (((QData)((IData)(
                                                              (- (IData)(
                                                                         (1U 
                                                                          & (IData)(
                                                                                ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1 
                                                                                << 
                                                                                (0x1fU 
                                                                                & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))) 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src1) 
                                                                << 
                                                                (0x1fU 
                                                                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__alu_src2))))))) 
                                         | (((- (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                    >> 0x18U))))) 
                                             & (((QData)((IData)(
                                                                 (- (IData)(
                                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result 
                                                                             >> 0x1fU))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__srlw_result)))) 
                                            | ((- (QData)((IData)(
                                                                  (1U 
                                                                   & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__id2ex_bus_r[3U] 
                                                                      >> 0x17U))))) 
                                               & (((QData)((IData)(
                                                                   (- (IData)(
                                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result 
                                                                               >> 0x1fU))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_EX__DOT__u_alu__DOT__sraw_result))))))))))))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data 
        = (0xffU & ((0x4000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                     ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                >> 0x38U)) : ((0x2000U 
                                               & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                               ? (IData)(
                                                         (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                          >> 0x30U))
                                               : ((0x1000U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? (IData)(
                                                             (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                              >> 0x28U))
                                                   : 
                                                  ((0x800U 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                    ? (IData)(
                                                              (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                               >> 0x20U))
                                                    : 
                                                   ((0x400U 
                                                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                     ? (IData)(
                                                               (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                >> 0x18U))
                                                     : 
                                                    ((0x200U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? (IData)(
                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                 >> 0x10U))
                                                      : 
                                                     ((0x100U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                       ? (IData)(
                                                                 (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                                  >> 8U))
                                                       : 
                                                      ((0x80U 
                                                        & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                        ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                                        : 0U)))))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data 
        = (0xffffU & ((0x2000U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                       ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                  >> 0x30U)) : ((0x800U 
                                                 & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                 ? (IData)(
                                                           (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                            >> 0x20U))
                                                 : 
                                                ((0x200U 
                                                  & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                  ? (IData)(
                                                            (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                                                             >> 0x10U))
                                                  : 
                                                 ((0x80U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                                   : 0U)))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
        = ((0x800U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
            ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data 
                       >> 0x20U)) : ((0x80U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                      ? (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data)
                                      : 0U));
    VSimTop___024unit____Vdpiimwrap_ram_read_helper_TOP____024unit(vlSelf->SimTop__DOT__inst_sram_en, 
                                                                   ((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_IF__DOT__pc 
                                                                     - 0x80000000ULL) 
                                                                    >> 3U), vlSelf->__Vfunc_ram_read_helper__0__Vfuncout);
    vlSelf->SimTop__DOT__inst_sram_rdata = vlSelf->__Vfunc_ram_read_helper__0__Vfuncout;
    __Vtemp_h4d85910c__0[3U] = (IData)(((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                         ? ((IData)(
                                                    (0x18000U 
                                                     == 
                                                     (0x18000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                             ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data))
                                             : ((0x10000U 
                                                 & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                 ? 
                                                (((- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data) 
                                                                         >> 7U))))) 
                                                  << 8U) 
                                                 | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data)))
                                                 : 
                                                ((IData)(
                                                         (0x28000U 
                                                          == 
                                                          (0x28000U 
                                                           & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                  ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data))
                                                  : 
                                                 ((0x20000U 
                                                   & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                   ? 
                                                  (((- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data) 
                                                                           >> 0xfU))))) 
                                                    << 0x10U) 
                                                   | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data)))
                                                   : 
                                                  ((IData)(
                                                           (0x48000U 
                                                            == 
                                                            (0x48000U 
                                                             & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                    ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data))
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data)))
                                                     : 
                                                    ((0x80000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data
                                                      : 0ULL)))))))
                                         : (((QData)((IData)(
                                                             vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))));
    __Vtemp_h4d85910c__0[4U] = (IData)((((0x40U & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                          ? ((IData)(
                                                     (0x18000U 
                                                      == 
                                                      (0x18000U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                              ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data))
                                              : ((0x10000U 
                                                  & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                  ? 
                                                 (((- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data) 
                                                                          >> 7U))))) 
                                                   << 8U) 
                                                  | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__b_data)))
                                                  : 
                                                 ((IData)(
                                                          (0x28000U 
                                                           == 
                                                           (0x28000U 
                                                            & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                   ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data))
                                                   : 
                                                  ((0x20000U 
                                                    & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data) 
                                                                            >> 0xfU))))) 
                                                     << 0x10U) 
                                                    | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__h_data)))
                                                    : 
                                                   ((IData)(
                                                            (0x48000U 
                                                             == 
                                                             (0x48000U 
                                                              & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])))
                                                     ? (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data))
                                                     : 
                                                    ((0x40000U 
                                                      & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                      ? 
                                                     (((QData)((IData)(
                                                                       (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data 
                                                                                >> 0x1fU))))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__w_data)))
                                                      : 
                                                     ((0x80000U 
                                                       & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U])
                                                       ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__d_data
                                                       : 0ULL)))))))
                                          : (((QData)((IData)(
                                                              vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[4U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[3U])))) 
                                        >> 0x20U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[0U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[1U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[1U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[2U] 
        = vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[2U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[3U] 
        = __Vtemp_h4d85910c__0[3U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[4U] 
        = __Vtemp_h4d85910c__0[4U];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[5U] 
        = (0x3fU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_MEM__DOT__ex2mem_bus_r[5U]);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[6U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[7U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[8U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[9U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xaU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xbU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xcU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xdU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xeU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0xfU] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x10U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x11U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__mem2wb_bus[0x12U] = 0U;
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__stall_flag)
            ? vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_r
            : vlSelf->SimTop__DOT__inst_sram_rdata);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
        = ((1U & (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__pc_r 
                          >> 2U))) ? (IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp 
                                              >> 0x20U))
            : (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst_tmp));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__stall 
        = ((IData)(vlSelf->reset) ? 0U : ((IData)((
                                                   (0x60U 
                                                    == 
                                                    (0x60U 
                                                     & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer))) 
                                                   & ((((0x1fU 
                                                         & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer)) 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                            >> 0xfU))) 
                                                       & (0U 
                                                          != 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0xfU)))) 
                                                      | (((0x1fU 
                                                           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__ex_load_buffer)) 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                              >> 0x14U))) 
                                                         & (0U 
                                                            != 
                                                            (0x1fU 
                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                >> 0x14U)))))))
                                           ? 7U : 0U));
    vlSelf->__Vtableidx4 = (0xfU & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                    >> 0x19U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l 
        = VSimTop__ConstPool__TABLE_h7a2fd741_0[vlSelf->__Vtableidx4];
    vlSelf->__Vtableidx5 = (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                            >> 0x1dU);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx5];
    vlSelf->__Vtableidx3 = (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 0xcU));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx3];
    vlSelf->__Vtableidx1 = (0xfU & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst);
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l 
        = VSimTop__ConstPool__TABLE_h7a2fd741_0[vlSelf->__Vtableidx1];
    vlSelf->__Vtableidx2 = (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h 
        = VSimTop__ConstPool__TABLE_h4b04e8c6_0[vlSelf->__Vtableidx2];
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0 
        = (1U & ((~ (IData)((0U != (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                          >> 0x1aU))))) 
                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                  >> 2U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0 
        = (1U & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                 & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_l)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 3U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal 
        = (IData)((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                    >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                              >> 0xfU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 7U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 2U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 6U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 3U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 0xbU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 0xbU)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l)) 
                 >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0 
        = (1U & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                 & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                    >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0 
        = (1U & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_h) 
                  >> 1U) & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__opcode_l) 
                            >> 3U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0 
        = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
            >> 1U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lui) 
           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_auipc));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4ca63e02__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7bab5530__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 7U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 7U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 6U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 4U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 2U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 3U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 1U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h06e356b7__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 2U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 3U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 4U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 6U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 7U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
               >> 1U) & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7fb1ec8d__0) 
           & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct3_d) 
              >> 5U));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d7abb66__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4d5a9f9f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h7f918046__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hdcf99ac5__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sb) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sh) 
              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sw) 
                 | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sd))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb9600e4a__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_ha4d3cc6c__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h04662687__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hb0e0068d__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h4b32a532__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hbc115b6f__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h5d1db1f9__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hf639659f__0 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
              | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0) 
           & (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_h1e5f83ac__0));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hfc166a37__0) 
           & ((~ (IData)((0U != (7U & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                       >> 0x1aU))))) 
              & ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__funct7_h) 
                 >> 2U)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__sel_rf_res 
        = ((((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                      | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_unsigned))))) 
            << 1U) | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal) 
                      | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr)));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__imm 
        = (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr) 
            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                  | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                     | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
                           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw) 
                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti) 
                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu) 
                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori) 
                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori) 
                                                   | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi)))))))))))))))
            ? (((- (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                    >> 0x1fU)))) << 0xcU) 
               | (QData)((IData)((vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                  >> 0x14U)))) : ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__data_ram_we)
                                                   ? 
                                                  (((- (QData)((IData)(
                                                                       (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                        >> 0x1fU)))) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((0xfe0U 
                                                                       & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                          >> 0x14U)) 
                                                                      | (0x1fU 
                                                                         & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                            >> 7U))))))
                                                   : 
                                                  (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_beq) 
                                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bne) 
                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_blt) 
                                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bge) 
                                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bltu) 
                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_bgeu))))))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      ((0x800U 
                                                                        & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                           << 4U)) 
                                                                       | ((0x7e0U 
                                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                              >> 0x14U)) 
                                                                          | (0x1eU 
                                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 7U)))))))
                                                    : 
                                                   ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       (0xfffff000U 
                                                                        & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst))))
                                                     : 
                                                    ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal)
                                                      ? 
                                                     (((- (QData)((IData)(
                                                                          (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                           >> 0x1fU)))) 
                                                       << 0x14U) 
                                                      | (QData)((IData)(
                                                                        ((0xff000U 
                                                                          & vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst) 
                                                                         | ((0x800U 
                                                                             & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 9U)) 
                                                                            | (0x7feU 
                                                                               & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                                >> 0x14U)))))))
                                                      : 
                                                     (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw) 
                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw) 
                                                          | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw)))
                                                       ? (QData)((IData)(
                                                                         (0x1fU 
                                                                          & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                             >> 0x14U))))
                                                       : 
                                                      (((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli) 
                                                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli) 
                                                           | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai)))
                                                        ? (QData)((IData)(
                                                                          (0x3fU 
                                                                           & (vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__inst 
                                                                              >> 0x14U))))
                                                        : 0ULL)))))));
    vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__rf_we 
        = ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT____VdfgTmp_hd9a7b774__0) 
           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jal) 
              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_jalr) 
                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lb) 
                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lh) 
                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lw) 
                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ld) 
                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lbu) 
                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lhu) 
                                   | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_lwu) 
                                      | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addi) 
                                         | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addiw) 
                                            | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slti) 
                                               | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltiu) 
                                                  | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xori) 
                                                     | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_ori) 
                                                        | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_andi) 
                                                           | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slli) 
                                                              | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slliw) 
                                                                 | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srli) 
                                                                    | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srliw) 
                                                                       | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srai) 
                                                                          | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraiw) 
                                                                             | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_add) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_addw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sub) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_subw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sll) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sllw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_slt) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sltu) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_xor) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srl) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_srlw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sra) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_sraw) 
                                                                                | ((IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_or) 
                                                                                | (IData)(vlSelf->SimTop__DOT__u_mycpu_pipeline__DOT__u_ID__DOT__u_decoder_64i__DOT__inst_and))))))))))))))))))))))))))))))))))))));
}
