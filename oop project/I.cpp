#include "I.h"
//Shape created by taha and rotation logic by yousuf
// Constructor
I::I(): rotationState(0) {
    for (int i = 0; i < 4; i++) {
        blocks[i].setSize(sf::Vector2f(50.f, 50.f));
        blocks[i].setFillColor(sf::Color::Cyan);
    }
    blocks[0].setPosition(550, 10);
    blocks[1].setPosition(605, 10);
    blocks[2].setPosition(660, 10);
    blocks[3].setPosition(715, 10);
    center = &blocks[2];
    frontRectXRight = &blocks[3];
    frontRectXLeft = &blocks[0];
    frontRectY = &blocks[1];
}
// Rotate I shape
void I::rotate() {
    // Implement rotation logic for I shape
    switch(rotationState){
        case 0:
            if(center->getPosition().y - 55 >= 10 && center->getPosition().y - 55 <= 780 && center->getPosition().y + 55 >= 10 && center->getPosition().y + 55 <= 780
            && center->getPosition().y + 110 >= 10 && center->getPosition().y + 110 <= 780){
                center->setPosition(center->getPosition().x,center->getPosition().y + 55);
                blocks[0].setPosition(center->getPosition().x,center->getPosition().y - 110);
                blocks[1].setPosition(center->getPosition().x,center->getPosition().y - 55);
                blocks[3].setPosition(center->getPosition().x,center->getPosition().y + 55);
                rotationState = 1;
                frontRectY = &blocks[3];
                frontRectXRight = &blocks[2];
                frontRectXLeft = &blocks[0];
                break;
            }
        case 1:
            if(blocks[2].getPosition().x - 55 >= 550 && blocks[2].getPosition().x - 55 <= 880){
                if(center->getPosition().x -55 >= 550 && center->getPosition().x -55 <= 880 && center->getPosition().x + 110 >= 550 && center->getPosition().x + 110 <= 880){
                    blocks[0].setPosition(center->getPosition().x - 110,center->getPosition().y);
                    blocks[1].setPosition(center->getPosition().x - 55,center->getPosition().y);
                    blocks[3].setPosition(center->getPosition().x + 55,center->getPosition().y);
                    rotationState = 2;
                    frontRectY = &blocks[2];
                    frontRectXRight = &blocks[3];
                    frontRectXLeft = &blocks[0];
                    center = &blocks[1];
                    break;
                }
            }
        case 2:
            if(center->getPosition().y - 55 >= 10 && center->getPosition().y - 55 <= 780){
                center->setPosition(center->getPosition().x,center->getPosition().y - 55);
                if(center->getPosition().y - 55 >= 10 && center->getPosition().y - 55 <= 780 && center->getPosition().y + 55 >= 10 && center->getPosition().y + 55 <= 780
                && center->getPosition().y + 110 >= 10 && center->getPosition().y + 110 <= 780){
                    blocks[0].setPosition(center->getPosition().x,center->getPosition().y - 55);
                    blocks[2].setPosition(center->getPosition().x,center->getPosition().y + 55);
                    blocks[3].setPosition(center->getPosition().x,center->getPosition().y + 110);
                    rotationState = 3;
                    frontRectY = &blocks[3];
                    frontRectXRight = &blocks[2];
                    frontRectXLeft = &blocks[0];
                    break;
                }
            }
        case 3:
            if(center->getPosition().x - 55 >= 550 && center->getPosition().x - 55 <= 880 && center->getPosition().x + 55 >= 550 && center->getPosition().x + 55 <= 880
            && center->getPosition().x + 110 >= 550 && center->getPosition().x + 110 <= 880){
                blocks[0].setPosition(center->getPosition().x - 55,center->getPosition().y);
                blocks[2].setPosition(center->getPosition().x + 55,center->getPosition().y);
                blocks[3].setPosition(center->getPosition().x + 110,center->getPosition().y);
                rotationState = 0;
                frontRectY = &blocks[2];
                frontRectXRight = &blocks[3];
                frontRectXLeft = &blocks[0];
                center = &blocks[2];
                break;   
            }
    }
}
// Clone I shape
Tetromino* I::clone() const {
    return new I(*this);
}