#include "Maze.h"
#include <iostream>
#include <glad/glad.h>
#include <glm.hpp>

Maze::Maze() {}

void Maze::draw() {
    for (int z = 0; z < height; ++z) {
        for (int x = 0; x < width; ++x) {
            if (layout[z][x] == 1) {
                std::cout << "Wall at (" << x << ", " << z << ")\n";
            }
            else if (layout[z][x] == 3) {
                std::cout << "Goal at (" << x << ", " << z << ")\n";
            }
        }
    }
}

bool Maze::isWall(int x, int z) const {
    return x >= 0 && z >= 0 && x < width && z < height && layout[z][x] == 1;
}

bool Maze::isGoal(int x, int z) const {
    return x >= 0 && z >= 0 && x < width && z < height && layout[z][x] == 3;
}
