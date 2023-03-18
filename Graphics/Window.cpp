#include "Window.h"
#include "GraphicException.h"
#include <iostream>

Window::Window(int width, int height) {
    if (!glfwInit()) {
        throw GraphicException("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindow = glfwCreateWindow(width, height, "Rubik's Cube", nullptr, nullptr);
    if (!glfwWindow) {
        glfwTerminate();
        throw GraphicException("Failed to create glfwWindow");
    }
    glfwMakeContextCurrent(glfwWindow);

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        throw GraphicException("Failed to initialize GLEW");
    }

#ifdef DEBUG_LOG
    std::cerr << glGetString(GL_VERSION) << "\n";
#endif

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(glfwWindow, resizeCallback);
}

void Window::resizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::~Window() {
    glfwTerminate();
}

GLFWwindow *Window::getGlfwWindow() {
    return glfwWindow;
}

float Window::sizeRatio() {
    int width, height;
    glfwGetWindowSize(glfwWindow, &width, &height);
    return float(width) / float(height);
}
