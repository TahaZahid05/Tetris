#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "PlayScreen.h"
#include "InitialScreen.h"
#include "howToPlayScreen.h"
#include "EnterPlayerName.h"

class InitialScreen {
public:
    void show(sf::RenderWindow& window);
private:
    sf::SoundBuffer bgBuffer;
    sf::Sound bgSound;
};

#endif
