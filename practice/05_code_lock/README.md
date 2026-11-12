# 模擬問題05: 数字ロックの候補を消して戻す

**制限時間: 30分。補完なし。** `cell.h` と `test.cpp` を先に読み、`cell.cpp` の `block()` と `unblock()` だけを実装する。最初の5分は、`options_` と `blocked_count_` がそれぞれ何を表すか説明できるようにする。

1〜4の数字を候補とするセルを考える。別の制約から同じ数字が複数回禁止されることがある。

- `block(digit)`: 未確定のセルなら、その数字を候補から消し、禁止回数を1増やす。既に禁止中なら候補には無くても回数を増やす。
- `unblock(digit)`: 禁止回数が正なら1減らす。0に戻った時だけ候補へ復活させる。
- 確定済みセル、1〜4以外の数字、禁止されていない数字への `unblock` は状態を変えない。
- `options_` の並び順は問わない。重複は作らない。

```bash
cmake -S . -B build
cmake --build build --target practice05
ctest --test-dir build --output-on-failure -R '^practice05$'
```

提出時に「なぜ `unblock` 1回だけで候補を戻してはいけない場合があるのか」を説明する。
