add_llvm_component_library(LLVMISSnakeDesc
  ISSnakeMCTargetDesc.cpp
  ISSnakeMCAsmInfo.cpp
  ISSnakeInstPrinter.cpp
  ISSnakeMCCodeEmitter.cpp
  ISSnakeAsmBackend.cpp
  ISSnakeELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  ISSnakeInfo

  ADD_TO_COMPONENT
  ISSnake
)

