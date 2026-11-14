# 必要な標準ヘッダーを探す

コンパイラが偶然、別のヘッダー経由で名前を見つけることがある。使う機能のヘッダーを自分で明示する。

| ヘッダー | 主な機能 |
|---|---|
| `<vector>` | `std::vector` |
| `<array>` | `std::array` |
| `<algorithm>` | `find`, `find_if`, `all_of`, `any_of`, `count`, `sort`, `remove`, `min`, `max`, `clamp` |
| `<numeric>` | `accumulate`, `iota` |
| `<iterator>` | `back_inserter` |
| `<string>` | `std::string`, `stoi`, `to_string` |
| `<sstream>` | `std::istringstream` |
| `<iostream>` | `std::cin`, `std::cout` |
| `<fstream>` | `std::ifstream`, `std::ofstream` |
| `<map>` | `std::map` |
| `<set>` | `std::set` |
| `<unordered_set>` | `std::unordered_set` |
| `<utility>` | `std::pair`, `std::swap` |
| `<functional>` | `std::greater` |
| `<optional>` | `std::optional`, `std::nullopt` |
| `<queue>` | `std::queue` |
| `<limits>` | `std::numeric_limits` |
| `<cassert>` | `assert` |
| `<stdexcept>` | `std::runtime_error` |
| `<cstdlib>` | 整数の `std::abs` |
| `<cstddef>` | `std::size_t` |

この辞書はC++17を前提とする。`std::erase_if(vector, predicate)` など、C++20以降の便利関数を試験環境で使えると決めつけない。
