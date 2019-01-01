cmake_minimum_required(VERSION 3.10)
project(ex3)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex3
        Code_Skeleton/Part1/Headers.hpp
        Code_Skeleton/Part1/PCQueue.hpp
        Code_Skeleton/Part1/Semaphore.hpp
        Code_Skeleton/Part2/Game.cpp
        Code_Skeleton/Part2/Game.hpp
        Code_Skeleton/Part2/main.cpp
        Code_Skeleton/Part2/Thread.hpp
        Code_Skeleton/Part2/utils.cpp
        Code_Skeleton/Part2/utils.hpp
        Code_Skeleton/makefile)