#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"
#include <vector>
#include "Cubie.h"

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

    std::vector<Cubie> cubies;

    void turnF(float angle);
    void turnB(float angle);
    void turnL(float angle);
    void turnR(float angle);
    void turnU(float angle);
    void turnD(float angle);

};

