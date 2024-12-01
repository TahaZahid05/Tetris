#include "Game.h"
#include <SFML/Audio.hpp>

Game::Game()
    : window(sf::VideoMode(1600, 900), "Tetris Game"), playScreen(nullptr) {
    window.setPosition(sf::Vector2i(0, 0));
    // window.setUserData(this);
}

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

void Game::run() {
    switchScreen("initial");
    while (window.isOpen()) {
        // Main game loop
    }
}

void Game::switchScreen(const std::string& screenName) {
    if (screenName == "initial") {
        initialScreen.show(window);
    } else if (screenName == "howToPlay") {
        howToPlayScreen.show(window);
    } else if (screenName == "enterPlayerName") {
        playerInfo.show(window);
    } else if (screenName == "play") {
        if (playScreen) delete playScreen;
        playScreen = new PlayScreen(playerInfo.getPlayerName());
        playScreen->show(window);
    } else if (screenName == "end") {
        endScreen.saveHighScore(playerInfo.getPlayerName(), playScreen->getScore());
        endScreen.show(window, playerInfo.getPlayerName(), playScreen->getScore());
    }
}