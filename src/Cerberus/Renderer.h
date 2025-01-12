#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Renderer {
public:
    static Renderer& getInstance();
    void init(int width, int height, const std::string& title);
    void clear();
    void swapBuffers();
    GLFWwindow* getWindow() const;

    // Clean up resources
    ~Renderer();

private:
    Renderer() = default;
    GLFWwindow* window = nullptr;
};

#endif // RENDERER_H


