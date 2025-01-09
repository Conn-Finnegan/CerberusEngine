#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic(Maze& maze, Ball& ball)
    : maze(maze), ball(ball), gameOver(false), won(false) {
}

void GameLogic::update(float deltaTime) {
    if (maze.isGoal((int)ball.getPosition().x, (int)ball.getPosition().z)) {
        won = true;
        gameOver = true;
        std::cout << "You win!" << std::endl;
    }

    // Add other conditions like falling into traps or timers here if needed
}

bool GameLogic::isGameOver() const {
    return gameOver;
}

bool GameLogic::hasWon() const {
    return won;
}
