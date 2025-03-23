#ifndef LLVM_LIB_TARGET_ISSNAKE_ISSNAKEREGISTERINFO_H
#define LLVM_LIB_TARGET_ISSNAKE_ISSNAKEREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "ISSnakeGenRegisterInfo.inc"

namespace llvm {

struct ISSnakeRegisterInfo : public ISSnakeGenRegisterInfo {
public:
  ISSnakeRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_ISSNAKEREGISTERINFO_H
