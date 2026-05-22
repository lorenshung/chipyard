// package chipyard.fpga.vcu118

// import sys.process._

// import chisel3._
// import org.chipsalliance.cde.config.Config
// import freechips.rocketchip.rocket.{MulDivParams, RocketCoreParams}
// import freechips.rocketchip.subsystem.{
//   CBUS,
//   CCBUS,
//   ClustersLocated,
//   ExtMem,
//   HierarchicalElementMasterPortParams,
//   HierarchicalElementSlavePortParams,
//   HierarchicalLocation,
//   InCluster,
//   InSubsystem,
//   NumTiles,
//   PeripheryBusKey,
//   ControlBusKey,
//   RocketCrossingParams,
//   RocketTileAttachParams,
//   SystemBusKey,
//   TilesLocated
// }
// import freechips.rocketchip.devices.debug.{DebugModuleKey, ExportDebug, JTAG}
// import freechips.rocketchip.devices.tilelink.{DevNullParams, BootROMLocated}
// import freechips.rocketchip.diplomacy.{RegionType, AddressSet}
// import freechips.rocketchip.resources.{DTSModel, DTSTimebase}
// import freechips.rocketchip.util.{SystemFileName}

// import sifive.blocks.devices.spi.{PeripherySPIKey, SPIParams}
// import sifive.blocks.devices.uart.{PeripheryUARTKey, UARTParams}

// import sifive.fpgashells.shell.{DesignKey}
// import sifive.fpgashells.shell.xilinx.{VCU118ShellPMOD, VCU118DDRSize}

// import testchipip.serdes.{SerialTLKey}

// import chipyard._
// import chipyard.harness._
// import saturn.common.{VectorParams => SaturnVectorParams}
// import saturn.common.{VectorParams}
// import saturn.common.VectorIssueStructure
// import freechips.rocketchip.diplomacy.BufferParams
// import freechips.rocketchip.tile.{FPUParams}
// import freechips.rocketchip.tile.RocketTileParams
// import freechips.rocketchip.rocket.{BHTParams, BTBParams, DCacheParams, ICacheParams}
// import freechips.rocketchip.prci.ClockSinkParameters
// import gemmini.{CapacityInKilobytes, Dataflow, GemminiArrayConfig, ScaleArguments}
// import gemmini.Arithmetic.SIntArithmetic

// class WithDefaultPeripherals extends Config((site, here, up) => {
//   case PeripheryUARTKey => List(UARTParams(address = BigInt(0x64000000L)))
//   case PeripherySPIKey => List(SPIParams(rAddress = BigInt(0x64001000L)))
//   case VCU118ShellPMOD => "SDIO"
// })

// class WithVCU118RocketCoreParams(coreParams: RocketCoreParams) extends Config((site, here, up) => {
//   case freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem) =>
//     up(freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem), site).map {
//       case tp: freechips.rocketchip.subsystem.RocketTileAttachParams =>
//         tp.copy(tileParams = tp.tileParams.copy(core = coreParams))
//       case other => other
//     }
// })

// class WithVCU118RocketTileParams(tileParams: RocketTileParams) extends Config((site, here, up) => {
//   case freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem) =>
//     up(freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem), site).map {
//       case tp: freechips.rocketchip.subsystem.RocketTileAttachParams =>
//         val existingTileId = tp.tileParams.tileId
//         tp.copy(tileParams = tileParams.copy(tileId = existingTileId))
//       case other => other
//     }
// })

// class WithNCustomRocketTiles(
//   n: Int,
//   tileParams: RocketTileParams,
//   location: HierarchicalLocation,
//   crossing: RocketCrossingParams,
// ) extends Config((site, here, up) => {
//   case TilesLocated(`location`) => {
//     val prev = up(TilesLocated(`location`), site)
//     val idOffset = up(NumTiles)
//     List.tabulate(n)(i => RocketTileAttachParams(
//       tileParams.copy(tileId = i + idOffset),
//       crossing
//     )) ++ prev
//   }
//   case NumTiles => up(NumTiles) + n
// }) {
//   def this(
//     n: Int,
//     tileParams: RocketTileParams,
//     location: HierarchicalLocation = InSubsystem,
//   ) = this(
//     n,
//     tileParams,
//     location,
//     RocketCrossingParams(
//       master = HierarchicalElementMasterPortParams.locationDefault(location),
//       slave = HierarchicalElementSlavePortParams.locationDefault(location),
//       mmioBaseAddressPrefixWhere = location match {
//         case InSubsystem => CBUS
//         case InCluster(clusterId) => CCBUS(clusterId)
//       }
//     )
//   )
// }

