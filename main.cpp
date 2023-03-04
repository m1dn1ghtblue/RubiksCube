#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"
#include "Cube/SequenceParser.h"

int main() {
    Cube cube;
    CubeCLI cli;
    cli.print_cube(cube);
    SequenceParser::perform_sequence(cube, "x F y B z U");
    cli.print_cube(cube);
    return 0;
}