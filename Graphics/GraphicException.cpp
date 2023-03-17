#include "GraphicException.h"

GraphicException::GraphicException(const std::string &message) : message(message) {}

const char *GraphicException::what() const noexcept {
    return this->message.c_str();
}
