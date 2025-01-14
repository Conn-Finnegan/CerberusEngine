#include "Core.h"
#include <GLFW/glfw3.h>

std::shared_ptr<Core> Core::initialize() {
    auto core = std::shared_ptr<Core>(new Core());
    core->camera = std::make_shared<Camera>();
    core->inputHandler = std::make_shared<InputHandler>(core->camera);
    core->renderer = Renderer::getInstance();
    core->renderer->init(800, 600, "Cerberus Game Engine");
    core->running = true;

    // Initialize input handling
    core->initializeInputHandler();

    return core;
}

void Core::initializeInputHandler() {
    auto window = renderer->getWindow();

    // Set mouse input callback to delegate to InputHandler
    glfwSetCursorPosCallback(window, [](GLFWwindow* win, double xpos, double ypos) {
        auto core = Core::getInstance();
        if (core) {
            core->inputHandler->handleMouseInput(win, xpos, ypos);
        }
        });

    // Disable the cursor for camera control
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Core::run() {
    float lastFrame = 0.0f;

    while (running && !renderer->getWindowShouldClose()) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Clear the screen
        renderer->clear();

        // Handle keyboard input through InputHandler
        inputHandler->handleKeyboardInput(renderer->getWindow(), deltaTime);

        // Update and render entities
        tickEntities();
        renderEntities();

        // Swap buffers and poll events
        renderer->swapBuffers();
        glfwPollEvents();
    }
}

void Core::stop() {
    running = false;
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



