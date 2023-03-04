#include "CubeGeneticWrapper.h"

CubeGeneticWrapper::CubeGeneticWrapper(const Cube &origin) : cube(origin) {
    gene = "";
}

CubeGeneticWrapper::CubeGeneticWrapper(const CubeGeneticWrapper &other) = default;

CubeGeneticWrapper &CubeGeneticWrapper::operator=(const CubeGeneticWrapper &other) {
    if (this != &other) {
        this->cube = other.cube;
        this->gene = other.gene;
    }
    return *this;
}

void CubeGeneticWrapper::append_gene(const std::string& sequence) {
    gene += sequence + " ";
}




