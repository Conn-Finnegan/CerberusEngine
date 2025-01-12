cmake_minimum_required(VERSION 3.16)

# Project Name and Version
project(CerberusGameEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(ASSETS_DIR "${PROJECT_SOURCE_DIR}/assets")
set(EXTERNAL_DIR "${PROJECT_SOURCE_DIR}/external")

# Output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# Add the main source files
file(GLOB_RECURSE ENGINE_SOURCES "${SRC_DIR}/Cerberus/*.cpp")
file(GLOB_RECURSE GAME_SOURCES "${SRC_DIR}/Game/*.cpp")
set(MAIN_FILE "${SRC_DIR}/main.cpp")

# Add executable
add_executable(CerberusGameEngine ${ENGINE_SOURCES} ${GAME_SOURCES} ${MAIN_FILE})

# Include directories
target_include_directories(CerberusGameEngine PRIVATE
    "${SRC_DIR}/Cerberus"
    "${SRC_DIR}/Game"
    "${EXTERNAL_DIR}/glad/include"
    "${EXTERNAL_DIR}/glfw/include"
)

# Add glad source file
add_library(glad "${EXTERNAL_DIR}/glad/src/glad.c")
target_include_directories(glad PRIVATE "${EXTERNAL_DIR}/glad/include")

# GLFW (Assumes glfw is included as source in the project directory)
add_subdirectory("${EXTERNAL_DIR}/glfw" "${CMAKE_BINARY_DIR}/glfw")

# Link libraries
target_link_libraries(CerberusGameEngine PRIVATE glad glfw ${CMAKE_DL_LIBS})

# Set up additional build flags for debugging
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(CerberusGameEngine PRIVATE DEBUG)
    message("Building in Debug mode")
else()
    message("Building in Release mode")
endif()

# Copy assets to the build directory after compiling
add_custom_command(
    TARGET CerberusGameEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${ASSETS_DIR}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets"
)
