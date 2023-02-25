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

    void turnClockWise(E_POS edgeUp, E_POS edgeRight, E_POS edgeDown, E_POS edgeLeft,
                 C_POS cornerUpLeft, C_POS cornerUpRight, C_POS cornerDownRight, C_POS cornerDownLeft);

    void turnCounterClockWise(E_POS edgeUp, E_POS edgeRight, E_POS edgeDown, E_POS edgeLeft,
                              C_POS cornerUpLeft, C_POS cornerUpRight, C_POS cornerDownRight, C_POS cornerDownLeft);

public:
    Cube();
    void turn_U(bool counterclockwise = false);
    void turn_U2();
    void turn_D(bool counterclockwise = false);
    void turn_D2();
    void turn_L(bool counterclockwise = false);
    void turn_L2();
    void turn_R(bool counterclockwise = false);
    void turn_R2();
    void turn_F(bool counterclockwise = false);
    void turn_F2();
    void turn_B(bool counterclockwise = false);
    void turn_B2();

    bool is_solved() const;
};
