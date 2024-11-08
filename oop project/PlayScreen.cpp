#include <SFML/Graphics.hpp>
#include <string>

void showEndScreen(sf::RenderWindow& window); 

void showPlayScreen(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(180.f,230.f));
    rect.setPosition(50,20);
    rect.setFillColor(sf::Color::White);
    sf::RectangleShape rectBorder(sf::Vector2f(200.f,250.f));
    rectBorder.setPosition(40,10);
    rectBorder.setFillColor(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return; 
    }

    // sf::Text playText("Play", font, 30);
    // playText.setPosition(350, 300);
    // playText.setFillColor(sf::Color::Black);

    sf::Text levelText("Level",font,30);
    levelText.setPosition(105,40);
    levelText.setFillColor(sf::Color::Black);

    sf::RectangleShape levelRect(sf::Vector2f(150.f,30.f));
    levelRect.setPosition(68,80);
    levelRect.setFillColor(sf::Color::Black);

    sf::Text linesText("Lines",font,30);
    linesText.setPosition(105,120);
    linesText.setFillColor(sf::Color::Black);

    sf::RectangleShape linesRect(sf::Vector2f(150.f,30.f));
    linesRect.setPosition(68,160);
    linesRect.setFillColor(sf::Color::Black);

    int numberOfColumns = 15;
    int numberfOfRows = 7;
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    for(int i = 0; i < numberfOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            tetrisRectangles[i][j].setSize(sf::Vector2f(50.f,50.f));
            tetrisRectangles[i][j].setPosition(550+(55*i),10+(55*j));
            tetrisRectangles[i][j].setFillColor(sf::Color::Black);
        }
    }

    sf::RectangleShape rectNext(sf::Vector2f(300.f,230.f));
    rectNext.setPosition(1250,20);
    rectNext.setFillColor(sf::Color::White);
    sf::RectangleShape rectNextBorder(sf::Vector2f(320.f,250.f));
    rectNextBorder.setPosition(1240,10);
    rectNextBorder.setFillColor(sf::Color::Black);

    sf::Text rectNextText("NEXT",font,30);
    rectNextText.setPosition(1350,40);
    rectNextText.setFillColor(sf::Color::Black);

    sf::Text rectShapesText("SHAPES",font,30);
    rectShapesText.setPosition(1330,80);
    rectShapesText.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // if (event.type == sf::Event::MouseButtonPressed) {
            //     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //     if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            //         showEndScreen(window);  
            //         return;
            //     }
            // }
        }

        window.clear(sf::Color::White);
        // window.draw(playText);
        window.draw(rectBorder);
        window.draw(rect);
        window.draw(levelText);
        window.draw(levelRect);
        window.draw(linesText);
        window.draw(linesRect);
        for(int i = 0; i < numberfOfRows; i++){
            for(int j = 0; j < numberOfColumns; j++){
                window.draw(tetrisRectangles[i][j]);
            }
        }
        window.draw(rectNextBorder);
        window.draw(rectNext);
        window.draw(rectNextText);
        window.draw(rectShapesText);
        window.display();
    }
}
