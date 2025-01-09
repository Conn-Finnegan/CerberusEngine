#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm.hpp>

class GameObject {
public:
    GameObject(glm::vec3 position = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));
    virtual ~GameObject() = default;

    // Pure virtual functions for update and render
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;

    // Setters and getters
    void setPosition(const glm::vec3& pos);
    void setScale(const glm::vec3& scale);

    glm::vec3 getPosition() const;
    glm::vec3 getScale() const;

protected:
    glm::vec3 position;
    glm::vec3 scale;
};

#endif


