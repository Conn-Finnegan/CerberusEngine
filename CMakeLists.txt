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
set(RUNTIME_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin/Debug")
set(LIBRARY_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin/lib")
set(ARCHIVE_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin/lib")

# Apply output directories globally
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${RUNTIME_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${LIBRARY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ARCHIVE_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RUNTIME_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${LIBRARY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ARCHIVE_OUTPUT_DIR})

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

# GLFW (Force consistent output directory)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Do not build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Do not build GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Do not build GLFW docs")
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

# Copy assets to the runtime output directory after compiling
add_custom_command(
    TARGET CerberusGameEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${RUNTIME_OUTPUT_DIR}/assets"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "${RUNTIME_OUTPUT_DIR}/assets"
)

# Debugging output
message(STATUS "Runtime Output Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Library Output Directory: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "Archive Output Directory: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
