// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VArtyTrenzJtagTB.h for the primary calling header

#include "VArtyTrenzJtagTB__pch.h"
#include "VArtyTrenzJtagTB_AsyncQueue.h"
#include "VArtyTrenzJtagTB__Syms.h"

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
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
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSelf->io_deq_reset) | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q__DOT__empty)));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_1__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
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
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) 
           | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_1__DOT__empty)));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_2__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
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
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) 
           | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_2__DOT__empty)));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_3__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
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
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) 
           | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_3__DOT__empty)));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_4__0\n"); );
    // Body
    vlSelf->__PVT__source__DOT__index = (7U & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                               ^ (4U 
                                                  & ((IData)(vlSelf->__PVT__source__DOT__widx_gray) 
                                                     >> 1U))));
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
    vlSelf->io_enq_ready = ((IData)(vlSelf->__PVT__source__DOT__ready_reg) 
                            & (IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset) 
           | (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset));
    vlSelf->__PVT__sink__DOT__ridx = (((IData)(vlSelf->sink__DOT____VdfgTmp_h4434c2cc__0) 
                                       << 3U) | (IData)(vlSelf->__PVT__sink__DOT___index_T));
    vlSelf->__PVT__source__DOT___widx_T_1 = ((IData)(vlSelf->io_enq_ready) 
                                             & (~ (IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async_io_enq_q_4__DOT__empty)));
    vlSelf->__PVT__sink__DOT__valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                       & ((IData)(vlSelf->__PVT__sink__DOT__ridx) 
                                          != (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                               << 3U) 
                                              | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->__PVT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->source__DOT____VdfgTmp_h04800923__0 = (0xfU 
                                                   & ((IData)(vlSelf->__PVT__source__DOT__widx_widx_bin) 
                                                      + (IData)(vlSelf->__PVT__source__DOT___widx_T_1)));
    vlSelf->__PVT__source__DOT__widx = ((0xfffffff8U 
                                         & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                                             << 3U) 
                                            & (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0))) 
                                        | (7U & (((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? (IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0)
                                                   : 0U) 
                                                 ^ 
                                                 ((IData)(vlSelf->__PVT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0)
                                                   ? 
                                                  ((IData)(vlSelf->source__DOT____VdfgTmp_h04800923__0) 
                                                   >> 1U)
                                                   : 0U))));
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async__0\n"); );
    // Body
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
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
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
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_1__0\n"); );
    // Body
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
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
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
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_2__0\n"); );
    // Body
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
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
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
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_3__0\n"); );
    // Body
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
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
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
}

VL_ATTR_COLD void VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4__0(VArtyTrenzJtagTB_AsyncQueue* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VArtyTrenzJtagTB__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  VArtyTrenzJtagTB_AsyncQueue___stl_sequent__TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__in_phits_in_async_4__0\n"); );
    // Body
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
    vlSelf->io_deq_valid = ((IData)(vlSelf->__PVT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0) 
                            & (IData)(vlSelf->__PVT__sink__DOT__valid_reg));
    vlSelf->sink__DOT____Vcellinp__sink_valid_0__reset 
        = ((IData)(vlSymsp->TOP.ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT___system_auto_cbus_fixedClockNode_anon_out_reset) 
           | (IData)(vlSymsp->TOP__ArtyTrenzJtagTB__DOT__dut__DOT__chiptop0__DOT__system__DOT__serial_tl_domain__DOT__phy__DOT__out_phits_out_async.io_deq_reset));
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
}
