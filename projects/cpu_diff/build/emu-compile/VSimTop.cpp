// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSimTop.h"
#include "VSimTop__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VSimTop::VSimTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSimTop__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_perfInfo_clean{vlSymsp->TOP.io_perfInfo_clean}
    , io_perfInfo_dump{vlSymsp->TOP.io_perfInfo_dump}
    , io_uart_out_valid{vlSymsp->TOP.io_uart_out_valid}
    , io_uart_out_ch{vlSymsp->TOP.io_uart_out_ch}
    , io_uart_in_valid{vlSymsp->TOP.io_uart_in_valid}
    , io_uart_in_ch{vlSymsp->TOP.io_uart_in_ch}
    , io_logCtrl_log_begin{vlSymsp->TOP.io_logCtrl_log_begin}
    , io_logCtrl_log_end{vlSymsp->TOP.io_logCtrl_log_end}
    , io_logCtrl_log_level{vlSymsp->TOP.io_logCtrl_log_level}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VSimTop::VSimTop(const char* _vcname__)
    : VSimTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSimTop::~VSimTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSimTop___024root___eval_debug_assertions(VSimTop___024root* vlSelf);
#endif  // VL_DEBUG
void VSimTop___024root___eval_static(VSimTop___024root* vlSelf);
void VSimTop___024root___eval_initial(VSimTop___024root* vlSelf);
void VSimTop___024root___eval_settle(VSimTop___024root* vlSelf);
void VSimTop___024root___eval(VSimTop___024root* vlSelf);

void VSimTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSimTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSimTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSimTop___024root___eval_static(&(vlSymsp->TOP));
        VSimTop___024root___eval_initial(&(vlSymsp->TOP));
        VSimTop___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSimTop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSimTop::eventsPending() { return false; }

uint64_t VSimTop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSimTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSimTop___024root___eval_final(VSimTop___024root* vlSelf);

VL_ATTR_COLD void VSimTop::final() {
    VSimTop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSimTop::hierName() const { return vlSymsp->name(); }
const char* VSimTop::modelName() const { return "VSimTop"; }
unsigned VSimTop::threads() const { return 1; }
