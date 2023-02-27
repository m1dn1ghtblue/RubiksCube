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

Cube::Cube(const Cube& other) {
    this->corners = other.corners;
    this->edges = other.edges;
}

Cube &Cube::operator=(const Cube& other) {
    if (this != &other) {
        this->corners = other.corners;
        this->edges = other.edges;
    }
    return *this;
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
        turnCounterClockWise(UF, UL, UB, UR, URF, UFL, ULB, UBR);
    }
    else {
        turnClockWise(UF, UL, UB, UR, URF, UFL, ULB, UBR);
    }
}

void Cube::turn_U2() {
    std::swap(corners[UFL], corners[UBR]);
    std::swap(corners[URF], corners[ULB]);
    std::swap(edges[UF], edges[UB]);
    std::swap(edges[UL], edges[UR]);
}

void Cube::turn_D(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(DF, DR, DB, DL, DLF, DFR, DRB, DBL);
    }
    else {
        turnClockWise(DF, DR, DB, DL, DLF, DFR, DRB, DBL);
    }
}

void Cube::turn_D2() {
    std::swap(corners[DLF], corners[DRB]);
    std::swap(corners[DFR], corners[DBL]);
    std::swap(edges[DF], edges[DB]);
    std::swap(edges[DL], edges[DR]);
}

void Cube::turn_B(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UB, BL, DB, BR, UBR, ULB, DBL, DRB);
    }
    else{
        turnClockWise(UB, BL, DB, BR, UBR, ULB, DBL, DRB);
    }

    corners[ULB].twist(1);
    corners[DRB].twist(1);
    corners[UBR].twist(2);
    corners[DBL].twist(2);

    edges[UB].twist();
    edges[BR].twist();
    edges[DB].twist();
    edges[BL].twist();
}

void Cube::turn_B2() {
    std::swap(corners[UBR], corners[DBL]);
    std::swap(corners[ULB], corners[DRB]);
    std::swap(edges[UB], edges[DB]);
    std::swap(edges[BR], edges[BL]);
}

void Cube::turn_F(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UF, FR, DF, FL, UFL, URF, DFR, DLF);
    }
    else {
        turnClockWise(UF, FR, DF, FL, UFL, URF, DFR, DLF);
    }

    corners[URF].twist(1);
    corners[DLF].twist(1);
    corners[DFR].twist(2);
    corners[UFL].twist(2);

    edges[UF].twist();
    edges[FR].twist();
    edges[DF].twist();
    edges[FL].twist();
}

void Cube::turn_F2() {
    std::swap(corners[UFL], corners[DFR]);
    std::swap(corners[URF], corners[DLF]);
    std::swap(edges[UF], edges[DF]);
    std::swap(edges[FL], edges[FR]);
}

void Cube::turn_L(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UL, FL, DL, BL, ULB, UFL, DLF, DBL);
    }
    else{
        turnClockWise(UL, FL, DL, BL, ULB, UFL, DLF, DBL);
    }

    corners[UFL].twist(1);
    corners[DBL].twist(1);
    corners[DLF].twist(2);
    corners[ULB].twist(2);
}

void Cube::turn_L2() {
    std::swap(corners[UFL], corners[DBL]);
    std::swap(corners[ULB], corners[DLF]);
    std::swap(edges[UL], edges[DL]);
    std::swap(edges[FL], edges[BL]);
}

void Cube::turn_R(bool counterclockwise) {
    if (counterclockwise) {
        turnCounterClockWise(UR, BR, DR, FR, URF, UBR, DRB, DFR);
    }
    else {
        turnClockWise(UR, BR, DR, FR, URF, UBR, DRB, DFR);
    }

    corners[UBR].twist(1);
    corners[DFR].twist(1);
    corners[URF].twist(2);
    corners[DRB].twist(2);
}

void Cube::turn_R2() {
    std::swap(corners[URF], corners[DRB]);
    std::swap(corners[UBR], corners[DFR]);
    std::swap(edges[UR], edges[DR]);
    std::swap(edges[FR], edges[BR]);
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

CornerCubie Cube::getCorner(C_POS position) const {
    return corners[position];
}

EdgeCubie Cube::getEdge(E_POS position) const {
    return edges[position];
}

