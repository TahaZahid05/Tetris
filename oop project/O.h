#ifndef O_H
#define O_H

#include "Tetromino.h"

class O : public Tetromino {
    private:
        sf::RectangleShape blocks[4];
        sf::RectangleShape* frontRectXRight;
        sf::RectangleShape* frontRectXLeft;
        sf::RectangleShape* frontRectY;
        sf::RectangleShape* center;
    public:
        O();
        void move(sf::Vector2f velocity);
        void draw(sf::RenderWindow& window);
        void rotate();
        sf::RectangleShape* getBlocks();
        sf::RectangleShape* getFrontRectXRight();
        sf::RectangleShape* getFrontRectXLeft();
        sf::RectangleShape* getFrontRectY();
        sf::RectangleShape* getCenter();
        bool isColliding(const std::vector<sf::RectangleShape>& settledShapes);
        Tetromino* clone() const override;
};

#endif