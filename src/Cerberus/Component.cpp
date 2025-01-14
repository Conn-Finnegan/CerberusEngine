#include "Component.h"

// If Component.cpp references Camera, ensure correct usage
#include "Camera.h"

// Example of a placeholder function if you need to demonstrate Camera usage
void demoCameraUsage() {
    Camera camera; // Uses default constructor
    camera.processKeyboard("FORWARD", 0.016f); // Simulate a small forward movement
    glm::mat4 viewMatrix = camera.getViewMatrix(); // Get the view matrix
    glm::mat4 projectionMatrix = camera.getProjectionMatrix(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
}

