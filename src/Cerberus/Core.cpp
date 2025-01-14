#include "Core.h"
#include "Entity.h"
#include "Renderer.h"

std::shared_ptr<Core> Core::initialize() {
    auto core = std::shared_ptr<Core>(new Core()); // Explicitly use `new`
    core->renderer = Renderer::getInstance();
    core->renderer->init(800, 600, "Engine with Core");
    core->running = true;
    return core;
}

void Core::run() {
    while (running && !renderer->getWindowShouldClose()) {
        renderer->clear();

        tickEntities();
        renderEntities();

        renderer->swapBuffers();
        glfwPollEvents();
    }
}

std::shared_ptr<Entity> Core::addEntity() {
    auto entity = std::make_shared<Entity>();
    entity->core = shared_from_this();
    entities.push_back(entity);
    return entity;
}

void Core::tickEntities() {
    for (auto& entity : entities) {
        entity->tick();
    }
}

void Core::renderEntities() {
    for (auto& entity : entities) {
        entity->render();
    }
}

void Core::stop() {
    running = false;
}



