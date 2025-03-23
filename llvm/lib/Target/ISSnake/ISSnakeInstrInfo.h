#ifndef LLVM_LIB_TARGET_ISSNAKE_ISSNAKEINSTRINFO_H
#define LLVM_LIB_TARGET_ISSNAKE_ISSNAKEINSTRINFO_H

#include "ISSnakeRegisterInfo.h"
#include "MCTargetDesc/ISSnakeInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "ISSnakeGenInstrInfo.inc"

namespace llvm {

class ISSnakeSubtarget;

class ISSnakeInstrInfo : public ISSnakeGenInstrInfo {
public:
  ISSnakeInstrInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_ISSNAKEINSTRINFO_H
