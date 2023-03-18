#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"

class Camera {
private:
    const float speed = 1.5f;
    const float radius = 3.0f;

    float Xpos;
    float Zpos;
    float angle;
    glm::vec3 target;
    glm::vec3 cameraUp;

public:
    Camera();

    void rotate(float delta);
    glm::mat4 getView();
};
