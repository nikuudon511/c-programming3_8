#include "solver.h"
#include <algorithm>

std::vector<Coord> Solver::neighbors(Coord center) const {
    std::vector<Coord> result;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int row = center.row + dr;
            int col = center.col + dc;
            if ((dr != 0 || dc != 0) && row >= 0 && row < 3 && col >= 0 && col < 3)
                result.push_back({row, col});
        }
    }
    return result;
}

void Solver::addUnique(std::vector<Coord>& list, Coord cell) {
    if (std::find(list.begin(), list.end(), cell) == list.end())
        list.push_back(cell);
}

Deduction Solver::deduce() const {
    // TODO: inspect every revealed clue and apply the two rules in README
    return {};
}
