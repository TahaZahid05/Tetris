#include "L.h"

L::L() {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color(255, 165, 0)); // Orange
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10); // Center
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(660, 65);
    center = &blocks[1];
}

void L::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void L::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

L::L() : rotationState(0) {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color(255, 165, 0)); // Orange
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10); // Center
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(550, 65);
    center = &blocks[1];
}
void L::rotate() {
    switch (rotationState) {
    case 0: // Vertical facing left
        blocks[0].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x + 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y + 55);
        rotationState = 1;
        break;
    case 1: // Vertical facing down
        blocks[0].setPosition(center->getPosition().x, center->getPosition().y - 55);
        blocks[2].setPosition(center->getPosition().x, center->getPosition().y + 55);
        blocks[3].setPosition(center->getPosition().x - 55, center->getPosition().y + 55);
        rotationState = 2;
        break;
    case 2: // Vertical facing right
        blocks[0].setPosition(center->getPosition().x + 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x - 55, center->getPosition().y - 55);
        rotationState = 3;
        break;
    case 3: // Vertical facing up
        blocks[0].setPosition(center->getPosition().x, center->getPosition().y + 55);
        blocks[2].setPosition(center->getPosition().x, center->getPosition().y - 55);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y - 55);
        rotationState = 0;
        break;
    }
}



sf::RectangleShape* L::getBlocks() {
    return blocks;
}

bool L::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (int i = 0; i < 4; i++) {
        for (const auto& shape : settledShapes) {
            if (blocks[i].getGlobalBounds().intersects(shape.getGlobalBounds()))
                return true;
        }
    }
    return false;
}
