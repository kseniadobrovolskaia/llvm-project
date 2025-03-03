#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheISSnakeTarget() {
  static Target TheISSnakeTarget;
  return TheISSnakeTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTargetInfo() {
  RegisterTarget<Triple::ISSnake> X(getTheISSnakeTarget(), "ISSnake", "Instruction Set Snake",
                                   "ISSnake");
}

