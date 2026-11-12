#include "cell.h"
#include <cassert>
#include <iostream>

int main() {
    Cell cell;
    assert(cell.options().size() == 4);
    cell.block(2);
    assert(!cell.hasOption(2) && cell.blockCount(2) == 1);
    cell.block(2);
    assert(!cell.hasOption(2) && cell.blockCount(2) == 2);
    cell.unblock(2);
    assert(!cell.hasOption(2) && cell.blockCount(2) == 1);
    cell.unblock(2);
    assert(cell.hasOption(2) && cell.blockCount(2) == 0);
    cell.unblock(2);
    assert(cell.blockCount(2) == 0 && cell.options().size() == 4);

    cell.block(0);
    cell.block(5);
    cell.unblock(-1);
    assert(cell.options().size() == 4);

    Cell fixed(3);
    fixed.block(2);
    fixed.unblock(2);
    assert(fixed.options().empty() && fixed.blockCount(2) == 0);

    std::cout << "All practice checks passed\n";
}
