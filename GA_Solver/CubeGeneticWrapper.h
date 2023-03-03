#pragma once

#include <string>
#include "../Cube/Cube.h"

class CubeGeneticWrapper {
private:
    Cube cube;
    std::string gene;

public:
    explicit CubeGeneticWrapper(const Cube& origin);
    CubeGeneticWrapper(const CubeGeneticWrapper& other);
    CubeGeneticWrapper& operator=(const CubeGeneticWrapper& other);

    void append_gene(const std::string& sequence);
    std::string get_gene();
};