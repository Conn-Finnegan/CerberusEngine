#include "GameWorld.h"
#include "Maze.h"
#include "Ball.h"
#include "GameLogic.h"
#include "InputManager.h"

void GameWorld::run() {
    Maze maze;
    Ball ball;
    GameLogic gameLogic(maze, ball);

    double lastTime = glfwGetTime();

    while (!renderer.shouldClose()) {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        glm::vec2 tilt(0.0f);
        if (InputManager::isKeyPressed(GLFW_KEY_UP)) tilt.y += 1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_DOWN)) tilt.y -= 1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_LEFT)) tilt.x -= 1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_RIGHT)) tilt.x += 1.0f;

        // Update ball and game logic
        ball.update(deltaTime, maze, tilt);
        gameLogic.update(deltaTime);

        if (gameLogic.isGameOver()) {
            break;
        }

        // Render the scene
        renderer.clear(0.2f, 0.3f, 0.3f, 1.0f);
        maze.draw();
        ball.render();
        renderer.swapBuffers();

        glfwPollEvents();
    }
}
