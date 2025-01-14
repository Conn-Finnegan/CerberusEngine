#pragma once

#include <memory>
#include <vector>
#include "Component.h"

class Core;

class Entity : public std::enable_shared_from_this<Entity> {
public:
    template <typename T, typename... Args>
    std::shared_ptr<T> addComponent(Args&&... args) {
        auto component = std::make_shared<T>(std::forward<Args>(args)...);
        component->entity = shared_from_this(); // Set entity reference
        components.push_back(component);
        return component;
    }
    template <typename T>
    std::shared_ptr<T> getComponent() {
        for (const auto& component : components) {
            auto casted = std::dynamic_pointer_cast<T>(component);
            if (casted) {
                return casted;
            }
        }
        return nullptr; 
    }


    void tick();
    void render();

private:
    std::vector<std::shared_ptr<Component>> components;
    std::weak_ptr<Core> core; // Allow Core to access this member
    friend class Core;        // Make Core a friend class
};





