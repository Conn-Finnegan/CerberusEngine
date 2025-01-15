#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <iostream>

template <typename Resource>
class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    std::shared_ptr<Resource> load(const std::string& id, const std::string& path) {
        auto it = resources.find(id);
        if (it != resources.end()) {
            std::cout << "Resource [" << id << "] already loaded. Using cached version.\n";
            return it->second;
        }

        std::shared_ptr<Resource> resource = std::make_shared<Resource>();
        if (!resource->loadFromFile(path)) {
            throw std::runtime_error("Failed to load resource from " + path);
        }

        resources[id] = resource;
        std::cout << "Resource [" << id << "] loaded successfully.\n";
        return resource;
    }

    std::shared_ptr<Resource> get(const std::string& id) const {
        auto it = resources.find(id);
        if (it == resources.end()) {
            throw std::runtime_error("Resource [" + id + "] not found in cache.");
        }
        return it->second;
    }

    void release(const std::string& id) {
        auto it = resources.find(id);
        if (it != resources.end()) {
            resources.erase(it);
            std::cout << "Resource [" << id << "] released.\n";
        }
    }

    void releaseAll() {
        resources.clear();
        std::cout << "All resources released.\n";
    }

private:
    ResourceManager() = default;
    ~ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    std::unordered_map<std::string, std::shared_ptr<Resource>> resources;
};

#endif // RESOURCEMANAGER_H
