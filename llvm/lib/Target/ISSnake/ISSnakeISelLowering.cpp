#include "ISSnakeISelLowering.h"
#include "ISSnake.h"
#include "ISSnakeRegisterInfo.h"
#include "ISSnakeSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "ISSnake-lower"

using namespace llvm;

ISSnakeTargetLowering::ISSnakeTargetLowering(const TargetMachine &TM,
                                             const ISSnakeSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  ISSNAKE_DUMP_RED
  addRegisterClass(MVT::i32, &ISSnake::GPRRegClass);
}

const char *ISSnakeTargetLowering::getTargetNodeName(unsigned Opcode) const {
  ISSNAKE_DUMP_RED
  switch (Opcode) {
  case ISSnakeISD::CALL:
    return "ISSnakeISD::CALL";
  case ISSnakeISD::RET:
    return "ISSnakeISD::RET";
  }
  return nullptr;
}
