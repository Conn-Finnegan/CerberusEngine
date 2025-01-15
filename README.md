# Game Engine Project

This repository contains the source code for a simple game engine built in C++ and OpenGL. The engine demonstrates the fundamentals of rendering, entity management, and component-based architecture.

The primary goal of this project is to create a secure engine that allows users to build games by adding components and defining behaviour without altering the core functionality. This design provides flexibility for game creation while maintaining the integrity of the engine's core systems.

## Features

- Component-based architecture for easy game object customization.
- Multiple renderers for basic shapes like triangles and cubes.
- Input handling for user interaction.
- Support for shaders to enhance graphical effects.
- Collision handling and music player integration.
- A demonstration program showcasing engine capabilities.

## Prerequisites

To build and run this project, ensure you have the following installed:

- **C++ Compiler**: GCC, Clang, or MSVC supporting C++17 or later.
- **OpenGL**: Version 3.3 or higher.
- **GLFW**: For window and input management.
- **GLAD**: For OpenGL function loading.
- **SDL2**: For cross-platform multimedia handling.
- **SDL2_mixer**: For audio playback.
- **CMake**: To configure the build system.

## Setup and Compilation

### Clone the Repository
To clone the repository, use the following commands:
```bash
git clone https://github.com/YourUsername/YourRepoName.git
cd YourRepoName
```

### Install Dependencies
Ensure the following dependencies are installed on your system:

- **GLFW**: Use your package manager or download it from [GLFW's website](https://www.glfw.org/).
- **GLAD**: Follow instructions to generate and include the loader files from [GLAD's website](https://gen.glad.sh/).
- **SDL2**: Install via your package manager or download from [SDL2's website](https://libsdl.org/).
- **SDL2_mixer**: Install via your package manager or download from [SDL2_mixer's website](https://libsdl.org/projects/SDL_mixer/).

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
./YourExecutableName
```

## Usage

The demonstration program displays a simple 3D scene with basic shapes. It allows you to:

- Use input controls to interact with objects.
- View rendering of shapes like cubes and triangles.
- Adjust parameters using the integrated GUI (if applicable).

### Controls
- **Keyboard**: A and D for side movement of camera ( modify as necessary )
- **Mouse**: Mouse movement for camera control ( modify as necessary )

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Make your changes.
3. Submit a pull request.

Ensure your code follows the existing style and is well-documented.

## License

This project is licensed under the [MIT License](LICENSE).
```


