#pragma once
#include "Cubie.h"
#include <array>

enum C_POS {
    ULB = 0,
    UFL = 1,
    URF = 2,
    UBR = 3,
    DBL = 4,
    DLF = 5,
    DFR = 6,
    DRB = 7
};

enum E_POS {
    UL = 0,
    UF = 1,
    UR = 2,
    UB = 3,
    BL = 4,
    FL = 5,
    FR = 6,
    BR = 7,
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
    Cube(const Cube& other);
    Cube& operator=(const Cube& other);

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

    [[nodiscard]] bool is_solved() const;
    [[nodiscard]] CornerCubie getCorner(C_POS position) const;
    [[nodiscard]] EdgeCubie getEdge(E_POS position) const;
};