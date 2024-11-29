
#ifndef ENTER_PLAYER_NAME_H
#define ENTER_PLAYER_NAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "InitialScreen.h"
#include "PlayScreen.h"
#include "howToPlayScreen.h"
class PlayerInfo {
public:
    PlayerInfo();
    void show(sf::RenderWindow& window);
    std::string getPlayerName() const;
private:
    std::string playerName;
    bool capturingName;
    sf::Font font;
    sf::Text namePromptText;
    sf::Text nameInputText;

    void capturePlayerName(sf::Event event);
};

#endif // ENTER_PLAYER_NAME_H
