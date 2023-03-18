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
}

CubeModel::~CubeModel() {
    glDeleteVertexArrays(1, &vaoRendererId);
    glDeleteBuffers(1, &vboRendererId);
}

void CubeModel::bind() const {
    glBindVertexArray(vaoRendererId);
}

std::vector<glm::vec3> CubeModel::getPositions() {
    return cubePositions;
}
