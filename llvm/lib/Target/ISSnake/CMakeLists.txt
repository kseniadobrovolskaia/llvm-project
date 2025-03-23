add_llvm_component_group(ISSnake)

set(LLVM_TARGET_DEFINITIONS ISSnake.td)

tablegen(LLVM ISSnakeGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM ISSnakeGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM ISSnakeGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM ISSnakeGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM ISSnakeGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM ISSnakeGenCallingConv.inc -gen-callingconv)
tablegen(LLVM ISSnakeGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(ISSnakeCommonTableGen)

add_llvm_target(ISSnakeCodeGen
  ISSnakeTargetMachine.cpp
  ISSnakeRegisterInfo.cpp
  ISSnakeInstrInfo.cpp
  ISSnakeSubtarget.cpp
  ISSnakeAsmPrinter.cpp
  ISSnakeISelDagToDag.cpp
  ISSnakeISelLowering.cpp
  ISSnakeMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ISSnakeInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  ISSnake
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

