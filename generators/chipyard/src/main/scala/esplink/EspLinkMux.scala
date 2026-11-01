package chipyard.esplink

import chisel3._
import chisel3.util._

/** Remote program loading over the FPGA <-> ESP32 link (E13/F14).
 *
 *  The drone carrier has exactly two wires between the FPGA and the ESP32-C6,
 *  and in a flying image they are uart1: telemetry down, uplink commands and
 *  motor duty frames. This block shares those two pins between uart1 and a
 *  UART-TSI client, which is a hardware TileLink master that can write DDR and
 *  start hart 0 whatever the software is doing -- the same job the JTAG debug
 *  module does over the FT2232, but reachable from the ESP and so over WiFi.
 *
 *  TSI cannot simply listen on the same RX line: every telemetry or command
 *  byte would execute as a bus write. So the pins belong to exactly one client
 *  at a time, and the switch is made by hardware, never by Rocket software,
 *  because a crashed image must not be able to lock the loader out:
 *
 *    UART   default. uart1 owns the pins; TSI's RX is held idle.
 *    BREAK  the ESP held its TX low for >= breakUs. A UART byte at any rate
 *           this link uses is low for at most 9 bit times (78 us at 115200,
 *           0.94 ms at 9600), so this cannot happen in traffic. Whichever client
 *           had the pins saw the first breakUs of it: sifive's UARTRx restarts on
 *           a held-low line, so uart1 receives a burst of framing-error 0x00
 *           bytes (overflowing its FIFO). Its RX is held idle from here on.
 *    KEY    the break ended. The next bytes, decoded here at a fixed 115200,
 *           must be exactly `key`, within keyWindowMs. Any other byte, or the
 *           window expiring, drops back to UART. The key is consumed here and
 *           reaches neither client.
 *    FENCE  key accepted; memFence asks the harness to stop the SoC's memory
 *           port at the next TileLink burst boundary and let outstanding
 *           responses drain (memQuiet). The DDR controller's TileLink/AXI
 *           adapters live in the harness reset domain, so resetting the SoC in
 *           the middle of a burst would leave them holding half of it, and the
 *           next requests -- TSI's -- would be consumed as its missing beats.
 *           memFence stays up through RESET. Gives up waiting after fenceMs
 *           and resets anyway: a port that is still busy then is already wedged.
 *    RESET  memory quiet. Sends `ack` to the ESP so it knows a loader-capable
 *           bitstream answered, and holds the whole SoC in reset for resetMs.
 *           That clears TSI's word-assembly state (a stray byte would otherwise
 *           misalign every following 32-bit TSI word) and parks hart 0 in the
 *           boot ROM, waiting for MSIP. DDR and the MIG are in the harness
 *           reset domain and keep their contents.
 *    TSI    TSI owns the pins. Returns to UART after idleMs with no activity in
 *           EITHER direction -- a long --selfcheck read-back is silent on RX for
 *           seconds while TSI is transmitting, so RX alone is not enough. The
 *           exit is silent: no byte reaches either client.
 *
 *  Why a break AND a key: GPIO16 is the ESP32-C6's U0TXD, so the ESP ROM and
 *  boot logs go out on this wire at every ESP reset or reflash, and while EN is
 *  low the pin floats. The RX pin is pulled up so a floating line reads idle,
 *  and a boot log cannot contain both a 2 ms low and the 8-byte binary key.
 */
case class EspLinkLoaderParams(
  baud: Int = 115200,
  breakUs: Int = 2000,
  keyWindowMs: Int = 200,
  resetMs: Int = 10,
  fenceMs: Int = 5,
  idleMs: Int = 2000,
  // "RBLD" + four bytes that ASCII text cannot contain.
  key: Seq[Int] = Seq(0x52, 0x42, 0x4c, 0x44, 0xa5, 0x5a, 0xc3, 0x3c),
  ack: Seq[Int] = Seq(0x52, 0x42, 0x4c, 0x4b))    // "RBLK"

object EspLinkLoaderMode {
  val width = 3
  val uart  = 0
  val break = 1
  val key   = 2
  val reset = 3
  val tsi   = 4
  val fence = 5
}

