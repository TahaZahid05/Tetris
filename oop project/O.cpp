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

void O::rotate() {
    // O shape does not need rotation
}

Tetromino* O::clone() const {
    return new O(*this);
}