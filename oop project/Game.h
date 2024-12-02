#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InitialScreen.h"
#include "howToPlayScreen.h"
#include "PlayScreen.h"
#include "EndScreen.h"
#include "EnterPlayerName.h"
#include <string>

class Game {
public:
    static Game& getInstance();
    void run();
    void switchScreen(const std::string& screenName);
private:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game* instance;
    sf::RenderWindow window;
    InitialScreen initialScreen;
    HowToPlayScreen howToPlayScreen;
    PlayScreen* playScreen;
    EndScreen endScreen;
    PlayerInfo playerInfo;
};

#endif