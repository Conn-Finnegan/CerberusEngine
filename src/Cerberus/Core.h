#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"
#include "InputHandler.h"

class Core : public std::enable_shared_from_this<Core> {
public:
    static std::shared_ptr<Core> initialize();
    void run();
    void stop();

    // Mouse input processing
    void processMouseInput(GLFWwindow* window, double xpos, double ypos);

private:
    Core() = default; // Private constructor to enforce initialization via `initialize`

    bool running = false;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<InputHandler> inputHandler;
    std::shared_ptr<Renderer> renderer;
    std::vector<std::shared_ptr<Entity>> entities;

    void tickEntities();
    void renderEntities();
};


