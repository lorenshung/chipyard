package chipyard.fpga.arty_trenz

import chisel3._

import freechips.rocketchip.diplomacy.{LazyRawModuleImp}
import org.chipsalliance.diplomacy.nodes.{HeterogeneousBag}

import sifive.blocks.devices.uart.{UARTPortIO}

import sifive.fpgashells.shell._
import sifive.fpgashells.ip.xilinx._
import sifive.fpgashells.shell.xilinx._

import chipyard._
import chipyard.harness._
import chipyard.iobinders._
import testchipip.serdes._

// USB-UART on the TE0705 carrier MIO group. RX = P19, TX = U18.
class WithArtyTrenzUART extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzHarness]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("uart")
    harnessIO <> port.io
    val packagePinsWithPackageIOs = Seq(
      ("P19", IOPin(harnessIO.rxd)),
      ("U18", IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addIOB(io)
    } }
  }
})

// External JTAG on PMod J5 (8-pin 2x4). Wire your dongle:
//   TCK -> V15 (J5-1), TMS -> V14 (J5-2), TDI -> U15 (J5-3),
//   TDO -> V13 (J5-4), GND -> J5-5/11, VCC -> J5-6/12.
class WithArtyTrenzJTAG extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: JTAGPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzHarness]
    val harnessIO = IO(new JTAGChipIO(false)).suggestName("jtag")
    harnessIO.TDO := port.io.TDO
    port.io.TCK := harnessIO.TCK
    port.io.TDI := harnessIO.TDI
    port.io.TMS := harnessIO.TMS
    // Keep the JTAG TAP out of the SoC reset domain. Tying it to
    // referenceReset was holding the TAP in reset whenever pllReset stayed
    // asserted (e.g. POR/MIG not releasing), which manifests as openocd
    // seeing "all ones" / DTM version 15. OpenOCD does its own TLR via
    // 5x TCK+TMS=1 at session start, so an explicit reset isn't needed.
    port.io.reset.foreach(_ := false.B)

    ath.sdc.addClock("JTCK", IOPin(harnessIO.TCK), 10)
    ath.sdc.addGroup(clocks = Seq("JTCK"))
    ath.xdc.clockDedicatedRouteFalse(IOPin(harnessIO.TCK))
    val packagePinsWithPackageIOs = Seq(
      ("V15", IOPin(harnessIO.TCK)),
      ("V14", IOPin(harnessIO.TMS)),
      ("U15", IOPin(harnessIO.TDI)),
      ("V13", IOPin(harnessIO.TDO))
    )

    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addPullup(io)
    } }
  }
})

// SerialTL exposed on the J11 40-pin header (all bank 16, LVCMOS33).
//   J11-5  F13  serial_tl_clock
//   J11-6  D21  out.valid
//   J11-7  D14  out.ready
//   J11-8  F16  in.valid
//   J11-9  A13  in.ready
//   J11-10 A14  out.bits.phit[0]   J11-14 A19  in.bits.phit[0]
//   J11-11 A15  out.bits.phit[1]   J11-15 A20  in.bits.phit[1]
//   J11-12 A16  out.bits.phit[2]   J11-16 B20  in.bits.phit[2]
//   J11-13 A18  out.bits.phit[3]   J11-17 F18  in.bits.phit[3]
class WithArtyTrenzSerialTLToGPIO extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: SerialTLPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzHarness]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("serial_tl")
    harnessIO <> port.io

    harnessIO match {
      case io: DecoupledPhitIO => {
        val clkIO = io match {
          case io: HasClockOut => IOPin(io.clock_out)
          case io: HasClockIn => IOPin(io.clock_in)
        }
        val packagePinsWithPackageIOs = Seq(
          ("F13", clkIO),
          ("D21", IOPin(io.out.valid)),
          ("D14", IOPin(io.out.ready)),
          ("F16", IOPin(io.in.valid)),
          ("A13", IOPin(io.in.ready)),
          ("A14", IOPin(io.out.bits.phit, 0)),
          ("A15", IOPin(io.out.bits.phit, 1)),
          ("A16", IOPin(io.out.bits.phit, 2)),
          ("A18", IOPin(io.out.bits.phit, 3)),
          ("A19", IOPin(io.in.bits.phit, 0)),
          ("A20", IOPin(io.in.bits.phit, 1)),
          ("B20", IOPin(io.in.bits.phit, 2)),
          ("F18", IOPin(io.in.bits.phit, 3))
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

// Backing memory for ExtTLMem -> the on-SoM DDR3L via the MIG.
class WithArtyTrenzDDRTL extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: TLMemPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[ArtyTrenzHarness]
    val bundles = ath.ddrClient.get.out.map(_._1)
    val ddrClientBundle = Wire(new HeterogeneousBag(bundles.map(_.cloneType)))
    bundles.zip(ddrClientBundle).foreach { case (bundle, io) => bundle <> io }
    ddrClientBundle <> port.io
  }
})
