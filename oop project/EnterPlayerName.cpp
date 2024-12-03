#include "EnterPlayerName.h"
#include "Game.h"
#include <iostream>
// Constructor
PlayerInfo::PlayerInfo()
    : capturingName(true), playerName("") {
    font.loadFromFile("ARIAL.TTF");
    namePromptText.setFont(font);
    namePromptText.setString("Enter your name: ");
    namePromptText.setCharacterSize(24);
    namePromptText.setPosition(100, 100);

    nameInputText.setFont(font);
    nameInputText.setCharacterSize(24);
    nameInputText.setPosition(100, 150);
}
// Display player name input screen
void PlayerInfo::show(sf::RenderWindow& window) {
    while (window.isOpen() && capturingName) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::TextEntered) {
                capturePlayerName(event);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                capturingName = false;
                Game::getInstance().switchScreen("play");
            }
        }

        window.clear();
        window.draw(namePromptText);
        window.draw(nameInputText);
        window.display();
    }
}
// Capture player name input
void PlayerInfo::capturePlayerName(sf::Event event) {
    if (event.text.unicode == 8 && !playerName.empty()) {
        playerName.pop_back();
    } else if (event.text.unicode < 128 && event.text.unicode > 31) {
        playerName += static_cast<char>(event.text.unicode);
    }
    nameInputText.setString(playerName);
}
// Get player name
std::string PlayerInfo::getPlayerName() const {
    return playerName;
}
