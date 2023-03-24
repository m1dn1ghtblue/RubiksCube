#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "CubeModel.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "Window.h"
#include "Animation.h"
#include "Cube.h"
#include "../GA_Solver/GeneticSolver.h"
#include <queue>
#include <thread>

class Scene {
private:
    Window window;

    CubeModel cubeModel;
    Shader* shader;
    Camera camera;
    Texture* borderMap;

    std::queue<Animation*> animations;
    float animationSpeed = 15.0f;
    char lastKey;
    bool solving;
    Cube cube;
    std::thread* solverThread;

    void processInput(float delta);
    float lastFrame;

    float deltaTime();
    void solve();
    void performSequence(const std::string& sequence);
    void performCommand(const std::string& command);
public:
    explicit Scene(const Window& window);
    ~Scene();
    void run();
};
