#include "Cube.h"
#include "GeneticSolver.h"
#include "SequenceParser.h"
#include <iostream>

int main() {
    Cube cube;
    SequenceParser::perform_sequence(cube, "U x B' R2 E U' F E L2");

    GeneticSolver solver(cube);
    std::cout << solver.solve();

    return 0;
}