#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "EndScreen.h"
#include "PlayScreen.h"
#include "Tetromino.h"
#include "I.h"
#include "O.h"
#include "T.h"

void PlayScreen::show(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(180.f, 230.f));
    rect.setPosition(50, 20);
    rect.setFillColor(sf::Color::White);
    sf::RectangleShape rectBorder(sf::Vector2f(200.f, 250.f));
    rectBorder.setPosition(40, 10);
    rectBorder.setFillColor(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return;
    }

    sf::Text levelText("Level", font, 30);
    levelText.setPosition(105, 40);
    levelText.setFillColor(sf::Color::Black);

    sf::RectangleShape levelRect(sf::Vector2f(150.f, 30.f));
    levelRect.setPosition(68, 80);
    levelRect.setFillColor(sf::Color::Black);

    sf::Text linesText("Lines", font, 30);
    linesText.setPosition(105, 120);
    linesText.setFillColor(sf::Color::Black);

    sf::RectangleShape linesRect(sf::Vector2f(150.f, 30.f));
    linesRect.setPosition(68, 160);
    linesRect.setFillColor(sf::Color::Black);

    int numberOfColumns = 15;
    int numberfOfRows = 7;
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    for (int i = 0; i < numberfOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            tetrisRectangles[i][j].setSize(sf::Vector2f(50.f, 50.f));
            tetrisRectangles[i][j].setPosition(550 + (55 * i), 10 + (55 * j));
            tetrisRectangles[i][j].setFillColor(sf::Color::Black);
        }
    }

    sf::RectangleShape rectNext(sf::Vector2f(300.f, 230.f));
    rectNext.setPosition(1250, 20);
    rectNext.setFillColor(sf::Color::White);
    sf::RectangleShape rectNextBorder(sf::Vector2f(320.f, 250.f));
    rectNextBorder.setPosition(1240, 10);
    rectNextBorder.setFillColor(sf::Color::Black);

    sf::Text rectNextText("NEXT", font, 30);
    rectNextText.setPosition(1350, 40);
    rectNextText.setFillColor(sf::Color::Black);

    sf::Text rectShapesText("SHAPES", font, 30);
    rectShapesText.setPosition(1330, 80);
    rectShapesText.setFillColor(sf::Color::Black);

    I shapeI;
    O shapeO;
    Tetromino* currentShape = &shapeI;
    Tetromino* nextShape = &shapeO;

    std::vector<sf::RectangleShape> settledShapes;
    sf::Vector2f velocity(0.0f, 0.15f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    currentShape->rotate();
                }
                else if(event.key.code == sf::Keyboard::Right){
                    if(currentShape->getFrontRectXRight()->getPosition().x < 880 && currentShape->getFrontRectY()->getPosition().y < 780){
                        currentShape->move(sf::Vector2f(55.f, 0.f));
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    if(currentShape->getFrontRectXLeft()->getPosition().x > 550 && currentShape->getFrontRectY()->getPosition().y < 780){
                        currentShape->move(sf::Vector2f(-55.f, 0.f));
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes)))
                velocity.y += 0.15f;
            else{
                velocity.y = 0;
                velocity.x = 0;
                int subtractFactor = (int)(currentShape->getFrontRectY()->getPosition().y - 10) % 55;
                for (int i = 0; i < 4; i++) {
                    currentShape->getBlocks()[i].setPosition(currentShape->getBlocks()[i].getPosition().x, currentShape->getBlocks()[i].getPosition().y - subtractFactor);
                }
                for(int i = 0; i < 4; i++){
                    settledShapes.push_back(currentShape->getBlocks()[i]);
                }
                currentShape = nextShape;
                int randomNum = rand() % 2;
                if(randomNum == 0)
                    nextShape = new I();
                else
                    nextShape = new O();
            }
        }
        else{
            if(currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes)))
                velocity.y = 0.15f;
            else{
                velocity.y = 0;
                velocity.x = 0;
                int subtractFactor = (int)(currentShape->getFrontRectY()->getPosition().y - 10) % 55;
                for (int i = 0; i < 4; i++) {
                    currentShape->getBlocks()[i].setPosition(currentShape->getBlocks()[i].getPosition().x, currentShape->getBlocks()[i].getPosition().y - subtractFactor);
                }
                for(int i = 0; i < 4; i++){
                    settledShapes.push_back(currentShape->getBlocks()[i]);
                }
                currentShape = nextShape;
                int randomNum = rand() % 2;
                if(randomNum == 0)
                    nextShape = new I();
                else
                    nextShape = new O();
            }
        }
        currentShape->move(velocity);
        window.clear(sf::Color::White);
        window.draw(rectBorder);
        window.draw(rect);
        window.draw(levelText);
        window.draw(levelRect);
        window.draw(linesText);
        window.draw(linesRect);
        for (int i = 0; i < numberfOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                window.draw(tetrisRectangles[i][j]);
            }
        }
        for (const auto& shape : settledShapes) {
            window.draw(shape);
        }
        currentShape->draw(window);
        window.draw(rectNextBorder);
        window.draw(rectNext);
        window.draw(rectNextText);
        window.draw(rectShapesText);
        window.display();
    }
}
