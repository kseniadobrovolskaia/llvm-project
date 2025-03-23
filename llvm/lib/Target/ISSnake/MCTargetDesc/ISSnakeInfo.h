#ifndef LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEINFO_H
#define LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace ISSnakeOp {
enum OperandType : unsigned {
  OPERAND_ISSNAKEM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace ISSnakeOp

} // end namespace llvm

#endif
