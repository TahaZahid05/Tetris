#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#define numberfOfRows 15
#define numberOfColumns 7

class PlayScreen {
private:
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    int score;
    int lines;
    int level;
 std::string playerName;
public:
    PlayScreen(const std::string& playerName);
    void show(sf::RenderWindow& window);
    void removeFilledRows(std::vector<sf::RectangleShape>& settledShapes);
};

#endif
