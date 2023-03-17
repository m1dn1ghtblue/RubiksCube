#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class WindowInitializer {
public:
    static GLFWwindow* init(int width, int height);
};
