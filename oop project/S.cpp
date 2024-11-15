#include "S.h"

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
}

void S::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void S::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void S::rotate() {
    if (rotationState == 0) {
        blocks[0].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x, center->getPosition().y + 55);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y + 55);
        rotationState = 1;
    } else {
        blocks[0].setPosition(center->getPosition().x, center->getPosition().y - 55);
        blocks[2].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x - 55, center->getPosition().y + 55);
        rotationState = 0;
    }
}

sf::RectangleShape* S::getBlocks() {
    return blocks;
}

bool S::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (int i = 0; i < 4; i++) {
        for (const auto& shape : settledShapes) {
            if (blocks[i].getGlobalBounds().intersects(shape.getGlobalBounds()))
                return true;
        }
    }
    return false;
}
