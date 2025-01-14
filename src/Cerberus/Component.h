#pragma once

#include <memory>

class Entity;

class Component {
public:
    virtual void onTick() {}
    virtual void onRender() {}
    virtual ~Component() = default;

protected:
    std::weak_ptr<Entity> entity; // Back-reference to the owning Entity
    friend class Entity;          // Grant access to Entity
};

