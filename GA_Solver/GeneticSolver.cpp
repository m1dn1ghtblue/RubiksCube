#include "GeneticSolver.h"
#include <ctime>
#include <vector>
#include <iostream>

GeneticSolver::GeneticSolver(const Cube &cube) : originalCube(cube) {
    std::srand(std::time(nullptr));

    current_population = 0;

    population.resize(POPULATION_SIZE, CubeGeneticWrapper(cube));

    mutationTypes = {'A' , 'B', 'C', 'D', 'E'};

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

    combos = {"R"};
}

unsigned int GeneticSolver::fitness(const Cube &cubeState) {
    unsigned int fitness = 0;
    for (int i = 0; i < 8; ++i) {
        CornerCubie corner = cubeState.getCorner(static_cast<C_POS>(i));
        if ((corner.get_original_id() == i) && (corner.get_twist_state() == 0)) {
            fitness++;
        }
    }

    for (int i = 0; i < 12; ++i) {
        EdgeCubie edge = cubeState.getEdge(static_cast<E_POS>(i));
        if ((edge.get_original_id() == i) && (edge.get_twist_state() == 0)) {
            fitness++;
        }
    }

    return fitness;
}

void GeneticSolver::perform_random_move(CubeGeneticWrapper &cubeWrapper) {
    std::string move = get_random_element(moves);
    cubeWrapper.parser.perform_command(cubeWrapper.cube, move);
    cubeWrapper.append_gene(move);
}

void GeneticSolver::perform_random_orientation(CubeGeneticWrapper &cubeWrapper) {
    std::string orientation = get_random_element(orientations);
    cubeWrapper.parser.perform_command(cubeWrapper.cube, orientation);
    cubeWrapper.append_gene(orientation);
}

void GeneticSolver::perform_random_combo(CubeGeneticWrapper &cubeWrapper) {
    std::string combo = get_random_element(combos);
    cubeWrapper.parser.perform_sequence(cubeWrapper.cube, combo);
    cubeWrapper.append_gene(combo);
}

std::string GeneticSolver::solve() {
    while (fitness(population[0].cube) != MAX_FITNESS) {
        std::cout << "population:" << current_population << " max fitness: " << fitness(population[0].cube) << "\n";
        evolve();
    }

    return population[0].gene;
}

void GeneticSolver::evolve() {
    std::sort(population.begin(), population.end(), [](const CubeGeneticWrapper &lhs, const CubeGeneticWrapper &rhs) {
        return GeneticSolver::fitness(lhs.cube) > GeneticSolver::fitness(rhs.cube);
    });

    for (size_t i = ELITE_COUNT; i < population.size(); ++i) {
        population[i] = get_random_element(population, ELITE_COUNT);
        mutate(population[i]);
    }

    current_population++;
}

template<typename T>
T GeneticSolver::get_random_element(std::vector<T> v) {
    return v[rand() % v.size()];
}

template<typename T>
T GeneticSolver::get_random_element(std::vector<T> v, size_t limit) {
    return v[rand() % limit];
}

void GeneticSolver::mutate(CubeGeneticWrapper &cubeWrapper) {
    switch (get_random_element(mutationTypes)) {
        case 'A':
            perform_random_move(cubeWrapper);
            break;

        case 'B':
            perform_random_orientation(cubeWrapper);
            break;

        case 'C':
            perform_random_combo(cubeWrapper);
            break;

        case 'D':
            perform_random_orientation(cubeWrapper);
            perform_random_move(cubeWrapper);
            break;

        case 'E':
            perform_random_orientation(cubeWrapper);
            perform_random_combo(cubeWrapper);
            break;

        default:
            break;
    }
}


