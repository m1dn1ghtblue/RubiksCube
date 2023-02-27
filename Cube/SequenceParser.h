#pragma once

#include <unordered_map>
#include "Cube.h"

enum Command {
    U_CW, U_CCW, U_2,
    D_CW, D_CCW, D_2,
    L_CW, L_CCW, L_2,
    R_CW, R_CCW, R_2,
    F_CW, F_CCW, F_2,
    B_CW, B_CCW, B_2
};

class SequenceParser {
private:
    std::unordered_map<std::string, Command> commands;

public:
    SequenceParser();

    void perform_sequence(Cube& cube, const std::string& sequence);
    void perform_command(Cube& cube, const std::string& command);
};