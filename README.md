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
If you don't want to install LLVM on your local machine, you can just use docker:
```shell
docker pull ghcr.io/enzymead/enzyme-dev-docker/ubuntu-20-llvm-12:latest
```
