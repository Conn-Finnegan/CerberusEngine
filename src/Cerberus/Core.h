#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Renderer.h"

class Core : public std::enable_shared_from_this<Core> {
public:
    static std::shared_ptr<Core> initialize();
    std::shared_ptr<Entity> addEntity();
    void run();
    void stop();

private:
    Core() = default; // Keep the constructor private
    bool running = false;
    std::vector<std::shared_ptr<Entity>> entities;
    std::shared_ptr<Renderer> renderer;

    void tickEntities();
    void renderEntities();

    // Friend class declaration is no longer necessary
};


