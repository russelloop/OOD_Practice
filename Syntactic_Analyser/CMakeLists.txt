cmake_minimum_required(VERSION 3.10)
project(Syntactic_Analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(Syntactic_Analyser main.c cmake-build-debug/Analyser.c cmake-build-debug/Lexical_ANA.c)