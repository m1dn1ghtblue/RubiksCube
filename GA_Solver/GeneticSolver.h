#pragma once
#include "../Cube/Cube.h"
#include "../Cube/SequenceParser.h"
#include <vector>
#include <string>

class GeneticSolver {
private:
    const unsigned int MAX_FITNESS = 20; // 20 of 26 cubies are movable
    const unsigned int POPULATION_SIZE = 400;
    const unsigned int ELITE_COUNT = 50;
    const unsigned int POPULATION_LIMIT = 200;

    Cube originalCube;
    SequenceParser parser;

    std::vector<std::string> moves;
    std::vector<std::string> orientations;
    std::vector<std::string> combos;

    int current_population;
    void perform_random_move(Cube& cube);
    void perform_random_orientation(Cube& cube);
    void perform_random_combo(Cube& cube);
    void evolve();

public:
    explicit GeneticSolver(const Cube& cube);
    static unsigned int fitness(const Cube& cubeState);
    std::string solve();
};
