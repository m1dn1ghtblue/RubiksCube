#include "GeneticSolver.h"
#include <random>
#include <ctime>
#include <vector>

GeneticSolver::GeneticSolver(const Cube& cube) : originalCube(cube) {
    parser = SequenceParser();
    current_population = 0;

    population.resize(POPULATION_SIZE, CubeGeneticWrapper(cube));

    moves = {"U", "U'", "U2",
             "D", "D'", "D2",
             "B", "B'", "B2",
             "F", "F'", "F2",
             "L", "L'", "L2",
             "R", "R'", "R2",
             "M", "M'", "M2",
             "E", "E'", "E2",
             "S", "S'", "S2"};

    orientations = {"x", "x'", "x2",
                  "y", "y'", "y2",
                  "z", "z'", "z2"};

    combos = {"R U R' U'"};
}

unsigned int GeneticSolver::fitness(const Cube &cubeState) {
    unsigned int fitness = 0;
    for (int i = 0; i < 8; ++i) {
        CornerCubie corner = cubeState.getCorner(static_cast<C_POS>(i));
        if (corner.get_original_id() == i && corner.get_twist_state() == 0) {
            fitness++;
        }
    }

    for (int i = 0; i < 12; ++i) {
        EdgeCubie edge = cubeState.getEdge(static_cast<E_POS>(i));
        if (edge.get_original_id() == i && edge.get_twist_state() == 0) {
            fitness++;
        }
    }

    return fitness;
}

void GeneticSolver::perform_random_move(Cube& cube) {
    std::srand(std::time(0));
    std::string move = moves[std::rand() % moves.size()];
    parser.perform_command(cube, move);
}

void GeneticSolver::perform_random_orientation(Cube& cube) {
    std::srand(std::time(0));
    std::string orientation = orientations[std::rand() % orientations.size()];
    parser.perform_command(cube, orientation);
}

void GeneticSolver::perform_random_combo(Cube& cube) {
    std::srand(std::time(0));
    std::string combo = combos[std::rand() % combos.size()];
    parser.perform_sequence(cube, combo);
}

std::string GeneticSolver::solve() {
    //TODO implement solve method
    throw "Not implemented";
}

void GeneticSolver::evolve() {
    //TODO implement evolve method
    throw "Not implemented";
}


