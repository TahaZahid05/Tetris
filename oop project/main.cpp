#include <SFML/Graphics.hpp>
#include "InitialScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Tetris Warriors");
    window.setPosition(sf::Vector2i(0, 0));

    InitialScreen startScreen;
    startScreen.show(window);

    return 0;
}
