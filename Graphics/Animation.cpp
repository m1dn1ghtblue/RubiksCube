#include "Animation.h"
#include "iostream"

Animation::Animation(CubeModel &cube, bool reverse, int layer) : cubeModel(cube), reverse(reverse), layer(layer) {
    angle = 0.5f * M_PI;
}

bool Animation::isFinished() const {
    return angle <= 0.0f;
}

TurnX::TurnX(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse, layer) {}
void TurnX::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateX(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnX(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnY::TurnY(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse, layer) {}
void TurnY::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateY(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnY(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnZ::TurnZ(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse, layer) {}
void TurnZ::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateZ(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnZ(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}