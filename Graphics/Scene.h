#pragma once

#include "CubeModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "Window.h"

class Scene {
private:
    Window window;

    CubeModel cubeModel;
    Shader* shader;
    Camera camera;
    Texture* borderMap;
    char lastKey = -1;

    void processInput(float delta);
    float lastFrame;

    float deltaTime();

public:
    explicit Scene(const Window& window);

    void run();
};
