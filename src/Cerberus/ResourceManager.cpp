// ResourceManager.cpp
#include "ResourceManager.h"

std::unordered_map<std::string, std::unique_ptr<Shader>> ResourceManager::shaders;

Shader* ResourceManager::LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {
    if (shaders.find(name) != shaders.end()) {
        return shaders[name].get();
    }
    auto shader = std::make_unique<Shader>(vertexPath, fragmentPath);
    shaders[name] = std::move(shader);
    return shaders[name].get();
}

void ResourceManager::ReleaseAll() {
    shaders.clear();
}
