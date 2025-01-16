#pragma once // Header included once 

#include <glm/glm.hpp> //   Include GLM 

//  CollisionHandler class to handle collsion detection 
class CollisionHandler {
public:

    // Static method to check if a point is inside box (AABB)
    // point: The point to check
    // minBounds: The minimum bounds of the AABB
    // maxBounds: The maximum bounds of the AABB
    
    static bool isPointInsideAABB(const glm::vec3& point, const glm::vec3& minBounds, const glm::vec3& maxBounds);
};
