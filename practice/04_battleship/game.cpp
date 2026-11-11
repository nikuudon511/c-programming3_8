#include "game.h"

Game::Game(Board board) : board_(board) {
    for (const auto& row : board_) {
        for (Cell cell : row) {
            if (cell == Cell::Ship) ++remaining_;
        }
    }
}

ShotResult Game::fire(int row, int col) {
    // TODO: implement according to README; change no state for invalid/repeated shots
    return ShotResult::OutOfBounds;
}
