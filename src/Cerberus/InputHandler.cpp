#include "InputHandler.h"
#include "Camera.h"

InputHandler::InputHandler(std::shared_ptr<Camera> camera)
    : camera(std::move(camera)) {}

void InputHandler::handleKeyboardInput(GLFWwindow* window, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->processKeyboard("FORWARD", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->processKeyboard("BACKWARD", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->processKeyboard("LEFT", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->processKeyboard("RIGHT", deltaTime);
}

void InputHandler::handleMouseInput(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Reversed since y-coordinates range from bottom to top
    lastX = xpos;
    lastY = ypos;

    camera->processMouseMovement(xoffset * mouseSensitivity, yoffset * mouseSensitivity);
}

void InputHandler::setMouseSensitivity(float sensitivity) {
    mouseSensitivity = sensitivity;
}

void InputHandler::setFirstMouse(bool isFirst) {
    firstMouse = isFirst;
}
