#pragma once

#include <string>
#include <unordered_map>
#include "GL/glew.h"
#include "glm/glm.hpp"


enum ShaderType { VERTEX = 0, FRAGMENT = 1 };

class Shader {
private:
    unsigned int rendererId;
    std::unordered_map<std::string, int> uniformCache;

    unsigned int loadShader(const std::string &path, ShaderType type);
    std::string readSource(const std::string& path);
    void checkCompilationErrorLog(unsigned int shaderId, ShaderType type) const;
    void checkLinkingErrorLog() const;
    int getLocation(const std::string& uniformName);

public:
    Shader(const std::string& vertexSourcePath, const std::string& fragmentSourcePath);
    ~Shader();

    void use() const;

    // to set uniforms don't forget to call program.use() before
    void setFloat1(const std::string& uniformName, float v1);
    void setFloat2(const std::string& uniformName, float v1, float v2);
    void setFloat3(const std::string& uniformName, float v1, float v2, float v3);
    void setFloat4(const std::string& uniformName, float v1, float v2, float v3, float v4);

    void setInt1(const std::string& uniformName, int v1);
    void setInt2(const std::string& uniformName, int v1, int v2);
    void setInt3(const std::string& uniformName, int v1, int v2, int v3);
    void setInt4(const std::string& uniformName, int v1, int v2, int v3, int v4);

    void setMatrixFloat4(const std::string& uniformName, glm::mat4& matrix);
};

