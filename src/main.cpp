#include "Core.h"
#include "CubeRenderer.h"
#include "MusicPlayer.h"
#include "ResourceManager.h"
#include <iostream>

int main() {
    // Initialize the core engine
    auto core = Core::initialize();

    // Add a cube entity and renderer
    auto cubeEntity = core->addEntity();
    cubeEntity->addComponent<CubeRenderer>();

    // Initialize and play music using MusicPlayer
    MusicPlayer musicPlayer;
    musicPlayer.loadMusic("../assets/audio/music.wav"); 
    musicPlayer.playMusic();

   
    Shader* basicShader = ResourceManager::LoadShader("basic", "../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");

    // Ensure application runs
    core->run();

    // Cleanup resources before exiting
    ResourceManager::ReleaseAll();
    std::cout << "Resources released." << std::endl;

    return 0;
}





