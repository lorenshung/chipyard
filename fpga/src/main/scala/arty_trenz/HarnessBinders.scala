package chipyard.fpga.arty_trenz

import chisel3._
import chisel3.util._

import freechips.rocketchip.jtag.{JTAGIO}
import freechips.rocketchip.subsystem.{PeripheryBusKey}
import freechips.rocketchip.tilelink.{TLBundle}
import freechips.rocketchip.diplomacy.{LazyRawModuleImp}
import org.chipsalliance.diplomacy.nodes.{HeterogeneousBag}
import sifive.blocks.devices.uart.{UARTPortIO, UARTParams}
import sifive.blocks.devices.jtag.{JTAGPins, JTAGPinsFromPort}
import sifive.blocks.devices.pinctrl.{BasePin}
import sifive.fpgashells.shell._
import sifive.fpgashells.ip.xilinx._
import sifive.fpgashells.shell.xilinx._
import sifive.fpgashells.clocks._
import chipyard._
import chipyard.harness._
import chipyard.iobinders._
import testchipip.serdes._

// ----------------------------------------------------------------------------
// UART on the carrier USB-UART chips (D11/D12 path).
//   FPGA-TX = U18 (MIO15)   FPGA-RX = P16 (MIO14)   both LVCMOS33 bank 14.
// ----------------------------------------------------------------------------
class WithArtyTrenzUART(rxdPin: String = "P16", txdPin: String = "U18") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzShell]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("uart")
    harnessIO <> port.io
    val packagePinsWithPackageIOs = Seq(
      (rxdPin, IOPin(harnessIO.rxd)),
      (txdPin, IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addIOB(io)
    } }
  }
})

// TSI-over-UART variant (used as the bringup FESVR channel in tweaks).
class WithArtyTrenzUARTTSI extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTTSIPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzShell]
    val harnessIO = IO(new UARTPortIO(port.io.uartParams)).suggestName("uart_tsi")
    harnessIO <> port.io.uart
    val packagePinsWithPackageIOs = Seq(
      ("P16", IOPin(harnessIO.rxd)),
      ("U18", IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addIOB(io)
    } }
  }
})

// ----------------------------------------------------------------------------
// DDR3 binder: wires the chip's external TL memory port to the on-shell DDR
// overlay. Only attaches to ArtyTrenzHarness (the DDR variant).
// ----------------------------------------------------------------------------
class WithArtyTrenzDDRTL extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: TLMemPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzHarness]
    val bundles = ath.ddrClient.out.map(_._1)
    val ddrClientBundle = Wire(new HeterogeneousBag(bundles.map(_.cloneType)))
    bundles.zip(ddrClientBundle).foreach { case (bundle, io) => bundle <> io }
    ddrClientBundle <> port.io
  }
})

