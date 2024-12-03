//Created by Taha. Used to handle sounds across different screens.
#include "SoundManager.h"

void SoundManager::loadSound(const std::string& filename) {
    sf::SoundBuffer newSound;
    soundBufferLength += 1;
    soundBuffers.push_back(newSound);
    if(!soundBuffers[soundBufferLength - 1].loadFromFile(filename)) {
        return;
    }
}

void SoundManager::playSound(int index) {
    sounds.setBuffer(soundBuffers[soundBufferLength - 1]);
    sounds.play();
}

void SoundManager::stopSound(int index) {
    sounds.stop();
}

void SoundManager::playBackgroundMusic(std::string bgMusic) {
    currentBackgroundSound = bgMusic;
    if (!bgBuffer.loadFromFile(bgMusic)) {
        return;
    }
    backgroundMusic.setBuffer(bgBuffer);
    backgroundMusic.setVolume(25);
    backgroundMusic.play();
}

void SoundManager::stopBackgroundMusic() {
    backgroundMusic.stop();
}

bool SoundManager::isBackgroundMusicPlaying() {
    if (backgroundMusic.getStatus() == sf::Sound::Playing) {
        return true;
    }
    return false;
}

std::string SoundManager::getCurrentBackgroundSound() {
    return currentBackgroundSound;
}

int SoundManager::getSoundBufferLength() {
    return soundBufferLength;
}