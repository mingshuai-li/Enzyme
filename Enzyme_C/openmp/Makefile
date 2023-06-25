CLANG = /home/lpaehler/Work/Dev-Tools/llvm-fortran/f18-llvm-project/build/bin/clang

LLVM_PATH = /home/lpaehler/Work/Dev-Tools/llvm-fortran/f18-llvm-project/build

ENZYME_PATH = /home/lpaehler/Work/AutomaticDifferentiation/Enzyme/build/Enzyme/LLVMEnzyme-13.so
LLVM13_PATH = /home/lpaehler/Work/AutomaticDifferentiation/llvm-project/build

all: omp_parallel_for.o

clean:
        rm -f *.o *.ll

%.o: %.c
        clang-12 $^ -O3 -Xclang -load -Xclang /Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -fopenmp -L/usr/lib/llvm-10/lib -I/usr/lib/llvm-10/include/openmp/ -o $@