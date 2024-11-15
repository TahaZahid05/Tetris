#ifndef J_H
#define J_H

#include "Tetromino.h"

class J : public Tetromino {
private:
    sf::RectangleShape blocks[4];
    sf::RectangleShape* frontRectXRight;
    sf::RectangleShape* frontRectXLeft;
    sf::RectangleShape* frontRectY;
    sf::RectangleShape* center;
    int rotationState;
public:
    J();
    void move(sf::Vector2f velocity);
    void draw(sf::RenderWindow& window);
    void rotate();
    sf::RectangleShape* getBlocks();
    sf::RectangleShape* getFrontRectXRight();
    sf::RectangleShape* getFrontRectXLeft();
    sf::RectangleShape* getFrontRectY();
    sf::RectangleShape* getCenter();
    bool isColliding(const std::vector<sf::RectangleShape>& settledShapes);
};

#endif
