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
    std::shared_ptr<Entity> addEntity();

    // Mouse input processing
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);

private:
    Core() = default;

    bool running = false;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<InputHandler> inputHandler;
    std::shared_ptr<Renderer> renderer;
    std::vector<std::shared_ptr<Entity>> entities;

    void initializeInputHandler();
    void tickEntities();
    void renderEntities();
};




