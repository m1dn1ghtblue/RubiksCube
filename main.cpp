#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"
#include "Cube/SequenceParser.h"

int main() {
    Cube cube;
    CubeCLI cli;
    SequenceParser parser;
    parser.perform_sequence(cube, "B2 R' U R B2 U' L2 R' U L' U2 R U' L R' U L' U2 R U' L U R U2 R' F2 L F' L' U2 L' U2 L F' L' U2 L R' F2 R U B2 F2 D2 B2 L");
    GeneticSolver solver(cube);

    std::cout << solver.solve() << "\n";
    return 0;
}