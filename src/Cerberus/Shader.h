#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    void setMat4(const std::string& name, const glm::mat4& mat);
    ~Shader();

private:
    unsigned int id;
    std::string loadShaderSource(const std::string& filePath);
    void compileShader(unsigned int shader, const std::string& source);
};
