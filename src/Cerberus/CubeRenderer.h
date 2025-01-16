#pragma once // Header is only included once

#include "Component.h" //   Include base component class
#include "Shader.h" //  Include shader class

//  CubeRenderer class derrived from component class
class CubeRenderer : public Component {
public:
    //Constructor 
    CubeRenderer();

    //  Called each update cycle
    void onTick() override;

    //  Called during render phase 
    void onRender() override;

    //Destructor 
    ~CubeRenderer();

    //  Returns thr shader that is being used 
    std::shared_ptr<Shader> getShader() const { return shader; } 

private:

    // Vertex Array Object and Vertex Buffer Object
    unsigned int VAO, VBO;

    //  Shader used for rendering the cube 
    std::shared_ptr<Shader> shader; 
};

