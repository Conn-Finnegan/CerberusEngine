#include "InputManager.h"
#include <iostream>

bool InputManager::keys[1024] = { false };

void InputManager::setup(GLFWwindow* window) {
    glfwSetKeyCallback(window, onKeyCallback);
}

bool InputManager::isKeyPressed(int key) {
    return keys[key];
}

void InputManager::onKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keys[key] = true;
        std::cout << "Key Pressed: " << key << std::endl;
    }
    else if (action == GLFW_RELEASE) {
        keys[key] = false;
        std::cout << "Key Released: " << key << std::endl;
    }
}
