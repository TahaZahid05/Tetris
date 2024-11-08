#include <SFML/Graphics.hpp>


void showStartScreen(sf::RenderWindow& window);

int main() {
    sf::RenderWindow window(sf::VideoMode(1600,900), "Tetris Warriors");
    showStartScreen(window);  
    return 0;
}
