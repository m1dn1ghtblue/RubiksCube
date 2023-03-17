#include <iostream>
#include "Graphics/Scene.h"
#include "Graphics/WindowInitializer.h"

int main() {
    GLFWwindow* window = WindowInitializer::init(800, 600);
    Scene scene(window);
    scene.run();

    return 0;
}