#pragma once

#include <unordered_map>
#include <string>
#include "Cube.h"


class SequenceParser {
public:
    static void perform_sequence(Cube& cube, const std::string& sequence);
    static void perform_command(Cube& cube, const std::string& command);
};