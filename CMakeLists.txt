cmake_minimum_required(VERSION 3.28)
project(MazeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MazeProject main.cpp
        maze.h
        maze.cpp)
