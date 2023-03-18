#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"

class Camera {
private:
    const float speed = 100.0f;
    const float radius = 8.0f;

    glm::vec3 cameraPosition;

    float yaw;
    float pitch;

    glm::vec3 target;
    glm::vec3 cameraUp;

    void updatePosition();
public:
    Camera();

    void rotate(float delta);
    void rotatePitch(float delta);
    glm::mat4 getView();
};
