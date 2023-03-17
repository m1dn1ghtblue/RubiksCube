#include "GeneticSolver.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <chrono>

GeneticSolver::GeneticSolver(const Cube &cube) : originalCube(cube) {
    std::srand(std::time(nullptr));

    populationNumber = 0;
    worldNumber = 0;

    population.resize(POPULATION_SIZE, CubeGeneticWrapper(originalCube));

    mutationTypes = {'A' , 'B', 'C', 'D'};

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

    combos_1 = {"U' L' U L U F U' F'",
              "U R U' R' U' F' U F",
              "R U2 R' U R U' R'",
              "R U R' U'",
              "R U B' R x' U x2 R2 x' U' R' F R F'",
              "y L' R2 B R' B L U2' L' B M'",
              "R U R' U R' F R F' U2 R' F R F'",
              "R' U2 F R U R' U' y' R2 U2 x' R U",
              "R' F R F' U2 R' F R y' R2 U2 R",
              "R' U2 x R' U R U' y R' U' R' U R' F",
              "M' U2 M U2 M' U M U2 M' U2 M",
              "F R U R' U y' R' U2 R' F R F'",
              "R' U' y L' U L' y' L F L' F R",
              "F U R U' R' U R U' R' F'",
              "R U' y R2 D R' U2 R D' R2 D E R'",
              "L' B' L U' R' U R U' R' U R L' B L",
              "L U' R' U L' U R U R' U R",
              "L' U R U' L U R'",
              "R' F' L F R F' L' F",
              "R' F' L' F R F' L F",
              "R U R' U R U' R' U R U2 R'",
              "R' U2 R U R' U R",
              "R2 D R' U2 R D' R' U2 R'",
              "M' U' M U2' M' U' M",
              "L' R U R' U' L R' F R F'",
              "L F R' F R F2 L'",
              "R' U' R y' x' R U' R' F R U R'",
              "F R U R' U' R U R' U' F'",
              "F R' F' R U R U' R'",
              "U' R U2' R' U' R U' R2 y' R' U' R U B",
              "L F' L' F U2 L2 y' L F L' F",
              "U' R' U2 R U R' U R2 y R U R' U' F'",
              "R' U2 x' R R U' R' U x R' U2 R",
              "R' F R' F' R2 U2 x' U' R U R'",
              "x L U2 R' U' R U' x' L'",
              "F' L' U' L U L' U' L U F",
              "R' F R F' U2 R2 y R' F' R F'",
              "R U R' y R' F R U' R' F' R",
              "U2 x L R2' U' R U' R' U2 R U' M",
              "L' B' L U' R' U R L' B L",
              "x' U' R U' R2' F x R U R' U' R B2",
              "L U' y' R' U2' R' U R U' R U2 R D' E' L'",
              "R2' U R' B' R U' R2' U R x' U R' x",
              "U2 R' x L2 U L' U L U2 L' U M",
              "x' L' U2 R U R' U x L",
              "R U x' R U' R' U x U' R'",
              "R U R' U' x D' R' U R E'",
              "R' F R U R' F' R y L U' L'",
              "L' B' L R' U' R U L' B L",
              "L F' L' U' L F L' y' R' U R",
              "R B R' L U L' U' R B' R'",
              "F U R U' R' F'",
              "L D E R' D' E' L' U L F L'",
              "R' D' E' L D E R U' R' F' R",
              "F' U' L' U L F",
              "F R U R' U' F'",
              "R U R' U' R' F R F'",
              "L U L' U L U' L' U' y2' R' F R F'",
              "R' U' R U' R' U R U y F R' F' R",
              "R' F R U R' U' y L' D E R",
              "L F' L' U' L U y' R D' E' L'",
              "x R' U R' D2 R U' R' D2 R2",
              "x' R U' R D2 R' U R D2 R2",
              "R2 U R U R' U' R' U' R' U R'",
              "R U' R U R U R U' R' U' R2",
              "M2 U M2 U2 M2 U M2",
              "R U R' U' R' F R2 U' R' U' R U R' F'",
              "R' U L' U2 R U' R' U2 R L U'",
              "R U R' F' R U R' U' R' F R2 U' R' U'",
              "L U2' L' U2' L F' L' U' L U L F L2' U",
              "R' U2 R U2 R' F R U R' U' R' F' R2 U'",
              "R' U R' d' R' F' R2 U' R' U R' F R F",
              "R2 y D R' U R' U' R y' D' R2 y' R' U R",
              "R' U' R y R2 y D R' U R U' R y' D' R2",
              "R2 y' D' R U' R U R' y D R2 y R U' R'",
              "R U R' y' R2 y' D' R U' R' U R' y D R2",
              "R' U2 R' D' E' R' F' R2 U' R' U R' F R U' F",
              "F R U' R' U' R U R' F' R U R' U' R' F R F'",
              "x' R U' R' D R U R' y2 D2 R' U R D R' U' R"
    };

    combos_2 = {
              "F' L' B' R' U' R U' B L F R U R' U",
              "F R B L U L' U B' R' F' L' U' L U'",
              "R' U L' U2 R U' L R' U L' U2 R U' L U'",
              "U2 B U2 B' R2 F R' F' U2 F' U2 F R'",
              "U2 R U2 R' F2 L F' L' U2 L' U2 L F'",
              "U' B2 D2 L' F2 D2 B2 R' U'",
              "U B2 D2 R F2 D2 B2 L U",
              "D' R' D R2 U' R B2 L U' L' B2 U R2",
              "D L D' L2 U L' B2 R' U R B2 U' L2",
              "F' U B U' F U B' U'",
              "F U' B' U F' U' B U",
              "L' U2 L R' F2 R",
              "L U' R U2 L' U R' L U' R U2 L' U R' U",
              "M2 U M2 U M' U2 M2 U2 M' U2",
              "R' U2 R L' B2 L"
              };
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
    std::string move = get_random_element(moves, moves.size());
    SequenceParser::perform_command(cubeWrapper.cube, move);
    cubeWrapper.append_gene(move);
}

