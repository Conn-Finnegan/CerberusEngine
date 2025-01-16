#pragma once // Header included once

#include "Component.h" // Include component class
#include "Shader.h"//   Include shader class

//  TriangleRenderer class derrived from component 
class TriangleRenderer : public Component {
public:

    //  Constructor 
    TriangleRenderer();

    // Called on each update cycle 
    void onTick() override;

    //Called during rendering
    void onRender() override;

    //  Destructor 
    ~TriangleRenderer();

private:
    unsigned int VAO, VBO; //   Vertex Array Object and Vertex Buffer Object
    std::shared_ptr<Shader> shader; //  Shader used for rendering the triangle 
};
