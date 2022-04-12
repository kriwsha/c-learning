cmake_minimum_required(VERSION 3.20)
project(hw2 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw2 main.c koi8.h koi8.c cp1251.h cp1251.c iso88595.h iso88595.c utf8.h utf8.c)
