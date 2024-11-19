#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InitialScreen.h"
#include "howToPlayScreen.h"
#include "PlayScreen.h"
#include "EndScreen.h"
#include <string>

using namespace std;

class Game {
public:
    Game();
    // void nextScreen(string screen);
private:
    sf::RenderWindow window;
    InitialScreen initialScreen;
};

#endif // GAME_H