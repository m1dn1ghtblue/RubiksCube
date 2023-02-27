cmake_minimum_required(VERSION 3.22)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 23)
add_executable(RubiksCube main.cpp Cube/Cube.h Cube/Cubie.h Cube/Cubie.cpp Cube/Cube.cpp CLI/CubeCLI.cpp CLI/CubeCLI.h GA_Solver/GeneticSolver.cpp GA_Solver/GeneticSolver.h)
