// ResourceManager.h
#pragma once

#include <unordered_map>
#include <string>
#include <memory> // for std::unique_ptr
#include "Shader.h"

class ResourceManager {
public:
    // Load Shader
    static Shader* LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);

    // Release all resources
    static void ReleaseAll();

private:
    static std::unordered_map<std::string, std::unique_ptr<Shader>> shaders;
};
