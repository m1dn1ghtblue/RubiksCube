#pragma once
#include "CubeModel.h"

class Animation {
protected:
    CubeModel& cubeModel;
    float angle;
    bool reverse;

public:
    explicit Animation(CubeModel& cube, bool reverse);

    [[nodiscard]] bool isFinished() const;
    virtual void update(float delta) {};
};

class TurnZ : public Animation {
private:
    int layer;

public:
    explicit TurnZ(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};

class TurnY : public Animation {
private:
    int layer;

public:
    explicit TurnY(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};

class TurnX : public Animation {
private:
    int layer;

public:
    explicit TurnX(CubeModel &cube, bool reverse, int layer);
    void update(float delta) override;
};

class TurnXFull : public Animation {
public:
    explicit TurnXFull(CubeModel &cube, bool reverse);
    void update(float delta) override;
};

class TurnYFull : public Animation {
public:
    explicit TurnYFull(CubeModel &cube, bool reverse);
    void update(float delta) override;
};

class TurnZFull : public Animation {
public:
    explicit TurnZFull(CubeModel &cube, bool reverse);
    void update(float delta) override;
};