#include "Core.h"
#include "CubeRenderer.h"

int main() {
    auto core = Core::initialize();
    auto cubeEntity = core->addEntity();
    cubeEntity->addComponent<CubeRenderer>();
    core->run();
    return 0;
}



