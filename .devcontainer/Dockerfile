# syntax=docker/dockerfile:1
FROM mcr.microsoft.com/devcontainers/base:jammy

# C and C++ development tools and utilities:
#   build-essential : GCC, G++, make, and other essential build tools
#   gdb             : GNU Debugger for C/C++
#   valgrind        : Memory error detector
#   clang           : Clang C/C++ compiler (provides clang++)
#   lldb            : LLVM Debugger
#   llvm            : LLVM toolchain (required for lldb/clang)
#   make            : Build automation tool (Makefiles)
#   git             : Version control system
#   pkg-config      : Manage compile/link flags for libraries
#   man             : Manual pages
#   less            : Pager for viewing text files
#   vim             : Text editor
#   cppcheck        : Static analysis for C/C++
#   lcov            : Code coverage tool
#   gcovr           : Coverage reports for GCC
#   doxygen         : Documentation generator for C/C++

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y --no-install-recommends \
        build-essential \
        gdb \
        valgrind \
        clang \
        lldb \
        llvm \
        make \
        git \
        pkg-config \
        man \
        less \
        vim \
        cppcheck \
        lcov \
        gcovr \
        doxygen \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Note: Avoid installing python3-clang-* packages due to dependency conflicts on Ubuntu Jammy.

