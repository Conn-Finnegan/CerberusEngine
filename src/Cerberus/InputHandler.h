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
    float lastX = 400.0f; // Initial mouse x-position
    float lastY = 300.0f; // Initial mouse y-position
    float mouseSensitivity = 0.1f; // Default sensitivity
};
