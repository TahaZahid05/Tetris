#include "Z.h"

Z::Z() : rotationState(0) {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Red);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10); // Center
    blocks[2].setPosition(605, 65);
    blocks[3].setPosition(660, 65);
    center = &blocks[2];
    frontRectXLeft = &blocks[0];
    frontRectXRight = &blocks[3];
    frontRectY = &blocks[3];
}

void Z::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void Z::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void Z::rotate() {
    sf::Vector2f newPos0, newPos1, newPos3;
    switch(rotationState) {
        case 0: // Horizontal facing right
            newPos0 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y);
            newPos1 = sf::Vector2f(center->getPosition().x, center->getPosition().y + 55);
            newPos3 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y - 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos1.x >= 550 && newPos1.x <= 880 && newPos1.y >= 10 && newPos1.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[1].setPosition(newPos1);
                blocks[3].setPosition(newPos3);
                rotationState = 1;
                frontRectXLeft = &blocks[1];
                frontRectXRight = &blocks[3];
                frontRectY = &blocks[1];
            }
            break;
        case 1:
            newPos0 = sf::Vector2f(center->getPosition().x, center->getPosition().y + 55);
            newPos1 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y);
            newPos3 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y + 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos1.x >= 550 && newPos1.x <= 880 && newPos1.y >= 10 && newPos1.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[1].setPosition(newPos1);
                blocks[3].setPosition(newPos3);
                rotationState = 0;
                frontRectXLeft = &blocks[1];
                frontRectXRight = &blocks[3];
                frontRectY = &blocks[0];
            }
            break;
        case 2:
            newPos0 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y);
            newPos1 = sf::Vector2f(center->getPosition().x, center->getPosition().y - 55);
            newPos3 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y + 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos1.x >= 550 && newPos1.x <= 880 && newPos1.y >= 10 && newPos1.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[1].setPosition(newPos1);
                blocks[3].setPosition(newPos3);
                rotationState = 3;
                frontRectXLeft = &blocks[3];
                frontRectXRight = &blocks[1];
                frontRectY = &blocks[3];
            }
            break;
        case 3:
            newPos0 = sf::Vector2f(center->getPosition().x, center->getPosition().y - 55);
            newPos1 = sf::Vector2f(center->getPosition().x + 55, center->getPosition().y);
            newPos3 = sf::Vector2f(center->getPosition().x - 55, center->getPosition().y - 55);
            if (newPos0.x >= 550 && newPos0.x <= 880 && newPos0.y >= 10 && newPos0.y <= 780 &&
                newPos1.x >= 550 && newPos1.x <= 880 && newPos1.y >= 10 && newPos1.y <= 780 &&
                newPos3.x >= 550 && newPos3.x <= 880 && newPos3.y >= 10 && newPos3.y <= 780) {
                blocks[0].setPosition(newPos0);
                blocks[1].setPosition(newPos1);
                blocks[3].setPosition(newPos3);
                rotationState = 0;
                frontRectXLeft = &blocks[3];
                frontRectXRight = &blocks[1];
                frontRectY = &blocks[1];
            }
            break;
    }
}

sf::RectangleShape* Z::getBlocks() {
    return blocks;
}

sf::RectangleShape* Z::getCenter(){
    return center;
}

bool Z::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (int i = 0; i < 4; i++) {
        for (const auto& shape : settledShapes) {
            if (blocks[i].getGlobalBounds().intersects(shape.getGlobalBounds()))
                return true;
        }
    }
    return false;
}

sf::RectangleShape* Z::getFrontRectXRight() {
    return &blocks[3];
}

sf::RectangleShape* Z::getFrontRectXLeft() {
    return &blocks[0];
}

sf::RectangleShape* Z::getFrontRectY() {
    return &blocks[3];
}

Tetromino* Z::clone() const {
    return new Z(*this);
}
