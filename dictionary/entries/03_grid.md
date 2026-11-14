# 盤面・座標・隣接マス

行列の順序は課題によって異なる。ヘッダーと呼び出し側の添字を先に確認する。

## G01
**固定サイズの2次元盤面を作る**
検索語: array 盤面 二次元 固定長 初期化

```cpp
#include <array>
std::array<std::array<int, 4>, 4> board{};  // 全て0
board[1][2] = 7;  // row=1, col=2
```

`std::array` はサイズがコンパイル時に決まる。`board.at(row).at(col)` は範囲を検査する。

## G02
**全マスを走査する**
検索語: grid 全マス 走査 row col 二重ループ

```cpp
for (int row = 0; row < rows; ++row)
    for (int col = 0; col < cols; ++col)
        inspect(board[row][col]);
```

`rows`, `cols` は盤面の実寸に合わせる。`<` と `<=` の違いに注意。

## G03
**盤面内か判定する**
検索語: grid bounds 境界 範囲外 row col 添字

```cpp
bool inside = row >= 0 && row < rows && col >= 0 && col < cols;
if (!inside) return false;
auto cell = board[row][col];
```

配列を読む**前**に判定する。4×4なら有効な添字は0〜3。

## G04
**上下左右の4近傍を列挙する**
検索語: grid neighbors 4方向 上下左右 隣接

```cpp
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
for (int i = 0; i < 4; ++i) {
    int nr = row + dr[i], nc = col + dc[i];
    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
        use(nr, nc);
}
```

迷路の移動に使う。`use` を結果への追加などに置き換える。

## G05
**斜めを含む8近傍を列挙する**
検索語: grid neighbors 8方向 斜め マインスイーパー 隣接

```cpp
for (int dr = -1; dr <= 1; ++dr)
    for (int dc = -1; dc <= 1; ++dc) {
        if (dr == 0 && dc == 0) continue;
        int nr = row + dr, nc = col + dc;
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            use(nr, nc);
    }
```

中央自身を除く。四隅では有効な隣接マスは3個。

## G06
**1次元配列と行列座標を変換する**
検索語: grid flat index row col 1次元 変換

```cpp
int index = row * cols + col;
int row2 = index / cols;
int col2 = index % cols;
```

9×9 Sudokuなら `index = 9*row + col`。列数を掛ける。

## G07
**x,yとrow,colを読み替える**
検索語: grid x y row col 座標 画像 迷路

```cpp
int row = y;
int col = x;
auto value = board[row][col];
```

画像や迷路では `(x,y)`、2次元配列では `[row][col]` がよく使われる。元コードで確認する。

## G08
**勝ち筋の3マスが同じか**
検索語: grid winner 勝利 三目並べ 同じ 空き 0

```cpp
int player = board[line[0]];
if (player != 0 &&
    player == board[line[1]] &&
    player == board[line[2]]) return player;
```

`player != 0` がないと空き3マスを勝利と誤判定する。

## G09
**方向に沿って連続マスを調べる**
検索語: grid 連続 4目並べ 五目並べ 方向 勝敗

```cpp
int count = 0;
for (int k = 0; k < needed; ++k) {
    int r = row + k * dr, c = col + k * dc;
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != player)
        break;
    ++count;
}
if (count == needed) return player;
```

横・縦・斜めの方向 `(dr,dc)` を変えて使う。範囲判定を左に置く。

## G10
**盤面をコピーして仮の手を試す**
検索語: grid copy simulation 仮の手 AI シミュレーション

```cpp
auto next = board;
next[row][col] = player;
int score = evaluate(next);
```

元盤面は変わらない。大きい盤面や深い探索ではコピーのコストに注意。

## G11
**幅優先探索の基本形**
検索語: grid BFS queue 迷路 最短経路 探索

```cpp
#include <queue>
std::queue<Coord> pending;
pending.push(start);
visited[start.row][start.col] = true;
while (!pending.empty()) {
    Coord current = pending.front(); pending.pop();
    for (Coord next : neighbors(current)) {
        if (visited[next.row][next.col]) continue;
        visited[next.row][next.col] = true;
        pending.push(next);
    }
}
```

`neighbors` は有効な隣接マスのみ返す想定。`visited` は入れる時に真にし、重複登録を防ぐ。

## G12
**マスを開くときの分岐順**
検索語: grid reveal マインスイーパー 開封 状態更新 範囲外

```cpp
if (!inside(row, col)) return OutOfBounds;
if (revealed[row][col]) return AlreadyOpen;
revealed[row][col] = true;
if (mines[row][col]) { lost = true; return Exploded; }
return Safe;
```

範囲外と再開封では状態を変えない。戻り値名は問題のenumに合わせる。
