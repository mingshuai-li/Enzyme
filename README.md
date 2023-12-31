# Enzyme
This repository contains a set of examples about how to use Enzyme in different languages and some benchmarks.

## Overview
Enzyme is a tool that takes arbitrary existing code as LLVM IR and computes the derivative (and gradient) of that function.
All of the examples based on the Enzyme, which is a plugin for LLVM. If you want to look into the code, you can click [Enzyme](https://github.com/EnzymeAD/Enzyme) or 
```shell
git clone https://github.com/EnzymeAD/Enzyme
cd Enzyme
```
If you have Homebrew or spack, you can also use
```shell
brew install enzyme
```
```shell
spack install enzyme
```

## Installation
Enzyme supprts multiple languages. We show C, Julia, and Rust here.

### C
To install Enzyme, you should first build [LLVM](https://llvm.org/docs/GettingStarted.html). Then build Enzyme with follows:
```shell
cd /path/to/Enzyme/enzyme
mkdir build && cd build
cmake -G Ninja .. -DLLVM_DIR=/path/to/llvm/lib/cmake/llvm -DLLVM_EXTERNAL_LIT=/path/to/lit/lit.py
ninja
```
If you don't want to install LLVM on your local machine, you can just use docker and build on it:
```shell
docker pull ghcr.io/enzymead/enzyme-dev-docker/ubuntu-20-llvm-12:latest
```
### Julia
Enzyme.jl can be installed in the usual way Julia packages are installed:
```shell
] add Enzyme
```


### Rust
The developers of Enzyme provide a repository for Rust. It contains the compiler, standard library, and documentation. And It is modified to use Enzyme for AutoDiff. For details you can look into [Enzyme_Rust](https://github.com/EnzymeAD/rust). The installation may take several hours and I just test several examples.

## Run the scripts
For each language, please see the README in corresponding folder.

## References
All the content is based on [Enzyme](enzyme.mit.edu) and its relevant github(can access via the website).
