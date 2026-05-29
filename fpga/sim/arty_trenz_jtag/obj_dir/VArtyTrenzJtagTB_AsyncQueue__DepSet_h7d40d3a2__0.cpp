// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"
#include "VArtyTrenzJtagTB__Syms.h"

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async\n"); );
    // Body
    if (vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) {
        vlSelf->__PVT__source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__source__DOT__ready_reg = 0U;
        vlSelf->__PVT__source__DOT__widx_gray = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset) {
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->io_deq_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__valid_reg = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__1\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (7U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_7_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (6U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_6_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (5U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_5_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (4U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_4_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (3U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_3_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (2U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_2_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (1U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_1_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (0U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_0_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_io_out_bits_phit;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__2(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__2\n"); );
    // Body
    vlSelf->__PVT__source__DOT__widx_widx_bin = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset)
                                                  ? 0U
                                                  : 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U));
    vlSelf->__PVT__source__DOT__ready_reg = ((1U & 
                                              (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
                                             && ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->__PVT__source__DOT__widx) 
                                                    != 
                                                    (0xcU 
                                                     ^ 
                                                     (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                       << 3U) 
                                                      | (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                          << 2U) 
                                                         | (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                             << 1U) 
                                                            | (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))))));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 3U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 2U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 1U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & (IData)(vlSelf->__PVT__sink__DOT__ridx_gray)));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q__DOT__empty)));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__5(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__5\n"); );
    // Body
    vlSelf->__PVT__source__DOT__widx_gray = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset)
                                              ? 0U : (IData)(vlSelf->__PVT__source__DOT__widx));
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__2(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__2\n"); );
    // Body
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSelf->io_deq_reset) | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1\n"); );
    // Body
    if (vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) {
        vlSelf->__PVT__source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__source__DOT__ready_reg = 0U;
        vlSelf->__PVT__source__DOT__widx_gray = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset) {
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__valid_reg = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__1\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (7U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_7_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (6U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_6_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (5U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_5_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (4U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_4_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (3U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_3_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (2U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_2_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (1U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_1_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (0U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_0_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_1_io_out_bits_phit;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__3(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__3\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__valid_reg = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
                                           && (IData)(vlSelf->__PVT__sink__DOT__valid));
    if (vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
    } else {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = vlSelf->__PVT__sink__DOT__ridx_incremented;
        vlSelf->__PVT__sink__DOT__ridx_gray = vlSelf->__PVT__sink__DOT__ridx;
    }
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    if (vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) {
        vlSelf->io_deq_valid = vlSelf->__PVT__sink__DOT__valid_reg;
        vlSelf->__PVT__sink__DOT__ridx_incremented 
            = vlSelf->__PVT__sink__DOT__ridx_ridx_bin;
    } else {
        vlSelf->io_deq_valid = 0U;
        vlSelf->__PVT__sink__DOT__ridx_incremented = 0U;
    }
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 3U));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 3U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 2U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 1U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & (IData)(vlSelf->__PVT__source__DOT__widx_gray)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_1__DOT__empty)));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__2(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__2\n"); );
    // Body
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) 
           | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__1\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (7U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_7_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (6U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_6_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (5U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_5_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (4U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_4_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (3U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_3_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (2U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_2_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (1U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_1_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (0U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_0_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_2_io_out_bits_phit;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_2__DOT__empty)));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__1\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (7U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_7_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (6U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_6_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (5U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_5_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (4U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_4_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (3U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_3_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (2U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_2_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (1U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_1_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (0U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_0_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_3_io_out_bits_phit;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_3__DOT__empty)));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__1\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (7U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_7_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (6U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_6_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (5U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_5_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (4U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_4_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (3U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_3_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (2U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_2_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (1U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_1_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
    if (((IData)(vlSelf->__PVT__source__DOT___widx_T_1) 
         & (0U == (IData)(vlSelf->__PVT__source__DOT__index)))) {
        vlSelf->__PVT__source__DOT__mem_0_phit = vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT___out_phits_out_async_io_enq_flit2phit_4_io_out_bits_phit;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__3(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__3\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__valid_reg = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
                                           && (IData)(vlSelf->__PVT__sink__DOT__valid));
    if (vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
    } else {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = vlSelf->__PVT__sink__DOT__ridx_incremented;
        vlSelf->__PVT__sink__DOT__ridx_gray = vlSelf->__PVT__sink__DOT__ridx;
    }
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__ridx_incremented = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin)
                                                   : 0U);
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    >> 3U));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 3U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 2U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 1U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & (IData)(vlSelf->__PVT__source__DOT__widx_gray)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_4__DOT__empty)));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___eval_initial__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async\n"); );
    // Body
    if (vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) {
        vlSelf->__PVT__source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__source__DOT__ready_reg = 0U;
        vlSelf->__PVT__source__DOT__widx_gray = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset) {
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
    if (vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) {
        vlSelf->__PVT__sink__DOT__ridx_ridx_bin = 0U;
        vlSelf->__PVT__sink__DOT__valid_reg = 0U;
        vlSelf->__PVT__sink__DOT__ridx_gray = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 = 0U;
        vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 = 0U;
    }
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__1(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__1\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__valid_reg = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
                                           && (IData)(vlSelf->__PVT__sink__DOT__valid));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__ridx_ridx_bin = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset)
                                                ? 0U
                                                : ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                    : 0U));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 3U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 2U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                     >> 1U)));
    vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (1U & (IData)(vlSelf->__PVT__source__DOT__widx_gray)));
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset))) 
           && (IData)(vlSelf->__PVT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__2(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__2\n"); );
    // Body
    if (vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) {
        vlSelf->__PVT__source__DOT__widx_widx_bin = 0U;
        vlSelf->__PVT__source__DOT__widx_gray = 0U;
    } else {
        vlSelf->__PVT__source__DOT__widx_widx_bin = vlSelf->__PVT__source__DOT__widx_incremented;
        vlSelf->__PVT__source__DOT__widx_gray = vlSelf->__PVT__source__DOT__widx;
    }
    vlSelf->__PVT__source__DOT__ready_reg = ((1U & 
                                              (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
                                             && ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->__PVT__source__DOT__widx) 
                                                    != 
                                                    (0xcU 
                                                     ^ 
                                                     (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                       << 3U) 
                                                      | (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                          << 2U) 
                                                         | (((IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                             << 1U) 
                                                            | (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))))));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
    vlSelf->__PVT__source__DOT__widx_incremented = 
        ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
          ? (IData)(vlSelf->__PVT__source__DOT__widx_widx_bin)
          : 0U);
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->__PVT__source__DOT__widx_widx_bin))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->__PVT__source__DOT__widx_widx_bin)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                   >> 1U)
                                                   : 0U))));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
    vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (IData)(vlSelf->__PVT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 3U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 2U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & ((IData)(vlSelf->__PVT__sink__DOT__ridx_gray) 
                     >> 1U)));
    vlSelf->__PVT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2 
        = ((1U & (~ (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset))) 
           && (1U & (IData)(vlSelf->__PVT__sink__DOT__ridx_gray)));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__0\n"); );
    // Body
    vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0 = (0xfU 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    + 
                                                    ((~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_io_inner_ser_0_in_q__DOT__full)) 
                                                     & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 3U));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__4(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__4\n"); );
    // Body
    vlSelf->__PVT__sink__DOT__ridx_gray = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset)
                                            ? 0U : (IData)(vlSelf->__PVT__sink__DOT__ridx));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__2(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__2\n"); );
    // Body
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1__0\n"); );
    // Body
    vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0 = (0xfU 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    + 
                                                    ((~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_io_inner_ser_1_in_q__DOT__full)) 
                                                     & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 3U));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2__0\n"); );
    // Body
    vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0 = (0xfU 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    + 
                                                    ((~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_io_inner_ser_2_in_q__DOT__full)) 
                                                     & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 3U));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3__0\n"); );
    // Body
    vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0 = (0xfU 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    + 
                                                    ((~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_io_inner_ser_3_in_q__DOT__full)) 
                                                     & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 3U));
}

VL_INLINE_OPT void VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___nba_comb__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4__0\n"); );
    // Body
    vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0 = (0xfU 
                                                 & ((IData)(vlSelf->__PVT__sink__DOT__ridx_ridx_bin) 
                                                    + 
                                                    ((~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_io_inner_ser_4_in_q__DOT__full)) 
                                                     & (IData)(vlSelf->io_deq_valid))));
    vlSelf->__PVT__sink__DOT___index_T = (7U & (((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                  ? (IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0)
                                                  : 0U) 
                                                ^ ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                    ? 
                                                   ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 1U)
                                                    : 0U)));
    vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0 = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                                 & ((IData)(vlSelf->sink__DOT____VdfgTmp_h53fc3cf3__0) 
                                                    >> 3U));
}
