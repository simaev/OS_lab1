cmake_minimum_required(VERSION 3.10)
project(OS_Lab1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Creator lab1_creator.cpp)
add_executable(Reporter lab1_reporter.cpp)
add_executable(Main lab1_main.cpp)