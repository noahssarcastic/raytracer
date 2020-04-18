cmake_minimum_required(VERSION 3.16)
project(. VERSION 1.0)

add_compile_options(-Wall -Wextra -Wpedantic)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)