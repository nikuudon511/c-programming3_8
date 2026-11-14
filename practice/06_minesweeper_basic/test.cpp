#include "game.h"
#include <cassert>
#include <iostream>

int main() {
    Game game({{{'.', '*', '.', '.'},
                {'.', '.', '*', '.'},
                {'.', '.', '.', '.'},
                {'*', '.', '.', '.'}}});

    assert(game.adjacentMines(0, 0) == 1);
    assert(game.adjacentMines(1, 1) == 2);
    assert(game.adjacentMines(3, 3) == 0);
    assert(game.adjacentMines(-1, 0) == 0);
    assert(game.adjacentMines(0, 4) == 0);

    assert(game.reveal(-1, 0) == RevealResult::OutOfBounds);
    assert(game.reveal(4, 0) == RevealResult::OutOfBounds);
    assert(!game.lost());
    assert(game.reveal(0, 0) == RevealResult::Safe);
    assert(game.isRevealed(0, 0));
    assert(game.reveal(0, 0) == RevealResult::AlreadyOpen);
    assert(game.reveal(0, 1) == RevealResult::Exploded);
    assert(game.isRevealed(0, 1) && game.lost());
    assert(game.reveal(0, 1) == RevealResult::AlreadyOpen);

    std::cout << "All basic minesweeper checks passed\n";
}
