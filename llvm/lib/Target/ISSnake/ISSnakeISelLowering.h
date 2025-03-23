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

class ISSnakeTargetLowering : public TargetLowering {
public:
  explicit ISSnakeTargetLowering(const TargetMachine &TM,
                                 const ISSnakeSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  ISSnakeSubtarget const &getSubtarget() const { return STI; }

private:
  const ISSnakeSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_ISSNAKEISELLOWERING_H
