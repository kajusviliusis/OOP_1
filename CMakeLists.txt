cmake_minimum_required(VERSION 4.1)
project(OOP_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_1
        main.cpp
        my_lib.cpp
        my_lib.h)
