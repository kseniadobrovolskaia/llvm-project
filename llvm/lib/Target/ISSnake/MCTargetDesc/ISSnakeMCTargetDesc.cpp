#include "ISSnake.h"
#include "MCTargetDesc/ISSnakeInfo.h"
#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ISSnakeGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ISSnakeGenInstrInfo.inc"

static MCRegisterInfo *createISSnakeMCRegisterInfo(const Triple &TT) {
  ISSNAKE_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitISSnakeMCRegisterInfo(X, ISSnake::R0);
  return X;
}

static MCInstrInfo *createISSnakeMCInstrInfo() {
  ISSNAKE_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitISSnakeMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTargetMC() {
  ISSNAKE_DUMP_MAGENTA
  Target &TheISSnakeTarget = getTheISSnakeTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheISSnakeTarget,
                                    createISSnakeMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheISSnakeTarget,
                                      createISSnakeMCInstrInfo);
}
