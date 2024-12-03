#ifndef TETROMINO_H
#define TETROMINO_H

#include <SFML/Graphics.hpp>
#include <vector>

//Originally created by Taha. Changes made by yousuf to rotate to make it work correctly. First 3 shapes are made by taha. Last 4 made by yousuf
class Tetromino {
public:
    void move(sf::Vector2f velocity);
    void draw(sf::RenderWindow& window);
    virtual void rotate() = 0;
    sf::RectangleShape* getBlocks();
    sf::RectangleShape* getFrontRectXRight();
    sf::RectangleShape* getFrontRectXLeft();
    sf::RectangleShape* getFrontRectY();
    sf::RectangleShape* getCenter();
    bool isColliding(const std::vector<sf::RectangleShape>& settledShapes);
    virtual Tetromino* clone() const = 0;

protected:
    sf::RectangleShape blocks[4];
    sf::RectangleShape* frontRectXRight;
    sf::RectangleShape* frontRectXLeft;
    sf::RectangleShape* frontRectY;
    sf::RectangleShape* center;
};

#endif // TETROMINO_H