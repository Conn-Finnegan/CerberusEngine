#pragma once

#include <string>
#include <SDL_mixer.h>

class MusicPlayer {
public:
    MusicPlayer();
    ~MusicPlayer();

    void loadMusic(const std::string& filePath);
    void playMusic(int loops = -1); // -1 for infinite looping
    void stopMusic();

private:
    Mix_Music* music;
};
