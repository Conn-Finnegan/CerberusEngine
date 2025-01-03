#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
public:
    static void setup(GLFWwindow* window);
    static bool isKeyPressed(int key);
    static void onKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    static bool keys[1024];
};

#endif
