cmake_minimum_required(VERSION 3.13)
project(untitled C)

set(CMAKE_C_STANDARD 99)

target_link_libraries(<math.h> m)
add_executable(untitled main.c)