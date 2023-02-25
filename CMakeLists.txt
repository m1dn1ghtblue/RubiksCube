cmake_minimum_required(VERSION 3.22)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 23)

add_executable(RubiksCube main.cpp Cube.h Cubie.h Cubie.cpp Cube.cpp)
