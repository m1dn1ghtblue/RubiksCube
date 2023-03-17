#pragma once

#include "CubeModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Scene {
private:
    GLFWwindow* window;

    CubeModel cubeModel;
    Shader* shader;

public:
    explicit Scene(GLFWwindow *window);
    ~Scene();

    void run();
};