// class WithSystemModifications extends Config((site, here, up) => {
//   case DTSTimebase => BigInt((1e6).toLong)
//   case BootROMLocated(x) => up(BootROMLocated(x), site).map { p =>
//     // invoke makefile for sdboot
//     val freqMHz = (site(SystemBusKey).dtsFrequency.get / (1000 * 1000)).toLong
//     val make = s"make -C fpga/src/main/resources/vcu118/sdboot PBUS_CLK=${freqMHz} bin"
//     require (make.! == 0, "Failed to build bootrom")
//     p.copy(hang = 0x10000, contentFileName = SystemFileName(s"./fpga/src/main/resources/vcu118/sdboot/build/sdboot.bin"))
//   }
//   case ExtMem => up(ExtMem, site).map(x => x.copy(master = x.master.copy(size = site(VCU118DDRSize)))) // set extmem to DDR size
//   case SerialTLKey => Nil // remove serialized tl port
// })

// // DOC include start: AbstractVCU118 and Rocket
// class WithVCU118Tweaks extends Config(
//   // clocking
//   new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
//   new chipyard.clocking.WithPassthroughClockGenerator ++
//   new chipyard.config.WithUniformBusFrequencies(100) ++
//   new WithFPGAFrequency(100) ++ // default 100MHz freq
//   // harness binders
//   new WithUART ++
//   new WithSPISDCard ++
//   new WithDDRMem ++
//   new WithJTAG ++
//   // other configuration
//   new WithDefaultPeripherals ++
//   new chipyard.config.WithTLBackingMemory ++ // use TL backing memory
//   new WithSystemModifications ++ // setup busses, use sdboot bootrom, setup ext. mem. size
//   new freechips.rocketchip.subsystem.WithoutTLMonitors ++
//   new freechips.rocketchip.subsystem.WithNMemoryChannels(1) ++
//   new chipyard.config.WithBroadcastManager
// )

// class RocketVCU118Config extends Config(
//   new WithVCU118Tweaks ++
//   new chipyard.RocketConfig
// )
// // DOC include end: AbstractVCU118 and Rocket

// object SmallIntGemminiVCU118Config {
//   val gemminiConfig = GemminiArrayConfig[SInt, Bool, UInt](
//     inputType = SInt(8.W),
//     weightType = SInt(8.W),
//     accType = SInt(32.W),

//     spatialArrayInputType = SInt(8.W),
//     spatialArrayWeightType = SInt(8.W),
//     spatialArrayOutputType = SInt(20.W),

//     tileRows = 1,
//     tileColumns = 1,
//     meshRows = 16,
//     meshColumns = 16,
//     dataflow = Dataflow.BOTH,

//     sp_capacity = CapacityInKilobytes(64),
//     acc_capacity = CapacityInKilobytes(16),
//     sp_banks = 4,
//     acc_banks = 2,
//     sp_singleported = true,
//     acc_singleported = false,
//     acc_sub_banks = 2,

//     ld_queue_length = 4,
//     st_queue_length = 2,
//     ex_queue_length = 4,
//     reservation_station_entries_ld = 4,
//     reservation_station_entries_st = 4,
//     reservation_station_entries_ex = 8,
//     max_in_flight_mem_reqs = 8,

//     dma_maxbytes = 64,
//     dma_buswidth = 128,
//     tlb_size = 4,

//     mvin_scale_args = None,
//     mvin_scale_acc_args = None,
//     mvin_scale_shared = false,
//     acc_scale_args = Some(ScaleArguments[SInt, UInt](
//       (value: SInt, shift: UInt) => value >> shift,
//       latency = 1,
//       multiplicand_t = UInt(8.W),
//       num_scale_units = -1,
//       identity = "0",
//       c_str = "ROUNDING_RIGHT_SHIFT(x, scale)"
//     )),

