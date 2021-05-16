cmake_minimum_required(VERSION 2.8)

project(poisson)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(poisson main.cpp )
