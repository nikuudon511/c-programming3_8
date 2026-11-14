#ifndef MINESWEEPER_AI_SOLVER_H
#define MINESWEEPER_AI_SOLVER_H

#include <array>
#include <vector>

struct Coord {
    int row;
    int col;
    bool operator==(const Coord& other) const {
        return row == other.row && col == other.col;
    }
};

struct Deduction {
    std::vector<Coord> safe;
    std::vector<Coord> mines;
};

class Solver {
public:
    using VisibleBoard = std::array<std::array<int, 3>, 3>;
    explicit Solver(VisibleBoard visible) : visible_(visible) {}
    Deduction deduce() const;

private:
    std::vector<Coord> neighbors(Coord center) const;
    static void addUnique(std::vector<Coord>& list, Coord cell);
    VisibleBoard visible_;  // -2=unopened, -1=flagged, 0..8=revealed clue
};

#endif
