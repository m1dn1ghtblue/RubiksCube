#include "Camera.h"
#include <cmath>
#include "glm/gtc/matrix_transform.hpp"

const float FullCircle = float(2.0f * M_PI);

Camera::Camera() {
    Xpos = 0.0f;
    Zpos = radius;
    angle = 0.0f;

    target = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::rotate(float delta) {
    angle -= delta * speed;
    if (angle < 0.0f) {
        angle = FullCircle + angle;
    }
    else if (angle > FullCircle) {
        angle -= FullCircle;
    }

    Xpos = sin(angle) * radius;
    Zpos = cos(angle) * radius;
}

glm::mat4 Camera::getView() {
    return glm::lookAt(glm::vec3(Xpos, 0.0, Zpos), target, cameraUp);
}

