#include <SFML/Graphics.hpp>
#include <string>

void showPlayScreen(sf::RenderWindow& window); 

void showStartScreen(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        return; 
    }

    // Create a VertexArray with 4 vertices (quads)
    sf::VertexArray gradient(sf::Quads, 4);

    // Set the position of each corner (filling the window)
    gradient[0].position = sf::Vector2f(0, 0);        // Top-left
    gradient[1].position = sf::Vector2f(1600, 0);      // Top-right
    gradient[2].position = sf::Vector2f(1600, 900);    // Bottom-right
    gradient[3].position = sf::Vector2f(0, 900);      // Bottom-left

    // Set the color for each vertex
    gradient[0].color = sf::Color(81, 112, 255);   // Top color
    gradient[1].color = sf::Color(255, 102, 196);
    gradient[2].color = sf::Color(255, 102, 196);  // Bottom color
    gradient[3].color = sf::Color(81, 112, 255);

    // sf::Text op("I",font,10);
    // op.setPosition(400,20);

    sf::Text title("Tetris Warriors", font, 50);
    title.setPosition(650, 100);


    sf::Text playText("Play", font, 30);
    playText.setPosition(750, 300);


    sf::Text exitText("Exit", font, 30);
    exitText.setPosition(750, 400);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    showPlayScreen(window);  
                    return;
                }
                if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(gradient);
        window.draw(title);
        window.draw(playText);
        window.draw(exitText);
        // window.draw(op);
        window.display();
    }
}