/** 8N1 receiver, sampling each bit at its midpoint. Only used for the key. */
class EspLinkByteRx(div: Int) extends Module {
  require(div >= 4)
  val io = IO(new Bundle {
    val in  = Input(Bool())
    val en  = Input(Bool())
    val out = Valid(UInt(8.W))
  })
  val cnt    = RegInit(0.U(log2Ceil(div + 1).W))
  val bitIdx = RegInit(0.U(4.W))
  val shift  = RegInit(0.U(8.W))
  val busy   = RegInit(false.B)

  io.out.valid := false.B
  io.out.bits  := shift

  when (!io.en) {
    busy := false.B
  } .elsewhen (!busy) {
    when (!io.in) {
      busy   := true.B
      cnt    := (div / 2).U
      bitIdx := 0.U
    }
  } .elsewhen (cnt =/= 0.U) {
    cnt := cnt - 1.U
  } .otherwise {
    cnt := (div - 1).U
    when (bitIdx === 0.U) {
      // Start-bit midpoint: still low or it was a glitch.
      when (io.in) { busy := false.B } .otherwise { bitIdx := 1.U }
    } .elsewhen (bitIdx <= 8.U) {
      shift  := Cat(io.in, shift(7, 1))   // LSB first
      bitIdx := bitIdx + 1.U
    } .otherwise {
      // Stop-bit midpoint. A low stop bit is a framing error: drop the byte.
      busy         := false.B
      io.out.valid := io.in
    }
  }
}

/** 8N1 transmitter, idle high. Only used for the ack. */
class EspLinkByteTx(div: Int) extends Module {
  val io = IO(new Bundle {
    val in   = Flipped(Decoupled(UInt(8.W)))
    val out  = Output(Bool())
    val idle = Output(Bool())
  })
  val shift = RegInit(((1 << 10) - 1).U(10.W))
  val left  = RegInit(0.U(4.W))
  val cnt   = RegInit(0.U(log2Ceil(div + 1).W))

  io.in.ready := left === 0.U
  io.idle     := left === 0.U
  io.out      := Mux(left === 0.U, true.B, shift(0))

  when (io.in.fire) {
    shift := Cat(1.U(1.W), io.in.bits, 0.U(1.W))   // stop, data, start
    left  := 10.U
    cnt   := (div - 1).U
  } .elsewhen (left =/= 0.U) {
    when (cnt === 0.U) {
      cnt   := (div - 1).U
      shift := Cat(1.U(1.W), shift(9, 1))
      left  := left - 1.U
    } .otherwise {
      cnt := cnt - 1.U
    }
  }
}

class EspLinkMux(clockHz: Double, c: EspLinkLoaderParams = EspLinkLoaderParams()) extends Module {
  val io = IO(new Bundle {
    val pinRx    = Input(Bool())    // from the ESP's TX
    val pinTx    = Output(Bool())   // to the ESP's RX
    val uartRxd  = Output(Bool())   // into the SoC's uart1
    val uartTxd  = Input(Bool())
    val tsiRxd   = Output(Bool())   // into the UART-TSI client
    val tsiTxd   = Input(Bool())
    val socReset = Output(Bool())   // registered: an async reset must not see decode glitches
    val memFence = Output(Bool())   // hold the SoC memory port at a burst boundary
    val memQuiet = Input(Bool())    // port stopped and no responses outstanding
    val mode     = Output(UInt(EspLinkLoaderMode.width.W))
  })

  private def cycles(us: Double): Int = math.round(clockHz * us / 1e6).toInt
  val div          = math.round(clockHz / c.baud).toInt
  val breakCycles  = cycles(c.breakUs)
  val keyCycles    = cycles(c.keyWindowMs * 1000.0)
  val resetCycles  = cycles(c.resetMs * 1000.0)
  val idleCycles   = cycles(c.idleMs * 1000.0)
  val fenceCycles  = cycles(c.fenceMs * 1000.0)
  val timerMax     = Seq(keyCycles, resetCycles, idleCycles, fenceCycles).max
  require(c.key.nonEmpty && c.ack.nonEmpty)
  require(cycles(c.resetMs * 1000.0) > div * 10 * c.ack.length,
    "the SoC reset must outlast the ack so the ESP hears it before TSI is live")

