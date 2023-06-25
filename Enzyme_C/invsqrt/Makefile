all: invsqrt-custom.o

clean:
        rm -f *.o *.ll

%-nocustom.o: %.c
        clang-12 $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@

%-custom.o: %.c
        clang-12 -DCUSTOM=1 $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@

run-%: %.o
        ./$^ 3