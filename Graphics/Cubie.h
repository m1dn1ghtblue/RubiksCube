#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Cubie {
private:
    glm::vec3 position;
    glm::mat4 rotation;
    glm::mat4 model;

    void update(float angle, glm::vec3 axis);

public:
    Cubie(int x, int y, int z);

    [[nodiscard]] glm::mat4 getModel() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getZ() const;

    void turnX(float angle);
    void turnY(float angle);
    void turnZ(float angle);

    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
};
