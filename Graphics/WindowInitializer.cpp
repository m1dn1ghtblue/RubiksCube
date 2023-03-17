#include "WindowInitializer.h"
#include <iostream>
#include "GraphicException.h"

GLFWwindow* WindowInitializer::init(int width, int height) {
    if (!glfwInit()) {
        throw GraphicException("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Rubik's Cube", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw GraphicException("Failed to create window");
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        throw GraphicException("Failed to initialize GLEW");
    }

#ifdef DEBUG_LOG
    std::cerr << glGetString(GL_VERSION) << "\n";
#endif

    return window;
}