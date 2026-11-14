# 数値・型・よくある計算

整数の範囲、符号、0除算を確認する。盤面の添字とゲームの番号はしばしば異なる。

## N01
**小さい方・大きい方を選ぶ**
検索語: min max 最小 最大 上限 下限

```cpp
#include <algorithm>
int maxMove = std::min(sticks, 3);
int best = std::max(scoreA, scoreB);
```

2引数は基本的に同じ型にする。

## N02
**絶対値・マンハッタン距離**
検索語: abs distance 距離 Manhattan 座標

```cpp
#include <cstdlib>
int distance = std::abs(x1 - x2) + std::abs(y1 - y2);
```

上下左右に1マスずつ移動する迷路の推定距離に使える。

## N03
**偶数・奇数を判定する**
検索語: modulo % 偶数 奇数 手番

```cpp
bool even = (turn_count % 2 == 0);
int player = 1 + (turn_count % 2);
```

`turn_count` が0から始まるか1から始まるかで手番は変わる。

## N04
**プレイヤー1と2を切り替える**
検索語: player 手番 切り替え 1 2

```cpp
player = 3 - player;
```

現在値が必ず1または2の場合だけ成立する。

## N05
**整数除算と余り**
検索語: division modulo / % 行列 3x3 ブロック

```cpp
int blockRow = row / 3;
int blockCol = col / 3;
int localRow = row % 3;
```

非負の盤面添字を想定。整数除算は小数部を捨てる。

## N06
**charの数字とintの数字を変換する**
検索語: char digit int ASCII 数字 文字 変換

```cpp
int digit = symbol - '0';
char symbol2 = static_cast<char>('0' + digit);
```

`symbol` が `'0'`〜`'9'`、`digit` が0〜9の場合。入力の妥当性を先に見る。

## N07
**符号なしと符号付きの比較を避ける**
検索語: size_t int signed unsigned warning 添字

```cpp
for (std::size_t i = 0; i < values.size(); ++i) { /* ... */ }
```

`values.size()` は `std::size_t`。負の座標を扱う境界判定は `int` で先に行う。

## N08
**数値の十分小さい初期値**
検索語: numeric_limits min 最大化 AI 初期値

```cpp
#include <limits>
int bestScore = std::numeric_limits<int>::min();
```

AIで最大値を探すとき、評価が負でも最初の候補を採用できる。
