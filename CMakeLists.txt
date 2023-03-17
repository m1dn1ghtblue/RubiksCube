cmake_minimum_required(VERSION 3.22)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES main.cpp Cube/Cube.h Cube/Cubie.h Cube/Cubie.cpp Cube/Cube.cpp CLI/CubeCLI.cpp CLI/CubeCLI.h GA_Solver/GeneticSolver.cpp GA_Solver/GeneticSolver.h Cube/SequenceParser.cpp Cube/SequenceParser.h GA_Solver/CubeGeneticWrapper.cpp GA_Solver/CubeGeneticWrapper.h Graphics/Scene.cpp Graphics/Scene.h Graphics/GraphicException.cpp Graphics/GraphicException.h)

add_compile_definitions(GLEW_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/Cube ${PROJECT_SOURCE_DIR}/GA_Solver)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/GLFW/include)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/GLEW/include)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/vendor)

link_directories(${PROJECT_SOURCE_DIR}/dependencies/GLFW/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/dependencies/GLEW/lib)

add_executable(RubiksCube ${SOURCE_FILES})

target_link_libraries(RubiksCube glew32s glfw3 opengl32)
