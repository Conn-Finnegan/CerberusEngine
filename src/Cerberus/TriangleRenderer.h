#pragma once

#include "Component.h"
#include "Shader.h"

class TriangleRenderer : public Component {
public:
    TriangleRenderer();
    void onTick() override;
    void onRender() override;
    ~TriangleRenderer();

private:
    unsigned int VAO, VBO;
    std::shared_ptr<Shader> shader;
};
