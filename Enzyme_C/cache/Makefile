all: cache-alias.o cache-noalias.o

clean:
        rm -f *.o *.ll

%-alias.o: %.c
        clang-12 -Rpass=enzyme $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@

%-noalias.o: %.c
        clang-12 -Rpass=enzyme -DNOALIAS=1 $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@

run-%: %.o
        ./$^