#pragma once

#include <string>
#include "../Cube/Cube.h"

struct CubeGeneticWrapper {
    Cube cube;
    std::string gene;

    explicit CubeGeneticWrapper(const Cube& origin);
    CubeGeneticWrapper(const CubeGeneticWrapper& other);
    CubeGeneticWrapper& operator=(const CubeGeneticWrapper& other);

    void append_gene(const std::string& sequence);
};