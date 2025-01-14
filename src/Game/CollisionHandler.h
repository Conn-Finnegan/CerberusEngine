#pragma once

#include <glm/glm.hpp>

class CollisionHandler {
public:
    // Check if a point (e.g., camera position) is inside an AABB
    static bool isPointInsideAABB(const glm::vec3& point, const glm::vec3& minBounds, const glm::vec3& maxBounds);
};
