#include "Scene.h"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image/stb_image.h"
#include "iostream"

Scene::Scene(const Window& window) : window(window){
    shader = new Shader("Graphics/resources/shaders/vertexShader.glsl", "Graphics/resources/shaders/fragmentShader.glsl");
    borderMap = new Texture("Graphics/resources/textures/borders.jpg");
    lastFrame = 0.0f;
    animation = nullptr;
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

        if (animation) {
            animation->update(animationSpeed * delta);
            if (animation->isFinished()) {
                animation = nullptr;
            }
        }

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

    if (!animation) {
        if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_PRESS) {
            animation = new TurnZ(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), -1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_PRESS) {
            animation = new TurnZ(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), 0);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_B) == GLFW_PRESS) {
            animation = new TurnZ(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS), 1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_L) == GLFW_PRESS) {
            animation = new TurnX(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS), 1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_PRESS) {
            animation = new TurnX(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), -1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_M) == GLFW_PRESS) {
            animation = new TurnX(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS), 0);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_U) == GLFW_PRESS) {
            animation = new TurnY(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), 1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_PRESS) {
            animation = new TurnY(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), -1);
        }

        if (glfwGetKey(glfwWindow, GLFW_KEY_E) == GLFW_PRESS) {
            animation = new TurnY(cubeModel, (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS), 0);
        }
    }
}

float Scene::deltaTime() {
    float currentFrame = (float)glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}





