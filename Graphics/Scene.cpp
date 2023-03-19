#include "Scene.h"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image/stb_image.h"
#include "iostream"

Scene::Scene(const Window& window) : window(window){
    shader = new Shader("Graphics/resources/shaders/vertexShader.glsl", "Graphics/resources/shaders/fragmentShader.glsl");
    borderMap = new Texture("Graphics/resources/textures/borders.jpg");
    lastFrame = 0.0f;
}

void Scene::run() {
    glEnable(GL_DEPTH_TEST);

    borderMap->bind();
    glClearColor(0.13f, 0.34f, 0.48f, 1.0f);

    while (!glfwWindowShouldClose(window.getGlfwWindow())) {
        float delta = deltaTime();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput(delta);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), window.sizeRatio(), 0.1f, 30.0f);
        glm::mat4 view = camera.getView();
        shader->use();
        shader->setMatrixFloat4("uView", view);
        shader->setMatrixFloat4("uProjection", projection);

        cubeModel.bind();

        for (int i = 0; i < cubeModel.cubies.size(); ++i) {
            if (cubeModel.cubies[i].getY() == 1) {
                cubeModel.cubies[i].rotateY(delta * 0.5f * M_PI);
            }
            glm::mat4 model = cubeModel.cubies[i].getModel();
            shader->setMatrixFloat4("uModel", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glfwSwapBuffers(window.getGlfwWindow());
        glfwPollEvents();
    }
}

void Scene::processInput(float delta) {
    GLFWwindow* glfwWindow = window.getGlfwWindow();
    if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
        camera.rotate(delta);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        camera.rotate(-delta);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_UP) == GLFW_PRESS) {
        camera.rotatePitch(delta);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
        camera.rotatePitch(-delta);
    }
}

float Scene::deltaTime() {
    float currentFrame = (float)glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}





