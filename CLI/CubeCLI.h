#pragma once
#include <array>
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
    SequenceParser parser;

    std::unordered_map<C_POS, std::array<char, 3>> cornerColormap;
    std::unordered_map<E_POS, std::array<char, 2>> edgeColormap;
    std::array<char, 6> surfaceColormap{};

    std::tuple<char, char> get_edge_colors(E_POS position);
    std::tuple<char, char, char> get_corner_colors(C_POS position);

public:
    CubeCLI();
    void print_cube();
    void loop();
};
