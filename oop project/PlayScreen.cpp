#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "EndScreen.h"
#include "PlayScreen.h"
#include "Tetromino.h"
#include "EnterPlayerName.h"
#include "Game.h"
#include "I.h"
#include "O.h"
#include "J.h"
#include "S.h"
#include "Z.h"
#include "L.h"
#include "T.h"

// using namespace std;

int PlayScreen::getScore() const {
    return score;
}

PlayScreen::PlayScreen(const std::string& playerName) 
    : score(0), lines(0), level(0), playerName(playerName), currentShape(new J()), nextShape(new O()), nextShapePrint(nextShape->clone()) {
    for (int i = 0; i < numberfOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            tetrisRectangles[i][j].setSize(sf::Vector2f(50.f, 50.f));
            tetrisRectangles[i][j].setFillColor(sf::Color::Black);
            tetrisRectangles[i][j].setPosition(550 + j * 55, 10 + i * 55);
        }
    }
}

PlayScreen::~PlayScreen() {
    delete currentShape;
    delete nextShape;
    delete nextShapePrint;
}

void PlayScreen::removeFilledRows(std::vector<sf::RectangleShape>& settledShapes) {
    int rowHeight = 55;
    int numRows = 15; // Assuming 14 rows based on the grid height
    int numCols = 7;  // Assuming 6 columns based on the grid width
    int totalLinesGone = 0;
    for (int row = 0; row < numRows; row++) {
        int filledCount = 0;
        for (int col = 0; col < numCols; col++) {
            // sf::Vector2f pos(550 + col * rowHeight, 10 + row * rowHeight);
            for (auto& shape : settledShapes) {
                if ((int)shape.getPosition().x == tetrisRectangles[row][col].getPosition().x && (int)shape.getPosition().y == tetrisRectangles[row][col].getPosition().y) {
                    ++filledCount;
                    break;
                }
            }
        }

        if (filledCount == numCols) {
            lines += 1;
            if(!lineUpBuffer.loadFromFile("sounds/tetris-gb-21-line-clear-101soundboards.ogg")){
                return;
            }
            lineUpSound.setBuffer(lineUpBuffer);
            lineUpSound.play();
            totalLinesGone += 1;
            if (int(lines / 10) > level){
                if(!levelUpBuffer.loadFromFile("sounds/next-level-101soundboards.ogg")){
                    return;
                }
                levelUpSound.setBuffer(levelUpBuffer);
                levelUpSound.play();
            }
            level = lines / 10;
            // Remove all squares in the filled row
            settledShapes.erase(
                std::remove_if(settledShapes.begin(), settledShapes.end(),
                               [rowHeight, row](const sf::RectangleShape& shape) {
                                   return (int)shape.getPosition().y == 10 + row * rowHeight;
                               }),
                settledShapes.end());

            // Move all squares above the filled row down by one row
            for (auto& shape : settledShapes) {
                if ((int)shape.getPosition().y < 10 + row * rowHeight) {
                    shape.move(0, rowHeight);
                }
            }
        }
    }
    if(totalLinesGone == 1){
        score += 40 * (level + 1);
    }
    else if(totalLinesGone == 2){
        score += 100 * (level + 1);
    }
    else if(totalLinesGone == 3){
        score += 300 * (level + 1);
    }
    else if(totalLinesGone == 4){
        score += 1200 * (level + 1);
    }
}

