#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"
#include <vector>

class CubeModel {
private:
    const float vertices[8 * 6 * 6] = {
        // coordinates              // color        // texture coord
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

        -0.5f, -0.5f, -0.5f,    1.0f, 0.6f, 0.0f,   0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 0.6f, 0.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f,     1.0f, 0.6f, 0.0f,   0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f,     1.0f, 0.6f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 0.6f, 0.0f,   1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 0.6f, 0.0f,   1.0f, 1.0f,

        0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        0.5f, 0.5f, -0.5f,      1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, 0.5f,       1.0f, 0.0f, 0.0f,   1.0f, 1.0f,

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

    std::vector<glm::vec3> cubePositions = {
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f),
            glm::vec3(1.0f, 0.0f, 1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, -1.0f),
            glm::vec3(1.0f, 0.0f, -1.0f),

            glm::vec3(0.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(-1.0f, 1.0f, 0.0f),
            glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, -1.0f),
            glm::vec3(1.0f, 1.0f, -1.0f),

            glm::vec3(0.0f, -1.0f, 1.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f),
            glm::vec3(1.0f, -1.0f, 1.0f),
            glm::vec3(0.0f, -1.0f, 0.0f),
            glm::vec3(-1.0f, -1.0f, 0.0f),
            glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(0.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, -1.0f),
            glm::vec3(1.0f, -1.0f, -1.0f),
    };

    unsigned int vboRendererId;
    unsigned int vaoRendererId;
public:
    CubeModel();
    ~CubeModel();

    void bind() const;
    std::vector<glm::vec3> getPositions();
};

