#ifndef CODE_LOCK_CELL_H
#define CODE_LOCK_CELL_H

#include <algorithm>
#include <array>
#include <vector>

class Cell {
public:
    explicit Cell(int fixed = 0) : fixed_(fixed) {
        if (fixed_ != 0) options_.clear();
    }

    bool hasOption(int digit) const {
        return std::find(options_.begin(), options_.end(), digit) != options_.end();
    }
    int blockCount(int digit) const { return blocked_count_.at(digit); }
    std::vector<int> options() const { return options_; }

    void block(int digit);
    void unblock(int digit);

private:
    int fixed_ = 0;                          // 0 = not fixed
    std::vector<int> options_{1, 2, 3, 4};  // possible digits
    std::array<int, 5> blocked_count_{};    // index 0 unused
};

#endif
