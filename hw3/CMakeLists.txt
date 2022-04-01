cmake_minimum_required(VERSION 3.20)
project(hw3 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw3 main.c hashmap.c hashfunc.c hashfunc.h hashmap.h)
