#pragma once // Header included once

#include <string> //    Include string for handling text
#include <glm/glm.hpp> //   Include GLM for matrix

//  Shader class to handle shaders 
class Shader {
public:

    //  Constructor that takes paths to the vertex and fragement shaders
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    //  Activate shader program 
    void use();

    //  Set 4x4 matrix unfirom in the shader 
    void setMat4(const std::string& name, const glm::mat4& mat);

    //  Destructor 
    ~Shader();

private:

    unsigned int id; // ID of the shader program 

    //  Load the shader froma file 
    std::string loadShaderSource(const std::string& filePath);

    //  Compile sahder from file 
    void compileShader(unsigned int shader, const std::string& source);
};
