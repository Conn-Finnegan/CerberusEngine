#include "Cerberus/GameWorld.h"

int main() {
    GameWorld gameWorld;

    if (!gameWorld.init(800, 600, "Game Engine")) {
        return -1;
    }

    gameWorld.run();

    return 0;
}
