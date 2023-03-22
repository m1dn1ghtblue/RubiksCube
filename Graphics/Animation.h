#pragma once
#include "CubeModel.h"

class Animation {
protected:
    CubeModel& cubeModel;
    float angle;
    bool reverse;
    int layer;

public:
    explicit Animation(CubeModel& cube, bool reverse, int layer);

    [[nodiscard]] bool isFinished() const;
    virtual void update(float delta) {};
};

class TurnZ : public Animation {
public:
    explicit TurnZ(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};

class TurnY : public Animation {
public:
    explicit TurnY(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};

class TurnX : public Animation {
public:
    explicit TurnX(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};