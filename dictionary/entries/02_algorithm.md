# <algorithm> — 条件判定・探索・並べ替え

原則 `#include <algorithm>`。範囲は `[begin, end)` で終端を含まない。

## A01
**指定値が存在するか**
検索語: algorithm find 含む 存在 値 探す

```cpp
bool exists = std::find(values.begin(), values.end(), target) != values.end();
```

`end()` との比較を忘れない。`std::vector`、`std::array` で同じ形。

## A02
**条件に合う最初の要素を探す**
検索語: algorithm find_if 条件 最初 探す ラムダ

```cpp
auto it = std::find_if(cells.begin(), cells.end(),
    [](const Cell& c) { return !c.assigned(); });
if (it != cells.end()) { /* *it を使う */ }
```

`Cell::assigned()` は例。実際のヘッダーのメソッド名を使う。

## A03
**全て条件を満たすか**
検索語: algorithm all_of 全件 全部 満杯 完了

```cpp
bool full = std::all_of(cells.begin(), cells.end(),
    [](const Cell& c) { return c.digit() != 0; });
```

空の範囲なら `true`。Sudokuの終了条件、盤面が満杯かの判定に有用。

## A04
**1件でも条件を満たすか**
検索語: algorithm any_of どれか 存在 一件 地雷

```cpp
bool has_mine = std::any_of(cells.begin(), cells.end(),
    [](const Cell& c) { return c.isMine(); });
```

見つかった時点で打ち切る。空の範囲なら `false`。

## A05
**どれも条件を満たさないか**
検索語: algorithm none_of ひとつもない 禁止

```cpp
bool no_conflict = std::none_of(neighbors.begin(), neighbors.end(),
    [&](const Cell* c) { return c->digit() == guess; });
```

`[&]` は外側の `guess` を参照して使う。空の範囲なら `true`。

## A06
**値または条件に合う個数を数える**
検索語: algorithm count count_if 個数 数える

```cpp
auto flags = std::count(states.begin(), states.end(), Flag);
auto hidden = std::count_if(states.begin(), states.end(),
    [](int state) { return state == -2; });
```

`Flag` は問題のenumや値に置き換える。

## A07
**比較関数で最小の要素を選ぶ**
検索語: algorithm min_element 比較候補 最適 最小

```cpp
auto it = std::min_element(cells.begin(), cells.end(),
    [](const Cell& a, const Cell& b) {
        return a.candidates().size() < b.candidates().size();
    });
if (it != cells.end()) use(*it);
```

比較関数は「aがbより前に来る」なら `true`。空の範囲を確認する。

## A08
**条件で新しいvectorへ選別する**
検索語: algorithm copy_if filter 抽出 フィルタ

```cpp
std::vector<int> legal;
std::copy_if(moves.begin(), moves.end(), std::back_inserter(legal),
    [](int m) { return m > 0; });
```

`<iterator>` も必要。短い課題では通常のforの方が読みやすいこともある。

## A09
**各要素を変換して新しいvectorへ**
検索語: algorithm transform map 変換

```cpp
std::vector<int> doubled;
std::transform(values.begin(), values.end(), std::back_inserter(doubled),
    [](int x) { return 2 * x; });
```

`<iterator>` も必要。元のvectorは変わらない。

## A10
**並べ替えの比較関数**
検索語: algorithm sort comparator 降順 比較

```cpp
std::sort(moves.begin(), moves.end(),
    [](const Move& a, const Move& b) { return a.score < b.score; });
```

同じ値のときは両方向とも `false` にする。`<=` を使うと比較規則が壊れる。

## A11
**ソート済み範囲で値を探す**
検索語: algorithm binary_search lower_bound ソート済み 二分探索

```cpp
std::sort(values.begin(), values.end());
bool found = std::binary_search(values.begin(), values.end(), target);
auto it = std::lower_bound(values.begin(), values.end(), target);
```

元の並びがソート済みであることが前提。`lower_bound` は位置を返す。

## A12
**値を範囲に収める**
検索語: algorithm clamp 範囲 制限 min max

```cpp
int limited = std::clamp(score, 0, 100);
```

C++17。`std::min(std::max(score, 0), 100)` と同じ目的。

## A13
**隣り合う同じ値を見つける**
検索語: algorithm adjacent_find 隣接 重複 連続

```cpp
auto it = std::adjacent_find(values.begin(), values.end());
if (it != values.end()) { /* *it と次が同じ */ }
```

全重複を見つけたいなら先にソート。元の順序を保ちたいならコピーをソート。

## A14
**2つの値を交換する**
検索語: algorithm swap 交換 手番 状態

```cpp
std::swap(current_player, next_player);
```

`<utility>` を明示的に含めると確実。`std::swap` は値やコンテナに使える。

## A15
**並びを逆にする**
検索語: algorithm reverse 経路 逆順 バックトラック

```cpp
std::reverse(path.begin(), path.end());
```

親を辿ってゴールからスタート順に集めた経路を反転する用途。

## A16
**条件に合う範囲を探す前に空確認**
検索語: algorithm begin end empty dereference 参照 外す

```cpp
auto it = std::min_element(values.begin(), values.end());
if (it == values.end()) return false;
use(*it);
```

`*end()` は不正。`find`、`min_element`、`max_element` の結果で共通。
