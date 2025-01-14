#include "Core.h"
#include "CubeRenderer.h"

int main() {
    auto core = Core::initialize();

    // Add an entity with a CubeRenderer
    auto cubeEntity = core->addEntity();
    cubeEntity->addComponent<CubeRenderer>();

    // Run the game engine
    core->run();

    return 0;
}



