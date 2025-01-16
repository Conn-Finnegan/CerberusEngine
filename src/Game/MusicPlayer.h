#pragma once // Include header file once 

#include <string> //    Include string for handling file paths 
#include <SDL_mixer.h> //   Include SDL_mixer for audio handling 

// MusicPlayer class to manage music playback 
class MusicPlayer {
public:

    //  Constructor 
    MusicPlayer();

    //  Destructor
    ~MusicPlayer();

    // Load music from a file 
    void loadMusic(const std::string& filePath);

    // Play the loaded music, with an option to loop ( -1 for infinite looping )
    void playMusic(int loops = -1); // -1 for looping

    //  Stop the music 
    void stopMusic();

private:
    Mix_Music* music; // Pointer to the music data 
};
