#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <GLFW/glfw3.h>
#include <string>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool init(int width, int height, const std::string& title);
    void clear(float r, float g, float b, float a);
    void swapBuffers();
    bool shouldClose() const;
    GLFWwindow* getWindow() const;

    void drawTriangle();  // New method for drawing a triangle

private:
    GLFWwindow* window;
    unsigned int createShaderProgram();  // Method for creating shader programs
};

#endif

