#pragma once
#include "../Cube/Cube.h"

class GeneticSolver {
private:
    const unsigned int MAX_FITNESS = 20; // 20 of 26 cubies are movable
    Cube cube;

public:
    explicit GeneticSolver(const Cube& cube);
    static unsigned int fitness(const Cube& cubeState);

};
