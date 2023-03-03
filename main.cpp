#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"
#include "Cube/SequenceParser.h"

int main() {
    Cube cube;
    CubeCLI cli;
    SequenceParser parser;
    parser.perform_sequence(cube, "F R' U B'");
    GeneticSolver solver(cube);

    std::cout << solver.solve() << "\n";
    return 0;
}