//     acc_read_full_width = false,
//     acc_read_small_width = true,
//     ex_read_from_spad = true,
//     ex_read_from_acc = true,
//     ex_write_to_spad = true,
//     ex_write_to_acc = true,

//     acc_latency = 2,
//     tile_latency = 0,
//     mesh_output_delay = 2,

//     has_training_convs = false,
//     has_max_pool = true,
//     has_nonlinear_activations = true,
//     has_normalizations = false,

//     num_counter = 0,
//     headerFileName = "gemmini_params.h",
//   )
// }

// class SmallIntGemminiVCU118Config extends Config(
//   new gemmini.DefaultGemminiConfig(SmallIntGemminiVCU118Config.gemminiConfig) ++
//   new chipyard.config.WithSystemBusWidth(128) ++
//   new WithFPGAFrequency(50) ++
//   new WithVCU118Tweaks ++
//   new chipyard.RocketConfig
// )

// class BoomVCU118Config extends Config(
//   new WithFPGAFrequency(50) ++
//   new WithVCU118Tweaks ++
//   new chipyard.MegaBoomV3Config
// )

// class CustomSaturnVCU118Config extends Config(
//   {
//     val vcu118VectorParams = SaturnVectorParams(
//       // In-order dispatch Queue
//       vdqEntries = 4,

//       // Load store instruction queues (in VLSU)
//       vliqEntries = 4,
//       vsiqEntries = 4,

//       // Load store in-flight queues (in VLSU)
//       vlifqEntries = 8,
//       vsifqEntries = 16,
//       vlrobEntries = 2,

//       // Scatter-gather engine params
//       vsgPorts = 8,
//       vsgifqEntries = 4,
//       vsgBuffers = 3,

//       // Load/store/execute/permute/maskindex issue queues
//       vlissqEntries = 0,
//       vsissqEntries = 0,
//       vxissqEntries = 0,
//       vpissqEntries = 0,

//       dLen = 64,
//       mLen = 64,
//       vatSz = 3,

//       useSegmentedIMul = false,
//       useScalarFPFMA = true,
//       useIterativeIMul = false,
//       useElementwiseFP64 = true,
//       fmaPipeDepth = 4,
//       imaPipeDepth = 4,

//       // for comparisons only
//       hazardingMultiplier = 0,
//       hwachaLimiter = None,
//       enableChaining = true,
//       latencyInject = false,
//       enableDAE = true,
//       enableOOO = true,
//       enableScalarVectorAddrDisambiguation = true,

//       doubleBufferSegments = false,

//       vrfBanking = 2,
//       vrfHiccupBuffer = true,

//       issStructure = VectorIssueStructure.Unified,

//       tlBuffer = BufferParams.default,
//     )

//     // Saturn `refParams`: stronger issue structure / segmented imul vs lite `vcu118VectorParams`.
//     // We also use our new `IntegerOnly` structure to drop all FP vector hardware.
//     val vcu118VectorParamsFullInt = SaturnVectorParams.refParams.copy(
//       issStructure = VectorIssueStructure.IntegerOnly
//     )

//     val vcu118RocketCoreParams = RocketCoreParams(
//       xLen = 64,
//       pgLevels = 3, // sv39 default
//       bootFreqHz = 0,
//       useVM = false,
//       useUser = false,
//       useSupervisor = false,
//       useHypervisor = false,
//       useDebug = true,
//       useAtomics = true,
//       useAtomicsOnlyForIO = false,
//       useCompressed = true,
//       useRVE = false,
//       useConditionalZero = false,
//       useZba = false,
//       useZbb = false,
//       useZbs = false,
//       nLocalInterrupts = 0,
//       useNMI = false,
//       nBreakpoints = 1,
//       useBPWatch = false,
//       mcontextWidth = 0,
//       scontextWidth = 0,
//       nPMPs = 8,
//       nPerfCounters = 0,
//       haveBasicCounters = true,
//       haveCFlush = false,
//       misaWritable = true,
//       nL2TLBEntries = 0,
//       nL2TLBWays = 1,
//       nPTECacheEntries = 0,
//       mtvecInit = Some(BigInt(0)),
//       mtvecWritable = true,
//       fastLoadWord = true,
//       fastLoadByte = false,
//       branchPredictionModeCSR = false,
//       clockGate = false,
//       mvendorid = 0,
//       mimpid = 0x20181004,
//       mulDiv = Some(MulDivParams()),
//       fpu = Some(FPUParams()),
//       debugROB = None,
//       haveCease = true,
//       haveSimTimeout = true,
//       vector = None,
//       enableTraceCoreIngress = false,
//     )

