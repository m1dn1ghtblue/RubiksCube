#include "Animation.h"

Animation::Animation(CubeModel &cube, bool reverse) : cubeModel(cube), reverse(reverse) {
    angle = 0.5f * M_PI;
}

bool Animation::isFinished() const {
    return angle <= 0.0f;
}

TurnX::TurnX(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse), layer(layer) {}
void TurnX::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateX(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnX(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnY::TurnY(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse), layer(layer) {}
void TurnY::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateY(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnY(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnZ::TurnZ(CubeModel &cube, bool reverse, int layer) : Animation(cube, reverse), layer(layer) {}
void TurnZ::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateZ(layer, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnZ(layer, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}


TurnXFull::TurnXFull(CubeModel &cube, bool reverse) : Animation(cube, reverse) {}
void TurnXFull::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateX(-1, (reverse ? -delta : delta));
        cubeModel.rotateX(0, (reverse ? -delta : delta));
        cubeModel.rotateX(1, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnX(-1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnX(0, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnX(1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnYFull::TurnYFull(CubeModel &cube, bool reverse) : Animation(cube, reverse) {}
void TurnYFull::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateY(-1, (reverse ? -delta : delta));
        cubeModel.rotateY(0, (reverse ? -delta : delta));
        cubeModel.rotateY(1, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnY(-1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnY(0, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnY(1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}

TurnZFull::TurnZFull(CubeModel &cube, bool reverse) : Animation(cube, reverse) {}
void TurnZFull::update(float delta) {
    angle -= delta;
    if (angle > 0.0f) {
        cubeModel.rotateZ(-1, (reverse ? -delta : delta));
        cubeModel.rotateZ(0, (reverse ? -delta : delta));
        cubeModel.rotateZ(1, (reverse ? -delta : delta));
    }
    else {
        cubeModel.turnZ(-1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnZ(0, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
        cubeModel.turnZ(1, reverse ? (-0.5f * M_PI) : (0.5f * M_PI));
    }
}