#include "Scene.h"
#include "glm/gtc/matrix_transform.hpp"
#include "stb_image/stb_image.h"
#include "iostream"
#include "SequenceParser.h"
#include "sstream"
#include <future>
#include <thread>


Scene::Scene(const Window& window) : window(window){
    shader = new Shader("Graphics/resources/shaders/vertexShader.glsl", "Graphics/resources/shaders/fragmentShader.glsl");
    borderMap = new Texture("Graphics/resources/textures/borders.jpg");
    lastFrame = 0.0f;
    lastKey = -1;
    solving = false;
    solverThread = nullptr;
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

        if (solverThread && !solving) {
            solverThread->join();
            delete(solverThread);
            solverThread = nullptr;
        }

        if (!animations.empty()) {
            animations.front()->update(animationSpeed * delta);
            if (animations.front()->isFinished()) {
                delete(animations.front());
                animations.pop();
            }
        }

        cubeModel.bind();

        for (auto & cubie : cubeModel.cubies) {
            glm::mat4 model = cubie.getModel();
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

    if (animations.empty() && !solving) {
        bool ccw = (glfwGetKey(glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS);

        if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_PRESS && lastKey != 'f') {
            lastKey = 'f';
            performCommand(!ccw ? "F" : "F'");
            cube.move_F(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_RELEASE && lastKey == 'f') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_PRESS && lastKey != 's') {
            lastKey = 's';
            performCommand(!ccw ? "S" : "S'");
            cube.move_S(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_RELEASE && lastKey == 's') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_B) == GLFW_PRESS && lastKey != 'b') {
            lastKey = 'b';
            performCommand(!ccw ? "B" : "B'");
            cube.move_B(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_B) == GLFW_RELEASE && lastKey == 'b') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_L) == GLFW_PRESS && lastKey != 'l') {
            lastKey = 'l';
            performCommand(!ccw ? "L" : "L'");
            cube.move_L(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_L) == GLFW_RELEASE && lastKey == 'l') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_PRESS && lastKey != 'r') {
            lastKey = 'r';
            performCommand(!ccw ? "R" : "R'");
            cube.move_R(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_RELEASE && lastKey == 'r') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_M) == GLFW_PRESS && lastKey != 'm') {
            lastKey = 'm';
            performCommand(!ccw ? "M" : "M'");
            cube.move_M(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_M) == GLFW_RELEASE && lastKey == 'm') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_U) == GLFW_PRESS && lastKey != 'u') {
            lastKey = 'u';
            performCommand(!ccw ? "U" : "U'");
            cube.move_U(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_U) == GLFW_RELEASE && lastKey == 'u') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_PRESS && lastKey != 'd') {
            lastKey = 'd';
            performCommand(!ccw ? "D" : "D'");
            cube.move_D(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_RELEASE && lastKey == 'd') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_E) == GLFW_PRESS && lastKey != 'e') {
            lastKey = 'e';
            performCommand(!ccw ? "E" : "E'");
            cube.move_E(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_E) == GLFW_RELEASE && lastKey == 'e') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_X) == GLFW_PRESS && lastKey != 'x') {
            lastKey = 'x';
            performCommand(!ccw ? "x" : "x'");
            cube.move_X(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_X) == GLFW_RELEASE && lastKey == 'x') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_Y) == GLFW_PRESS && lastKey != 'y') {
            lastKey = 'y';
            performCommand(!ccw ? "y" : "y'");
            cube.move_Y(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_Y) == GLFW_RELEASE && lastKey == 'y') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_Z) == GLFW_PRESS && lastKey != 'z') {
            lastKey = 'z';
            performCommand(!ccw ? "z" : "z'");
            cube.move_Z(ccw, false);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_Z) == GLFW_RELEASE && lastKey == 'z') lastKey = -1;

        if (glfwGetKey(glfwWindow, GLFW_KEY_ENTER) == GLFW_PRESS && lastKey != 0) {
            lastKey = 0;
            solving = true;
            solverThread = new std::thread(&Scene::solve, this);
        }
        if (glfwGetKey(glfwWindow, GLFW_KEY_ENTER) == GLFW_RELEASE && lastKey == 0) lastKey = -1;
    }
}

void Scene::solve() {
    GeneticSolver solver(cube);
    std::cout << solver.getSolution() << "\n";
    performSequence(solver.getSolution());
    solving = false;
}

float Scene::deltaTime() {
    auto currentFrame = (float)glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}

void Scene::performSequence(const std::string &sequence) {
    SequenceParser::perform_sequence(cube, sequence);
    std::istringstream sequenceStream(sequence);
    std::string command;
    while (std::getline(sequenceStream, command, ' ')) {
        performCommand(command);
    }
}

void Scene::performCommand(const std::string& command) {
    if (command.empty()) {
        return;
    }
    char move = command[0];
    bool ccw = false;
    bool half = false;
    if (command.size() > 1) {
        if (command[1] == '\'') ccw = true;
        else if (command[1] == '2') half = true;
    }

    switch (move) {
        case 'U':
            animations.push(new TurnY(cubeModel, !ccw, 1));
            if (half) {
                animations.push(new TurnY(cubeModel, !ccw, 1));
            }
            break;
        case 'D':
            animations.push(new TurnY(cubeModel, ccw, -1));
            if (half) {
                animations.push(new TurnY(cubeModel, ccw, -1));
            }
            break;
        case 'L':
            animations.push(new TurnX(cubeModel, !ccw, 1));
            if (half) {
                animations.push(new TurnX(cubeModel, !ccw, 1));
            }
            break;
        case 'R':
            animations.push(new TurnX(cubeModel, ccw, -1));
            if (half) {
                animations.push(new TurnX(cubeModel, ccw, -1));
            }
            break;
        case 'B':
            animations.push(new TurnZ(cubeModel, !ccw, 1));
            if (half) {
                animations.push(new TurnZ(cubeModel, !ccw, 1));
            }
            break;
        case 'F':
            animations.push(new TurnZ(cubeModel, ccw, -1));
            if (half) {
                animations.push(new TurnZ(cubeModel, ccw, -1));
            }
            break;
        case 'x':
            animations.push(new TurnXFull(cubeModel, ccw));
            if (half) {
                animations.push(new TurnXFull(cubeModel, ccw));
            }
            break;
        case 'y':
            animations.push(new TurnYFull(cubeModel, !ccw));
            if (half) {
                animations.push(new TurnYFull(cubeModel, !ccw));
            }
            break;
        case 'z':
            animations.push(new TurnZFull(cubeModel, ccw));
            if (half) {
                animations.push(new TurnZFull(cubeModel, ccw));
            }
            break;
        case 'M':
            animations.push(new TurnX(cubeModel, !ccw, 0));
            if (half) {
                animations.push(new TurnX(cubeModel, !ccw, 0));
            }
            break;
        case 'E':
            animations.push(new TurnY(cubeModel, ccw, 0));
            if (half) {
                animations.push(new TurnY(cubeModel, ccw, 0));
            }
            break;
        case 'S':
            animations.push(new TurnZ(cubeModel, ccw, 0));
            if (half) {
                animations.push(new TurnZ(cubeModel, ccw, 0));
            }
            break;
        default:
            break;
    }
}

Scene::~Scene() {
    delete(solverThread);
    while(!animations.empty()) {
        delete(animations.front());
        animations.pop();
    }
}





