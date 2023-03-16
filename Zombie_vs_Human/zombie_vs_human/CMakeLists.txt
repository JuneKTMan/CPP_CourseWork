cmake_minimum_required(VERSION 3.21)
project(zombie_vs_human)

set(CMAKE_CXX_STANDARD 14)

add_executable(zombie_vs_human main.cpp city.cpp city.h organism.cpp organism.h zombie.cpp zombie.h human.cpp human.h gobalVar.h)
