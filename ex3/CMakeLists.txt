cmake_minimum_required(VERSION 3.12)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Code_Skeleton)
include_directories(Code_Skeleton/Part1)
include_directories(Code_Skeleton/Part2)

add_executable(ex3
        Code_Skeleton/Part1/Headers.hpp
        Code_Skeleton/Part1/PCQueue.hpp
        Code_Skeleton/Part1/Semaphore.hpp)
