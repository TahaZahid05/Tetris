#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Game.h"
#include "EndScreen.h"
#include "PlayScreen.h"

using namespace std;

void EndScreen::loadHighScores() {
    std::ifstream highscoreFile("highscore.csv");
    std::string line;
    highScores.clear();  // Clear any existing scores

    while (std::getline(highscoreFile, line)) {
        std::stringstream ss(line);
        std::string playerName;
        int score;

        // Read player name and score from each line
        if (std::getline(ss, playerName, ',') && ss >> score) {
            highScores.push_back({playerName, score});
            if (playerName == currentPlayer) {
                personalBestScore = std::max(personalBestScore, score);  // Update personal best for current player
            }
        }
    }
    highscoreFile.close();
}

void EndScreen::displayHighScore(sf::RenderWindow& window, sf::Font& font) {
    if (highScores.empty()) return;  // No high scores available

    // Find the highest score overall
    auto highest = *std::max_element(highScores.begin(), highScores.end(),
                                      [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                                          return a.second < b.second;  // Compare by score
                                      });

    // Display highest score
    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setString("High Score: " + highest.first + " - " + std::to_string(highest.second));
    highScoreText.setPosition(200, 200);  // Adjust position as needed

    window.draw(highScoreText);
}

void EndScreen::displayCurrentScore(sf::RenderWindow& window, sf::Font& font, int score) {
    // Display current score
    sf::Text currentScoreText;
    currentScoreText.setFont(font);
    currentScoreText.setCharacterSize(30);
    currentScoreText.setFillColor(sf::Color::White);
    currentScoreText.setString("Current Score: " + std::to_string(score));
    currentScoreText.setPosition(200, 250);  // Adjust position as needed

    window.draw(currentScoreText);
}

void EndScreen::displayPersonalBest(sf::RenderWindow& window, sf::Font& font) {
    // Display personal best score
    sf::Text personalBestText;
    personalBestText.setFont(font);
    personalBestText.setCharacterSize(30);
    personalBestText.setFillColor(sf::Color::White);
    personalBestText.setString("Personal Best: " + std::to_string(personalBestScore));
    personalBestText.setPosition(400, 500);  // Adjust position as needed

    window.draw(personalBestText);
}

void EndScreen::saveHighScore(const std::string& playerName, int score) {
    std::ofstream highscoreFile("highscore.csv", std::ios::app); // Open in append mode

    if (highscoreFile.is_open()) {
        highscoreFile << playerName << "," << score << std::endl;  // Format: Name,Score
        highscoreFile.close();
    } else {
        std::cout << "Unable to open highscore file!" << std::endl;
    }
}

void EndScreen::show(sf::RenderWindow& window, const std::string& playerName, int score) {
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        return;
    }

    // Display "Game Over" text
    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200, 100);

    // Retry and Exit buttons
    sf::Text retryText("Retry", font, 30);
    retryText.setPosition(350, 300);

    sf::Text exitText("Exit", font, 30);
    exitText.setPosition(350, 400);

    // Set current player's name
    setPlayerName(playerName);

    // Load high scores from file
    loadHighScores();

    // Save the current high score
    saveHighScore(playerName, score);

    // Main loop for the end screen
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (retryText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // PlayScreen playScreen(playerName);  // Pass player name to restart the game
                    // playScreen.show(window);  // Restart the game
                    Game::getInstance().switchScreen("play");
                    return;
                }
                if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();  // Exit the game
                }
            }
        }

        window.clear();
        window.draw(gameOverText);
        window.draw(retryText);
        window.draw(exitText);

        // Display current high score
        displayHighScore(window, font);
        // Display the current score
        displayCurrentScore(window, font, score);
        // Display the personal best score
        displayPersonalBest(window, font);

        window.display();
    }
}

void EndScreen::setPlayerName(const std::string& playerName) {
    currentPlayer = playerName;
    personalBestScore = 0;  // Initialize personal best score to 0 (it will be updated during score loading)
}
