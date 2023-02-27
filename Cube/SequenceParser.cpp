#include <string>
#include <sstream>
#include "SequenceParser.h"


SequenceParser::SequenceParser() {
    commands = {
            {"U", U_CW},
            {"U'", U_CCW},
            {"U2", U_2},
            {"D", D_CW},
            {"D'", D_CCW},
            {"D2", D_2},
            {"L", L_CW},
            {"L'", L_CCW},
            {"L2", L_2},
            {"R", R_CW},
            {"R'", R_CCW},
            {"R2", R_2},
            {"B", B_CW},
            {"B'", B_CCW},
            {"B2", B_2},
            {"F", F_CW},
            {"F'", F_CCW},
            {"F2", F_2},
    };
}

void SequenceParser::perform_sequence(Cube& cube, const std::string& sequence) {
    std::istringstream sequenceStream(sequence);
    std::string command;
    while (std::getline(sequenceStream, command, ' ')) {
        perform_command(cube, command);
    }
}

void SequenceParser::perform_command(Cube& cube, const std::string& command) {
    switch (commands[command]) {
        case U_CW:
            cube.turn_U();
            break;
        case U_CCW:
            cube.turn_U(true);
            break;
        case U_2:
            cube.turn_U2();
            break;
        case D_CW:
            cube.turn_D();
            break;
        case D_CCW:
            cube.turn_D(true);
            break;
        case D_2:
            cube.turn_D2();
            break;
        case L_CW:
            cube.turn_L();
            break;
        case L_CCW:
            cube.turn_L(true);
            break;
        case L_2:
            cube.turn_L2();
            break;
        case R_CW:
            cube.turn_R();
            break;
        case R_CCW:
            cube.turn_R(true);
            break;
        case R_2:
            cube.turn_R2();
            break;
        case F_CW:
            cube.turn_F();
            break;
        case F_CCW:
            cube.turn_F(true);
            break;
        case F_2:
            cube.turn_F2();
            break;
        case B_CW:
            cube.turn_B();
            break;
        case B_CCW:
            cube.turn_B(true);
            break;
        case B_2:
            cube.turn_B2();
            break;
        default:
            break;
    }
}

