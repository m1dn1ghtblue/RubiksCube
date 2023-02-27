#include "GeneticSolver.h"

GeneticSolver::GeneticSolver(const Cube& cube) : cube(cube) {

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
