#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <memory>

class Renderer {
public:
    static std::shared_ptr<Renderer> getInstance(); // Singleton 
    void init(int width, int height, const std::string& title);
    void clear(float r = 0.2f, float g = 0.3f, float b = 0.3f, float a = 1.0f);
    void swapBuffers();
    bool getWindowShouldClose() const;

    GLFWwindow* getWindow() const; 

    ~Renderer();

private:
    Renderer() = default; // Private constructor for singleton
    GLFWwindow* window = nullptr;
};

#endif 




