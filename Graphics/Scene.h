#pragma once

#include "CubeModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"

class Scene {
private:
    GLFWwindow* window;

    CubeModel cubeModel;
    Shader* shader;
    Camera camera;

    void processInput();
    float lastFrame;

    float deltaTime();
public:
    explicit Scene(GLFWwindow *window);
    ~Scene();

    void run();
};
