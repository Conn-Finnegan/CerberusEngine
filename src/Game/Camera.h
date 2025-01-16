#pragma once // Header file included once 

#include <glm/glm.hpp> //   Inlcude GLM
#include <glm/gtc/matrix_transform.hpp> //  Inlcude GLM matrix transformations 

//  Camera class to manage view and projection matrices
class Camera {
public:

    //  Constructor with defualt position, up vector, yaw and pitch 
    Camera(glm::vec3 position = glm::vec3(2.0f, 1.0f, 2.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        float yaw = -133.0f, float pitch = -20.0f);

    // Get the view matrix 
    glm::mat4 getViewMatrix() const;

    //  Get the projection matrix 
    glm::mat4 getProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane) const;

    // Process keyboard input for camera movement 
    void processKeyboard(const char* direction, float deltaTime);

    //  Process mouse movement for camera movement 
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

    void updateCameraVectors(); //  Update camera vectors based on currect values 
};
