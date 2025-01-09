#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Maze.h"
#include "Ball.h"

class GameLogic {
public:
    GameLogic(Maze& maze, Ball& ball);

    void update(float deltaTime);
    bool isGameOver() const;
    bool hasWon() const;

private:
    Maze& maze;
    Ball& ball;
    bool gameOver;
    bool won;
};

#endif
