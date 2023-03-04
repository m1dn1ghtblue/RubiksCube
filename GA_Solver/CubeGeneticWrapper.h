#pragma once

#include <string>
#include "../Cube/Cube.h"
#include "../Cube/SequenceParser.h"

struct CubeGeneticWrapper {
    Cube cube;
    std::string gene;

    explicit CubeGeneticWrapper(const Cube& origin);
    CubeGeneticWrapper(const CubeGeneticWrapper& other);
    CubeGeneticWrapper& operator=(const CubeGeneticWrapper& other);

    void append_gene(const std::string& sequence);
};