package chipyard.fpga.arty100t

import chisel3._

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

class WithArty100TDDRTL extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: TLMemPort, chipId: Int) => {
    val artyTh = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
    val bundles = artyTh.ddrClient.out.map(_._1)
    val ddrClientBundle = Wire(new HeterogeneousBag(bundles.map(_.cloneType)))
    bundles.zip(ddrClientBundle).foreach { case (bundle, io) => bundle <> io }
    ddrClientBundle <> port.io
  }
})

class WithArty100TUARTTSI extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTTSIPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
    val harnessIO = IO(new UARTPortIO(port.io.uartParams)).suggestName("uart_tsi")
    harnessIO <> port.io.uart
    val packagePinsWithPackageIOs = Seq(
      ("P16" , IOPin(harnessIO.rxd)),
      ("U18", IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addIOB(io)
    } }
  }
})

// // Maps the UART device to the on-board USB-UART
class WithArty100TUART(rxdPin: String = "A9", txdPin: String = "D10") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
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

// Maps the UART device to PMOD JD pins 3/7
class WithArty100TPMODUART extends WithArty100TUART("V18", "Y18")

class WithArty100TJTAG extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: JTAGPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
    val harnessIO = IO(new JTAGChipIO(false)).suggestName("jtag")
    harnessIO.TDO := port.io.TDO
    port.io.TCK := harnessIO.TCK
    port.io.TDI := harnessIO.TDI
    port.io.TMS := harnessIO.TMS
    port.io.reset.foreach(_ := th.referenceReset)

    ath.sdc.addClock("JTCK", IOPin(harnessIO.TCK), 10)
    ath.sdc.addGroup(clocks = Seq("JTCK"))
    ath.xdc.clockDedicatedRouteFalse(IOPin(harnessIO.TCK))
    val packagePinsWithPackageIOs = Seq(
      ("W19", IOPin(harnessIO.TCK)),
      ("V20", IOPin(harnessIO.TMS)),
      ("W20", IOPin(harnessIO.TDI)),
      ("U20", IOPin(harnessIO.TDO))
    )
    
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addPullup(io)
    } }
  }
})

// Brings the SoC's I2C controller out to two FPGA pins as an open-drain 2-wire bus.
// One TLI2C controller == one SCL/SDA bus that addresses many slaves (HM01B0 @ 0x24 + others).
// Placed in WithArty100TOspiPeriphery so it overrides the default chipyard.harness.WithI2CTiedOff.
// PINS: board-specific (xc7a100t-fgg484). I2C needs pull-ups: addPullup enables the weak internal
// pull-up; external ~4.7k is recommended for reliable I2C rise times.
class WithArty100TI2C(sclPin: String = "A18", sdaPin: String = "A19") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: I2CPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
    val harnessIO = IO(new ShellI2CPortIO).suggestName("i2c")
    // Open-drain: drive the line low only when output-enable is asserted; otherwise tri-state.
    UIntToAnalog(port.io.scl.out, harnessIO.scl, port.io.scl.oe)
    UIntToAnalog(port.io.sda.out, harnessIO.sda, port.io.sda.oe)
    port.io.scl.in := AnalogToUInt(harnessIO.scl).asBool
    port.io.sda.in := AnalogToUInt(harnessIO.sda).asBool
    Seq((sclPin, IOPin(harnessIO.scl)), (sdaPin, IOPin(harnessIO.sda))) foreach { case (pin, io) => {
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
      ath.xdc.addPullup(io)
    } }
  }
})

// Brings the HM01B0 capture peripheral's parallel-video pins out to the xc7a100t-fgg484 shell.
// These defaults are buildable package-pin assignments, but must be matched to the carrier wiring.
// The sensor is limited to 3.0 V IOVDD, so a level shifter is required at this 3.3 V interface.
class WithArty100TOspi(
  dataPins: Seq[String] = Seq("B17", "B18", "A14", "A13", "D16", "E16", "E17", "F16"),
  pclkPin: String = "B15",
  fvldPin: String = "A16",
  lvldPin: String = "B16",
  intrPin: String = "F19",
  mclkPin: String = "A15",
  trigPin: String = "F20") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: OspiPort, chipId: Int) => {
    val ath = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[Arty100THarness]
    require(dataPins.size == 8, "HM01B0 8-bit mode requires exactly eight data pins")

    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("ospi")
    harnessIO <> port.io

    dataPins.zipWithIndex.foreach { case (pin, i) =>
      val io = IOPin(harnessIO.d, i)
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
    }

    val pclkIO = IOPin(harnessIO.pclk)
    ath.xdc.addPackagePin(pclkIO, pclkPin)
    ath.xdc.addIOStandard(pclkIO, "LVCMOS33")

    val ctrlPins = Seq(
      (fvldPin, IOPin(harnessIO.fvld)), // FLVD (bundle keeps the historical `fvld` spelling)
      (lvldPin, IOPin(harnessIO.lvld)), // LVLD
      (intrPin, IOPin(harnessIO.intr)), // INT
      (mclkPin, IOPin(harnessIO.mclk)), // MCLK
      (trigPin, IOPin(harnessIO.trig))  // TRIG
    )

    ctrlPins.foreach { case (pin, io) =>
      ath.xdc.addPackagePin(io, pin)
      ath.xdc.addIOStandard(io, "LVCMOS33")
    }

    ath.sdc.addClock("ospi_pclk", pclkIO, 36)
    ath.sdc.addGroup(clocks = Seq("ospi_pclk"))
    // B15 is not a clock-capable package pin. The override permits routing at the HM01B0's low
    // pixel-clock rate; override pclkPin with a carrier-connected MRCC/SRCC pin when available.
    ath.xdc.clockDedicatedRouteFalse(pclkIO)
  }
})
