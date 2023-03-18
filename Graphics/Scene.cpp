#include "Scene.h"
#include "WindowInitializer.h"
#include "glm/gtc/matrix_transform.hpp"

Scene::Scene(GLFWwindow *window) : window(window){
    shader = new Shader("Graphics/resources/shaders/vertexShader.glsl", "Graphics/resources/shaders/fragmentShader.glsl");
    lastFrame = 0.0f;
}

Scene::~Scene() {
    glfwTerminate();
}

void Scene::run() {
    glEnable(GL_DEPTH_TEST);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    shader->use();
    shader->setMatrixFloat4("uProjection", projection);
    glm::mat4 model = glm::mat4(1.0f);
    shader->setMatrixFloat4("uModel", model);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput();

        shader->use();
        shader->setMatrixFloat4("uView", camera.getView());

        cubeModel.bind();
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Scene::processInput() {
    float delta = deltaTime();
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        camera.rotate(delta);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        camera.rotate(-delta);
    }
}

float Scene::deltaTime() {
    float currentFrame = (float)glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}




