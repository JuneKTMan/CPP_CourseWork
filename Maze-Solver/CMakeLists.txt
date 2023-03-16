cmake_minimum_required(VERSION 3.24)
project(ASSIGN2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

add_executable(ASSIGN1 src/main.cpp src/container.cpp inc/container.hpp inc/node.hpp)
