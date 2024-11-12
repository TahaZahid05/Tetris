
#include "O.h"

O::O() {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Yellow);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10);
    blocks[2].setPosition(550, 65);
    blocks[3].setPosition(605, 65);
    frontRectXRight = &blocks[3];
    frontRectXLeft = &blocks[0];
    frontRectY = &blocks[3];
    center = &blocks[1];
}

void O::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void O::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void O::rotate() {
    // O shape does not need rotation
}

sf::RectangleShape* O::getBlocks() {
    return blocks;
}

sf::RectangleShape* O::getFrontRectXRight() {
    return frontRectXRight;
}

sf::RectangleShape* O::getFrontRectXLeft() {
    return frontRectXLeft;
}

sf::RectangleShape* O::getFrontRectY() {
    return frontRectY;
}

sf::RectangleShape* O::getCenter() {
    return center;
}

bool O::isColliding(const std::vector<sf::RectangleShape>& settledShapes){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < settledShapes.size(); j++) {
            if(blocks[i].getGlobalBounds().intersects(settledShapes[j].getGlobalBounds()))
                return true;
        }
    }
    return false;
}