#pragma once

#include <array>
#include "Cubie.h"

class Cube {
private:
    std::array<CornerCubie, 8> corners;
    std::array<EdgeCubie, 12> edges;

public:
    Cube();
};
