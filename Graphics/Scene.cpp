#include "Scene.h"
#include "GraphicException.h"
#include <iostream>

Scene::Scene() {
    if (!glfwInit()) {
        throw GraphicException("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowWidth, windowHeight, "Rubik's Cube", nullptr, nullptr);
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
}

Scene::~Scene() {
    glfwTerminate();
}

void Scene::run() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}


