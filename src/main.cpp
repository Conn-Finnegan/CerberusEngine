#include "Core.h"
#include "TriangleRenderer.h"

int main() {
    auto core = Core::initialize();

    auto entity = core->addEntity();
    entity->addComponent<TriangleRenderer>();

    core->run();
    return 0;
}



