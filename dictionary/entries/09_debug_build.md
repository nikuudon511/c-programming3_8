# ビルド・テスト・デバッグ

試験PCのコンパイラと課題の `CMakeLists.txt` を優先する。以下は一般的なLinux/Qt Creatorでの形。

## D01
**1個のC++課題を直接コンパイルする**
検索語: g++ compile コンパイル C++17 ビルド

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g game.cpp test.cpp -o test_game
./test_game
```

`-g` はデバッグ情報。必要な `.cpp` を全て指定する。

## D02
**CMake課題をビルドする**
検索語: cmake build CMakeLists Qt Creator ビルド

```bash
cmake -S . -B build
cmake --build build --target practice06
```

`CMakeLists.txt` のあるディレクトリで実行する。ターゲット名はそのファイルで確認。

## D03
**CTestで指定の問題だけ試す**
検索語: ctest test assert テスト 失敗

```bash
ctest --test-dir build --output-on-failure -R '^practice06$'
```

未実装の別問題のテストを避ける。`-R` はテスト名の正規表現。

## D04
**最初のコンパイルエラーを読む**
検索語: compile error not declared matching function コンパイルエラー

```text
file.cpp:23:10: error: 'name' was not declared in this scope
```

最初のエラーから見る。名前・スコープ・`#include`・宣言と定義の一致を確認する。

## D05
**リンクエラーを読む**
検索語: linker undefined reference リンク 定義 ない

```text
undefined reference to `Game::winner() const'
```

宣言はあるが定義が無い、または該当 `.cpp` をビルドに入れていない可能性。`const` も照合する。

## D06
**assert失敗とSIGABRTを読む**
検索語: assert SIGABRT abort テスト 止まる

```cpp
assert(game.fire(0, 1) == ShotResult::Missed);
```

条件が偽なら `assert` が停止させる。`SIGABRT` はその結果であり、必ずしもメモリ破壊ではない。行番号と期待値を読む。

## D07
**Qt Creatorでブレークポイントを使う**
検索語: Qt Creator breakpoint F9 F5 F10 Locals デバッグ

```text
F9: 行のブレークポイントを切替
F5: デバッグ開始・続行
F10: 一行進める（関数へ入らない）
```

Localsで引数・メンバーの値を見る。ショートカットはVMのQt Creator設定やウィンドウマネージャで違う場合がある。

## D08
**gdbで停止箇所を調べる**
検索語: gdb backtrace bt run crash デバッグ

```bash
gdb ./test_game
```

gdb内で `run`、停止後 `bt`、`frame 0`、`print row`。`-g` 付きでビルドする。

## D09
**境界外アクセスを検出する**
検索語: sanitizer ASan undefined 範囲外 メモリ

```bash
g++ -std=c++17 -g -fsanitize=address,undefined game.cpp test.cpp -o test_game
./test_game
```

試験PCに対応ランタイムがあれば使える。`std::array::operator[]` は範囲検査しないので有用。

## D10
**変更したファイルだけ確認する**
検索語: git diff status 提出 変更ファイル

```bash
git status --short
git diff -- game.cpp
```

意図せずヘッダーやテストを変えていないか確認する。ビルド生成物は提出対象にしない。

## D11
**古い実行ファイルを疑う**
検索語: stale binary 古い 実行ファイル ビルド 更新されない

```bash
cmake --build build --target practice06
ctest --test-dir build --output-on-failure -R '^practice06$'
```

ソースを保存してからビルドする。Qt Creatorの実行ターゲットとビルドディレクトリが一致しているか確認。
