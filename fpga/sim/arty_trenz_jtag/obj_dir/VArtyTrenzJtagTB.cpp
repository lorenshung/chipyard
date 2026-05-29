// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VArtyTrenzJtagTB__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VArtyTrenzJtagTB::VArtyTrenzJtagTB(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VArtyTrenzJtagTB__Syms(contextp(), _vcname__, this)}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3}
    , __PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4{vlSymsp->TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VArtyTrenzJtagTB::VArtyTrenzJtagTB(const char* _vcname__)
    : VArtyTrenzJtagTB(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VArtyTrenzJtagTB::~VArtyTrenzJtagTB() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VArtyTrenzJtagTB___024root___eval_debug_assertions(VArtyTrenzJtagTB___024root* vlSelf);
#endif  // VL_DEBUG
void VArtyTrenzJtagTB___024root___eval_static(VArtyTrenzJtagTB___024root* vlSelf);
void VArtyTrenzJtagTB___024root___eval_initial(VArtyTrenzJtagTB___024root* vlSelf);
void VArtyTrenzJtagTB___024root___eval_settle(VArtyTrenzJtagTB___024root* vlSelf);
void VArtyTrenzJtagTB___024root___eval(VArtyTrenzJtagTB___024root* vlSelf);

void VArtyTrenzJtagTB::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VArtyTrenzJtagTB::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VArtyTrenzJtagTB___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VArtyTrenzJtagTB___024root___eval_static(&(vlSymsp->TOP));
        VArtyTrenzJtagTB___024root___eval_initial(&(vlSymsp->TOP));
        VArtyTrenzJtagTB___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VArtyTrenzJtagTB___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VArtyTrenzJtagTB::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step VArtyTrenzJtagTB::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool VArtyTrenzJtagTB::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t VArtyTrenzJtagTB::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* VArtyTrenzJtagTB::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VArtyTrenzJtagTB___024root___eval_final(VArtyTrenzJtagTB___024root* vlSelf);

VL_ATTR_COLD void VArtyTrenzJtagTB::final() {
    VArtyTrenzJtagTB___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VArtyTrenzJtagTB::hierName() const { return vlSymsp->name(); }
const char* VArtyTrenzJtagTB::modelName() const { return "VArtyTrenzJtagTB"; }
unsigned VArtyTrenzJtagTB::threads() const { return 1; }
void VArtyTrenzJtagTB::prepareClone() const { contextp()->prepareClone(); }
void VArtyTrenzJtagTB::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VArtyTrenzJtagTB::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VArtyTrenzJtagTB___024root__trace_decl_types(VerilatedFst* tracep);

void VArtyTrenzJtagTB___024root__trace_init_top(VArtyTrenzJtagTB___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VArtyTrenzJtagTB___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VArtyTrenzJtagTB___024root*>(voidSelf);
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VArtyTrenzJtagTB___024root__trace_decl_types(tracep);
    VArtyTrenzJtagTB___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VArtyTrenzJtagTB___024root__trace_register(VArtyTrenzJtagTB___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VArtyTrenzJtagTB::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VArtyTrenzJtagTB::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VArtyTrenzJtagTB___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
