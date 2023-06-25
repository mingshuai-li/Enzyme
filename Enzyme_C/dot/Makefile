all: dot.o

clean:
        rm -f *.o *.ll

%.o: %.c
        clang-12 $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@

run-%: %.o
        ./$^
