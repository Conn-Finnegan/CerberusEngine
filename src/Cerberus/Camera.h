#pragma once

#include <glm/glm.hpp>

class Camera {
public:
    Camera(glm::vec3 position);
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float fov, float aspect, float nearPlane, float farPlane) const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
};
