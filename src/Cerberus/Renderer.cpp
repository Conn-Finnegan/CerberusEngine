#include "Renderer.h"
#include <iostream>

std::shared_ptr<Renderer> Renderer::getInstance() {
    static std::shared_ptr<Renderer> instance = std::shared_ptr<Renderer>(new Renderer());
    return instance;
}

void Renderer::init(int width, int height, const std::string& title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, width, height);
}

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Renderer::getWindowShouldClose() const {
    return glfwWindowShouldClose(window);
}

GLFWwindow* Renderer::getWindow() const {
    return window;
}

Renderer::~Renderer() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}


