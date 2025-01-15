#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(2.0f, 1.0f, 2.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        float yaw = -133.0f, float pitch = -20.0f);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane) const;

    void processKeyboard(const char* direction, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    // Camera position and orientation
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    // Camera options
    float movementSpeed;
    float mouseSensitivity;

private:
    float yaw;
    float pitch;

    void updateCameraVectors();
};
