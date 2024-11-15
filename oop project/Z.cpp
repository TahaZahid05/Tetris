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
    center = &blocks[1];
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
    if (rotationState == 0) {
        blocks[0].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x, center->getPosition().y + 55);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y + 55);
        rotationState = 1;
    } else {
        blocks[0].setPosition(center->getPosition().x, center->getPosition().y - 55);
        blocks[2].setPosition(center->getPosition().x + 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y + 55);
        rotationState = 0;
    }
}

sf::RectangleShape* Z::getBlocks() {
    return blocks;
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
