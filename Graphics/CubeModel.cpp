#include "CubeModel.h"

CubeModel::CubeModel() {
    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    vaoRendererId = vao;
    vboRendererId = vbo;

    glBindVertexArray(vaoRendererId);
    glBindBuffer(GL_ARRAY_BUFFER, vboRendererId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            for (int z = -1; z <= 1; ++z) {
                cubies.emplace_back(x, y, z);
            }
        }
    }
}

CubeModel::~CubeModel() {
    glDeleteVertexArrays(1, &vaoRendererId);
    glDeleteBuffers(1, &vboRendererId);
}

void CubeModel::bind() const {
    glBindVertexArray(vaoRendererId);
}

void CubeModel::turnF(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getZ() == -1) {
            cubie.rotateZ(angle);
        }
    }
}

void CubeModel::turnB(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getZ() == 1) {
            cubie.rotateZ(angle);
        }
    }
}

void CubeModel::turnL(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getX() == 1) {
            cubie.rotateX(angle);
        }
    }
}

void CubeModel::turnR(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getX() == -1) {
            cubie.rotateX(angle);
        }
    }
}

void CubeModel::turnU(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getY() == 1) {
            cubie.rotateY(angle);
        }
    }
}

void CubeModel::turnD(float angle) {
    for (auto & cubie : cubies) {
        if(cubie.getY() == -1) {
            cubie.rotateY(angle);
        }
    }
}
