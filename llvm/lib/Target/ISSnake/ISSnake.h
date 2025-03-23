#ifndef LLVM_LIB_TARGET_ISSnake_ISSnake_H
#define LLVM_LIB_TARGET_ISSnake_ISSnake_H

#include "MCTargetDesc/ISSnakeMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define ISSNAKE_DUMP(Color)                                                    \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ISSNAKE_DUMP(Color) {}

#define ISSNAKE_DUMP_RED ISSNAKE_DUMP(llvm::raw_ostream::RED)
#define ISSNAKE_DUMP_GREEN ISSNAKE_DUMP(llvm::raw_ostream::GREEN)
#define ISSNAKE_DUMP_YELLOW ISSNAKE_DUMP(llvm::raw_ostream::YELLOW)
#define ISSNAKE_DUMP_CYAN ISSNAKE_DUMP(llvm::raw_ostream::CYAN)
#define ISSNAKE_DUMP_MAGENTA ISSNAKE_DUMP(llvm::raw_ostream::MAGENTA)
#define ISSNAKE_DUMP_WHITE ISSNAKE_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class ISSnakeTargetMachine;
class FunctionPass;
class ISSnakeSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerISSnakeMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                      AsmPrinter &AP);
bool LowerISSnakeMachineOperandToMCOperand(const MachineOperand &MO,
                                           MCOperand &MCOp,
                                           const AsmPrinter &AP);
FunctionPass *createISSnakeISelDag(ISSnakeTargetMachine &TM,
                                   CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_ISSnake_ISSnake_H
