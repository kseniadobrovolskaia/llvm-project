add_llvm_component_group(ISSnake)

set(LLVM_TARGET_DEFINITIONS ISSnake.td)

tablegen(LLVM ISSnakeGenRegisterInfo.inc -gen-register-info)
add_public_tablegen_target(ISSnakeCommonTableGen)

add_llvm_target(ISSnakeCodeGen
  ISSnakeTargetMachine.cpp
  ISSnakeRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ISSnakeInfo

  ADD_TO_COMPONENT
  ISSnake
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