//     val vcu118RocketTileParams = RocketTileParams(
//       core = vcu118RocketCoreParams,
//       icache = Some(ICacheParams(
//         nSets = 64,
//         nWays = 4,
//         rowBits = 128,
//         nTLBSets = 1,
//         nTLBWays = 32,
//         nTLBBasePageSectors = 4,
//         nTLBSuperpages = 4,
//         cacheIdBits = 0,
//         tagECC = None,
//         dataECC = None,
//         itimAddr = None,
//         prefetch = false,
//         blockBytes = 64,
//         latency = 2,
//         fetchBytes = 4,
//       )),
//       dcache = Some(DCacheParams(
//         nSets = 64,
//         nWays = 4,
//         rowBits = 64,
//         subWordBits = None,
//         replacementPolicy = "random",
//         nTLBSets = 1,
//         nTLBWays = 32,
//         nTLBBasePageSectors = 4,
//         nTLBSuperpages = 4,
//         tagECC = None,
//         dataECC = None,
//         dataECCBytes = 1,
//         nMSHRs = 1,
//         nSDQ = 17,
//         nRPQ = 16,
//         nMMIOs = 1,
//         blockBytes = 64,
//         separateUncachedResp = false,
//         acquireBeforeRelease = false,
//         pipelineWayMux = false,
//         clockGate = false,
//         scratch = None,
//       )),
//       btb = Some(BTBParams(
//         nEntries = 28,
//         nMatchBits = 14,
//         nPages = 6,
//         nRAS = 6,
//         bhtParams = Some(BHTParams(
//           nEntries = 512,
//           counterLength = 1,
//           historyLength = 8,
//           historyBits = 3,
//         )),
//         updatesOutOfOrder = false,
//       )),
//       dataScratchpadBytes = 0,
//       tileId = 0,
//       beuAddr = None,
//       blockerCtrlAddr = None,
//       clockSinkParams = ClockSinkParameters(),
//       boundaryBuffers = None,
//       traceParams = None,
//     )
  
//     new WithVCU118Tweaks ++
//     // Per-tile Saturn: left (outer) layer runs after the right; full-int tile first in chain, lite tile inner.
//     // new saturn.rocket.WithRocketVectorUnit(128, 128, vcu118VectorParamsFullInt, cores = Some(Seq(0))) ++
//     new saturn.rocket.WithRocketVectorUnit(128, 128, VectorParams.refParams, cores = Some(Seq(0))) ++
//     new saturn.rocket.WithRocketVectorUnit(128, 128, vcu118VectorParams, cores = Some(Seq(1))) ++
//     new chipyard.config.WithSystemBusWidth(128) ++
//     new WithNCustomRocketTiles(2, vcu118RocketTileParams) ++
//     new chipyard.config.AbstractConfig
//   }
// )

// class WithFPGAFrequency(fMHz: Double) extends Config(
//   new chipyard.harness.WithHarnessBinderClockFreqMHz(fMHz) ++
//   new chipyard.config.WithSystemBusFrequency(fMHz) ++
//   new chipyard.config.WithPeripheryBusFrequency(fMHz) ++
//   new chipyard.config.WithControlBusFrequency(fMHz) ++
//   new chipyard.config.WithFrontBusFrequency(fMHz) ++
//   new chipyard.config.WithMemoryBusFrequency(fMHz)
// )

// class WithFPGAFreq25MHz extends WithFPGAFrequency(25)
// class WithFPGAFreq50MHz extends WithFPGAFrequency(50)
// class WithFPGAFreq75MHz extends WithFPGAFrequency(75)
// class WithFPGAFreq100MHz extends WithFPGAFrequency(100)
