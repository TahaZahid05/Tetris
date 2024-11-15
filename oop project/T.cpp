#include "T.h"

T::T() {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Magenta);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10);
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(605, 65);
    frontRectXRight = &blocks[2];
    frontRectXLeft = &blocks[0];
    frontRectY = &blocks[3];
    center = &blocks[1];
}

void T::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void T::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void T::rotate() {
    // Implement rotation logic for T shape
    // Example rotation logic can be added here
}

sf::RectangleShape* T::getBlocks() {
    return blocks;
}

sf::RectangleShape* T::getFrontRectXRight() {
    return frontRectXRight;
}

sf::RectangleShape* T::getFrontRectXLeft() {
    return frontRectXLeft;
}

sf::RectangleShape* T::getFrontRectY() {
    return frontRectY;
}

sf::RectangleShape* T::getCenter() {
    return center;
}

bool T::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < settledShapes.size(); j++) {
            if (blocks[i].getGlobalBounds().intersects(settledShapes[j].getGlobalBounds()))
                return true;
        }
    }
    return false;
}
