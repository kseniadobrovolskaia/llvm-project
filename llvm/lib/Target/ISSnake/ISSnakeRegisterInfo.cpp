#include "ISSnakeRegisterInfo.h"
#include "ISSnake.h"
#include "ISSnakeFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ISSnakeGenRegisterInfo.inc"

ISSnakeRegisterInfo::ISSnakeRegisterInfo()
    : ISSnakeGenRegisterInfo(ISSnake::R0) {
  ISSNAKE_DUMP_GREEN
}
