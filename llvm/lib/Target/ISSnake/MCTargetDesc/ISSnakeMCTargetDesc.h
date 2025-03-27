#ifndef LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCTARGETDESC_H
#define LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCTARGETDESC_H

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createISSnakeMCCodeEmitter(const MCInstrInfo &MCII,
                                          MCContext &Ctx);
MCAsmBackend *createISSnakeAsmBackend(const Target &T,
                                      const MCSubtargetInfo &STI,
                                      const MCRegisterInfo &MRI,
                                      const MCTargetOptions &Options);

std::unique_ptr<MCObjectTargetWriter>
createISSnakeELFObjectWriter(bool Is64Bit, uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for ISSnake registers.  This defines a mapping from
// register name to register number.

#define GET_REGINFO_ENUM
#include "ISSnakeGenRegisterInfo.inc"

// Defines symbolic names for the ISSnake instructions.
#define GET_INSTRINFO_ENUM
#include "ISSnakeGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ISSNAKE_MCTARGETDESC_ISSNAKEMCTARGETDESC_H

