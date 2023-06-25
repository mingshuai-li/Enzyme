all: norm-O2enzyme.o norm-enzymeO2.o norm-O2enzyme.ll norm-enzymeO2.ll norm-unopt.ll

clean:
        rm -f *.o *.ll

%-unopt.ll: %.c
         clang-12 $^ -O1 -Xclang -disable-llvm-passes -fno-vectorize -fno-slp-vectorize -ffast-math -fno-unroll-loops -o $@ -S -emit-llvm

%-enzymeO2.ll: %-unopt.ll
        opt-12 $^ -load /home/vscode/Enzyme/enzyme/build/Enzyme/LLVMEnzyme-12.so -enzyme -O2 -o $@ -S

%-O2enzyme.ll: %-unopt.ll
        opt-12 $^ -load /home/vscode/Enzyme/enzyme/build/Enzyme/LLVMEnzyme-12.so -O2 -enzyme -o $@ -S

%.o: %.ll
        clang-12 -O2 $^ -o $@ -lm

run-%: %.o
        ./$^ 2000
~                                                                                                                                               ~                      