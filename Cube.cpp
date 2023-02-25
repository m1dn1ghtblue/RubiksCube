#include "Cube.h"
#include <vector>

Cube::Cube() {
    // create corners
    for (int i = 0; i < 8; ++i) {
        corners[i] = CornerCubie(i);
    }
    // create edges
    for (int i = 0; i < 12; ++i) {
        edges[i] = EdgeCubie(i);
    }
}

void Cube::turnClockWise(E_POS edgeUp, E_POS edgeRight, E_POS edgeDown, E_POS edgeLeft,
                    C_POS cornerUpLeft, C_POS cornerUpRight, C_POS cornerDownRight, C_POS cornerDownLeft) {
    EdgeCubie tmpEdge = edges[edgeUp];
    edges[edgeUp] = edges[edgeLeft];
    edges[edgeLeft] = edges[edgeDown];
    edges[edgeDown] = edges[edgeRight];
    edges[edgeRight] = tmpEdge;

    CornerCubie tmpCorner = corners[cornerUpLeft];
    corners[cornerUpLeft] = corners[cornerDownLeft];
    corners[cornerDownLeft] = corners[cornerDownRight];
    corners[cornerDownRight] = corners[cornerUpRight];
    corners[cornerUpRight] = tmpCorner;
}

void Cube::turnCounterClockWise(E_POS edgeUp, E_POS edgeRight, E_POS edgeDown, E_POS edgeLeft, C_POS cornerUpLeft,
                                C_POS cornerUpRight, C_POS cornerDownRight, C_POS cornerDownLeft) {
    EdgeCubie tmpEdge = edges[edgeUp];
    edges[edgeUp] = edges[edgeRight];
    edges[edgeRight] = edges[edgeDown];
    edges[edgeDown] = edges[edgeLeft];
    edges[edgeLeft] = tmpEdge;

    CornerCubie tmpCorner = corners[cornerUpLeft];
    corners[cornerUpLeft] = corners[cornerUpRight];
    corners[cornerUpRight] = corners[cornerDownRight];
    corners[cornerDownRight] = corners[cornerDownLeft];
    corners[cornerDownLeft] = tmpCorner;
}

void Cube::turn_U(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UF, UL, UB, UR, URF, ULF, ULB, URB);
    }
    else {
        turnClockWise(UF, UL, UB, UR, URF, ULF, ULB, URB);
    }
}

void Cube::turn_U2() {
    std::swap(corners[ULF], corners[URB]);
    std::swap(corners[URF], corners[ULB]);
    std::swap(edges[UF], edges[UB]);
    std::swap(edges[UL], edges[UR]);
}

void Cube::turn_D(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(DF, DR, DB, DL, DLF, DRF, DRB, DLB);
    }
    else {
        turnClockWise(DF, DR, DB, DL, DLF, DRF, DRB, DLB);
    }
}

void Cube::turn_D2() {
    std::swap(corners[DLF], corners[DRB]);
    std::swap(corners[DRF], corners[DLB]);
    std::swap(edges[DF], edges[DB]);
    std::swap(edges[DL], edges[DR]);
}

void Cube::turn_B(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UB, LB, DB, RB, URB, ULB, DLB, DRB);
    }
    else{
        turnClockWise(UB, LB, DB, RB, URB, ULB, DLB, DRB);
    }

    corners[ULB].twist(1);
    corners[DRB].twist(1);
    corners[URB].twist(2);
    corners[DLB].twist(2);

    edges[UB].twist();
    edges[RB].twist();
    edges[DB].twist();
    edges[LB].twist();
}

void Cube::turn_B2() {
    std::swap(corners[URB], corners[DLB]);
    std::swap(corners[ULB], corners[DRB]);
    std::swap(edges[UB], edges[DB]);
    std::swap(edges[RB], edges[LB]);
}

void Cube::turn_F(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UF, RF, DF, LF, ULF, URF, DRF, DLF);
    }
    else {
        turnClockWise(UF, RF, DF, LF, ULF, URF, DRF, DLF);
    }

    corners[URF].twist(1);
    corners[DLF].twist(1);
    corners[DRF].twist(2);
    corners[ULF].twist(2);

    edges[UF].twist();
    edges[RF].twist();
    edges[DF].twist();
    edges[LF].twist();
}

void Cube::turn_F2() {
    std::swap(corners[ULF], corners[DRF]);
    std::swap(corners[URF], corners[DLF]);
    std::swap(edges[UF], edges[DF]);
    std::swap(edges[LF], edges[RF]);
}

void Cube::turn_L(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UL, LF, DL, LB, ULB, ULB, DLF, DLB);
    }
    else{
        turnClockWise(UL, LF, DL, LB, ULB, ULB, DLF, DLB);
    }

    corners[ULF].twist(1);
    corners[DLB].twist(1);
    corners[DLF].twist(2);
    corners[ULB].twist(2);
}

void Cube::turn_L2() {
    std::swap(corners[ULF], corners[DLB]);
    std::swap(corners[ULB], corners[DLF]);
    std::swap(edges[UL], edges[DL]);
    std::swap(edges[LF], edges[LB]);
}

void Cube::turn_R(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UR, RB, DR, RF, URF, URB, DRB, DRF);
    }
    else {
        turnClockWise(UR, RB, DR, RF, URF, URB, DRB, DRF);
    }

    corners[URB].twist(1);
    corners[DRF].twist(1);
    corners[URF].twist(2);
    corners[DRB].twist(2);
}

void Cube::turn_R2() {
    std::swap(corners[URF], corners[DRB]);
    std::swap(corners[URB], corners[DRF]);
    std::swap(edges[UR], edges[DR]);
    std::swap(edges[RF], edges[RB]);
}

bool Cube::is_solved() const {
    for (int id = 0; id < 8; ++id) {
        if (corners[id].get_original_id() != id || corners[id].get_twist_state() != 0) {
            return false;
        }
    }

    for (int id = 0; id < 12; ++id) {
        if (edges[id].get_original_id() != id || edges[id].get_twist_state() != 0) {
            return false;
        }
    }

    return true;
}
