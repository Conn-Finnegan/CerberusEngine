Game Engine Project

This repository contains the source code for a simple game engine built in C++ and OpenGL. The engine demonstrates the fundamentals of rendering, entity management, and component-based architecture.

The primary goal of this project is to create a secure engine that allows users to build games by adding components and defining behaviour without altering the core functionality. This design provides flexibility for game creation while maintaining the integrity of the engine's core systems.

Features

Component-based architecture for easy game object customization.
Multiple renderers for basic shapes like triangles and cubes.
Input handling for user interaction.
Support for shaders to enhance graphical effects.
Collision handling and music player integration.
A demonstration program showcasing engine capabilities.
Prerequisites

To build and run this project, ensure you have the following installed:

C++ Compiler: GCC, Clang, or MSVC supporting C++17 or later.
OpenGL: Version 3.3 or higher.
GLFW: For window and input management.
GLEW: For OpenGL extension handling.
CMake: To configure the build system.
Setup and Compilation

Clone the Repository:
git clone https://github.com/YourUsername/YourRepoName.git
cd YourRepoName
Install Dependencies: Ensure you have installed GLFW and GLEW on your system. Use your package manager or follow instructions from their official websites.
Build the Project: Use CMake to generate and build the project:
mkdir build
cd build
cmake ..
cmake --build .
Run the Executable: After building, an executable file will be created in the build directory. Run it using:
./YourExecutableName

Usage

The demonstration program displays a simple 3D scene with basic shapes and allows you to:

Use input controls to interact with objects.
View rendering of shapes like cubes and triangles.
Adjust parameters using the integrated GUI (if applicable).

Controls

Keyboard: A and D
Mouse: Camera movement 

File Structure

Core.h/cpp: Contains the main engine functionality.
InputHandler.h/cpp: Manages user inputs.
Renderer.h/cpp: Implements rendering functionality.
Entity.h/cpp: Defines game objects.
Component.h/cpp: Base class for all components.
Shader.h/cpp: Handles shader operations.
CollisionHandler.cpp: Manages collision detection.
MusicPlayer.h/cpp: Integrates music playback.
main.cpp: Entry point demonstrating engine capabilities.
Contributing

Contributions are welcome! Please fork the repository, make your changes, and submit a pull request. Ensure your code follows the existing style and is well-documented.

License

This project is licensed under the MIT License.
