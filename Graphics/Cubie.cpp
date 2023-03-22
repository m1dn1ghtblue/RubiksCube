#include "Cubie.h"
#include "iostream"

Cubie::Cubie(int x, int y, int z) {
    position = glm::vec3(x, y, z);
    model = glm::mat4(1.0f);
    rotation = glm::mat4(1.0f);
}

glm::mat4 Cubie::getModel() const {
    return glm::translate(glm::mat4(1.0f), position) * rotation;
}

void Cubie::rotateX(float angle)
{
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * rotation;

    model = glm::rotate(model, angle, glm::vec3(1.0f, 0.0f, 0.0f));
    update();
    model = glm::mat4(1.0f);
}

void Cubie::rotateY(float angle) {
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * rotation;

    model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
    update();
    model = glm::mat4(1.0f);
}

void Cubie::rotateZ(float angle) {
    rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f)) * rotation;

    model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));
    update();
    model = glm::mat4(1.0f);
}

int Cubie::getX() const {
    return (int)round(glm::translate(model, position)[3][0]);
}

int Cubie::getY() const {
    return (int)round(glm::translate(model, position)[3][1]);
}

int Cubie::getZ() const {
    return (int)round(glm::translate(model, position)[3][2]);
}

void Cubie::update() {
    position = glm::vec3(getX(), getY(), getZ());
}