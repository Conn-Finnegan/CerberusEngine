#pragma once
#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Renderer.h"
#include "InputManager.h"

class GameWorld {
public:
    GameWorld();
    ~GameWorld();

    bool init(int width, int height, const std::string& title);
    void run();

private:
    Renderer renderer;
};

#endif
