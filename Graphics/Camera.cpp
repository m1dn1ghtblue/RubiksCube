#include "Camera.h"
#include <cmath>
#include "glm/gtc/matrix_transform.hpp"
#include "iostream"

Camera::Camera() {;
    yaw = -60.0f;
    pitch = 30.0f;

    target = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    updatePosition();
}

void Camera::rotate(float delta) {
    yaw += delta * speed;
    if (yaw < 0.0f) {
        yaw += 360.0f;
    }
    if (yaw > 360.0f) {
        yaw -= 360.0f;
    }

    updatePosition();
}

glm::mat4 Camera::getView() {
    return glm::lookAt(cameraPosition, target, cameraUp);
}

void Camera::rotatePitch(float delta) {
    pitch += delta * speed;
    pitch = std::min(std::max(pitch, -89.0f), 89.0f);

    updatePosition();
}

void Camera::updatePosition() {
    float yawRad = glm::radians(yaw);
    float pitchRad = glm::radians(pitch);

    cameraPosition.x = cos(yawRad) * radius * cos(pitchRad);
    cameraPosition.y = sin(pitchRad) * radius;
    cameraPosition.z = sin(yawRad) * radius * cos(pitchRad);
}

