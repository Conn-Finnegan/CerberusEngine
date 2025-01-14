#include "CollisionHandler.h"

bool CollisionHandler::isPointInsideAABB(const glm::vec3& point, const glm::vec3& minBounds, const glm::vec3& maxBounds) {
    return (point.x > minBounds.x && point.x < maxBounds.x &&
        point.y > minBounds.y && point.y < maxBounds.y &&
        point.z > minBounds.z && point.z < maxBounds.z);
}
