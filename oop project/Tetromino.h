
#ifndef TETROMINO_H
#define TETROMINO_H

#include <SFML/Graphics.hpp>

class Tetromino {
public:
    virtual void move(sf::Vector2f velocity) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void rotate() = 0;
    virtual sf::RectangleShape* getBlocks() = 0;
    virtual sf::RectangleShape* getFrontRectXRight() = 0;
    virtual sf::RectangleShape* getFrontRectXLeft() = 0;
    virtual sf::RectangleShape* getFrontRectY() = 0;
    virtual sf::RectangleShape* getCenter() = 0;
    virtual bool isColliding(const std::vector<sf::RectangleShape>& settledShapes) = 0;
};

#endif // TETROMINO_H