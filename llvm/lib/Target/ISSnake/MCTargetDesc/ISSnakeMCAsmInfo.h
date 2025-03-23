#ifndef LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCASMINFO_H
#define LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class ISSnakeELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit ISSnakeELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCASMINFO_H
