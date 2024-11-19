#include "Game.h"

Game::Game()
    : window(sf::VideoMode(1600,900), "Tetris Game"){
        window.setPosition(sf::Vector2i(0, 0));
        initialScreen.show(window);
}

// void Game::nextScreen(string screen){
//     if(screen == "play"){
//         playScreen.show(window);
//     }
//     else if(screen == "end"){
//         endScreen.show(window);
//     }
//     else if(screen == "howToPlay"){
//         howToPlayScreen.show(window);
//     }
// }