#include <string>
#include <sstream>
#include "SequenceParser.h"


SequenceParser::SequenceParser() {
    commands = {
            {'U', U},
            {'D', D},
            {'L', L},
            {'R', R},
            {'B', B},
            {'F', F},
            {'z', Z},
            {'y', Y},
            {'x', X}
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
    switch (commands[command[0]]) {
        case U:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_U(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_U2();
                    break;
                }
            }
            cube.turn_U();
            break;

        case D:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_D(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_D2();
                    break;
                }
            }
            cube.turn_D();
            break;

        case L:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_L(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_L2();
                    break;
                }
            }
            cube.turn_L();
            break;

        case R:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_R(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_R2();
                    break;
                }
            }
            cube.turn_R();
            break;

        case F:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_F(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_F2();
                    break;
                }
            }
            cube.turn_F();
            break;

        case B:
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    cube.turn_B(true);
                    break;
                }
                else if (command[1] == '2') {
                    cube.turn_B2();
                    break;
                }
            }
            cube.turn_B();
            break;

        case X:
            orient_x();
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    orient_x();
                    orient_x();
                    break;
                }
                else if (command[1] == '2') {
                    orient_x();
                    break;
                }
            }
            break;

        case Y:
            orient_y();
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    orient_y();
                    orient_y();
                    break;
                }
                else if (command[1] == '2') {
                    orient_y();
                    break;
                }
            }
            break;

        case Z:
            orient_z();
            if (command.size() > 1) {
                if (command[1] == '\'') {
                    orient_z();
                    orient_z();
                    break;
                }
                else if (command[1] == '2') {
                    orient_z();
                    break;
                }
            }
            break;

        default:
            break;
    }
}

void SequenceParser::orient_x() {
    COMMAND tmp = commands['B'];
    commands['B'] = commands['U'];
    commands['U'] = commands['F'];
    commands['F'] = commands['D'];
    commands['D'] = tmp;
}

void SequenceParser::orient_y() {
    COMMAND tmp = commands['B'];
    commands['B'] = commands['L'];
    commands['L'] = commands['F'];
    commands['F'] = commands['R'];
    commands['R'] = tmp;
}

void SequenceParser::orient_z() {
    COMMAND tmp = commands['L'];
    commands['L'] = commands['D'];
    commands['D'] = commands['R'];
    commands['R'] = commands['U'];
    commands['U'] = tmp;
}
