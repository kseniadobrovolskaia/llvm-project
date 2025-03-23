#include "ISSnakeSubtarget.h"
#include "ISSnake.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "ISSnake-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ISSnakeGenSubtargetInfo.inc"

ISSnakeSubtarget::ISSnakeSubtarget(const StringRef &CPU,
                                   const StringRef &TuneCPU,
                                   const StringRef &FS, const TargetMachine &TM)
    : ISSnakeGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  ISSNAKE_DUMP_CYAN
}
