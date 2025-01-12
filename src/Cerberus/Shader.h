#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    ~Shader();

private:
    unsigned int id;
    std::string loadShaderSource(const std::string& filePath);
    void compileShader(unsigned int shader, const std::string& source);
};

#endif // SHADER_H
