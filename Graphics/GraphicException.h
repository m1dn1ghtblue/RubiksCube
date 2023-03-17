#pragma once
#include <exception>
#include <string>

class GraphicException : public std::exception {
private:
    std::string message;
public:
    explicit GraphicException(const std::string& message);
    [[nodiscard]] const char * what() const noexcept override;
};
