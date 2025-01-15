#pragma once

#include <GLFW/glfw3.h>
#include <memory>
#include <glm/glm.hpp>

class Camera;

class InputHandler {
public:
    explicit InputHandler(std::shared_ptr<Camera> camera);

    void handleKeyboardInput(GLFWwindow* window, float deltaTime);
    void handleMouseInput(GLFWwindow* window, double xpos, double ypos);

    void setMouseSensitivity(float sensitivity);
    void setFirstMouse(bool isFirst);

private:
    std::shared_ptr<Camera> camera;
    bool firstMouse = true;
    float lastX = 400.0f; 
    float lastY = 300.0f; 
    float mouseSensitivity = 0.2f; 
};

