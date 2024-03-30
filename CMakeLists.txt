cmake_minimum_required(VERSION 3.27)
project(Perceptron)

set(CMAKE_CXX_STANDARD 23)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-march=native)
endif ()

add_executable(Perceptron main.cpp)
