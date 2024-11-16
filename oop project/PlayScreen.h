#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics.hpp>

#define numberfOfRows 15
#define numberOfColumns 7

class PlayScreen {
private:
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    int score;
    int lines;
    int level;
public:
    PlayScreen();
    void show(sf::RenderWindow& window);
    void removeFilledRows(std::vector<sf::RectangleShape>& settledShapes);
};

#endif
