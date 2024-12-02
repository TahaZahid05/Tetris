#include "SoundManager.h"

void SoundManager::loadSound(const std::string& filename) {
    sf::SoundBuffer newSound;
    soundBufferLength += 1;
    soundBuffers.push_back(newSound);
    if(!soundBuffers[soundBufferLength - 1].loadFromFile(filename)) {
        return;
    }

    // sf::SoundBuffer buffer;
    // if (!buffer.loadFromFile(filename)) {
    //     return;
    // }
    // soundBuffers.push_back(buffer);
    // sf::Sound sound;
    // sound.setBuffer(soundBuffers.back());
    // sounds.push_back(sound);
}

void SoundManager::playSound(int index) {
    sounds.setBuffer(soundBuffers[soundBufferLength - 1]);
    sounds.play();
    // if (index >= 0 && index < sounds.size()) {
    //     sounds[index].play();
    // } else {
    //     return;
    // }
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
    // backgroundMusic.setLoop(true);
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