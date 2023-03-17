#include "Scene.h"
#include "WindowInitializer.h"

Scene::Scene(GLFWwindow *window) : window(window){
    shader = new Shader("Graphics/resources/shaders/vertexShader.glsl", "Graphics/resources/shaders/fragmentShader.glsl");
}

Scene::~Scene() {
    glfwTerminate();
}

void Scene::run() {
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->use();

        cubeModel.bind();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}




