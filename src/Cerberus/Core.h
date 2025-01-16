#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"
#include "InputHandler.h"

//  The core class acts as the brain of the engine
//  It handles initialisation, main loop and cleanup
class Core : public std::enable_shared_from_this<Core> {
public:

    //  Creates and initialises a shared instance of core
    static std::shared_ptr<Core> initialize();

    //  starts the main loop of the engine
    void run();

    //  Ends the main loop
    void stop();

    //  Returns a shared pointer to a newly added entity
    std::shared_ptr<Entity> addEntity();

    //  Mouse input 
    //  Used with GLFW to handle updates in mouse position
    // -Window: Pointer to the GLFW window
    // -xpos: x coord of cursor
    // -ypos: y coord of cursor
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);

private:

    //  Private constructor to enforce controlled init through the initialise method
    Core() = default;

    // Is the engine currently running 
    bool running = false;

    //  Points to the active camera 
    //  Responsible for determining the view and projection matrices for rendering 
    std::shared_ptr<Camera> camera;

    //  InputHandler Responsible for managing user inputs e.g keyboard and mouse
    std::shared_ptr<InputHandler> inputHandler;

    //  Renderer, responsible for rendering entities and other visual artifacts.
    std::shared_ptr<Renderer> renderer;

    //  Encompasses all of the current entities in the scene that are being managed by the engine 
    std::vector<std::shared_ptr<Entity>> entities;

    //  Inits the input handler and sets up callbacks 
    void initializeInputHandler();

    //  Updates all entities in the engine 
    void tickEntities();

    //  Renders all entities by calling their render function 
    void renderEntities();
};




