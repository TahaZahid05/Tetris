#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>


class SoundManager{
    private:
        std::vector<sf::SoundBuffer> soundBuffers;
        sf::Sound sounds;
        sf::Sound backgroundMusic;
        sf::SoundBuffer bgBuffer;
        std::string currentBackgroundSound;
        int soundBufferLength = soundBuffers.size();
    public:
        void playBackgroundMusic(std::string bgMusic);
        void stopBackgroundMusic();
        void loadSound(const std::string& filename);
        void playSound(int index);
        void stopSound(int index);     
        std::string getCurrentBackgroundSound();
        bool isBackgroundMusicPlaying();   
        int getSoundBufferLength();


};




#endif