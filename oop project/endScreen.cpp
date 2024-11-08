#include <SFML/Graphics.hpp>
#include <string>

void showPlayScreen(sf::RenderWindow& window); 

void showEndScreen(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        return; 
    }

    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200, 100);

    sf::Text retryText("Retry", font, 30);
    retryText.setPosition(350, 300);

    sf::Text exitText("Exit", font, 30);
    exitText.setPosition(350, 400);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (retryText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    showPlayScreen(window);  
                    return;
                }
                if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(gameOverText);
        window.draw(retryText);
        window.draw(exitText);
        window.display();
    }
}
