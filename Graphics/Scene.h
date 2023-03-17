#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Scene {
private:
    const int windowWidth = 1000;
    const int windowHeight = 800;

    GLFWwindow *window;

public:
    Scene();
    ~Scene();

    void run();
};
