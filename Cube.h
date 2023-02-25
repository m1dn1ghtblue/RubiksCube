#pragma once

#include <array>
#include "Cubie.h"

enum C_POS {
    ULB = 0,
    ULF = 1,
    URF = 2,
    URB = 3,
    DLB = 4,
    DLF = 5,
    DRF = 6,
    DRB = 7
};

enum E_POS {
    UL = 0,
    UF = 1,
    UR = 2,
    UB = 3,
    LB = 4,
    LF = 5,
    RF = 6,
    RB = 7,
    DL = 8,
    DF = 9,
    DR = 10,
    DB = 11
};

class Cube {
private:
    std::array<CornerCubie, 8> corners;
    std::array<EdgeCubie, 12> edges;

    void turnClockWise(E_POS edge1, E_POS edge2, E_POS edge3, E_POS edge4,
                 C_POS corner1, C_POS corner2, C_POS corner3, C_POS corner4);

    void turnCounterClockWise(E_POS edge1, E_POS edge2, E_POS edge3, E_POS edge4,
                 C_POS corner1, C_POS corner2, C_POS corner3, C_POS corner4);

public:
    Cube();
    void turn_U();
    void turn_U2();
    void turn_D();
    void turn_D2();
    void turn_L();
    void turn_L2();
    void turn_R();
    void turn_R2();
    void turn_F();
    void turn_F2();
    void turn_B();
    void turn_B2();
};
