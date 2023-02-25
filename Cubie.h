#pragma once

class Cubie {
protected:
    unsigned int _original_id; // index in solved state
    unsigned int _twist_state; // number of twists

public:
    explicit Cubie(unsigned int id);
    Cubie();

    unsigned int get_original_id() const;
    unsigned int get_twist_state() const;
};

class EdgeCubie : public Cubie {
public:
    explicit EdgeCubie(unsigned int id);
    EdgeCubie();

    EdgeCubie& operator=(const EdgeCubie& other);

    void twist();
};

class CornerCubie : public Cubie {
public:
    explicit CornerCubie(unsigned int id);
    CornerCubie();

    CornerCubie& operator=(const CornerCubie& other);

    void twist(unsigned int count);
};