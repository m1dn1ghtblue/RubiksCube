#include <iostream>
#include "Graphics/Scene.h"
#include "Graphics/Window.h"

int main() {
    Window window(800, 600);
    Scene scene(window);
    scene.run();

    return 0;
}