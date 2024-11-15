#ifndef Z_H
#define Z_H

#include "Tetromino.h"

class Z : public Tetromino {
private:
    sf::RectangleShape blocks[4];
    sf::RectangleShape* center;
    int rotationState; // Tracks the current rotation state (0 or 1 for Z)
public:
    Z();
    void move(sf::Vector2f velocity) ;
    void draw(sf::RenderWindow& window) ;
    void rotate() ;
    sf::RectangleShape* getBlocks() ;
    bool isColliding(const std::vector<sf::RectangleShape>& settledShapes);
};

#endif
