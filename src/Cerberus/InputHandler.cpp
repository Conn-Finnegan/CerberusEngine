#include "InputHandler.h"
#include "Camera.h"
#include "CollisionHandler.h"

InputHandler::InputHandler(std::shared_ptr<Camera> camera)
    : camera(std::move(camera)) {}

void InputHandler::handleKeyboardInput(GLFWwindow* window, float deltaTime) {
    glm::vec3 nextPosition = camera->position; // Start with the current position

    // Process keyboard input for camera movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        nextPosition += camera->front * camera->movementSpeed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        nextPosition -= camera->front * camera->movementSpeed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        nextPosition -= camera->right * camera->movementSpeed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        nextPosition += camera->right * camera->movementSpeed * deltaTime;

    
    glm::vec3 cubeMin = glm::vec3(-0.7f, -0.7f, -0.7f); 
    glm::vec3 cubeMax = glm::vec3(0.7f, 0.7f, 0.7f);

    // Use CollisionHandler to check for collision
    if (!CollisionHandler::isPointInsideAABB(nextPosition, cubeMin, cubeMax)) {
       
        camera->position = nextPosition;
    }
}

void InputHandler::handleMouseInput(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = static_cast<float>(xpos);
        lastY = static_cast<float>(ypos);
        firstMouse = false;
    }

    
    float xoffset = static_cast<float>(xpos) - lastX;
    float yoffset = lastY - static_cast<float>(ypos);
    lastX = static_cast<float>(xpos);
    lastY = static_cast<float>(ypos);

    // camera rotation based on mouse movement
    camera->processMouseMovement(xoffset * mouseSensitivity, yoffset * mouseSensitivity);
}

void InputHandler::setMouseSensitivity(float sensitivity) {
    mouseSensitivity = sensitivity;
}

void InputHandler::setFirstMouse(bool isFirst) {
    firstMouse = isFirst;
}

