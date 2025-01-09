#pragma once
#ifndef BALL_H
#define BALL_H

#include <glm.hpp>
#include "GameObject.h"
#include "Maze.h"

class Ball : public GameObject {
public:
    Ball();

    // Update takes 3 arguments: deltaTime, the maze, and tilt direction
    void update(float deltaTime, const Maze& maze, glm::vec2 tilt) override;
    void render() const override;

private:
    glm::vec3 velocity;
    float radius;
};

#endif