  // Asynchronous input from another chip: synchronise. Idle (high) at reset.
  val rx = RegNext(RegNext(RegNext(io.pinRx, true.B), true.B), true.B)

  // Consecutive-low counter; breakNow is a one-cycle pulse at the threshold.
  val lowCnt = RegInit(0.U(log2Ceil(breakCycles + 1).W))
  when (rx) {
    lowCnt := 0.U
  } .elsewhen (lowCnt =/= breakCycles.U) {
    lowCnt := lowCnt + 1.U
  }
  val breakNow = !rx && lowCnt === (breakCycles - 1).U

  val sUart  = EspLinkLoaderMode.uart.U(EspLinkLoaderMode.width.W)
  val sBreak = EspLinkLoaderMode.break.U(EspLinkLoaderMode.width.W)
  val sKey   = EspLinkLoaderMode.key.U(EspLinkLoaderMode.width.W)
  val sReset = EspLinkLoaderMode.reset.U(EspLinkLoaderMode.width.W)
  val sTsi   = EspLinkLoaderMode.tsi.U(EspLinkLoaderMode.width.W)
  val sFence = EspLinkLoaderMode.fence.U(EspLinkLoaderMode.width.W)

  val state  = RegInit(sUart)
  val timer  = RegInit(0.U(log2Ceil(timerMax + 1).W))
  val keyIdx = RegInit(0.U(log2Ceil(c.key.length + 1).W))
  val ackIdx = RegInit(0.U(log2Ceil(c.ack.length + 1).W))
  val keyVec = VecInit(c.key.map(_.U(8.W)))
  val ackVec = VecInit(c.ack.map(_.U(8.W)))

  val byteRx = Module(new EspLinkByteRx(div))
  byteRx.io.in := rx
  byteRx.io.en := state === sKey

  val byteTx = Module(new EspLinkByteTx(div))
  byteTx.io.in.valid := state === sReset && ackIdx =/= c.ack.length.U
  byteTx.io.in.bits  := ackVec(ackIdx)
  when (byteTx.io.in.fire) { ackIdx := ackIdx + 1.U }

  when (breakNow && state =/= sBreak) {
    // From any state, including TSI: a fresh break always restarts the
    // handshake, and a completed handshake always resets the SoC, so whatever
    // the break did to TSI's word assembly is discarded.
    state := sBreak
  } .otherwise {
    switch (state) {
      is (sBreak) {
        when (rx) {
          state  := sKey
          keyIdx := 0.U
          timer  := keyCycles.U
        }
      }
      is (sKey) {
        when (timer === 0.U) {
          state := sUart
        } .otherwise {
          timer := timer - 1.U
        }
        when (byteRx.io.out.valid) {
          when (byteRx.io.out.bits =/= keyVec(keyIdx)) {
            state := sUart
          } .elsewhen (keyIdx === (c.key.length - 1).U) {
            state := sFence
            timer := fenceCycles.U
          } .otherwise {
            keyIdx := keyIdx + 1.U
          }
        }
      }
      is (sFence) {
        when (io.memQuiet || timer === 0.U) {
          state  := sReset
          timer  := resetCycles.U
          ackIdx := 0.U
        } .otherwise {
          timer := timer - 1.U
        }
      }
      is (sReset) {
        when (timer =/= 0.U) {
          timer := timer - 1.U
        } .elsewhen (ackIdx === c.ack.length.U && byteTx.io.idle) {
          state := sTsi
          timer := idleCycles.U
        }
      }
      is (sTsi) {
        when (!rx || !io.tsiTxd) {
          timer := idleCycles.U
        } .elsewhen (timer === 0.U) {
          state := sUart
        } .otherwise {
          timer := timer - 1.U
        }
      }
    }
  }

  io.uartRxd  := Mux(state === sUart, rx, true.B)
  io.tsiRxd   := Mux(state === sTsi, rx, true.B)
  io.pinTx    := RegNext(MuxLookup(state, true.B)(Seq(
    sUart  -> io.uartTxd,
    sTsi   -> io.tsiTxd,
    sReset -> byteTx.io.out)), true.B)
  io.socReset := RegNext(state === sReset, false.B)
  io.memFence := state === sFence || state === sReset || io.socReset
  io.mode     := state
}
