#pragma once
#include "Cube.h"
#include "SequenceParser.h"
#include "CubeGeneticWrapper.h"
#include <vector>
#include <string>

class GeneticSolver {
private:
    const unsigned int MAX_FITNESS = 20; // 20 of 26 cubies are movable
    const unsigned int POPULATION_SIZE = 200;
    const unsigned int ELITE_COUNT = 20;
    const unsigned int POPULATION_LIMIT = 300;

    const Cube originalCube;

    std::vector<std::string> moves;
    std::vector<std::string> orientations;
    std::vector<std::string> combos_1;
    std::vector<std::string> combos_2;

    std::vector<char> mutationTypes;
    std::vector<CubeGeneticWrapper> population;

    unsigned int populationNumber;
    unsigned int worldNumber;

    void perform_random_move(CubeGeneticWrapper& cubeWrapper);
    void perform_random_orientation(CubeGeneticWrapper& cubeWrapper);
    void perform_random_combo(CubeGeneticWrapper& cubeWrapper);
    void evolve();
    void mutate(CubeGeneticWrapper& cubeWrapper);

    template<typename T> T get_random_element(std::vector<T> v, size_t limit);

public:
    explicit GeneticSolver(const Cube& cube);
    static unsigned int fitness(const Cube& cubeState);
    std::string solve();
};
