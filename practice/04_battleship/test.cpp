#include "game.h"
#include <cassert>
#include <iostream>

int main() {
    Game game({{{Cell::Ship, Cell::Water, Cell::Water, Cell::Water},
                {Cell::Water, Cell::Ship, Cell::Water, Cell::Water},
                {Cell::Water, Cell::Water, Cell::Water, Cell::Water},
                {Cell::Water, Cell::Water, Cell::Water, Cell::Water}}});
    assert(game.remaining() == 2 && !game.won());
    assert(game.fire(-1, 0) == ShotResult::OutOfBounds);
    assert(game.fire(0, 4) == ShotResult::OutOfBounds);
    assert(game.remaining() == 2);
    assert(game.fire(0, 1) == ShotResult::Missed);
    assert(game.at(0, 1) == Cell::Miss);
    assert(game.fire(0, 1) == ShotResult::AlreadyTried);
    assert(game.fire(0, 0) == ShotResult::HitShip);
    assert(game.remaining() == 1 && game.at(0, 0) == Cell::Hit);
    assert(game.fire(0, 0) == ShotResult::AlreadyTried);
    assert(game.remaining() == 1);
    assert(game.fire(1, 1) == ShotResult::HitShip);
    assert(game.remaining() == 0 && game.won());
    std::cout << "All practice checks passed\n";
}
