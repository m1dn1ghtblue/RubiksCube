#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Cubie {
private:
    glm::vec3 position;
    glm::mat4 model;

    glm::mat4 rotation;

public:
    Cubie(int x, int y, int z);

    [[nodiscard]] glm::mat4 getModel() const;
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getZ() const;

    void update();
};
