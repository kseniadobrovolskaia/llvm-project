#ifndef LLVM_LIB_TARGET_ISSNAKE_ISSNAKEISELLOWERING_H
#define LLVM_LIB_TARGET_ISSNAKE_ISSNAKEISELLOWERING_H

#include "ISSnake.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class ISSnakeSubtarget;
class ISSnakeTargetMachine;

namespace ISSnakeISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace ISSnakeISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_ISSNAKEISELLOWERING_H
