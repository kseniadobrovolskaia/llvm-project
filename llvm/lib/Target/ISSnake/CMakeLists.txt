add_llvm_component_group(ISSnake)

add_llvm_target(ISSnakeCodeGen
  ISSnakeTargetMachine.cpp

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

