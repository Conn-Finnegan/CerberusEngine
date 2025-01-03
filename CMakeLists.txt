# Minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Project name and language
project(CerberusEngine LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Force consistent runtime library usage
# Multi-threaded Debug DLL (/MDd) for Debug, Multi-threaded DLL (/MD) for Release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MD")

# Include directories for the project
include_directories(
    src
    src/Cerberus
    src/Game
    external/glad/include
    external/glfw/include
)

# Source files for the project
file(GLOB_RECURSE PROJECT_SOURCES
    src/*.cpp
)

# Add the executable target
add_executable(GameEngine ${PROJECT_SOURCES})

# Add GLAD as a library
add_library(glad external/glad/src/glad.c)

# Ensure GLAD uses consistent runtime libraries
set_target_properties(glad PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)

# Add GLFW as a subdirectory
add_subdirectory(external/glfw)

# Ensure GLFW uses consistent runtime libraries
set_target_properties(glfw PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
)

# Link libraries to the executable
target_link_libraries(GameEngine PRIVATE glad glfw opengl32)

# Platform-specific settings (optional)
if (WIN32)
    target_compile_definitions(GameEngine PRIVATE GLFW_EXPOSE_NATIVE_WIN32)
endif()
