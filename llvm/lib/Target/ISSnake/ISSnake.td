include "llvm/Target/Target.td"
include "ISSnakeRegisterInfo.td"
include "ISSnakeInstrInfo.td"
 
class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;
def : Proc<"generic", []>;

def ISSnakeInstrInfo : InstrInfo;
def ISSnake : Target {
  let InstructionSet = ISSnakeInstrInfo;
}

