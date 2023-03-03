//
// Created by Ilya on 03/03/2023.
//

#include "CubeGeneticWrapper.h"

CubeGeneticWrapper::CubeGeneticWrapper(const Cube &origin) : cube(origin) {
    gene = "";
}

CubeGeneticWrapper::CubeGeneticWrapper(const CubeGeneticWrapper &other) : cube(other.cube), gene(other.gene) {};

CubeGeneticWrapper &CubeGeneticWrapper::operator=(const CubeGeneticWrapper &other) {
    if (this != &other) {
        this->cube = other.cube;
        this->gene = other.gene;
    }
    return *this;
}

void CubeGeneticWrapper::append_gene(const std::string& sequence) {
    gene = gene + " " + sequence;
}

std::string CubeGeneticWrapper::get_gene() {
    return gene;
}




