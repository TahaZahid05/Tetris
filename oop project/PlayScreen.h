#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <queue>
#define numberfOfRows 15
#define numberOfColumns 7

class PlayScreen {
private:
    sf::RectangleShape tetrisRectangles[numberfOfRows][numberOfColumns];
    int score;
    int lines;
    int level;
    sf::Sound bgSound;
    sf::SoundBuffer bgBuffer;
    sf::SoundBuffer bgBuffer1;
    sf::SoundBuffer bgBuffer2;
    sf::SoundBuffer bgBuffer3;
    sf::SoundBuffer bgBuffer4;
    sf::SoundBuffer bgBuffer5;
    sf::SoundBuffer levelUpBuffer;
    sf::Sound levelUpSound;
    sf::SoundBuffer GameOver;
    std::queue<sf::SoundBuffer*> soundQueue;
    std::string playerName;
    void playNextSound();
    void stopSound();
public:
    PlayScreen(const std::string& playerName);
    void show(sf::RenderWindow& window);
    void removeFilledRows(std::vector<sf::RectangleShape>& settledShapes);

};

#endif
