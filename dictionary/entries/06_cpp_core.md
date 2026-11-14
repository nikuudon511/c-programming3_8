# クラス・関数・参照・型

ヘッダーの宣言と実装の定義は、戻り値・引数・`const`・名前空間を一致させる。

## C01
**ヘッダー宣言に対応するメソッドを定義する**
検索語: class メソッド 定義 :: header cpp const

```cpp
// game.h: int winner() const;
int Game::winner() const {
    return 0;
}
```

`Game::` と末尾の `const` を忘れると別の関数扱い、または定義不一致になる。

## C02
**コンストラクタでメンバーを初期化する**
検索語: constructor 初期化リスト メンバー コンストラクタ

```cpp
Game::Game(int start) : sticks_(start), player_(1) {}
```

初期化の実際の順序はヘッダー内のメンバー宣言順。初期化リストの記載順ではない。

## C03
**読み取り専用メソッドのconst**
検索語: const member method 読み取り専用 メソッド

```cpp
int Game::remaining() const { return remaining_; }
```

`const` メソッドでは通常、メンバー変数を変更できない。`const Game&` から呼べる。

## C04
**値・参照・const参照を使い分ける**
検索語: 引数 value reference const& コピー 変更

```cpp
void setScore(int value);                  // 小さい値をコピー
void update(Game& game);                   // 呼び出し元を変更
int evaluate(const Game& game);           // 読むだけ、コピーなし
```

`Game game` は全体をコピーする。複雑な盤面では意図しているか確認する。

## C05
**ポインタのメンバーにアクセスする**
検索語: pointer -> * ポインタ セル 隣接

```cpp
Cell* neighbor = /* 有効なセルへのポインタ */;
if (neighbor != nullptr) neighbor->prune(guess);
```

`neighbor->prune(x)` は `(*neighbor).prune(x)` と同じ。無効なポインタを使わない。

## C06
**参照で要素を変更する**
検索語: reference auto& for 参照 vector 変更

```cpp
for (Cell& cell : cells) cell.reset();
```

`for (Cell cell : cells)` ではコピーが変更されるだけ。変更禁止の要素には `const Cell&`。

## C07
**enum classを比較し返す**
検索語: enum class 列挙型 戻り値 状態

```cpp
if (board[row][col] == Cell::Ship) return ShotResult::HitShip;
```

`Cell::Ship` のように型名を付ける。整数に暗黙変換されない。

## C08
**structで座標をまとめる**
検索語: struct Point Coord 座標 初期化 比較

```cpp
struct Coord { int row; int col; };
Coord next{row + 1, col};
```

`std::find` などで比較したいなら `operator==` を定義する（C++17では自動生成されない）。

## C09
**ラムダで外側の値を使う**
検索語: lambda capture [&] [=] ラムダ キャプチャ

```cpp
bool found = std::any_of(cells.begin(), cells.end(),
    [guess](const Cell& c) { return c.digit() == guess; });
```

`[guess]` は値をコピー。`[&]` は使用する外側の変数を参照で捕まえる。

## C10
**ヘッダーの多重読み込みを防ぐ**
検索語: include guard header #ifndef #define ヘッダー

```cpp
#ifndef GAME_H
#define GAME_H
// 宣言
#endif
```

同じヘッダーが複数経路で読み込まれてもクラスの再定義を防ぐ。

## C11
**optionalで「値なし」を表す**
検索語: optional nullopt 値なし find 戻り値

```cpp
#include <optional>
std::optional<int> result = std::nullopt;
if (result) use(*result);
```

C++17。`0` も有効な値なら、`-1` より明確に「見つからない」を表せる。

## C12
**例外を投げる・受ける**
検索語: exception throw runtime_error try catch エラー

```cpp
#include <stdexcept>
if (invalid) throw std::runtime_error("invalid move");
```

課題の仕様が「不正手ならfalse」を要求するなら、例外ではなくfalseを返す。
