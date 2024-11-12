
#include "I.h"

I::I() {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Cyan);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10);
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(715, 10);
    frontRectXRight = &blocks[3];
    frontRectXLeft = &blocks[0];
    frontRectY = &blocks[0];
    center = &blocks[1];
}

void I::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}

void I::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(blocks[i]);
    }
}

void I::rotate() {
    // Implement rotation logic for I shape
    if(frontRectY == &blocks[0] && (*frontRectY).getPosition().y <= 670){
        blocks[0].setPosition(center->getPosition().x,center->getPosition().y - 55);
        blocks[2].setPosition(center->getPosition().x,center->getPosition().y + 55);
        blocks[3].setPosition(center->getPosition().x,center->getPosition().y + 110);
        frontRectY = &blocks[3];
        frontRectXRight = &blocks[3];
        frontRectXLeft = &blocks[3];
    }
    else if(frontRectY == &blocks[3] && (*frontRectY).getPosition().y <= 715){
        blocks[0].setPosition(center->getPosition().x - 55,center->getPosition().y);
        blocks[2].setPosition(center->getPosition().x + 55,center->getPosition().y);
        blocks[3].setPosition(center->getPosition().x + 110,center->getPosition().y);
        frontRectY = &blocks[0];
        frontRectXRight = &blocks[3];
        frontRectXLeft = &blocks[0];
    }
}

sf::RectangleShape* I::getBlocks() {
    return blocks;
}

sf::RectangleShape* I::getFrontRectXRight() {
    return frontRectXRight;
}

sf::RectangleShape* I::getFrontRectXLeft() {
    return frontRectXLeft;
}

sf::RectangleShape* I::getFrontRectY() {
    return frontRectY;
}

sf::RectangleShape* I::getCenter() {
    return center;
}

bool I::isColliding(const std::vector<sf::RectangleShape>& settledShapes){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < settledShapes.size(); j++) {
            if(blocks[i].getGlobalBounds().intersects(settledShapes[j].getGlobalBounds()))
                return true;
        }
    }
    return false;
}