// ----------------------------------------------------------------------------
// JTAG on carrier J5 PMod pins 1..4 (FTDI dongle). PULLUP added so the FPGA
// reads an idle JTAG bus when the cable is unplugged.
//   TCK = W20 (J5-1)   TMS = V20 (J5-2)   TDI = W19 (J5-3)   TDO = U20 (J5-4)
// Probe-only mirrors drive copies on the remaining J5 signal pins:
//   TCK = V18 (J5-5)   TMS = Y18 (J5-6)   TDI = V19 (J5-7)   TDO = Y19 (J5-8)
// All LVCMOS33 on bank 14.
// ----------------------------------------------------------------------------
class WithArtyTrenzJTAG extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: JTAGPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzShell]
    val harnessIO = IO(new JTAGChipIO(false)).suggestName("jtag")
    harnessIO.TDO := port.io.TDO
    port.io.TCK := harnessIO.TCK
    port.io.TDI := harnessIO.TDI
    port.io.TMS := harnessIO.TMS
    // The JTAG debug TAP must be reachable independently of the system clock/PLL.
    // `referenceReset` is the DUT-domain system reset (= ~PLL_locked | ~resetPin),
    // and inside ChipTop it becomes the TAP reset via ResetCatchAndSync(TCK, .).
    // Tying the TAP reset to it holds the ENTIRE TAP (including the IDCODE chain)
    // in reset whenever the core clock/PLL isn't up -> TDO frozen, scan-chain
    // interrogation reads all-ones. Drive a self-clearing power-on reset in the
    // free-running TCK domain instead, so the TAP comes alive as soon as the
    // adapter clocks TCK -- regardless of the PLL / external reset state.
    port.io.reset.foreach(_ := PowerOnResetFPGAOnly(harnessIO.TCK))

    val probeTCK = IO(Output(Bool())).suggestName("jtag_probe_TCK")
    val probeTMS = IO(Output(Bool())).suggestName("jtag_probe_TMS")
    val probeTDI = IO(Output(Bool())).suggestName("jtag_probe_TDI")
    val probeTDO = IO(Output(Bool())).suggestName("jtag_probe_TDO")
    probeTCK := harnessIO.TCK.asUInt.asBool
    probeTMS := harnessIO.TMS
    probeTDI := harnessIO.TDI
    probeTDO := harnessIO.TDO

    ath.sdc.addClock("JTCK", IOPin(harnessIO.TCK), 10)
    ath.sdc.addGroup(clocks = Seq("JTCK"))
    ath.xdc.clockDedicatedRouteFalse(IOPin(harnessIO.TCK))
    val packagePinsWithPackageIOs = Seq(
      // jtag_TCK MUST sit on a clock-capable (_P / *RCC) pin so it can take the
      // dedicated route to a BUFG. W19 = IO_L12P_T1_MRCC_14 (J5-3) is the MRCC
      // P-side. It was previously on W20 = IO_L12N_T1_MRCC_14 (the N-side), which
      // has NO dedicated clock route (Vivado [Place 30-574] / DRC PLCK-12), so the
      // TAP flops + the TCK-clocked POR never clocked -> OpenOCD read all-ones.
      // A Verilator sim of the real RTL proved the logic is correct (see
      // fpga/sim/arty_trenz_jtag), isolating the fault to this pin. TDI is data,
      // so it is happy on the N-side W20. NOTE: this swaps the cable's TCK/TDI
      // leads (J5-1 <-> J5-3, both top row).
      ("W19", IOPin(harnessIO.TCK)),  // J5-3  (was TDI) -- MRCC P-side, clock-capable
      ("V20", IOPin(harnessIO.TMS)),  // J5-2
      ("W20", IOPin(harnessIO.TDI)),  // J5-1  (was TCK)
      ("U20", IOPin(harnessIO.TDO))   // J5-4
    )

    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addPullup(io)
    } }

    val probePinsWithPackageIOs = Seq(
      ("V18", IOPin(probeTCK)),  // J5-5, TCK mirror
      ("Y18", IOPin(probeTMS)),  // J5-6, TMS mirror
      ("V19", IOPin(probeTDI)),  // J5-7, TDI mirror
      ("Y19", IOPin(probeTDO))   // J5-8, TDO mirror
    )
    probePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
    } }

    ath match {
      case debugLEDs: HasArtyTrenzJTAGDebugLEDs if debugLEDs.jtagDebugLEDs.nonEmpty => {
        withClockAndReset(th.harnessBinderClock, th.harnessBinderReset) {
          def syncedEdge(signal: Bool): Bool = {
            val sync0 = RegNext(signal, false.B)
            val sync1 = RegNext(sync0, false.B)
            val sync2 = RegNext(sync1, false.B)
            sync2 ^ sync1
          }

          val holdCycles = math.max(1, (th.getHarnessBinderClockFreqHz / 8.0).toInt)
          def pulseStretch(pulse: Bool): Bool = {
            val counterWidth = log2Ceil(holdCycles + 1)
            val counter = RegInit(0.U(counterWidth.W))
            when (pulse) {
              counter := holdCycles.U(counterWidth.W)
            } .elsewhen (counter =/= 0.U) {
              counter := counter - 1.U
            }
            counter =/= 0.U
          }

          debugLEDs.jtagDebugLEDs(0) := pulseStretch(syncedEdge(harnessIO.TCK.asUInt.asBool))
          if (debugLEDs.jtagDebugLEDs.size > 1) {
            debugLEDs.jtagDebugLEDs(1) := pulseStretch(syncedEdge(port.io.TDO))
          }
        }
      }
      case _ => ()
    }
  }
})

