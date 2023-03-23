#pragma once
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "CubieModel.h"

class CubeModel {
private:
    const float vertices[8 * 6 * 6] = {
        // coordinates          // color        // texture coord
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      0.0f, 1.0f, 0.0f,   1.0f, 1.0f,

        -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,      0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,      0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
        0.5f, -0.5f, 0.5f,      0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
        0.5f, 0.5f, 0.5f,       0.0f, 0.0f, 1.0f,   1.0f, 1.0f,

        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 0.0f, 0.0f,   1.0f, 1.0f,

        0.5f, -0.5f, -0.5f,     1.0f, 0.6f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 0.6f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 0.6f, 0.0f,   0.0f, 1.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 0.6f, 0.0f,   0.0f, 1.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 0.6f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, 0.5f,       1.0f, 0.6f, 0.0f,   1.0f, 1.0f,

        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 0.0f,   1.0f, 1.0f,

        -0.5f, 0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.0f, 1.0f
    };

    unsigned int vboRendererId;
    unsigned int vaoRendererId;

public:
    CubeModel();
    ~CubeModel();

    void bind() const;

    void turnX(int layer, float angle);
    void turnY(int layer, float angle);
    void turnZ(int layer, float angle);

    void rotateX(int layer, float angle);
    void rotateY(int layer, float angle);
    void rotateZ(int layer, float angle);

    std::vector<CubieModel> cubies;
};

