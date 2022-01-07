cmake_minimum_required(VERSION 3.13)
project(base_converter C)

set(CMAKE_C_STANDARD 99)

add_executable(base_converter main.c)
target_link_libraries(base_converter m)