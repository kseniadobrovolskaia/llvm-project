#include "TargetInfo/ISSnakeTargetInfo.h"
#include "ISSnake.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheISSnakeTarget() {
  ISSNAKE_DUMP_YELLOW
  static Target TheISSnakeTarget;
  return TheISSnakeTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTargetInfo() {
  ISSNAKE_DUMP_YELLOW
  RegisterTarget<Triple::ISSnake> X(getTheISSnakeTarget(), "ISSnake", "Instruction Set Snake",
                                   "ISSnake");
}

