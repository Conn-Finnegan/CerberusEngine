#pragma once

#include "Component.h"
#include "Shader.h"

class CubeRenderer : public Component {
public:
    CubeRenderer();
    void onTick() override;
    void onRender() override;
    ~CubeRenderer();

    std::shared_ptr<Shader> getShader() const { return shader; } // Accessor method

private:
    unsigned int VAO, VBO;
    std::shared_ptr<Shader> shader; // Keeps this member private
};

