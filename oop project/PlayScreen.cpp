#include <SFML/Graphics.hpp>
#include <string>
#include "EndScreen.h"
#include "PlayScreen.h"

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

    sf::RectangleShape I1(sf::Vector2f(50.f,50.f));
    sf::RectangleShape I2(sf::Vector2f(50.f,50.f));
    sf::RectangleShape I3(sf::Vector2f(50.f,50.f));
    sf::RectangleShape I4(sf::Vector2f(50.f,50.f));
    I1.setFillColor(sf::Color::Cyan);
    I2.setFillColor(sf::Color::Cyan);
    I3.setFillColor(sf::Color::Cyan);
    I4.setFillColor(sf::Color::Cyan);
    I1.setPosition(550,10);
    I2.setPosition(550+55,10);
    I3.setPosition(550+(2*55),10);
    I4.setPosition(550+(3*55),10);
    sf::RectangleShape* frontRectXRight = &I4;
    sf::RectangleShape* frontRectXLeft = &I1;
    sf::RectangleShape* frontRectY = &I1;
    sf::Vector2f velocity(0.0f, 0.15f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    if((*frontRectY).getPosition().y <= 670){
                        if(frontRectY == &I1){
                            I2.setPosition(I1.getPosition().x,I1.getPosition().y + 55);
                            I3.setPosition(I1.getPosition().x,I2.getPosition().y + 55);
                            I4.setPosition(I1.getPosition().x,I3.getPosition().y + 55);
                            frontRectY = &I4;
                            frontRectXRight = &I4;
                            frontRectXLeft = &I4;
                        }
                        else{
                            I2.setPosition(I1.getPosition().x + 55,I1.getPosition().y);
                            I3.setPosition(I2.getPosition().x + 55,I2.getPosition().y);
                            I4.setPosition(I3.getPosition().x + 55,I3.getPosition().y);
                            frontRectY = &I1;
                            frontRectXRight = &I4;
                            frontRectXLeft = &I1;
                        }
                    }
                }
                else if(event.key.code == sf::Keyboard::Right){
                    if((*frontRectXRight).getPosition().x < 880 && (*frontRectY).getPosition().y < 780){
                        I4.setPosition(I4.getPosition().x + 55,I4.getPosition().y);
                        I3.setPosition(I3.getPosition().x + 55,I3.getPosition().y);
                        I2.setPosition(I2.getPosition().x + 55,I2.getPosition().y);
                        I1.setPosition(I1.getPosition().x + 55,I1.getPosition().y);
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    if((*frontRectXLeft).getPosition().x > 550 && (*frontRectY).getPosition().y < 780){
                        I4.setPosition(I4.getPosition().x - 55,I4.getPosition().y);
                        I3.setPosition(I3.getPosition().x - 55,I3.getPosition().y);
                        I2.setPosition(I2.getPosition().x - 55,I2.getPosition().y);
                        I1.setPosition(I1.getPosition().x - 55,I1.getPosition().y);
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if((*frontRectY).getPosition().y < 780)
                velocity.y += 0.15f;
            else
                velocity.y = 0;
                velocity.x = 0;
                if((*frontRectY).getPosition().y > 780){
                    int subtractFactor = (*frontRectY).getPosition().y - 780;
                    if(frontRectY == &I1){
                        I1.setPosition(I1.getPosition().x,780);
                        I2.setPosition(I2.getPosition().x,I2.getPosition().y - subtractFactor);
                        I3.setPosition(I3.getPosition().x,I3.getPosition().y - subtractFactor);
                        I4.setPosition(I4.getPosition().x,I4.getPosition().y - subtractFactor);
                    }
                    else{
                        I4.setPosition(I4.getPosition().x,780);
                        I2.setPosition(I2.getPosition().x,I2.getPosition().y - subtractFactor);
                        I3.setPosition(I3.getPosition().x,I3.getPosition().y - subtractFactor);
                        I1.setPosition(I1.getPosition().x,I1.getPosition().y - subtractFactor);
                    }
                }
        }
        else{
            if((*frontRectY).getPosition().y < 780)
                velocity.y = 0.15f;
            else
                velocity.y = 0;
                velocity.x = 0;
                if((*frontRectY).getPosition().y > 780){
                    int subtractFactor = (*frontRectY).getPosition().y - 780;
                    if(frontRectY == &I1){
                        I1.setPosition(I1.getPosition().x,780);
                        I2.setPosition(I2.getPosition().x,I2.getPosition().y - subtractFactor);
                        I3.setPosition(I3.getPosition().x,I3.getPosition().y - subtractFactor);
                        I4.setPosition(I4.getPosition().x,I4.getPosition().y - subtractFactor);
                    }
                    else{
                        I4.setPosition(I4.getPosition().x,780);
                        I2.setPosition(I2.getPosition().x,I2.getPosition().y - subtractFactor);
                        I3.setPosition(I3.getPosition().x,I3.getPosition().y - subtractFactor);
                        I1.setPosition(I1.getPosition().x,I1.getPosition().y - subtractFactor);
                    }
                }
        }
        I1.move(velocity);
        I2.move(velocity);
        I3.move(velocity);
        I4.move(velocity);
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
        window.draw(I1);
        window.draw(I2);
        window.draw(I3);
        window.draw(I4);
        window.draw(rectNextBorder);
        window.draw(rectNext);
        window.draw(rectNextText);
        window.draw(rectShapesText);
        window.display();
    }
}
