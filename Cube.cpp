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

void
Cube::turnClockWise(E_POS edgeUp, E_POS edgeRight, E_POS edgeDown, E_POS edgeLeft,
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

