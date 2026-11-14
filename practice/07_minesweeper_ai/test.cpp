#include "solver.h"
#include <cassert>
#include <iostream>
#include <vector>

bool has(const std::vector<Coord>& cells, Coord target) {
    for (Coord cell : cells) if (cell == target) return true;
    return false;
}

int main() {
    Solver safe({{{1, -1, -2},
                  {-2, -2, -2},
                  {-2, -2, -2}}});
    auto a = safe.deduce();
    assert(a.safe.size() == 2 && has(a.safe, {1, 0}) && has(a.safe, {1, 1}));
    assert(a.mines.empty());

    Solver mine({{{1, 1, -2},
                  {1, -2, -2},
                  {-2, -2, -2}}});
    auto b = mine.deduce();
    assert(has(b.mines, {1, 1}));
    assert(!has(b.safe, {1, 1}));

    Solver dedupe({{{0, 0, -2},
                    {-2, -2, -2},
                    {-2, -2, -2}}});
    auto c = dedupe.deduce();
    assert(c.safe.size() == 4);
    assert(has(c.safe, {1, 1}) && has(c.safe, {0, 2}));
    assert(c.mines.empty());

    Solver unknown({{{-2, -2, -2},
                     {-2, 1, -2},
                     {-2, -2, -2}}});
    auto d = unknown.deduce();
    assert(d.safe.empty() && d.mines.empty());

    std::cout << "All AI minesweeper checks passed\n";
}
