all: lib.exe

clean:
        rm -f *.o *.ll *.exe

%.o: %.c
        clang-12 -c -fuse-ld=lld -flto $^ -O2 -ffast-math -o $@

lib.exe: myblas.o multisource.o
        clang-12 -fuse-ld=lld -flto ./myblas.o ./multisource.o -O2 -ffast-math -o $@ -Wl,-mllvm=-load=/home/vscode/Enzyme/enzyme/build/Enzyme/LLDEnzyme-12.so

run-%: %.exe
        ./$^ 3