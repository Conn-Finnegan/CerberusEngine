# Cerberus Engine

![Cerberus](Cerberus-Logo.png)

This repository contains the source code for **Cerberus Engine**, a simple game engine built in C++ and OpenGL. The engine demonstrates the fundamentals of rendering, entity management, and component-based architecture.

The primary goal of this project is to create a secure engine that allows users to build games by adding components and defining behaviour without altering the core functionality. This design provides flexibility for game creation while maintaining the integrity of the engine's core systems.

## Features

- Component-based architecture for easy game object customization.
- Multiple renderers for basic shapes like triangles and cubes.
- Input handling for user interaction.
- Support for shaders to enhance graphical effects.
- Collision handling and music player integration.
- A demonstration program showcasing engine capabilities.
- A doxygen file has been included to provide documentation 

## Prerequisites

To build and run this project, ensure you have the following installed:

- **C++ Compiler**: GCC, Clang, or MSVC supporting C++17 or later.
- **OpenGL**: Version 3.3 or higher.
- **CMake**: To configure the build system.

## Setup and Compilation

### Clone the Repository
To clone the repository, use the following commands:
```bash
git clone https://github.com/YourUsername/CerberusEngine.git
cd CerberusEngine
```

### Install Dependencies
All required dependencies (GLFW, GLAD, SDL2, SDL2_mixer) are included in the repository. There is no need to install them separately.

### Build the Project
To build the project, run the following commands:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Executable
After building, navigate to the `build` directory and run the generated executable:
```bash
./CerberusEngine
```

## Usage

The demonstration program displays a simple 3D scene with basic shapes. It allows you to:

- Use input controls to interact with objects.
- View rendering of shapes like cubes and triangles.
- Adjust parameters using the integrated GUI (if applicable).

### Controls
- **Keyboard**: Use `A` and `D` for side camera movement.
- **Mouse**: Use the mouse for camera control.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Make your changes.
3. Submit a pull request.

Ensure your code follows the existing style and is well-documented.

## License

This project is licensed under the [MIT License]
