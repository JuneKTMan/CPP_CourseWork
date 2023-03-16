cmake_minimum_required(VERSION 3.24)
project(ASSIGN1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

add_executable(ASSIGN1 src/main.cpp src/linked_list.cpp inc/linked_list.hpp inc/node.hpp)
