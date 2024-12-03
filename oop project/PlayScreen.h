#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <queue>
#include "Tetromino.h"
#include "SoundManager.h"
#define numberfOfRows 15
#define numberOfColumns 7
#define LINES_PER_LEVEL 2

class PlayScreen {
private:
    SoundManager playSound;
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    int score;
    int lines;
    int level;
    std::string playerName;
    Tetromino* currentShape;
    Tetromino* nextShape;
    Tetromino* nextShapePrint;
    void playNextSound();
    void stopSound();
public:
    PlayScreen(const std::string& playerName);
    void show(sf::RenderWindow& window);
    void removeFilledRows(std::vector<sf::RectangleShape>& settledShapes);
    int getScore() const;

};

#endif
