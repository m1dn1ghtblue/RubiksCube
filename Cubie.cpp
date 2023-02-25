#include "Cubie.h"
#include <stdexcept>

Cubie::Cubie(unsigned int id, unsigned int max_twist_state) : _original_id(id), _max_twist_state(max_twist_state) {
    _twist_state = 0;
}

Cubie::Cubie() : _original_id(0), _twist_state(0), _max_twist_state(0) {}

unsigned int Cubie::get_original_id() const {
    return this->_original_id;
}

unsigned int Cubie::get_twist_state() const {
    return this->_twist_state;
}

void Cubie::twist(unsigned int count) {
    _twist_state = (_twist_state + count) % (_max_twist_state + 1);
}

EdgeCubie::EdgeCubie(unsigned int id) : Cubie(id, 1) {
    if (id > 7) {
        throw std::invalid_argument("Invalid edge cubie id: " + std::to_string(id));
    }
}

EdgeCubie::EdgeCubie() : Cubie(0, 1) {}

EdgeCubie& EdgeCubie::operator=(const EdgeCubie &other) {
    if (this != &other) {
        this->_twist_state = other.get_twist_state();
        this->_original_id = other.get_original_id();
    }
    return *this;
}

CornerCubie::CornerCubie(unsigned int id) : Cubie(id, 2) {
    if (id > 11) {
        throw std::invalid_argument("Invalid corner cubie id: " + std::to_string(id));
    }
}

CornerCubie::CornerCubie() : Cubie(0, 2) {}

CornerCubie& CornerCubie::operator=(const CornerCubie &other) {
    if (this != &other) {
        this->_twist_state = other.get_twist_state();
        this->_original_id = other.get_original_id();
    }
    return *this;
}