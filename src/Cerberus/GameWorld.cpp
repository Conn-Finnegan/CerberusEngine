#include "GameWorld.h"
#include <iostream>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

bool GameWorld::init(int width, int height, const std::string& title) {
    if (!renderer.init(width, height, title)) {
        return false;
    }

    InputManager::setup(renderer.getWindow());
    return true;
}

void GameWorld::run() {
    while (!renderer.shouldClose()) {
        renderer.clear(0.2f, 0.3f, 0.3f, 1.0f);
        renderer.drawTriangle();  // Render the triangle
        renderer.swapBuffers();
        glfwPollEvents();
    }
}

