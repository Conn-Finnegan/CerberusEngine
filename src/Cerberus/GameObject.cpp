#include "GameObject.h"

GameObject::GameObject(glm::vec3 position, glm::vec3 scale)
    : position(position), scale(scale) {
}

void GameObject::setPosition(const glm::vec3& pos) {
    position = pos;
}

void GameObject::setScale(const glm::vec3& scale) {
    this->scale = scale;
}

glm::vec3 GameObject::getPosition() const {
    return position;
}

glm::vec3 GameObject::getScale() const {
    return scale;
}
