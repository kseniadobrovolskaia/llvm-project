include "llvm/Target/Target.td"
include "ISSnakeRegisterInfo.td"
include "ISSnakeInstrInfo.td"
 
def ISSnakeInstrInfo : InstrInfo;
def ISSnake : Target {
  let InstructionSet = ISSnakeInstrInfo;
}

