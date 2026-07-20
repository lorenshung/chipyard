package chipyard.fpga.ku040

import chisel3._

import freechips.rocketchip.jtag.{JTAGIO}
import freechips.rocketchip.subsystem.{PeripheryBusKey}
import freechips.rocketchip.tilelink.{TLBundle}
import freechips.rocketchip.diplomacy.{LazyRawModuleImp}
import org.chipsalliance.diplomacy.nodes.{HeterogeneousBag}
import sifive.blocks.devices.uart.{UARTPortIO, UARTParams}
import sifive.fpgashells.shell._
import sifive.fpgashells.ip.xilinx._
import sifive.fpgashells.shell.xilinx._
import sifive.fpgashells.clocks._
import chipyard._
import chipyard.harness._
import chipyard.iobinders._
import testchipip.serdes._

// All pins below sit in bank 68, an HP bank (1.8V max, LVCMOS33 illegal).
// The header must be level-shifted on board if it is 3.3V at the connector,
// as on the Alinx KU040 FMC pins.
//
// UART-TSI is parked on spare bank-68 pins A4/B4 (unconnected for now); the
// PMOD UART pins D3/D4 carry the sifive UART (WithKU040UART below). OSPI configs move RX to C3
// so the P-side clock-capable D3 pin can carry the sensor PCLK.
class WithKU040UARTTSI(rxdPin: String = "A4", txdPin: String = "B4") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTTSIPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(new UARTPortIO(port.io.uartParams)).suggestName("uart_tsi")
    harnessIO <> port.io.uart
    val packagePinsWithPackageIOs = Seq(
      (rxdPin, IOPin(harnessIO.rxd)),
      (txdPin, IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addIOB(io)
    } }
  }
})

// Maps the sifive UART device to the PMOD UART pins (PMOD2):
//   RX (FPGA in)  - D3
//   TX (FPGA out) - D4
class WithKU040UART(rxdPin: String = "D3", txdPin: String = "D4") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: UARTPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("uart")
    harnessIO <> port.io
    val packagePinsWithPackageIOs = Seq(
      (rxdPin, IOPin(harnessIO.rxd)),
      (txdPin, IOPin(harnessIO.txd)))
    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addIOB(io)
    } }
  }
})

// Pin assignments (PMOD1):
//   TCK - E5, TMS - C6, TDI - D5, TDO - D6
class WithKU040JTAG(tckPin: String = "E5", tmsPin: String = "C6",
                    tdiPin: String = "D5", tdoPin: String = "D6") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: JTAGPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(new JTAGChipIO(false)).suggestName("jtag")
    harnessIO.TDO := port.io.TDO
    port.io.TCK := harnessIO.TCK
    port.io.TDI := harnessIO.TDI
    port.io.TMS := harnessIO.TMS
    port.io.reset.foreach(_ := th.referenceReset)

    kth.sdc.addClock("JTCK", IOPin(harnessIO.TCK), 10)
    kth.sdc.addGroup(clocks = Seq("JTCK"))
    // E5 is clock-capable (IO_L13P_GC_QBC_68); kept anyway to match the
    // working Trenz arty100t binder
    kth.xdc.clockDedicatedRouteFalse(IOPin(harnessIO.TCK))
    val packagePinsWithPackageIOs = Seq(
      (tckPin, IOPin(harnessIO.TCK)),
      (tmsPin, IOPin(harnessIO.TMS)),
      (tdiPin, IOPin(harnessIO.TDI)),
      (tdoPin, IOPin(harnessIO.TDO))
    )

    packagePinsWithPackageIOs foreach { case (pin, io) => {
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addPullup(io)
    } }
  }
})

// Open-drain I2C bus used to configure the HM01B0 (default sensor address 0x24). The weak internal
// pull-ups aid bring-up; use external pull-ups sized for the board capacitance in hardware.
class WithKU040I2C(sclPin: String = "A1", sdaPin: String = "A2") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: I2CPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    val harnessIO = IO(new ShellI2CPortIO).suggestName("i2c")
    UIntToAnalog(port.io.scl.out, harnessIO.scl, port.io.scl.oe)
    UIntToAnalog(port.io.sda.out, harnessIO.sda, port.io.sda.oe)
    port.io.scl.in := AnalogToUInt(harnessIO.scl).asBool
    port.io.sda.in := AnalogToUInt(harnessIO.sda).asBool
    Seq((sclPin, IOPin(harnessIO.scl)), (sdaPin, IOPin(harnessIO.sda))).foreach { case (pin, io) =>
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
      kth.xdc.addPullup(io)
    }
  }
})

// Default allocation uses otherwise-unused bank-68 pins; D3 is a P-side global-clock-capable input.
// All pins are valid for xcku040-sfva784 and use 1.8 V I/O, but the mapping must still be matched to
// the carrier/header schematic before connecting a camera.
class WithKU040Ospi(
  dataPins: Seq[String] = Seq("H3", "H4", "G2", "H2", "E2", "F2", "D1", "E1"),
  pclkPin: String = "D3",
  fvldPin: String = "E3",
  lvldPin: String = "F3",
  intrPin: String = "F4",
  mclkPin: String = "G4",
  trigPin: String = "B1") extends HarnessBinder({
  case (th: HasHarnessInstantiators, port: OspiPort, chipId: Int) => {
    val kth = th.asInstanceOf[LazyRawModuleImp].wrapper.asInstanceOf[KU040Harness]
    require(dataPins.size == 8, "HM01B0 8-bit mode requires exactly eight data pins")

    val harnessIO = IO(chiselTypeOf(port.io)).suggestName("ospi")
    harnessIO <> port.io

    dataPins.zipWithIndex.foreach { case (pin, i) =>
      val io = IOPin(harnessIO.d, i)
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
    }

    val pclkIO = IOPin(harnessIO.pclk)
    kth.xdc.addPackagePin(pclkIO, pclkPin)
    kth.xdc.addIOStandard(pclkIO, "LVCMOS18")

    Seq(
      (fvldPin, IOPin(harnessIO.fvld)),
      (lvldPin, IOPin(harnessIO.lvld)),
      (intrPin, IOPin(harnessIO.intr)),
      (mclkPin, IOPin(harnessIO.mclk)),
      (trigPin, IOPin(harnessIO.trig))).foreach { case (pin, io) =>
      kth.xdc.addPackagePin(io, pin)
      kth.xdc.addIOStandard(io, "LVCMOS18")
    }

    kth.sdc.addClock("ospi_pclk", pclkIO, 36)
    kth.sdc.addGroup(clocks = Seq("ospi_pclk"))
  }
})
