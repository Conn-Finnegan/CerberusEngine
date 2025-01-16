
#pragma once // Header included once

#include <unordered_map> // Include for storing resources 
#include <string> //    Include string for handling text
#include <memory>  //   Include for memory managment 
#include "Shader.h" //  Include the shader class

//  Class to manage loading and releasing resources 
class ResourceManager {
public:
    // Load Shader from given file paths 
    static Shader* LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);

    // Release all resources
    static void ReleaseAll();

private:

    //  Map to store shaders with their names as keys 
    static std::unordered_map<std::string, std::unique_ptr<Shader>> shaders;
};
