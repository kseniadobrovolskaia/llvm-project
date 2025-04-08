let TargetPrefix = "issnake" in {  // All intrinsics start with "llvm.issnake.".
 
 def int_issnake_putpixel: ClangBuiltin<"putPixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_issnake_updatescreen: ClangBuiltin<"updateScreen">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "issnake"
