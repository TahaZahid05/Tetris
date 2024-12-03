#include "S.h"
// Shape created by taha and rotation logic by yousuf
S::S() : rotationState(0) {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Green);
    }
    blocks[0].setPosition(605, 10);
    blocks[1].setPosition(660, 10); // Center
    blocks[2].setPosition(550, 65);
    blocks[3].setPosition(605, 65);
    center = &blocks[1];
    frontRectXRight = &blocks[1];
    frontRectXLeft = &blocks[2];
    frontRectY = &blocks[2];
}

void S::rotate() {
    sf::Vector2f newPos0, newPos2, newPos3;
    switch(rotationState){
        case 0:
            newPos0 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y);
            newPos2 = sf::Vector2f(center->getPosition().x, center->getPosition().y + 55);
            newPos3 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y - 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos2.x >= 550 && newPos2.x <= 880 && newPos2.y >= 10 && newPos2.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[2].setPosition(newPos2);
                blocks[3].setPosition(newPos3);
                rotationState = 1;
                frontRectY = &blocks[2];
                frontRectXRight = &blocks[2];
                frontRectXLeft = &blocks[3];
            }
            break;
        case 1:
            newPos0 = sf::Vector2f(center->getPosition().x, center->getPosition().y - 55);
            newPos2 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y);
            newPos3 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y - 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos2.x >= 550 && newPos2.x <= 880 && newPos2.y >= 10 && newPos2.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[2].setPosition(newPos2);
                blocks[3].setPosition(newPos3);
                rotationState = 2;
                frontRectY = &blocks[1];
                frontRectXRight = &blocks[3];
                frontRectXLeft = &blocks[2];
            }
            break;
        case 2:
            newPos0 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y);
            newPos2 = sf::Vector2f(center->getPosition().x, center->getPosition().y - 55);
            newPos3 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y + 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos2.x >= 550 && newPos2.x <= 880 && newPos2.y >= 10 && newPos2.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[2].setPosition(newPos2);
                blocks[3].setPosition(newPos3);
                rotationState = 3;
                frontRectY = &blocks[3];
                frontRectXRight = &blocks[3];
                frontRectXLeft = &blocks[1];
            }
            break;
        case 3:
            newPos0 = sf::Vector2f(center->getPosition().x, center->getPosition().y + 55);
            newPos2 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y);
            newPos3 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y + 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos2.x >= 550 && newPos2.x <= 880 && newPos2.y >= 10 && newPos2.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[2].setPosition(newPos2);
                blocks[3].setPosition(newPos3);
                rotationState = 0;
                frontRectY = &blocks[0];
                frontRectXRight = &blocks[2];
                frontRectXLeft = &blocks[3];
            }
            break;
    }
}

Tetromino* S::clone() const {
    return new S(*this);
}
