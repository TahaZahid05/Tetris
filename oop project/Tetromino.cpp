#include "Tetromino.h"
//Originally created by Taha. Changes made by yousuf to rotate to make it work correctly.
// Constructor
void Tetromino::move(sf::Vector2f velocity) {
    for (int i = 0; i < 4; i++) {
        blocks[i].move(velocity);
    }
}
// Draw Tetromino
void Tetromino::draw(sf::RenderWindow& window) {
    for (const auto& block : blocks) {
        window.draw(block);
    }
}

// void Tetromino::rotate() {
//     // no need
// }
// Getters
sf::RectangleShape* Tetromino::getBlocks() {
    return blocks;
}

sf::RectangleShape* Tetromino::getFrontRectXRight() {
    return frontRectXRight;
}

sf::RectangleShape* Tetromino::getFrontRectXLeft() {
    return frontRectXLeft;
}

sf::RectangleShape* Tetromino::getFrontRectY() {
    return frontRectY;
}

sf::RectangleShape* Tetromino::getCenter() {
    return center;
}

bool Tetromino::isColliding(const std::vector<sf::RectangleShape>& settledShapes) {
    for (const auto& block : blocks) {
        for (const auto& shape : settledShapes) {
            if (block.getGlobalBounds().intersects(shape.getGlobalBounds())) {
                return true;
            }
        }
    }
    return false;
}
