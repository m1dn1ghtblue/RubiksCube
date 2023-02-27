#include <iostream>
#include "Cube/Cube.h"
#include "CLI/CubeCLI.h"
#include "GA_Solver/GeneticSolver.h"

int main() {
    CubeCLI cli;
    cli.loop();
    return 0;
}