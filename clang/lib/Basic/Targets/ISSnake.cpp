#include "ISSnake.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void ISSnakeTargetInfo::getTargetDefines(const LangOptions &Opts,
                                         MacroBuilder &Builder) const {
  Builder.defineMacro("__issnake__");
}

ArrayRef<Builtin::Info> ISSnakeTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
