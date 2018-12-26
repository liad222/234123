cmake_minimum_required(VERSION 3.10)
project(Code_Skeleton)

set(CMAKE_CXX_STANDARD 11)

include_directories(Part1)
include_directories(Part2)

add_executable(Code_Skeleton
        Part1/Headers.hpp
        Part1/PCQueue.hpp
        Part1/Semaphore.hpp
        Part2/Game.cpp
        Part2/Game.hpp
        Part2/main.cpp
        Part2/Thread.hpp
        Part2/utils.cpp
        Part2/utils.hpp)
