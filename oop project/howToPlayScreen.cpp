#include "howToPlayScreen.h"
#include "InitialScreen.h"
#include <SFML/Graphics.hpp>

// ...existing code...

void HowToPlayScreen::show(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(
        "How to Play Tetris:\n"
        "1. Use the arrow keys to move the Tetriminos left, right, or down.\n"
        "2. Use the up arrow key to rotate the Tetrimino.\n"
        "3. Fill a row completely to clear it and earn points.\n"
        "4. The game ends when the Tetriminos stack up to the top of the screen.\n"
        "5. Try to clear as many rows as possible to achieve a high score!\n"
    );
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 50);

    sf::Text backText;
    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(24);
    backText.setFillColor(sf::Color::Black);
    backText.setPosition(50, 800);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(backText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    InitialScreen initialScreen;
                    initialScreen.show(window);
                    return;
                }
            }
        }

    window.clear(sf::Color::White);
    window.draw(text);
    window.draw(backText);
    window.display();
    }
}

// ...existing code...

