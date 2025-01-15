#include "CubeRenderer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>

CubeRenderer::CubeRenderer() {
    shader = std::make_shared<Shader>("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");

    float vertices[] = {
       
        // Back face
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // Red
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 

        // Front face
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, // Green
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 

        // Left face
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // Blue
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 

        // Right face
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, // Yellow
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 
         0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 

         // Bottom face
         -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, // Pink
          0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 
          0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 
          0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 
         -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 
         -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 

         // Top face
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, // Light blue
          0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 
          0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 
          0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 
         -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Colour 
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void CubeRenderer::onTick() {
    
}

void CubeRenderer::onRender() {
    shader->use();

    glm::mat4 model = glm::mat4(1.0f); 
    shader->setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

CubeRenderer::~CubeRenderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
