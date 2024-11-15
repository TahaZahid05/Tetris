#ifndef S_H
#define S_H

#include "Tetromino.h"

class S : public Tetromino {
private:
    sf::RectangleShape blocks[4];
    sf::RectangleShape* center;
    int rotationState; // Tracks the current rotation state (0 or 1 for S)
public:
    S();
    void move(sf::Vector2f velocity) ;
    void draw(sf::RenderWindow& window) ;
    void rotate() ;
    sf::RectangleShape* getBlocks() ;
    bool isColliding(const std::vector<sf::RectangleShape>& settledShapes) ;
};

#endif
