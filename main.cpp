#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"
#include "Cube/SequenceParser.h"

int main() {
    Cube cube;
    CubeCLI cli;
    SequenceParser::perform_sequence(cube, "U R U' x R' U L'  y M S");
    cli.print_cube(cube);

    GeneticSolver solver(cube);
    std::cout << solver.solve();
    return 0;
}