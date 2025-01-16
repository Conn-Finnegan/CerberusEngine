#pragma once // Header only included once 

#include <GLFW/glfw3.h> //  Include GLFW for window 
#include <memory> //    Include memory for management 
#include <glm/glm.hpp> //   Include GLM

class Camera; //    Declare camera class

// InputHandler class to manage keybaord and mouse inputs 
class InputHandler {
public:

    //  Constructor takes shared ptr to camera object 
    explicit InputHandler(std::shared_ptr<Camera> camera);

    //  Handle keybaord input for specified window and delat time
    void handleKeyboardInput(GLFWwindow* window, float deltaTime);

    //  Handle mouse movement for specified window and delta time 
    void handleMouseInput(GLFWwindow* window, double xpos, double ypos);

    //  Set sensitivity of the mouse 
    void setMouseSensitivity(float sensitivity);

    //  Set if this is the fitst mouse input
    void setFirstMouse(bool isFirst);

private:
    std::shared_ptr<Camera> camera; //  Shared ptr to camera object
    bool firstMouse = true; //  Bool to check if this is the first mouse input 
    float lastX = 400.0f;  //   Last xpos of mouse
    float lastY = 300.0f; //    Lasy ypos of mouse
    float mouseSensitivity = 0.2f; //   Sensitivity of mouse 
};

