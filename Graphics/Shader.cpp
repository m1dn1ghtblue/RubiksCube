#include <fstream>
#include <iostream>
#include <sstream>
#include "Shader.h"
#include "glm/gtc/type_ptr.hpp"
#include "GraphicException.h"

Shader::Shader(const std::string &vertexSourcePath, const std::string &fragmentSourcePath) {
    unsigned int vertexRendererId, fragmentRendererId;
    vertexRendererId = loadShader(vertexSourcePath, VERTEX);
    fragmentRendererId = loadShader(fragmentSourcePath, FRAGMENT);

    glCompileShader(vertexRendererId);
    glCompileShader(fragmentRendererId);

    rendererId = glCreateProgram();

    glAttachShader(rendererId, vertexRendererId);
    glAttachShader(rendererId, fragmentRendererId);
    glLinkProgram(rendererId);

#ifdef DEBUG_LOG
    checkCompilationErrorLog(vertexRendererId, VERTEX);
    checkCompilationErrorLog(fragmentRendererId, FRAGMENT);
    checkLinkingErrorLog();
#endif

    glDeleteShader(vertexRendererId);
    glDeleteShader(fragmentRendererId);
}

unsigned int Shader::loadShader(const std::string &path, ShaderType type) {
    unsigned int shaderId = glCreateShader((type == VERTEX) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    std::string sourceStr = readSource(path);
    const char* source = sourceStr.c_str();
    glShaderSource(shaderId, 1, &source, nullptr); /* attach source code to shader
                                                    (last parameter can be an array of provided strings lengths
                                                    in case if more than one string is provided) */
    return shaderId;
}

std::string Shader::readSource(const std::string& path) {
    std::ifstream fileStream(path);
    if (!fileStream.is_open()) {
        throw GraphicException("Could not open file " + path);
    }
    std::string code;

    std::stringstream shaderStream;
    shaderStream << fileStream.rdbuf();
    code = shaderStream.str();
    fileStream.close();

    return code;
}

void Shader::checkCompilationErrorLog(unsigned int shaderId, ShaderType type) const {
    int success;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        char log[512];
        glGetShaderInfoLog(shaderId, 512, nullptr, log); // 3rd parameter - "returns" actual length of returned log
        std::cerr << "[" << (type == VERTEX ? "Vertex" : "Fragment") << " shader compilation error]:\n" << log << "\n";
    }
    else {
        std::cerr << (type == VERTEX ? "Vertex" : "Fragment") << " shader compilation successful!\n";
    }
}

void Shader::checkLinkingErrorLog() const {
    int success;
    glGetProgramiv(rendererId, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        char log[512];
        glGetShaderInfoLog(rendererId, 512, nullptr, log);
        std::cerr << "[Shader program linking error]:\n" << log << "\n";
    }
    else {
        std::cerr << "Shader program successfully linked!\n";
    }
}

void Shader::use() const {
    glUseProgram(rendererId);
}

int Shader::getLocation(const std::string &uniformName) {
    if (!uniformCache.contains(uniformName)) {
        int location = glGetUniformLocation(rendererId, uniformName.c_str());
#ifdef DEBUG_LOG
        if (location == -1) std::cerr << "Uniform " << uniformName << " does not exist!\n";
#endif
        uniformCache[uniformName] = location;
    }

    return uniformCache[uniformName];
}

void Shader::setFloat1(const std::string &uniformName, float v1) {
    glUniform1f(getLocation(uniformName), v1);
}

void Shader::setFloat2(const std::string &uniformName, float v1, float v2) {
    glUniform2f(getLocation(uniformName), v1, v2);
}

void Shader::setFloat3(const std::string &uniformName, float v1, float v2, float v3) {
    glUniform3f(getLocation(uniformName), v1, v2, v3);
}

void Shader::setFloat4(const std::string &uniformName, float v1, float v2, float v3, float v4) {
    glUniform4f(getLocation(uniformName), v1, v2, v3, v4);
}

void Shader::setInt1(const std::string &uniformName, int v1) {
    glUniform1i(getLocation(uniformName), v1);
}

void Shader::setInt2(const std::string &uniformName, int v1, int v2) {
    glUniform2i(getLocation(uniformName), v1, v2);
}

void Shader::setInt3(const std::string &uniformName, int v1, int v2, int v3) {
    glUniform3i(getLocation(uniformName), v1, v2, v3);
}

void Shader::setInt4(const std::string &uniformName, int v1, int v2, int v3, int v4) {
    glUniform4i(getLocation(uniformName), v1, v2, v3, v4);
}

void Shader::setMatrixFloat4(const std::string &uniformName, glm::mat4 &matrix) {
    glUniformMatrix4fv(getLocation(uniformName), 1, GL_FALSE, glm::value_ptr(matrix));
}

