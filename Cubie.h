#pragma once

class Cubie {
protected:
    const unsigned int _max_twist_state;
    unsigned int _original_id; // index in solved state
    unsigned int _twist_state; // number of twists

public:
    explicit Cubie(unsigned int id, unsigned int twist_state_number);

    Cubie();
    unsigned int get_original_id() const;
    unsigned int get_twist_state() const;

    void twist(unsigned int count);
};

class EdgeCubie : public Cubie {
public:
    explicit EdgeCubie(unsigned int id);
    EdgeCubie();
    EdgeCubie& operator=(const EdgeCubie& other);
};

class CornerCubie : public Cubie {
public:
    explicit CornerCubie(unsigned int id);
    CornerCubie();
    CornerCubie& operator=(const CornerCubie& other);
};