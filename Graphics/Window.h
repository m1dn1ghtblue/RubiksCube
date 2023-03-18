#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Window {
private:
    GLFWwindow* glfwWindow;

    static void resizeCallback(GLFWwindow *window, int width, int height);
public:
    Window(int width, int height);
    ~Window();

    GLFWwindow* getGlfwWindow();
    float sizeRatio();
};
