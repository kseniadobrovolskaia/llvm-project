#include "ISSnake.h"
#include "ISSnakeInstPrinter.h"
#include "ISSnakeMCAsmInfo.h"
#include "MCTargetDesc/ISSnakeInfo.h"
#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

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

static MCAsmInfo *createISSnakeMCAsmInfo(const MCRegisterInfo &MRI,
                                         const Triple &TT,
                                         const MCTargetOptions &Options) {
  ISSNAKE_DUMP_MAGENTA
  MCAsmInfo *MAI = new ISSnakeELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(ISSnake::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createISSnakeMCInstPrinter(const Triple &T,
                                                 unsigned SyntaxVariant,
                                                 const MCAsmInfo &MAI,
                                                 const MCInstrInfo &MII,
                                                 const MCRegisterInfo &MRI) {
  ISSNAKE_DUMP_MAGENTA
  return new ISSnakeInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTargetMC() {
  ISSNAKE_DUMP_MAGENTA
  Target &TheISSnakeTarget = getTheISSnakeTarget();
  RegisterMCAsmInfoFn X(TheISSnakeTarget, createISSnakeMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheISSnakeTarget,
                                    createISSnakeMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheISSnakeTarget,
                                      createISSnakeMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheISSnakeTarget,
                                          createISSnakeMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheISSnakeTarget,
                                        createISSnakeMCInstPrinter);
  // Register the MC Code Emitter.
  TargetRegistry::RegisterMCCodeEmitter(TheISSnakeTarget,
                                        createISSnakeMCCodeEmitter);
}
