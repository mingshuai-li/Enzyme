# Run the C scripts
To Run these examples, you can just use make in each example. You should replace the path of ClangEnzyme-12.so and LLDEnzyme-12.so in Makefile with the path on your local machine, such as:
```shell
all: square.o

clean:
        rm -f *.o *.ll

%.o: %.c
        clang-12 $^ -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o $@
```
You can also use command, such as:
```shell
clang-12 square.c -O3 -Xclang -load -Xclang /home/vscode/Enzyme/enzyme/build/Enzyme/ClangEnzyme-12.so -ffast-math -o square.o
```
Besides, there are many arguments you can change, which can help you understand how Enzyme works on LLVM. For more details, see [UsingEnzyme](https://enzyme.mit.edu/getting_started/UsingEnzyme/)
