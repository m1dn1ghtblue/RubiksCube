#include "CubeGeneticWrapper.h"

CubeGeneticWrapper::CubeGeneticWrapper(const Cube &origin) : cube(origin) {
    gene = "";
    parser = SequenceParser();
}

CubeGeneticWrapper::CubeGeneticWrapper(const CubeGeneticWrapper &other) : cube(other.cube), gene(other.gene), parser(other.parser) {};

CubeGeneticWrapper &CubeGeneticWrapper::operator=(const CubeGeneticWrapper &other) {
    if (this != &other) {
        this->cube = other.cube;
        this->gene = other.gene;
        this->parser = other.parser;
    }
    return *this;
}

void CubeGeneticWrapper::append_gene(const std::string& sequence) {
    gene += sequence + " ";
}




