cmake_minimum_required(VERSION 3.16)

# Project Name and Version
project(CerberusGameEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(ASSETS_DIR "${PROJECT_SOURCE_DIR}/assets")
set(EXTERNAL_DIR "${PROJECT_SOURCE_DIR}/external")
set(BUILD_DIR "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_DIR "${PROJECT_BINARY_DIR}/lib")

# Apply output directories globally
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_DIR})


# Add source files
file(GLOB_RECURSE ENGINE_SOURCES "${SRC_DIR}/Cerberus/*.cpp")
file(GLOB_RECURSE GAME_SOURCES "${SRC_DIR}/Game/*.cpp")
file(GLOB_RECURSE SHADER_SOURCES "${SRC_DIR}/Cerberus/Shaders/*.cpp")
set(MAIN_FILE "${SRC_DIR}/main.cpp")

# Add executable
add_executable(CerberusGameEngine ${ENGINE_SOURCES} ${GAME_SOURCES} ${SHADER_SOURCES} ${MAIN_FILE})

# Include directories
target_include_directories(CerberusGameEngine PRIVATE
    "${SRC_DIR}/Cerberus"
    "${SRC_DIR}/Game"
    "${EXTERNAL_DIR}/glad/include"
    "${EXTERNAL_DIR}/glfw/include"
    "${EXTERNAL_DIR}/glm"
)
# Add glad as a static library
add_library(glad "${EXTERNAL_DIR}/glad/src/glad.c")
target_include_directories(glad PRIVATE "${EXTERNAL_DIR}/glad/include")

# GLFW configuration
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Do not build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Do not build GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Do not build GLFW docs")
add_subdirectory("${EXTERNAL_DIR}/glfw" "${CMAKE_BINARY_DIR}/glfw")

# GLM Integration
# Assuming glm is a header-only library
target_include_directories(CerberusGameEngine PRIVATE "${EXTERNAL_DIR}/glm")

# Link libraries
target_link_libraries(CerberusGameEngine PRIVATE glad glfw ${CMAKE_DL_LIBS})

# Define build configurations
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(CerberusGameEngine PRIVATE DEBUG)
    message(STATUS "Building in Debug mode")
else()
    message(STATUS "Building in Release mode")
endif()

# Post-build steps: Copy assets to runtime output directory
add_custom_command(
    TARGET CerberusGameEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${BUILD_DIR}/assets"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "${BUILD_DIR}/assets"
)

# Debugging information
message(STATUS "Runtime Output Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Library Output Directory: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "Archive Output Directory: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
