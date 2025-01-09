#pragma once
#ifndef MAZE_H
#define MAZE_H

class Maze {
public:
    Maze();
    void draw();
    bool isWall(int x, int z) const;
    bool isGoal(int x, int z) const;

    static const int width = 5;
    static const int height = 5;

private:
    const int layout[height][width] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 3, 1},
        {1, 0, 1, 0, 1},
        {1, 2, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };
};

#endif
