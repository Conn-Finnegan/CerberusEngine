#include "Core.h"
#include "CubeRenderer.h"

int main() {
    auto core = Core::initialize();
    auto cubeEntity = core->addEntity();
    cubeEntity->addComponent<CubeRenderer>();
    core->run(); // Depth buffer will now be used correctly
    return 0;
}



