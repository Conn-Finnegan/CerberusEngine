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

# Detect architecture and set library directories
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit architecture
    set(SDL2_LIB_DIR "${EXTERNAL_DIR}/SDL2/lib/x64")
    set(SDL2_MIXER_LIB_DIR "${EXTERNAL_DIR}/SDL2_mixer/lib/x64")
else()
    # 32-bit architecture
    set(SDL2_LIB_DIR "${EXTERNAL_DIR}/SDL2/lib/x86")
    set(SDL2_MIXER_LIB_DIR "${EXTERNAL_DIR}/SDL2_mixer/lib/x86")
endif()

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
    "${EXTERNAL_DIR}/SDL2/include"
    "${EXTERNAL_DIR}/SDL2_mixer/include"
)

# Add glad as a static library
add_library(glad "${EXTERNAL_DIR}/glad/src/glad.c")
target_include_directories(glad PRIVATE "${EXTERNAL_DIR}/glad/include")

# GLFW configuration
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Do not build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Do not build GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Do not build GLFW docs")
add_subdirectory("${EXTERNAL_DIR}/glfw" "${CMAKE_BINARY_DIR}/glfw")

# GLM Integration (Header-only library)
target_include_directories(CerberusGameEngine PRIVATE "${EXTERNAL_DIR}/glm")

# Link SDL2 and SDL2_mixer libraries
target_link_libraries(CerberusGameEngine PRIVATE
    "${SDL2_LIB_DIR}/SDL2.lib"
    "${SDL2_LIB_DIR}/SDL2main.lib"
    "${SDL2_MIXER_LIB_DIR}/SDL2_mixer.lib"
)

# Link glad and glfw
target_link_libraries(CerberusGameEngine PRIVATE glad glfw ${CMAKE_DL_LIBS})

# Add definitions for GLFW
add_definitions(-DGLFW_INCLUDE_NONE)

# Post-build steps: Copy assets and DLLs to runtime output directory
add_custom_command(
    TARGET CerberusGameEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${BUILD_DIR}/assets"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "${BUILD_DIR}/assets"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_LIB_DIR}/SDL2.dll"
        "$<TARGET_FILE_DIR:CerberusGameEngine>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_MIXER_LIB_DIR}/SDL2_mixer.dll"
        "$<TARGET_FILE_DIR:CerberusGameEngine>"
)

# Debugging information
message(STATUS "Runtime Output Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Library Output Directory: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "Archive Output Directory: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