// ----------------------------------------------------------------------------
// SerialTL on carrier J11 40-pin header pins 5..17 (13 GPIO on bank 16,
// LVCMOS33). Used by the scratchpad / SerialTL bringup variant; not used by
// the DDR variant.
//
//   clock  = F13 (J11-5,  IOA0)
//   out.v  = D21 (J11-6,  IOA1)
//   out.r  = D14 (J11-7,  IOA2)
//   in.v   = F16 (J11-8,  IOA3)
//   in.r   = A13 (J11-9,  IOA4)
//   out[0] = A14 (J11-10, IOA5)
//   out[1] = A15 (J11-11, IOA6)
//   out[2] = A16 (J11-12, IOA7)
//   out[3] = A18 (J11-13, IOA8)
//   in[0]  = A19 (J11-14, IOA9)
//   in[1]  = A20 (J11-15, IOA10)
//   in[2]  = B20 (J11-16, IOA11)
//   in[3]  = F18 (J11-17, IOA12)
// ----------------------------------------------------------------------------
class WithArtyTrenzSerialTLToGPIO extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: SerialTLPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzShell]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("serial_tl")
    harnessIO <> port.io

    harnessIO match {
      case io: DecoupledPhitIO => {
        val clkIO = io match {
          case io: HasClockOut => IOPin(io.clock_out)
          case io: HasClockIn => IOPin(io.clock_in)
        }
        val packagePinsWithPackageIOs = Seq(
          ("F13", clkIO),                           // J11-5
          ("D21", IOPin(io.out.valid)),             // J11-6
          ("D14", IOPin(io.out.ready)),             // J11-7
          ("F16", IOPin(io.in.valid)),              // J11-8
          ("A13", IOPin(io.in.ready)),              // J11-9
          ("A14", IOPin(io.out.bits.phit, 0)),      // J11-10
          ("A15", IOPin(io.out.bits.phit, 1)),      // J11-11
          ("A16", IOPin(io.out.bits.phit, 2)),      // J11-12
          ("A18", IOPin(io.out.bits.phit, 3)),      // J11-13
          ("A19", IOPin(io.in.bits.phit, 0)),       // J11-14
          ("A20", IOPin(io.in.bits.phit, 1)),       // J11-15
          ("B20", IOPin(io.in.bits.phit, 2)),       // J11-16
          ("F18", IOPin(io.in.bits.phit, 3))        // J11-17
        )
        packagePinsWithPackageIOs foreach { case (pin, io) => {
          ath.xdc.addPackagePin(io, pin)
          ath.xdc.addIOStandard(io, "LVCMOS33")
        }}

        // Don't add IOB to the clock if it's an input
        io match {
          case io: DecoupledInternalSyncPhitIO => packagePinsWithPackageIOs foreach { case (pin, io) => {
            ath.xdc.addIOB(io)
          }}
          case io: DecoupledExternalSyncPhitIO => packagePinsWithPackageIOs.drop(1).foreach { case (pin, io) => {
            ath.xdc.addIOB(io)
          }}
        }

        ath.sdc.addClock("ser_tl_clock", clkIO, 100)
        ath.sdc.addGroup(pins = Seq(clkIO))
        ath.xdc.clockDedicatedRouteFalse(clkIO)
      }
    }
  }
})
