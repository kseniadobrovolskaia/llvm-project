#include "ISSnakeSubtarget.h"
#include "ISSnake.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ISSnake-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ISSnakeGenSubtargetInfo.inc"

ISSnakeSubtarget::ISSnakeSubtarget(const Triple &TT, const std::string &CPU,
                                   const std::string &FS,
                                   const TargetMachine &TM)
    : ISSnakeGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this) {
  ISSNAKE_DUMP_CYAN
}
