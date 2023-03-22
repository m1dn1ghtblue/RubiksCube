#include "Cubie.h"
#include "iostream"

Cubie::Cubie(int x, int y, int z) {
    position = glm::vec3(x, y, z);
    rotation = glm::mat4(1.0f);
    model = glm::mat4(1.0f);
}

glm::mat4 Cubie::getModel() const {
    return glm::translate(model, position) * rotation;
}

void Cubie::turnX(float angle)
{
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * rotation;
    update(angle, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Cubie::turnY(float angle) {
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * rotation;
    update(angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Cubie::turnZ(float angle) {
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f)) * rotation;
    update(angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Cubie::update(float angle, glm::vec3 axis) {
    glm::mat4 matrix = glm::rotate(glm::mat4(1.0f), angle, axis);
    matrix = glm::translate(matrix, position);
    int x = (int)round(matrix[3][0]);
    int y = (int)round(matrix[3][1]);
    int z = (int)round(matrix[3][2]);

    position = glm::vec3(x, y, z);
    model = glm::mat4(1.0f);
}

int Cubie::getX() const {
    return (int)position.x;
}

int Cubie::getY() const {
    return (int)position.y;
}

int Cubie::getZ() const {
    return (int)position.z;
}

void Cubie::rotateX(float angle) {
    model = glm::rotate(model, angle, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Cubie::rotateY(float angle) {
    model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Cubie::rotateZ(float angle) {
    model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));
}
