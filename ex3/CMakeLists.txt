cmake_minimum_required(VERSION 3.12)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3
        Code_Skeleton/Headers.hpp
        Code_Skeleton/PCQueue.hpp
        Code_Skeleton/Semaphore.hpp
        Code_Skeleton/Game.cpp
        Code_Skeleton/Game.hpp
        Code_Skeleton/Job.hpp
        Code_Skeleton/main.cpp
        Code_Skeleton/Thread.hpp
        Code_Skeleton/utils.cpp
        Code_Skeleton/utils.hpp
        Code_Skeleton/makefile)