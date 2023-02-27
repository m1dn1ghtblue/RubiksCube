#pragma once

#include <unordered_map>
#include "Cube.h"

enum COMMAND { U, B, L, R, D, F, X, Y, Z, M, E, S };

class SequenceParser {
private:
    std::unordered_map<char, COMMAND> commands;

    void orient_x();
    void orient_y();
    void orient_z();

    void slice_m(Cube& cube);
    void slice_e(Cube& cube);
    void slice_s(Cube& cube);
public:
    SequenceParser();

    void perform_sequence(Cube& cube, const std::string& sequence);
    void perform_command(Cube& cube, const std::string& command);
};