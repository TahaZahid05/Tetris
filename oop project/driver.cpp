#include "Game.h"

int main() {
    Game& game = Game::getInstance();
    // Game& game1 = Game::getInstance();
    game.run();
    return 0;
}