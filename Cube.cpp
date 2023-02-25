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