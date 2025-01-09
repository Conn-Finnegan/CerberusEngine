#include "Ball.h"
#include <iostream>
#include <glad/glad.h>
#include <gtc/matrix_transform.hpp>

Ball::Ball() : GameObject(glm::vec3(1.5f, 0.5f, 3.5f)), velocity(0.0f), radius(0.2f) {}

void Ball::update(float deltaTime, const Maze& maze, glm::vec2 tilt) {
    // Apply gravity based on tilt
    glm::vec3 gravity(tilt.x, 0, tilt.y);
    velocity += gravity * deltaTime;

    // Calculate the next position
    glm::vec3 nextPosition = position + velocity * deltaTime;

    // Collision detection with walls
    if (!maze.isWall(static_cast<int>(nextPosition.x), static_cast<int>(nextPosition.z))) {
        position = nextPosition;
    }
    else {
        velocity = glm::vec3(0.0f); // Stop movement on collision
    }
}

void Ball::render() const {
    // Replace with actual rendering logic for the ball
    std::cout << "Ball rendered at position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
}


