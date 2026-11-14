#include "game.h"

int Game::adjacentMines(int row, int col) const {
    // TODO: count mines in up to eight neighboring cells
    return 0;
}

RevealResult Game::reveal(int row, int col) {
    // TODO: check bounds and previous state before changing the cell
    return RevealResult::OutOfBounds;
}
