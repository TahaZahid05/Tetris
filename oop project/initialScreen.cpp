#include "InitialScreen.h"
#include "SoundManager.h"
#include "Game.h"
// Display initial screen
// Created initially by Yousuf Aijaz. Changes made by both accordingly. Used to show initial screen
void InitialScreen::show(sf::RenderWindow& window) {
    intialSound.playBackgroundMusic("sounds/initialBG.ogg");

    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        return;
    }

    sf::VertexArray gradient(sf::Quads, 4);
    gradient[0].position = sf::Vector2f(0, 0);
    gradient[1].position = sf::Vector2f(1600, 0);
    gradient[2].position = sf::Vector2f(1600, 900);
    gradient[3].position = sf::Vector2f(0, 900);

    gradient[0].color = sf::Color(81, 112, 255);
    gradient[1].color = sf::Color(255, 102, 196);
    gradient[2].color = sf::Color(255, 102, 196);
    gradient[3].color = sf::Color(81, 112, 255);

    sf::Text title("Tetris Warriors", font, 50);
    title.setPosition(650, 100);

    sf::Text playText("Play", font, 30);
    playText.setPosition(750, 300);

    sf::Text exitText("Exit", font, 30);
    exitText.setPosition(750, 500);

    sf::Text howToPlayText("How to play", font, 30);
    howToPlayText.setPosition(750, 400);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    intialSound.stopBackgroundMusic();
                    Game::getInstance().switchScreen("enterPlayerName");
                    return;
                }
                if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    intialSound.stopBackgroundMusic();
                    window.close();
                }
                if (howToPlayText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    Game::getInstance().switchScreen("howToPlay");
                    return;
                }
            }
        }

        window.clear();
        window.draw(gradient);
        window.draw(title);
        window.draw(playText);
        window.draw(exitText);
        window.draw(howToPlayText);
        window.display();
    }
}
