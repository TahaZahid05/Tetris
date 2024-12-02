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
    highScores.clear(); // Clear any existing scores

    while (std::getline(highscoreFile, line)) {
        std::stringstream ss(line);
        std::string playerName;
        int score;

        // Read player name and score from each line
        if (std::getline(ss, playerName, ',') && ss >> score) {
            highScores.push_back({playerName, score});
            if (playerName == currentPlayer) {
                personalBestScore = std::max(personalBestScore, score); // Update personal best for current player
            }
        }
    }
    highscoreFile.close();
}

void EndScreen::displayHighScore(sf::RenderWindow& window, sf::Font& font) {
    if (highScores.empty()) return; // No high scores available

    // Find the highest score overall
    auto highest = *std::max_element(highScores.begin(), highScores.end(),
                                      [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                                          return a.second < b.second; // Compare by score
                                      });

    // Display highest score
    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setString("High Score: " + highest.first + " - " + std::to_string(highest.second));
    highScoreText.setPosition(300, 150); // Adjust position as needed

    window.draw(highScoreText);
}

void EndScreen::displayCurrentScore(sf::RenderWindow& window, sf::Font& font, int score) {
    // Display current score
    sf::Text currentScoreText;
    currentScoreText.setFont(font);
    currentScoreText.setCharacterSize(30);
    currentScoreText.setFillColor(sf::Color::Cyan);
    currentScoreText.setString("Current Score: " + std::to_string(score));
    currentScoreText.setPosition(300, 200); // Adjust position as needed

    window.draw(currentScoreText);
}

void EndScreen::displayPersonalBest(sf::RenderWindow& window, sf::Font& font) {
    // Display personal best score
    sf::Text personalBestText;
    personalBestText.setFont(font);
    personalBestText.setCharacterSize(30);
    personalBestText.setFillColor(sf::Color::Green);
    personalBestText.setString("Personal Best: " + std::to_string(personalBestScore));
    personalBestText.setPosition(300, 250); // Adjust position as needed

    window.draw(personalBestText);
}

void EndScreen::saveHighScore(const std::string& playerName, int score) {
    static bool scoreSaved = false; // Ensure scores are saved only once per session
    if (scoreSaved) {
        return;
    }
    scoreSaved = true;

    std::vector<std::pair<std::string, int>> highScores;
    std::ifstream infile("highscore.csv");
    std::string line;

    // Read existing high scores
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string name;
        int existingScore;
        if (std::getline(ss, name, ',') && ss >> existingScore) {
            highScores.push_back({name, existingScore});
        }
    }
    infile.close();

    // Add the new score
    highScores.push_back({playerName, score});

    // Sort scores in descending order
    std::sort(highScores.begin(), highScores.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    // Write back the updated scores
    std::ofstream outfile("highscore.csv", std::ios::trunc);
    for (const auto& entry : highScores) {
        outfile << entry.first << "," << entry.second << "\n";
    }
    outfile.close();
}

void EndScreen::show(sf::RenderWindow& window, const std::string& playerName, int score) {
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF")) {
        return;
    }

    // Display "Game Over" text
    sf::Text gameOverText("Game Over", font, 60);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(300, 50);

    // Retry button
    sf::RectangleShape retryButton(sf::Vector2f(200, 50));
    retryButton.setPosition(300, 350);
    retryButton.setFillColor(sf::Color::Blue);

    sf::Text retryText("Retry", font, 30);
    retryText.setFillColor(sf::Color::White);
    retryText.setPosition(350, 355);

    // Exit button
    sf::RectangleShape exitButton(sf::Vector2f(200, 50));
    exitButton.setPosition(300, 450);
    exitButton.setFillColor(sf::Color::Blue);

    sf::Text exitText("Exit", font, 30);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(360, 455);

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

                if (retryButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    Game::getInstance().switchScreen("play");
                    return;
                }

                if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close(); // Exit the game
                }
            }
        }

        window.clear();

        // Draw game over text
        window.draw(gameOverText);

        // Draw retry button
        window.draw(retryButton);
        window.draw(retryText);

        // Draw exit button
        window.draw(exitButton);
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
    personalBestScore = 0; // Initialize personal best score to 0 (it will be updated during score loading)
}
