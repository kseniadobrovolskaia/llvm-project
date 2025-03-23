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

const MCPhysReg *
ISSnakeRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ISSNAKE_DUMP_GREEN
  return CSR_ISSnake_SaveList;
}

BitVector
ISSnakeRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ISSNAKE_DUMP_GREEN
  ISSnakeFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(ISSnake::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(ISSnake::R2);
  }
  return Reserved;
}

bool ISSnakeRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool ISSnakeRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                              int SPAdj, unsigned FIOperandNum,
                                              RegScavenger *RS) const {
  ISSNAKE_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register
ISSnakeRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ISSNAKE_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? ISSnake::R2 : ISSnake::R1;
}

const uint32_t *
ISSnakeRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                          CallingConv::ID CC) const {
  ISSNAKE_DUMP_GREEN
  return CSR_ISSnake_RegMask;
}
