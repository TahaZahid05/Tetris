#include "J.h"

J::J() {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Blue);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10);
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(550, 65);
    frontRectXRight = &blocks[2];
    frontRectXLeft = &blocks[0];
    frontRectY = &blocks[3];
    center = &blocks[1];
}
J::J() : rotationState(0) {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Blue);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10); // Center
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(660, 65);
    center = &blocks[1];
}


void J::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void J::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void J::rotate() {
     switch (rotationState) {
    case 0: // Vertical facing right
        blocks[0].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x + 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x - 55, center->getPosition().y - 55);
        rotationState = 1;
        break;
    case 1: // Vertical facing down
        blocks[0].setPosition(center->getPosition().x, center->getPosition().y - 55);
        blocks[2].setPosition(center->getPosition().x, center->getPosition().y + 55);
        blocks[3].setPosition(center->getPosition().x - 55, center->getPosition().y + 55);
        rotationState = 2;
        break;
    case 2: // Vertical facing left
        blocks[0].setPosition(center->getPosition().x + 55, center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x - 55, center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x + 55, center->getPosition().y + 55);
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


sf::RectangleShape* J::getBlocks() {
    return blocks;
}

sf::RectangleShape* J::getFrontRectXRight() {
    return frontRectXRight;
}

sf::RectangleShape* J::getFrontRectXLeft() {
    return frontRectXLeft;
}

sf::RectangleShape* J::getFrontRectY() {
    return frontRectY;
}

sf::RectangleShape* J::getCenter() {
    return center;
}

bool J::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < settledShapes.size(); j++) {
            if (blocks[i].getGlobalBounds().intersects(settledShapes[j].getGlobalBounds()))
                return true;
        }
    }
    return false;
}
