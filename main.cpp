#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"

int main() {
    Cube cube;
    GeneticSolver solver(cube);
    std::cout << GeneticSolver::fitness(cube);
    std::cout << "\n";
    cube.turn_F2();
    cube.turn_B();
    cube.turn_R();
    cube.turn_U();
    std::cout << GeneticSolver::fitness(cube);
    return 0;
}