#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"
#include "Cube/SequenceParser.h"

int main() {
    Cube cube;
    CubeCLI cli;
    SequenceParser::perform_sequence(cube, "F U2 L2 B2 F' U L2 U R2 D2 L' B L2 B' R2 U2");
    cli.print_cube(cube);

    GeneticSolver solver(cube);
    std::cout << solver.solve();
    return 0;
}