#ifndef LLVM_LIB_TARGET_ISSNAKE_ISSNAKETARGETMACHINE_H
#define LLVM_LIB_TARGET_ISSNAKE_ISSNAKETARGETMACHINE_H

#include "ISSnakeSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheISSnakeTarget;

class ISSnakeTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  ISSnakeSubtarget Subtarget;

public:
  ISSnakeTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                       StringRef FS, const TargetOptions &Options,
                       std::optional<Reloc::Model> RM,
                       std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                       bool JIT);

  const ISSnakeSubtarget *getSubtargetImpl(const Function &) const override {
    ISSNAKE_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_ISSNAKE_ISSNAKETARGETMACHINE_H
