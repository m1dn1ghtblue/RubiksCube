#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "../Cube/Cube.h"
#include "../Cube/SequenceParser.h"

enum SURFACE {
    U_SURFACE = 0,
    L_SURFACE = 1,
    F_SURFACE = 2,
    R_SURFACE = 3,
    B_SURFACE = 4,
    D_SURFACE = 5
};

class CubeCLI {
private:
    Cube cube;

    std::unordered_map<C_POS, std::array<char, 3>> cornerColormap;
    std::unordered_map<E_POS, std::array<char, 2>> edgeColormap;
    std::vector<char> surfaceColormap;

    std::tuple<char, char> get_edge_colors(E_POS position, const Cube& cube);
    std::tuple<char, char, char> get_corner_colors(C_POS position, const Cube& cube);

public:
    CubeCLI();
    void print_cube(const Cube& cube);
    void print_cube();
    void loop();
};
