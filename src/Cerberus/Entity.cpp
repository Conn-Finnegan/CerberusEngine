#include "Entity.h"
#include "Core.h"

void Entity::tick() {
    for (auto& component : components) {
        component->onTick();
    }
}

void Entity::render() {
    for (auto& component : components) {
        component->onRender();
    }
}



