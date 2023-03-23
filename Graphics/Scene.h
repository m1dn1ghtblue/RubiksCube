#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "CubeModel.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "Window.h"
#include "Animation.h"
#include "Cube.h"
#include "../GA_Solver/GeneticSolver.h"

class Scene {
private:
    Window window;

    CubeModel cubeModel;
    Shader* shader;
    Camera camera;
    Texture* borderMap;

    Animation* animation;
    const float animationSpeed = 10.0f;
    bool solving;

    Cube cube;

    void processInput(float delta);
    float lastFrame;

    float deltaTime();

public:
    explicit Scene(const Window& window);

    void run();
};
