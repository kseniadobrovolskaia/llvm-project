#include "ISSnakeTargetMachine.h"
#include "ISSnake.h"
#include "TargetInfo/ISSnakeTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeISSnakeTarget() {
  // Register the target.
  ISSNAKE_DUMP_CYAN
  RegisterTargetMachine<ISSnakeTargetMachine> A(getTheISSnakeTarget());
}

ISSnakeTargetMachine::ISSnakeTargetMachine(const Target &T, const Triple &TT,
                                           StringRef CPU, StringRef FS,
                                           const TargetOptions &Options,
                                           std::optional<Reloc::Model> RM,
                                           std::optional<CodeModel::Model> CM,
                                           CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  ISSNAKE_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// ISSnake Code Generator Pass Configuration Options.
class ISSnakePassConfig : public TargetPassConfig {
public:
  ISSnakePassConfig(ISSnakeTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  ISSnakeTargetMachine &getISSnakeTargetMachine() const {
    return getTM<ISSnakeTargetMachine>();
  }

  bool addInstSelector() override {
    ISSNAKE_DUMP_CYAN
    addPass(createISSnakeISelDag(getISSnakeTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *ISSnakeTargetMachine::createPassConfig(PassManagerBase &PM) {
  ISSNAKE_DUMP_CYAN
  return new ISSnakePassConfig(*this, PM);
}

TargetLoweringObjectFile *ISSnakeTargetMachine::getObjFileLowering() const {
  ISSNAKE_DUMP_CYAN
  return TLOF.get();
}
