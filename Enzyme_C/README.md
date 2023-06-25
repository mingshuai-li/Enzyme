# Run the C scripts
To Run these examples, you can just use make in each example (Replace the path of ClangEnzyme-12.so and LLDEnzyme-12.so in Makefile with the path on your local machine).
You can also use command, such as:
```shell
clang test.c -S -emit-llvm -o input.ll -O2 -fno-vectorize -fno-slp-vectorize -fno-unroll-loops
```
