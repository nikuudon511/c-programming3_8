#ifndef BATTLESHIP_PRACTICE_GAME_H
#define BATTLESHIP_PRACTICE_GAME_H

#include <array>

enum class Cell { Water, Ship, Miss, Hit };
enum class ShotResult { OutOfBounds, AlreadyTried, Missed, HitShip };

class Game {
public:
    using Board = std::array<std::array<Cell, 4>, 4>;
    explicit Game(Board board);
    ShotResult fire(int row, int col);
    Cell at(int row, int col) const { return board_.at(row).at(col); }
    int remaining() const { return remaining_; }
    bool won() const { return remaining_ == 0; }

private:
    Board board_;
    int remaining_ = 0;  // number of Ship cells not yet hit
};

#endif
