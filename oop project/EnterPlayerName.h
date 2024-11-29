
#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

class PlayScreen {
public:
    PlayScreen();
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

#endif // PLAYSCREEN_H
