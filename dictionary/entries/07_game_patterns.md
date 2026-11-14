# ゲーム課題に当てはめる小さな型

ここは関数そのものより、状態の読み方と変更順序の例。型や戻り値は課題のヘッダーに合わせる。

## P01
**合法手を列挙する**
検索語: game AvailableMoves legal moves 候補 列挙 vector

```cpp
std::vector<int> moves;
for (int move = 1; move <= 3 && move <= sticks; ++move)
    moves.push_back(move);
return moves;
```

`0` 手を含めない。列挙順が仕様にあるならその順に追加する。

## P02
**不正手を拒否してから状態を変更する**
検索語: game MakeMove play 不正手 状態変更

```cpp
if (move < 1 || move > 3 || move > sticks) return false;
sticks -= move;
history.push_back(move);
player = 3 - player;  // 1と2のみ
return true;
```

検査前に状態を変えない。成功した操作だけ履歴に記録する。

## P03
**最後の手を巻き戻す**
検索語: game CancelMove undo 戻す 履歴 vector

```cpp
if (history.empty()) return false;
int last = history.back();
history.pop_back();
sticks += last;
player = 3 - player;
return true;
```

最後の手を読む前に `pop_back` しない。手番も元へ戻す。

## P04
**勝者を返す**
検索語: game Winner 勝敗 勝者 三目並べ

```cpp
for (const auto& line : winning_lines) {
    int p = board[line[0]];
    if (p != 0 && p == board[line[1]] && p == board[line[2]])
        return p;
}
return 0;
```

`0=勝者なし` とする仕様の例。別の値・盤面表現なら読み替える。

## P05
**終了条件と勝者を分ける**
検索語: game Over finished 終了 引き分け 勝者

```cpp
bool finished = winner() != 0 || availableMoves().empty();
```

満杯の引き分けは `winner()==0` でも終了。両者を混同しない。

## P06
**バックトラックの基本形**
検索語: game backtracking 再帰 試す 戻す Sudoku

```cpp
if (complete()) return true;
for (auto move : availableMoves()) {
    makeMove(move);
    if (solveNext()) return true;
    cancelMove(move);
}
return false;
```

成功時に状態を残す例。失敗した手だけ取り消す。再帰の終了条件を先に置く。

## P07
**AIの候補を評価して最善を選ぶ**
検索語: game AI best move 評価 score 最大

```cpp
int bestScore = std::numeric_limits<int>::min();
int bestMove = -1;
for (int move : availableMoves()) {
    makeMove(move);
    int score = evaluate();
    cancelMove(move);
    if (score > bestScore) { bestScore = score; bestMove = move; }
}
```

`<limits>` が必要。手がない場合の `bestMove` の意味を仕様に合わせる。

## P08
**minimaxの手番による最大化・最小化**
検索語: game minimax alpha beta 最大 最小 AI 対戦

```cpp
int best = maximizing ? -INF : INF;
for (int move : availableMoves()) {
    makeMove(move);
    int value = search(depth - 1, !maximizing);
    cancelMove(move);
    best = maximizing ? std::max(best, value) : std::min(best, value);
}
return best;
```

`INF` は十分大きい評価値として定義する。終了・深さ0で評価を返す処理を別途先に置く。

## P09
**マインスイーパーの周囲地雷数**
検索語: game minesweeper 地雷 8近傍 数える

```cpp
int count = 0;
for (int dr = -1; dr <= 1; ++dr)
    for (int dc = -1; dc <= 1; ++dc) {
        int nr = row + dr, nc = col + dc;
        if ((dr || dc) && inside(nr, nc) && mine[nr][nc]) ++count;
    }
return count;
```

`inside` を左に置き、範囲外の配列アクセスを防ぐ。

## P10
**数字から安全・地雷を確定する**
検索語: game minesweeper AI clue flag hidden 推論 安全

```cpp
if (clue == flagged)
    for (Coord p : hidden) addUnique(safe, p);
if (clue == flagged + static_cast<int>(hidden.size()))
    for (Coord p : hidden) addUnique(mines, p);
```

`hidden` はその数字マスの周囲の未開封マス。実際の地雷配置は読まない。

## P11
**複数の制約で禁止された候補を戻す**
検索語: game Sudoku prune restore 候補 禁止 回数

```cpp
// 禁止時: 初回だけ候補から消し、禁止回数は毎回増やす。
if (blocked[digit]++ == 0) eraseCandidate(digit);
// 解除時: 回数が0へ戻った場合だけ候補へ追加する。
if (blocked[digit] > 0 && --blocked[digit] == 0)
    candidates.push_back(digit);
```

未確定セル・有効な数字かを先に確認する。`eraseCandidate` の戻り値が必要な仕様ならそれも確認。

## P12
**マスの状態を先に検査する**
検索語: game state 盤面 開封 重複 範囲外 return

```cpp
if (!inside(row, col)) return OutOfBounds;
if (revealed[row][col]) return AlreadyOpen;
revealed[row][col] = true;
```

早い `return` で不正入力の変更を防ぐ。配列の読む順序にも注意。

## P13
**幅優先で連鎖的にマスを開く**
検索語: game flood fill 連鎖 開封 queue BFS

```cpp
std::queue<Coord> pending;
pending.push(start);
while (!pending.empty()) {
    Coord p = pending.front(); pending.pop();
    if (!inside(p.row, p.col) || revealed[p.row][p.col]) continue;
    revealed[p.row][p.col] = true;
    if (adjacentMines(p.row, p.col) == 0)
        for (Coord n : neighbors(p)) pending.push(n);
}
```

`<queue>`。地雷の扱い、旗付きマス、終了条件は課題に合わせて追加する。

## P14
**変更前後の不変条件を確認する**
検索語: game invariant 不変条件 状態 整合性 デバッグ

```cpp
int before = remaining;
makeMove(move);
cancelMove(move);
assert(remaining == before);
```

`<cassert>`。`makeMove` と `cancelMove` が対になっているかの簡単な検査。
