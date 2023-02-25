#include "Cubie.h"
#include <stdexcept>

Cubie::Cubie(unsigned int id) : _original_id(id), _twist_state(0) {}

Cubie::Cubie() : _original_id(0), _twist_state(0) {}

unsigned int Cubie::get_original_id() const {
    return this->_original_id;
}

unsigned int Cubie::get_twist_state() const {
    return this->_twist_state;
}

EdgeCubie::EdgeCubie(unsigned int id) : Cubie(id) {
    if (id > 7) {
        throw std::invalid_argument("Invalid edge cubie id: " + std::to_string(id));
    }
}
EdgeCubie::EdgeCubie() : Cubie() {}

void EdgeCubie::twist() {
    _twist_state = (_twist_state + 1) % 2;
}


EdgeCubie& EdgeCubie::operator=(const EdgeCubie &other) {
    if (this != &other) {
        this->_twist_state = other.get_twist_state();
        this->_original_id = other.get_original_id();
    }
    return *this;
}

CornerCubie::CornerCubie(unsigned int id) : Cubie(id) {
    if (id > 11) {
        throw std::invalid_argument("Invalid corner cubie id: " + std::to_string(id));
    }
}

CornerCubie::CornerCubie() : Cubie() {}

CornerCubie& CornerCubie::operator=(const CornerCubie &other) {
    if (this != &other) {
        this->_twist_state = other.get_twist_state();
        this->_original_id = other.get_original_id();
    }
    return *this;
}

void CornerCubie::twist(unsigned int count) {
    if (count > 2) {
        throw std::invalid_argument("Twist count for corner cubie can not be greater than 2");
    }

    _twist_state = (_twist_state + count) % 3;
}