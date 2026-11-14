# 文字列・入出力

試験の入力形式と出力形式は課題文を優先する。改行や空白も結果に影響する。

## S01
**文字列を作り、長さを得る**
検索語: string 文字列 長さ size empty

```cpp
#include <string>
std::string name = "maze";
if (!name.empty()) { auto n = name.size(); }
```

`size()` は文字数ではなくバイト数。英数字の盤面記号には通常これでよい。

## S02
**文字を1個読む・変更する**
検索語: string 添字 char 文字 変更

```cpp
char c = line.at(2);
line[2] = '#';
```

`at` は範囲外で例外、`[]` は範囲検査しない。`'#'` はchar、`"#"` は文字列。

## S03
**部分文字列を取る**
検索語: string substr 切り出し 部分

```cpp
std::string part = text.substr(start, length);
```

第2引数は終点ではなく文字数。省略すると末尾まで。

## S04
**文字列内を探す**
検索語: string find 検索 npos 含む

```cpp
auto pos = text.find("TODO");
if (pos != std::string::npos) { /* 見つかった */ }
```

`npos` は見つからない印。`pos >= 0` では判定できない。

## S05
**文字列を連結する**
検索語: string append + 連結 追加

```cpp
std::string message = "Player " + std::to_string(player) + " wins";
```

`std::to_string` は `<string>`。最初が `const char*` でも右が `std::string` ならこの形は使える。

## S06
**整数に変換する**
検索語: string stoi to_string 数値 変換

```cpp
int value = std::stoi(text);
std::string shown = std::to_string(value);
```

`stoi` は変換できない入力で例外。ユーザー入力なら妥当性を確認する。

## S07
**空白区切りの値を読む**
検索語: cin 入力 整数 空白

```cpp
#include <iostream>
int row, col;
if (!(std::cin >> row >> col)) return 1;
```

`>>` は空白を飛ばす。読み取り失敗後に未設定の値を使わない。

## S08
**1行を丸ごと読む**
検索語: getline 行 入力 空白 スペース

```cpp
std::string line;
if (std::getline(std::cin, line)) { /* line を使う */ }
```

直前に `std::cin >> value` を使うと残りの改行を読むことがある。必要なら `std::getline(std::cin >> std::ws, line)`。

## S09
**結果を表示する**
検索語: cout 出力 改行 print

```cpp
std::cout << "row=" << row << " col=" << col << '\n';
```

`'\n'` は改行。`std::endl` は改行に加えフラッシュする。

## S10
**ファイルを1行ずつ読む**
検索語: ifstream ファイル 読む 行 オフライン

```cpp
#include <fstream>
std::ifstream input("board.txt");
std::string line;
while (std::getline(input, line)) { /* 処理 */ }
```

相対パスは実行時の作業ディレクトリ基準。ファイルが開けたか `if (!input)` で確認する。

## S11
**文字列を整数ごとに分割する**
検索語: istringstream parse 分割 空白 数列

```cpp
#include <sstream>
std::istringstream in(line);
int value;
while (in >> value) numbers.push_back(value);
```

入力行に複数の整数がある場合。区切りがカンマなら別処理が必要。

## S12
**盤面を行として表示する**
検索語: 盤面 表示 rows cols cout 二重ループ

```cpp
for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col)
        std::cout << board[row][col] << ' ';
    std::cout << '\n';
}
```

デバッグ表示なら行と列の番号も付けると添字違いを見つけやすい。
