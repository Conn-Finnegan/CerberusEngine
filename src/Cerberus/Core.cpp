#include "Core.h"
#include "CubeRenderer.h"
#include <GLFW/glfw3.h>

std::shared_ptr<Core> Core::initialize() {
    auto core = std::shared_ptr<Core>(new Core());
    core->camera = std::make_shared<Camera>();
    core->inputHandler = std::make_shared<InputHandler>(core->camera);
    core->renderer = Renderer::getInstance();
    core->renderer->init(800, 600, "Cerberus Game Engine");
    core->running = true;

    //  Core instance with the GLFW window
    glfwSetWindowUserPointer(core->renderer->getWindow(), core.get());

    core->initializeInputHandler();
    return core;
}

void Core::initializeInputHandler() {
    auto window = renderer->getWindow();

    // Set GLFW mouse input callback
    glfwSetCursorPosCallback(window, Core::mouseCallback);

    // Disable the cursor for camera control
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Core::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    Core* core = static_cast<Core*>(glfwGetWindowUserPointer(window));
    if (core && core->inputHandler) {
        core->inputHandler->handleMouseInput(window, xpos, ypos);
    }
}

void Core::run() {
    float lastFrame = 0.0f;

    while (running && !renderer->getWindowShouldClose()) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        renderer->clear();
        inputHandler->handleKeyboardInput(renderer->getWindow(), deltaTime);

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
        auto cubeRenderer = entity->getComponent<CubeRenderer>();
        if (cubeRenderer) {
            cubeRenderer->getShader()->setMat4("view", camera->getViewMatrix());
            cubeRenderer->getShader()->setMat4("projection",
                camera->getProjectionMatrix(45.0f, 800.0f / 600.0f, 0.1f, 100.0f));
        }
        entity->render();
    }
}





