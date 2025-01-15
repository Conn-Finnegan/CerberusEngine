#pragma once

#include <glm/glm.hpp>

class CollisionHandler {
public:
    
    static bool isPointInsideAABB(const glm::vec3& point, const glm::vec3& minBounds, const glm::vec3& maxBounds);
};
