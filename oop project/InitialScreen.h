#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "PlayScreen.h"
#include "InitialScreen.h"
#include "howToPlayScreen.h"
#include "EnterPlayerName.h"

// Created initially by Yousuf Aijaz. Changes made by both accordingly. Used to show initial screen

class InitialScreen {
public:
    void show(sf::RenderWindow& window);
private:
    SoundManager intialSound;
};

#endif
