#pragma once // Header only included once 

#ifndef RENDERER_H // Additional header guard to protect agasint multiple inclusions 
#define RENDERER_H

#include <glad/glad.h> //   Inlcude GLAD for OpenGL
#include <GLFW/glfw3.h> //  Include GLFW for window management 
#include <string> //    Include string for handling text
#include <memory> //    Include memory for management 

//  Renderer class to handle rendering operations 
class Renderer {
public:

    //  Singleton pattern to get the instance of the renderer 
    static std::shared_ptr<Renderer> getInstance();

    //  Init the renderer with window dimesnsions and title 
    void init(int width, int height, const std::string& title);

    // Clear screen 
    void clear(float r = 0.2f, float g = 0.3f, float b = 0.3f, float a = 1.0f);

    //  Swap the front and back buffers 
    void swapBuffers();

    //  Check if the window should close 
    bool getWindowShouldClose() const;

    //  Get the GLFW window 
    GLFWwindow* getWindow() const; 

    //  Destructor 
    ~Renderer();

private:

    //  Private constructor for singleton 
    Renderer() = default; 

    //  Pointer to GLFW video 
    GLFWwindow* window = nullptr;
};

#endif //   End of header guard 




