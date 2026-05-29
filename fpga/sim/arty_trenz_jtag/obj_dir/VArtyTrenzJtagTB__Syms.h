// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VARTYTRENZJTAGTB__SYMS_H_
#define VERILATED_VARTYTRENZJTAGTB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_fst_c.h"

// INCLUDE MODEL CLASS

#include "VArtyTrenzJtagTB.h"

// INCLUDE MODULE CLASSES
#include "VArtyTrenzJtagTB___024root.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VArtyTrenzJtagTB__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VArtyTrenzJtagTB* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedFstC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VArtyTrenzJtagTB___024root     TOP;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3;
    VArtyTrenzJtagTB_AsyncQueue    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4;

    // SCOPE NAMES
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__bank_1__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__bank__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__atomics;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_bootrom__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_clint__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_debug__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_plic__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__in_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__out_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__fragmenter_1;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_1;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_2;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_3;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__dmiAccessChain;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__dtmInfoChain;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__tapIO_idcodeChain;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__fbus__fbus_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__mbus__mbus_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__atomics;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__coupler_to_bootaddressreg__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__coupler_to_device_named_uart_0__fragmenter;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__out_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__plic_domain__plic;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__sbus__system_bus_xbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__PlusArgTimeout;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__csr;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__ibuf;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__dcache;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__fpuOpt;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend__icache;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend__tlb;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__ptw;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__tlMasterXbar;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmInner__dmInner;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmInner__dmInner__sb2tlOpt;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmOuter__dmiBypass__error;
    VerilatedScope __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmOuter__dmiXbar;

    // CONSTRUCTORS
    VArtyTrenzJtagTB__Syms(VerilatedContext* contextp, const char* namep, VArtyTrenzJtagTB* modelp);
    ~VArtyTrenzJtagTB__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
