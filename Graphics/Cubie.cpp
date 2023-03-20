#include "Cubie.h"
#include "iostream"

Cubie::Cubie(int x, int y, int z) : Xpos(x), Ypos(y), Zpos(z) {
    position = glm::vec3(Xpos, Ypos, Zpos);
    model = glm::mat4(1.0f);
}

glm::mat4 Cubie::getModel() const {
    return glm::translate(model, position);
}

void Cubie::rotateX(float angle)
{
    model = glm::rotate(model, angle, glm::vec3(1.0f, 0.0f, 0.0f));
    update();
}

void Cubie::rotateY(float angle) {
    model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
    update();
}

void Cubie::rotateZ(float angle) {
    model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));
    update();
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
    model = glm::mat4(1.0f);
}


