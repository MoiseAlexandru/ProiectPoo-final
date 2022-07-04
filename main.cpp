#include "Game.h"

int main() {
    srand(time(NULL));
    auto& game = Game::get_game();
    game.play();
    return 0;
}
