//Implemented by taha. Used as the main game loop
#include "Game.h"
#include <SFML/Audio.hpp>
//
Game* Game::instance = nullptr;
// Constructor
Game::Game(): window(sf::VideoMode(1600, 900), "Tetris Game"), playScreen("") {
    window.setPosition(sf::Vector2i(0, 0));
}
// Get instance of Game
Game& Game::getInstance() {
    if(instance == nullptr) {
        instance = new Game();
    }
    return *instance;
}
// Run the game
void Game::run() {
    switchScreen("initial");
}
// Switch between screens
void Game::switchScreen(const std::string& screenName) {
    if (screenName == "initial") {
        initialScreen.show(window);
    } else if (screenName == "howToPlay") {
        howToPlayScreen.show(window);
    } else if (screenName == "enterPlayerName") {
        playerInfo.show(window);
    } else if (screenName == "play") {
        playScreen = PlayScreen(playerInfo.getPlayerName());
        playScreen.show(window);
    } else if (screenName == "end") {
        endScreen.saveHighScore(playerInfo.getPlayerName(), playScreen.getScore());
        endScreen.show(window, playerInfo.getPlayerName(), playScreen.getScore());
    }
}