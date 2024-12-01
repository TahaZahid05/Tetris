#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>  // For std::string
#include <vector>  // For storing high scores

class EndScreen {
private:
    std::vector<std::pair<std::string, int>> highScores;  // Store player name and score pairs
    std::string currentPlayer;  // Store the current player's name
    int personalBestScore;  // Store the player's personal best score

    void loadHighScores();  // Function to load high scores from the file
    void displayHighScore(sf::RenderWindow& window, sf::Font& font);  // Function to display high score
    void displayCurrentScore(sf::RenderWindow& window, sf::Font& font, int score);  // Display current score
    void displayPersonalBest(sf::RenderWindow& window, sf::Font& font);  // Display personal best score

public:
    void saveHighScore(const std::string& playerName, int score);  // Save the high score to the file
    void show(sf::RenderWindow& window, const std::string& playerName, int score);  // Show end screen
    void setPlayerName(const std::string& playerName);  // Set the current player's name
};

#endif
