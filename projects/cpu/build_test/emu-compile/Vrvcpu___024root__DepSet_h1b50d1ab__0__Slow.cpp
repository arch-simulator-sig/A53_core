// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrvcpu.h for the primary calling header

#include "verilated.h"

#include "Vrvcpu__Syms.h"
#include "Vrvcpu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrvcpu___024root___dump_triggers__stl(Vrvcpu___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrvcpu___024root___eval_triggers__stl(Vrvcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrvcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrvcpu___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrvcpu___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
