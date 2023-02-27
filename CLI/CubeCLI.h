#pragma once
#include <array>
#include <unordered_map>
#include <string>
#include "../Cube/Cube.h"

enum SURFACE {
    U = 0,
    L = 1,
    F = 2,
    R = 3,
    B = 4,
    D = 5
};

enum Command {
    U_CW, U_CCW, U_2,
    D_CW, D_CCW, D_2,
    L_CW, L_CCW, L_2,
    R_CW, R_CCW, R_2,
    F_CW, F_CCW, F_2,
    B_CW, B_CCW, B_2
};

class CubeCLI {
private:
    Cube cube;

    std::unordered_map<std::string, Command> commands;
    std::unordered_map<C_POS, std::array<char, 3>> cornerColormap;
    std::unordered_map<E_POS, std::array<char, 2>> edgeColormap;
    std::array<char, 6> surfaceColormap{};

    std::tuple<char, char> get_edge_colors(E_POS position);
    std::tuple<char, char, char> get_corner_colors(C_POS position);

public:
    CubeCLI();
    void print_cube();
    void perform_sequence(const std::string& sequence);
    void perform_command(const std::string& command);
};
