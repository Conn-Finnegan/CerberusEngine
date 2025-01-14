#include "Core.h"
#include "CubeRenderer.h"
#include "Game/MusicPlayer.h"

int main() {
    auto core = Core::initialize();
    auto cubeEntity = core->addEntity();
    cubeEntity->addComponent<CubeRenderer>();

    // Initialize and play music
    MusicPlayer musicPlayer;
    musicPlayer.loadMusic("../assets/audio/music.wav"); // Replace with your file path
    musicPlayer.playMusic();

    core->run();

    return 0;
}




