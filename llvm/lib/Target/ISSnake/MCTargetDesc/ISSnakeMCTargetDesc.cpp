#include "ISSnake.h"
#include "MCTargetDesc/ISSnakeInfo.h"
#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ISSnakeGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ISSnakeGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "ISSnakeGenSubtargetInfo.inc"

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

static MCSubtargetInfo *
createISSnakeMCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  ISSNAKE_DUMP_MAGENTA
  return createISSnakeMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
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
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheISSnakeTarget,
                                          createISSnakeMCSubtargetInfo);
}
