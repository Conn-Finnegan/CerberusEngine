#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"

class Core : public std::enable_shared_from_this<Core> {
public:
    static std::shared_ptr<Core> initialize();
    std::shared_ptr<Entity> addEntity();
    void run();
    void stop();

private:
    Core() = default; // Private constructor
    bool running = false;
    std::vector<std::shared_ptr<Entity>> entities;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<Camera> camera; // Camera for 3D rendering

    void tickEntities();
    void renderEntities();
};


