#include "howToPlayScreen.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

void HowToPlayScreen::show(sf::RenderWindow& window) {
    // Create a gradient background
    sf::VertexArray gradient(sf::Quads, 4);
    gradient[0].position = sf::Vector2f(0, 0);
    gradient[1].position = sf::Vector2f(1600, 0);
    gradient[2].position = sf::Vector2f(1600, 900);
    gradient[3].position = sf::Vector2f(0, 900);

    gradient[0].color = sf::Color(100, 149, 237);
    gradient[1].color = sf::Color(255, 182, 193);
    gradient[2].color = sf::Color(255, 105, 180);
    gradient[3].color = sf::Color(123, 104, 238);

    // Load font
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return;
    }

    // Title text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("How to Play Tetris");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(800 - titleText.getGlobalBounds().width / 2, 50);

    // Instructions text
    sf::Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setString(
        "1. Use the arrow keys to move the Tetriminos left, right, or down.\n"
        "2. Use the up arrow key to rotate the Tetrimino.\n"
        "3. Fill a row completely to clear it and earn points.\n"
        "4. The game ends when the Tetriminos stack up to the top of the screen.\n"
        "5. Try to clear as many rows as possible to achieve a high score!"
    );
    instructionsText.setCharacterSize(30);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setPosition(100, 150);

    // Back button
    sf::RectangleShape backButton(sf::Vector2f(200, 60));
    backButton.setPosition(700, 750);
    backButton.setFillColor(sf::Color(70, 130, 180));
    backButton.setOutlineColor(sf::Color::White);
    backButton.setOutlineThickness(3);

    sf::Text backText;
    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(30);
    backText.setFillColor(sf::Color::White);
    backText.setPosition(
        backButton.getPosition().x + (backButton.getSize().x - backText.getGlobalBounds().width) / 2,
        backButton.getPosition().y + (backButton.getSize().y - backText.getGlobalBounds().height) / 2 - 5
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (backButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    Game::getInstance().switchScreen("initial");
                    return;
                }
            }
        }

        window.clear();
        window.draw(gradient);
        window.draw(titleText);
        window.draw(instructionsText);
        window.draw(backButton);
        window.draw(backText);
        window.display();
    }
}
