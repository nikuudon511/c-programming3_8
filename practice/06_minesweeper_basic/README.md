# 模擬問題06: マインスイーパー基本編

**目安: 30分。補完なし。** `game.h` → `test.cpp` の順に読み、`game.cpp` の2つのTODOだけを実装する。最初に、`mines_[row][col]` と `revealed_[row][col]` の違いを説明できるようにする。

盤面は4×4。`'*'` は地雷、`'.'` は安全なマス。座標は0〜3。

- `adjacentMines(row,col)` は周囲8マスの地雷数を返す。自身は数えず、盤面の外にはアクセスしない。引数が盤面外なら0を返す。
- `reveal(row,col)` は盤面外なら `OutOfBounds`、既に開いたマスなら `AlreadyOpen` を返し、状態を変えない。
- 初めて開く地雷ならそのマスを開き、`lost_` を真にして `Exploded` を返す。
- 初めて開く安全なマスならそのマスを開いて `Safe` を返す。周囲の空きマスを自動展開する必要はない。

```bash
cmake -S . -B build
cmake --build build --target practice06
ctest --test-dir build --output-on-failure -R '^practice06$'
```

提出時には、四隅で8方向を調べても範囲外アクセスしない方法を説明する。
