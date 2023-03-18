#pragma once
#include <string>

class Texture {
private:
    unsigned int rendererId;
public:
    Texture(std::string path);

    void bind() const;
};
