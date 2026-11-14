#ifndef MINESWEEPER_BASIC_GAME_H
#define MINESWEEPER_BASIC_GAME_H

#include <array>

enum class RevealResult { OutOfBounds, AlreadyOpen, Safe, Exploded };

class Game {
public:
    using MineMap = std::array<std::array<char, 4>, 4>;
    explicit Game(MineMap mines) : mines_(mines) {}

    int adjacentMines(int row, int col) const;
    RevealResult reveal(int row, int col);
    bool isRevealed(int row, int col) const { return revealed_.at(row).at(col); }
    bool lost() const { return lost_; }

private:
    MineMap mines_;  // '*' = mine, '.' = safe
    std::array<std::array<bool, 4>, 4> revealed_{};
    bool lost_ = false;
};

#endif
