#include <string>
#include <sstream>
#include "SequenceParser.h"

void SequenceParser::perform_sequence(Cube &cube, const std::string &sequence) {
    std::istringstream sequenceStream(sequence);
    std::string command;
    while (std::getline(sequenceStream, command, ' ')) {
        perform_command(cube, command);
    }
}

void SequenceParser::perform_command(Cube &cube, const std::string &command) {
    if (command.empty()) {
        return;
    }
    char move = command[0];
    bool ccw = false;
    bool half = false;
    if (command.size() > 1) {
        if (command[1] == '\'') ccw = true;
        else if (command[1] == '2') half = true;
    }

    switch (move) {
        case 'U':
            cube.move_U(ccw, half);
            break;
        case 'D':
            cube.move_D(ccw, half);
            break;
        case 'L':
            cube.move_L(ccw, half);
            break;
        case 'R':
            cube.move_R(ccw, half);
            break;
        case 'B':
            cube.move_B(ccw, half);
            break;
        case 'F':
            cube.move_F(ccw, half);
            break;
        case 'x':
            cube.move_X(ccw, half);
            break;
        case 'y':
            cube.move_Y(ccw, half);
            break;
        case 'z':
            cube.move_Z(ccw, half);
            break;
        case 'M':
            cube.move_M(ccw, half);
            break;
        case 'E':
            cube.move_E(ccw, half);
            break;
        case 'S':
            cube.move_S(ccw, half);
            break;
    }
}