void PlayScreen::show(sf::RenderWindow& window) {
    if(!bgBuffer.loadFromFile("sounds/nutcracker-101soundboards.ogg")){
        return;
    }
    if(!bgBuffer1.loadFromFile("sounds/nutcracker-2-101soundboards.ogg")){
        return;
    }
    if(!bgBuffer2.loadFromFile("sounds/nutcracker-3-101soundboards.ogg")){
        return;
    }
    if(!bgBuffer3.loadFromFile("sounds/nutcracker-4-101soundboards.ogg")){
        return;
    }
    if(!bgBuffer4.loadFromFile("sounds/nutcracker-5-101soundboards.ogg")){
        return;
    }
    if(!bgBuffer5.loadFromFile("sounds/nutcracker-6-101soundboards.ogg")){
        return;
    }
    soundQueue.push(&bgBuffer);
    soundQueue.push(&bgBuffer1);
    soundQueue.push(&bgBuffer2);
    soundQueue.push(&bgBuffer3);
    soundQueue.push(&bgBuffer4);
    soundQueue.push(&bgBuffer5);

    playNextSound();

    level = 1;
    sf::RectangleShape rect(sf::Vector2f(180.f, 320.f));
    rect.setPosition(50, 20);
    rect.setFillColor(sf::Color::White);
    sf::RectangleShape rectBorder(sf::Vector2f(200.f, 340.f));
    rectBorder.setPosition(40, 10);
    rectBorder.setFillColor(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        return;
    }

    sf::Text levelText("Level", font, 30);
    levelText.setPosition(105, 40);
    levelText.setFillColor(sf::Color::Black);

    sf::RectangleShape levelRect(sf::Vector2f(150.f, 40.f));
    levelRect.setPosition(68, 80);
    levelRect.setFillColor(sf::Color::Black);

    sf::Text linesText("Lines", font, 30);
    linesText.setPosition(105, 130);
    linesText.setFillColor(sf::Color::Black);

    sf::RectangleShape linesRect(sf::Vector2f(150.f, 40.f));
    linesRect.setPosition(68, 170);
    linesRect.setFillColor(sf::Color::Black);

    sf::Text scoreText("Score", font, 30);
    scoreText.setPosition(105, 220);
    scoreText.setFillColor(sf::Color::Black);

    sf::RectangleShape scoreRect(sf::Vector2f(150.f, 40.f));
    scoreRect.setPosition(68, 260);
    scoreRect.setFillColor(sf::Color::Black);

    sf::RectangleShape rectNext(sf::Vector2f(300.f, 320.f));
    rectNext.setPosition(1250, 20);
    rectNext.setFillColor(sf::Color::White);
    sf::RectangleShape rectNextBorder(sf::Vector2f(320.f, 340.f));
    rectNextBorder.setPosition(1240, 10);
    rectNextBorder.setFillColor(sf::Color::Black);

    sf::Text rectNextText("NEXT", font, 30);
    rectNextText.setPosition(1350, 40);
    rectNextText.setFillColor(sf::Color::Black);

    sf::Text rectShapesText("SHAPES", font, 30);
    rectShapesText.setPosition(1330, 80);
    rectShapesText.setFillColor(sf::Color::Black);


    I shapeI;
    O shapeO;
    J shapeJ;
    L shapeL;
    S shapeS;
    Z shapeZ;
    T shapeT;

    std::vector<sf::RectangleShape> settledShapes;
    sf::Vector2f velocity(0.0f, 0.05f);

    if(level <= 10){
        velocity.y = 0.15f;
    }
    else if(level == 13){
        velocity.y = 0.25f;
    }
    else if(level == 16){
        velocity.y = 0.35f;
    }
    else if(level == 19){
        velocity.y = 0.45f;
    }
    else if(level == 29){
        velocity.y = 0.55f;
    }

    bool isPaused = false;
    sf::RectangleShape pauseButton(sf::Vector2f(100.f, 50.f));
    pauseButton.setPosition(40, 750);
    pauseButton.setFillColor(sf::Color::Red);

    sf::Text pauseButtonText("Pause", font, 20);
    pauseButtonText.setPosition(60, 760);
    pauseButtonText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        if(bgSound.getStatus() == sf::Sound::Stopped){
            playNextSound();
        }
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (pauseButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    isPaused = !isPaused;
                    pauseButtonText.setString(isPaused ? "Resume" : "Pause");
                }
            }

            if (!isPaused) {
                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Up){
                        if(currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes))){
                            currentShape->rotate();
                            if(!rotateBuffer.loadFromFile("sounds/tetris-gb-19-rotate-piece-101soundboards.ogg")){
                                return;
                            }
                            rotateSound.setBuffer(rotateBuffer);
                            rotateSound.play();
                        }
                    }
                    else if(event.key.code == sf::Keyboard::Right){
                        if(currentShape->getFrontRectXRight()->getPosition().x < 880 && currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes))){
                            currentShape->move(sf::Vector2f(55.f, 0.f));
                            if(!moveBuffer.loadFromFile("sounds/tetris-gb-18-move-piece-101soundboards.ogg")){
                                return;
                            }
                            moveSound.setBuffer(moveBuffer);
                            moveSound.play();
                        }
                    }
                    else if(event.key.code == sf::Keyboard::Left){
                        if(currentShape->getFrontRectXLeft()->getPosition().x > 550 && currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes))){
                            currentShape->move(sf::Vector2f(-55.f, 0.f));
                            if(!moveBuffer.loadFromFile("sounds/tetris-gb-18-move-piece-101soundboards.ogg")){
                                return;
                            }
                            moveSound.setBuffer(moveBuffer);
                            moveSound.play();
                        }
                    }
                    
                }
            }
        }

        if (!isPaused) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                score += 1;
                if(currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes)))
                    velocity.y += 0.15f;
                else{
                    if(currentShape->isColliding(settledShapes) && currentShape->getFrontRectY()->getPosition().y <= 10){
                        velocity.y = 0;
                        velocity.x = 0;
                        sf::Clock clock;
                        sf::Text linesScore(std::to_string(lines), font, 30);
                        linesScore.setPosition(109 + (21/(std::to_string(lines)).length()), 170);
                        linesScore.setFillColor(sf::Color::White);

                        sf::Text levelScore(std::to_string(level), font, 30);
                        levelScore.setPosition(109 + (21/(std::to_string(level)).length()), 80);
                        levelScore.setFillColor(sf::Color::White);

                        sf::Text scoreScore(std::to_string(score), font, 30);
                        scoreScore.setPosition(109 + (21/(std::to_string(score)).length()), 260);
                        scoreScore.setFillColor(sf::Color::White);
                        bgSound.stop();
                        if(!GameOver.loadFromFile("sounds/game-over-101soundboards.ogg")){
                            return;
                        }
                        bgSound.setBuffer(GameOver);
                        bgSound.play();
                        while (clock.getElapsedTime().asSeconds() < 2.0f) {
                            // Display the current state to the user
                            window.clear(sf::Color::White);
                            window.draw(rectBorder);
                            window.draw(rect);
                            window.draw(levelText);
                            window.draw(levelRect);
                            window.draw(levelScore);
                            window.draw(linesText);
                            window.draw(linesRect);
                            window.draw(linesScore);
                            window.draw(scoreText);
                            window.draw(scoreRect);
                            window.draw(scoreScore);
                            for (int i = 0; i < numberfOfRows; i++) {
                                for (int j = 0; j < numberOfColumns; j++) {
                                    window.draw(tetrisRectangles[i][j]);
                                }
                            }
                            for (const auto& shape : settledShapes) {
                                window.draw(shape);
                            }
      
                            currentShape->draw(window);
                            window.draw(rectNextBorder);
                            window.draw(rectNext);
                            window.draw(rectNextText);
                            window.draw(rectShapesText);
                            window.display();
                        }
                        // EndScreen endScreen;
                        // endScreen.saveHighScore(playerName, score);
                        // endScreen.show(window, playerName, score);
                        Game::getInstance().switchScreen("end");
                    }
                    else{
                        velocity.y = 0;
                        velocity.x = 0;
                        int subtractFactor = (int)(currentShape->getFrontRectY()->getPosition().y - 10) % 55;
                        for (int i = 0; i < 4; i++) {
                            currentShape->getBlocks()[i].setPosition(currentShape->getBlocks()[i].getPosition().x, currentShape->getBlocks()[i].getPosition().y - subtractFactor);
                        }
                        for(int i = 0; i < 4; i++){
                            settledShapes.push_back(currentShape->getBlocks()[i]);
                        }
                        removeFilledRows(settledShapes); // Check and remove filled rows
                        delete currentShape;
                        currentShape = nextShape;
                        int randomNum = rand() % 7;
                        if(randomNum == 0){
                            nextShape = new I();
                        }
                        else if(randomNum == 1){
                            nextShape = new O();
                        }
                        else if(randomNum == 2){
                            nextShape = new T();
                        }
                        else if(randomNum == 3){
                            nextShape = new J();
                        }
                        else if(randomNum == 4){
                            nextShape = new L();
                        }
                        else if(randomNum == 5){
                            nextShape = new S();
                        }
                        else{
                            nextShape = new Z();
                        }
                        delete nextShapePrint;
                        nextShapePrint = nextShape->clone();
                    }
                }
            }
            else{
                if(currentShape->getFrontRectY()->getPosition().y < 780 && !(currentShape->isColliding(settledShapes)))
                    velocity.y = 0.15f;
                else{
                    if(currentShape->isColliding(settledShapes) && currentShape->getFrontRectY()->getPosition().y <= 10){
                        velocity.y = 0;
                        velocity.x = 0;
                        sf::Clock clock;
                        sf::Text linesScore(std::to_string(lines), font, 30);
                        linesScore.setPosition(109 + (21/(std::to_string(lines)).length()), 170);
                        linesScore.setFillColor(sf::Color::White);

                        sf::Text levelScore(std::to_string(level), font, 30);
                        levelScore.setPosition(109 + (21/(std::to_string(level)).length()), 80);
                        levelScore.setFillColor(sf::Color::White);

                        sf::Text scoreScore(std::to_string(score), font, 30);
                        scoreScore.setPosition(109 + (21/(std::to_string(score)).length()), 260);
                        scoreScore.setFillColor(sf::Color::White);
                        bgSound.stop();
                        if(!GameOver.loadFromFile("sounds/game-over-101soundboards.ogg")){
                            return;
                        }
                        bgSound.setBuffer(GameOver);
                        bgSound.play();
                        while (clock.getElapsedTime().asSeconds() < 2.0f) {
                            // Display the current state to the user
                            window.clear(sf::Color::White);
                            window.draw(rectBorder);
                            window.draw(rect);
                            window.draw(levelText);
                            window.draw(levelRect);
                            window.draw(levelScore);
                            window.draw(linesText);
                            window.draw(linesRect);
                            window.draw(linesScore);
                            window.draw(scoreText);
                            window.draw(scoreRect);
                            window.draw(scoreScore);
                            for (int i = 0; i < numberfOfRows; i++) {
                                for (int j = 0; j < numberOfColumns; j++) {
                                    window.draw(tetrisRectangles[i][j]);
                                }
                            }
                            for (const auto& shape : settledShapes) {
                                window.draw(shape);
                            }
                            currentShape->draw(window);
                            window.draw(rectNextBorder);
                            window.draw(rectNext);
                            window.draw(rectNextText);
                            window.draw(rectShapesText);
                            window.display();
                        }
                        // EndScreen endScreen;
                        // endScreen.saveHighScore(playerName, score);
                        // endScreen.show(window, playerName, score);
                        Game::getInstance().switchScreen("end");
                    }
                    else{
                        velocity.y = 0;
                        velocity.x = 0;
                        int subtractFactor = (int)(currentShape->getFrontRectY()->getPosition().y - 10) % 55;
                        for (int i = 0; i < 4; i++) {
                            currentShape->getBlocks()[i].setPosition(currentShape->getBlocks()[i].getPosition().x, currentShape->getBlocks()[i].getPosition().y - subtractFactor);
                        }
                        for(int i = 0; i < 4; i++){
                            settledShapes.push_back(currentShape->getBlocks()[i]);
                        }
                        removeFilledRows(settledShapes); // Check and remove filled rows
                        delete currentShape;
                        currentShape = nextShape;
                        int randomNum = rand() % 7;
                        if(randomNum == 0){
                            nextShape = new I();
                        }
                        else if(randomNum == 1){
                            nextShape = new O();
                        }
                        else if(randomNum == 2){
                            nextShape = new T();
                        }
                        else if(randomNum == 3){
                            nextShape = new J();
                        }
                        else if(randomNum == 4){
                            nextShape = new L();
                        }
                        else if(randomNum == 5){
                            nextShape = new S();
                        }
                        else{
                            nextShape = new Z();
                        }
                        delete nextShapePrint;
                        nextShapePrint = nextShape->clone();
                    }
                }
            }

            currentShape->move(velocity);
        }

        sf::Text linesScore(std::to_string(lines), font, 30);
        linesScore.setPosition(109 + (21/(std::to_string(lines)).length()), 170);
        linesScore.setFillColor(sf::Color::White);

        sf::Text levelScore(std::to_string(level), font, 30);
        levelScore.setPosition(109 + (21/(std::to_string(level)).length()), 80);
        levelScore.setFillColor(sf::Color::White);

        sf::Text scoreScore(std::to_string(score), font, 30);
        scoreScore.setPosition(109 + (21/(std::to_string(score)).length()), 260);
        scoreScore.setFillColor(sf::Color::White);

        window.clear(sf::Color::White);
        window.draw(rectBorder);
        window.draw(rect);
        window.draw(levelText);
        window.draw(levelRect);
        window.draw(levelScore);
        window.draw(linesText);
        window.draw(linesRect);
        window.draw(linesScore);
        window.draw(scoreText);
        window.draw(scoreRect);
        window.draw(scoreScore);
        for (int i = 0; i < numberfOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                window.draw(tetrisRectangles[i][j]);
            }
        }
        for (auto& shape : settledShapes) {
            window.draw(shape);
        }
        currentShape->draw(window);
        window.draw(rectNextBorder);
        window.draw(rectNext);
        window.draw(rectNextText);
        window.draw(rectShapesText);
        nextShapePrint->getBlocks()[0].setPosition(nextShape->getBlocks()[0].getPosition().x + 750, nextShape->getBlocks()[0].getPosition().y + 150);
        nextShapePrint->getBlocks()[1].setPosition(nextShape->getBlocks()[1].getPosition().x + 750, nextShape->getBlocks()[1].getPosition().y + 150);
        nextShapePrint->getBlocks()[2].setPosition(nextShape->getBlocks()[2].getPosition().x + 750, nextShape->getBlocks()[2].getPosition().y + 150);
        nextShapePrint->getBlocks()[3].setPosition(nextShape->getBlocks()[3].getPosition().x + 750, nextShape->getBlocks()[3].getPosition().y + 150);
        nextShapePrint->draw(window); // Draw the next shape in the "NEXT SHAPE" rectangle

        window.draw(pauseButton);
        window.draw(pauseButtonText);

        window.display();
    }

    delete nextShapePrint;
}


void PlayScreen::playNextSound(){
    if (!soundQueue.empty()) {
        sf::SoundBuffer* nextBuffer = soundQueue.front();
        soundQueue.pop();
        bgSound.setBuffer(*nextBuffer);
        soundQueue.push(nextBuffer);
        bgSound.setVolume(25);
        bgSound.play();
    }
}