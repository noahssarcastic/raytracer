cmake_minimum_required(VERSION 3.16)
project(raytracer)
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")

include(CTest)
enable_testing()

include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)
include(ExternalProject)

include_directories(include)
include_directories(lib/bitmap)

add_executable(run src/main.cpp lib/bitmap/bitmap_image.hpp)

add_executable(loadbitmap test/loadbitmap.cpp lib/bitmap/bitmap_image.hpp)
add_test(loadbitmap_test loadbitmap)

#add_subdirectory(include)
#add_subdirectory(lib)
#add_subdirectory(src)
#add_subdirectory(test)