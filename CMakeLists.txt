cmake_minimum_required(VERSION 3.1)
project(OOP_1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(OOP_1
        main.cpp
        my_lib.cpp
        my_lib.h)