void GeneticSolver::perform_random_orientation(CubeGeneticWrapper &cubeWrapper) {
    std::string orientation = get_random_element(orientations, orientations.size());
    SequenceParser::perform_command(cubeWrapper.cube, orientation);
    cubeWrapper.append_gene(orientation);
}

void GeneticSolver::perform_random_combo(CubeGeneticWrapper &cubeWrapper) {
    std::string combo;
    if (rand() % 2) combo = get_random_element(combos_1, combos_1.size());
    else combo = get_random_element(combos_2, combos_2.size());

    SequenceParser::perform_sequence(cubeWrapper.cube, combo);
    cubeWrapper.append_gene(combo);
}

std::string GeneticSolver::solve() {
    auto time_start = std::chrono::high_resolution_clock::now();
    while (fitness(population[0].cube) != MAX_FITNESS) {
        if (populationNumber % POPULATION_LIMIT == 0) {
            worldNumber++;
            std::cerr << "started world: " << worldNumber << "\n";
            populationNumber = 0;
            std::fill(population.begin(), population.end(), CubeGeneticWrapper(originalCube));
        }

        evolve();
    }
    std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - time_start;

    std::cerr << "solution found on world: " << worldNumber << " population: " << populationNumber << " in " << duration.count() << "s\n";
    return population[0].gene;
}

void GeneticSolver::evolve() {
    std::sort(population.begin(), population.end(), [](const CubeGeneticWrapper &lhs, const CubeGeneticWrapper &rhs) {
        auto lhsFitness = GeneticSolver::fitness(lhs.cube);
        auto rhsFitness = GeneticSolver::fitness(rhs.cube);
        if (lhsFitness == rhsFitness) {
            return lhs.gene.size() < rhs.gene.size();
        }
        return lhsFitness > rhsFitness;
    });

    for (size_t i = ELITE_COUNT; i < population.size(); ++i) {
        population[i] = get_random_element(population, ELITE_COUNT);
        mutate(population[i]);
    }

    populationNumber++;
}

template<typename T>
T GeneticSolver::get_random_element(std::vector<T> v, size_t limit) {
    return v[rand() % limit];
}

void GeneticSolver::mutate(CubeGeneticWrapper &cubeWrapper) {
    switch (get_random_element(mutationTypes, mutationTypes.size())) {
        case 'A':
            perform_random_move(cubeWrapper);
            break;

        case 'B':
            perform_random_combo(cubeWrapper);
            break;

        case 'C':
            perform_random_orientation(cubeWrapper);
            perform_random_move(cubeWrapper);
            break;

        case 'D':
            perform_random_orientation(cubeWrapper);
            perform_random_combo(cubeWrapper);
            break;

        default:
            break;
    }
}


