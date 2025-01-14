#include "Core.h"
#include "Entity.h"
#include "Renderer.h"
#include "CubeRenderer.h"
#include "Camera.h"

std::shared_ptr<Core> Core::initialize() {
    auto core = std::shared_ptr<Core>(new Core());
    core->renderer = Renderer::getInstance();
    core->renderer->init(800, 600, "Cerberus Game Engine");
    core->camera = std::make_shared<Camera>(glm::vec3(0.0f, 0.0f, 3.0f)); // Initialize camera
    core->running = true;
    return core;
}

void Core::run() {
    while (running && !renderer->getWindowShouldClose()) {
        renderer->clear();

        // Update all entities
        tickEntities();

        // Render all entities
        for (auto& entity : entities) {
            auto cubeRenderer = entity->getComponent<CubeRenderer>();
            if (cubeRenderer) {
                // Use accessor method to get the shader
                cubeRenderer->getShader()->setMat4("view", camera->getViewMatrix());
                cubeRenderer->getShader()->setMat4("projection",
                    camera->getProjectionMatrix(45.0f, 800.0f / 600.0f, 0.1f, 100.0f));
            }
            entity->render();
        }




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

void Core::stop() {
    running = false;
}



