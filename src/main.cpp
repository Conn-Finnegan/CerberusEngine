#include "Cerberus/Renderer.h"
#include "Cerberus/Shader.h"

int main() {
    Renderer& renderer = Renderer::getInstance();
    renderer.init(800, 600, "Modular Engine - Green Triangle");

    Shader shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

    float vertices[] = {
         0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(renderer.getWindow())) {
        renderer.clear();

        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        renderer.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}

