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

    if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_PRESS && lastKey != 'f') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnF(-0.25f * M_PI);
        }
        else {
            cubeModel.turnF(0.25f * M_PI);
        }
        lastKey = 'f';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_RELEASE && lastKey == 'f') {
        lastKey = -1;
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_B) == GLFW_PRESS && lastKey != 'b') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnB(0.25f * M_PI);
        }
        else {
            cubeModel.turnB(-0.25f * M_PI);
        }
        lastKey = 'b';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_B) == GLFW_RELEASE && lastKey == 'b') {
        lastKey = -1;
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_L) == GLFW_PRESS && lastKey != 'l') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnL(0.25f * M_PI);
        }
        else {
            cubeModel.turnL(-0.25f * M_PI);
        }
        lastKey = 'l';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_L) == GLFW_RELEASE && lastKey == 'l') {
        lastKey = -1;
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_PRESS && lastKey != 'r') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnR(-0.25f * M_PI);
        }
        else {
            cubeModel.turnR(0.25f * M_PI);
        }
        lastKey = 'r';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_RELEASE && lastKey == 'r') {
        lastKey = -1;
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_U) == GLFW_PRESS && lastKey != 'u') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnU(-0.25f * M_PI);
        }
        else {
            cubeModel.turnU(0.25f * M_PI);
        }
        lastKey = 'u';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_U) == GLFW_RELEASE && lastKey == 'u') {
        lastKey = -1;
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_PRESS && lastKey != 'd') {
        if (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cubeModel.turnD(-0.25f * M_PI);
        }
        else {
            cubeModel.turnD(0.25f * M_PI);
        }
        lastKey = 'd';
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_RELEASE && lastKey == 'd') {
        lastKey = -1;
    }
}

float Scene::deltaTime() {
    float currentFrame = (float)glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}





