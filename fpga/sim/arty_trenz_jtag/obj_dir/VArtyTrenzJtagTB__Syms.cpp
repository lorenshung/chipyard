// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB.h"
#include "VArtyTrenzJtagTB___024root.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"

// FUNCTIONS
VArtyTrenzJtagTB__Syms::~VArtyTrenzJtagTB__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void VArtyTrenzJtagTB__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void VArtyTrenzJtagTB__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedFstC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void VArtyTrenzJtagTB__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

VArtyTrenzJtagTB__Syms::VArtyTrenzJtagTB__Syms(VerilatedContext* contextp, const char* namep, VArtyTrenzJtagTB* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.in_phits_in_async")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.in_phits_in_async_1")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.in_phits_in_async_2")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.in_phits_in_async_3")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.in_phits_in_async_4")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.out_phits_out_async")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.out_phits_out_async_1")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.out_phits_out_async_2")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.out_phits_out_async_3")}
    , TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4{this, Verilated::catName(namep, "ArtyTrenzJtagTB.dut.chiptop0.system.serial_tl_domain.phy.out_phits_out_async_4")}
{
        // Check resources
        Verilated::stackCheck(3534230);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3;
    TOP.__PVT__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4 = &TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async.__Vconfigure(true);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3.__Vconfigure(false);
    TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4.__Vconfigure(false);
    // Setup scopes
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__bank_1__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.bank_1.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__bank__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.bank.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__atomics.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.atomics", "atomics", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_bootrom__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.coupler_to_bootrom.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_clint__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.coupler_to_clint.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_debug__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.coupler_to_debug.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__coupler_to_plic__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.coupler_to_plic.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__in_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.in_xbar", "in_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__cbus__out_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.cbus.out_xbar", "out_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.chipyard_prcictrl_domain.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__fragmenter_1.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.chipyard_prcictrl_domain.fragmenter_1", "fragmenter_1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__chipyard_prcictrl_domain__xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.chipyard_prcictrl_domain.xbar", "xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.coh_wrapper.broadcast_1", "broadcast_1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.coh_wrapper.broadcast_1.TLBroadcastTracker", "TLBroadcastTracker", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_1.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.coh_wrapper.broadcast_1.TLBroadcastTracker_1", "TLBroadcastTracker_1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_2.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.coh_wrapper.broadcast_1.TLBroadcastTracker_2", "TLBroadcastTracker_2", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__coh_wrapper__broadcast_1__TLBroadcastTracker_3.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.coh_wrapper.broadcast_1.TLBroadcastTracker_3", "TLBroadcastTracker_3", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.dtm", "dtm", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__dmiAccessChain.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.dtm.dmiAccessChain", "dmiAccessChain", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__dtmInfoChain.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.dtm.dtmInfoChain", "dtmInfoChain", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__dtm__tapIO_idcodeChain.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.dtm.tapIO_idcodeChain", "tapIO_idcodeChain", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__fbus__fbus_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.fbus.fbus_xbar", "fbus_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__mbus__mbus_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.mbus.mbus_xbar", "mbus_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__atomics.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.pbus.atomics", "atomics", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__coupler_to_bootaddressreg__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.pbus.coupler_to_bootaddressreg.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__coupler_to_device_named_uart_0__fragmenter.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.pbus.coupler_to_device_named_uart_0.fragmenter", "fragmenter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__pbus__out_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.pbus.out_xbar", "out_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__plic_domain__plic.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.plic_domain.plic", "plic", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__sbus__system_bus_xbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.sbus.system_bus_xbar", "system_bus_xbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.core", "core", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__PlusArgTimeout.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.core.PlusArgTimeout", "PlusArgTimeout", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__csr.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.core.csr", "csr", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__core__ibuf.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.core.ibuf", "ibuf", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__dcache.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.dcache", "dcache", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__fpuOpt.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.fpuOpt", "fpuOpt", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.frontend", "frontend", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend__icache.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.frontend.icache", "icache", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__frontend__tlb.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.frontend.tlb", "tlb", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__ptw.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.ptw", "ptw", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tile_prci_domain__element_reset_domain_rockettile__tlMasterXbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tile_prci_domain.element_reset_domain_rockettile.tlMasterXbar", "tlMasterXbar", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmInner__dmInner.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tlDM.dmInner.dmInner", "dmInner", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmInner__dmInner__sb2tlOpt.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tlDM.dmInner.dmInner.sb2tlOpt", "sb2tlOpt", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmOuter__dmiBypass__error.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tlDM.dmOuter.dmiBypass.error", "error", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ArtyTrenzJtagTB__dut__chiptop0__system__tlDM__dmOuter__dmiXbar.configure(this, name(), "ArtyTrenzJtagTB.dut.chiptop0.system.tlDM.dmOuter.dmiXbar", "dmiXbar", -9, VerilatedScope::SCOPE_OTHER);
}
