# 模擬問題04: 4×4の簡易バトルシップ

**制限時間: 30分。** `game.h` と `test.cpp` を読み、`game.cpp` の `fire()` だけを実装する。補完機能は使わず、プレーンテキストエディタまたは補完を無効にしたエディタで入力する。まず5分で「入力・変える状態・戻り値・境界条件」を紙に整理する。

仕様:

- `board_[row][col]` は各マスの状態。`Water` は海、`Ship` は未命中の船、`Miss` と `Hit` は既に撃ったマス。
- 座標が範囲外なら `OutOfBounds`。既に撃ったマスなら `AlreadyTried`。どちらも状態を変更しない。
- `Water` を撃つと `Miss` にして `Missed` を返す。
- `Ship` を撃つと `Hit` にし、残りの船マス `remaining_` を1減らして `HitShip` を返す。
- 同じ船マスを2回撃っても `remaining_` を2回減らしてはいけない。

`game.h` と `test.cpp` は変更しない。

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g game.cpp test.cpp -o test_game
./test_game
```

提出時にコードと一緒に答えること:

1. 範囲チェックを `board_[row][col]` より前に置く理由。
2. `AlreadyTried` を先に判定する理由。
3. `remaining_` が変わる場合と変わらない場合。
