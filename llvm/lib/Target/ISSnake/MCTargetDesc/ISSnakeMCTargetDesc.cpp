#include "ISSnake.h"
#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;
#define GET_REGINFO_MC_DESC
#include "ISSnakeGenRegisterInfo.inc"

static MCRegisterInfo *createISSnakeMCRegisterInfo(const Triple &TT) {
  ISSNAKE_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitISSnakeMCRegisterInfo(X, ISSnake::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTargetMC() {
  ISSNAKE_DUMP_MAGENTA
  Target &TheISSnakeTarget = getTheISSnakeTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheISSnakeTarget,
                                    createISSnakeMCRegisterInfo);
}
