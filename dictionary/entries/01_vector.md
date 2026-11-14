# std::vector — 可変長配列

`#include <vector>`。要素数は実行中に変えられる。添字は0始まり。各例は必要な変数だけを示す。

## V01
**vectorを作る・初期化する**
検索語: vector 宣言 初期化 作成 constructor

```cpp
std::vector<int> empty;
std::vector<int> fiveZeros(5, 0);
std::vector<int> digits{1, 2, 3};
```

`(5, 0)` は「5個の0」、`{5, 0}` は「5と0の2個」。混同しない。

## V02
**要素数と空判定**
検索語: vector size empty 長さ 空か 個数

```cpp
if (values.empty()) return false;
for (std::size_t i = 0; i < values.size(); ++i) { /* ... */ }
```

`size()` の型は符号なし。`int` と比較すると警告が出る場合がある。

## V03
**添字で読む・書く**
検索語: vector [] at 添字 アクセス 読む 書く 範囲外

```cpp
int first = values[0];
values[1] = 7;
int checked = values.at(2);
```

`[]` は範囲外を検査しない。`at()` は範囲外なら例外。どちらも添字は0から `size()-1`。

## V04
**末尾に追加する**
検索語: vector push_back 追加 append 末尾 候補

```cpp
std::vector<int> moves;
for (int move = 1; move <= 3; ++move)
    if (legal(move)) moves.push_back(move);
```

ゲームの合法手や隣接点を集めるときの基本形。`legal` は問題側の判定に置き換える。

## V05
**末尾に直接構築する**
検索語: vector emplace_back 追加 構築 Point 座標

```cpp
std::vector<Point> neighbors;
neighbors.emplace_back(x, y);  // Point(int x, int y) がある場合
```

`push_back(Point{x,y})` でもよい。コンストラクタの引数と型をヘッダーで確認。

## V06
**最後を取り除く**
検索語: vector pop_back 削除 最後 undo 履歴

```cpp
if (!history.empty()) {
    int last = history.back();
    history.pop_back();
}
```

`pop_back()` は値を返さない。空のvectorに使わない。

## V07
**先頭・末尾を読む**
検索語: vector front back 先頭 末尾

```cpp
if (!values.empty()) {
    int first = values.front();
    int last = values.back();
}
```

空のときの `front()` / `back()` は使えない。

## V08
**全要素を読む（範囲for）**
検索語: vector range for 全件 走査 const 参照

```cpp
for (const auto& cell : cells) {
    inspect(cell);
}
```

大きな要素をコピーしない。`inspect` は読む処理に置き換える。

## V09
**全要素を変更する（参照）**
検索語: vector range for 変更 auto& 参照 コピー

```cpp
for (auto& cell : cells) {
    cell.reset();
}
```

`auto cell` はコピーなので元の要素は変わらない。

## V10
**添字も必要なときのfor**
検索語: vector index 添字 for 座標 位置

```cpp
for (std::size_t i = 0; i < values.size(); ++i) {
    if (values[i] == target) return static_cast<int>(i);
}
return -1;
```

「見つからない」を何で表すかは関数契約を優先する。

## V11
**値を1個探す**
検索語: vector std::find find 検索 含む 存在 iterator

```cpp
#include <algorithm>
auto it = std::find(values.begin(), values.end(), target);
if (it != values.end()) { /* 見つかった */ }
```

`end()` は最後の要素ではなく、最後の次を表す。

## V12
**条件に合う要素を探す**
検索語: vector find_if 条件 検索 lambda

```cpp
#include <algorithm>
auto it = std::find_if(cells.begin(), cells.end(),
    [](const Cell& c) { return c.digit() == 0; });
if (it != cells.end()) it->set(3);
```

ラムダは条件を満たしたら `true`。`it->` はイテレータが指す要素のメンバー。

## V13
**指定した値を最初の1個だけ消す**
検索語: vector erase find 削除 1個 候補

```cpp
auto it = std::find(values.begin(), values.end(), target);
if (it != values.end()) values.erase(it);
```

`#include <algorithm>` が必要。`erase` 後の `it` は使わない。

## V14
**指定した値を全部消す（erase-remove）**
検索語: vector erase remove 全削除 重複 削除

```cpp
values.erase(std::remove(values.begin(), values.end(), target),
             values.end());
```

`#include <algorithm>`。`std::remove` だけではvectorの長さは変わらない。C++17ではこの2段階。

## V15
**条件に合う要素を全部消す**
検索語: vector remove_if erase_if 条件 削除

```cpp
values.erase(std::remove_if(values.begin(), values.end(),
    [](int v) { return v < 0; }), values.end());
```

`#include <algorithm>`。`std::erase_if` はC++20なので、この辞書のC++17では使わない。

## V16
**途中に挿入する**
検索語: vector insert 途中 挿入 位置

```cpp
values.insert(values.begin() + 2, 99);  // 位置2の前
```

位置2が存在するか（または末尾か）確認。挿入後、古いイテレータや参照は無効になり得る。

## V17
**全要素を消す**
検索語: vector clear クリア 空にする リセット

```cpp
values.clear();
```

要素数が0になる。容量が必ず0になるわけではない。

## V18
**要素数を変更する**
検索語: vector resize サイズ 変更 追加 要素数

```cpp
values.resize(9);     // 9要素にする。intの追加分は0
values.resize(4, 7);  // 4要素にする。増える場合の値は7
```

縮む場合は末尾が消える。`reserve` とは違い、`size()` が変わる。

## V19
**容量だけ予約する**
検索語: vector reserve capacity 容量 予約 高速化

```cpp
std::vector<int> moves;
moves.reserve(9);
moves.push_back(3);
```

`reserve(9)` 直後でも `size()==0`。`moves[0]` は `push_back` 前には使えない。

## V20
**全要素を同じ値にする**
検索語: vector assign fill 埋める 初期化 リセット

```cpp
values.assign(9, 0);              // サイズも9にする
std::fill(values.begin(), values.end(), 0);  // サイズは維持
```

`std::fill` は `<algorithm>`。

## V21
**昇順・降順に並べる**
検索語: vector sort 並べ替え 昇順 降順

```cpp
std::sort(values.begin(), values.end());
std::sort(values.begin(), values.end(), std::greater<int>{});
```

`<algorithm>`、降順に `<functional>`。元の順序が重要な履歴には不用意に使わない。

## V22
**重複を消して一意にする**
検索語: vector unique 重複 取り除く dedupe

```cpp
std::sort(values.begin(), values.end());
values.erase(std::unique(values.begin(), values.end()), values.end());
```

`<algorithm>`。`unique` は隣り合う重複だけ処理するので、先にソートする。

## V23
**順序を逆にする**
検索語: vector reverse 逆順 反転

```cpp
std::reverse(values.begin(), values.end());
```

`<algorithm>`。元のvectorが変更される。

## V24
**関数へコピーせず渡す**
検索語: vector const& 引数 参照 コピー 関数

```cpp
int score(const std::vector<int>& moves);  // 読むだけ
void prune(std::vector<int>& moves);       // 元を変更
```

`const&` はコピーを避け、変更も禁止する。変更が必要なら `&`。

## V25
**vectorを戻り値として返す**
検索語: vector return 戻り値 返す 関数

```cpp
std::vector<int> legalMoves() {
    std::vector<int> result;
    result.push_back(1);
    return result;
}
```

C++17では通常この形でよい。ローカルvectorの参照を返してはいけない。

## V26
**2次元vectorを作る**
検索語: vector 二次元 grid 盤面 行列 rows cols

```cpp
std::vector<std::vector<int>> board(6, std::vector<int>(7, 0));
int cell = board[row][col];
```

6行7列。外側が行、内側が列。`board[x][y]` と決めつけない。

## V27
**走査しながら要素を消す**
検索語: vector erase iterator 走査中 削除 イテレータ

```cpp
for (auto it = values.begin(); it != values.end();) {
    if (*it < 0) it = values.erase(it);
    else ++it;
}
```

`erase` は次の有効な位置を返す。削除したあと同じ `it` を増やさない。

## V28
**合計を取る**
検索語: vector accumulate sum 合計 数える 数値

```cpp
#include <numeric>
int total = std::accumulate(values.begin(), values.end(), 0);
```

初期値 `0` の型が合計値の型になる。大きな合計なら `0LL`。

## V29
**連番を作る**
検索語: vector iota 連番 候補 1から9

```cpp
#include <numeric>
std::vector<int> digits(9);
std::iota(digits.begin(), digits.end(), 1);  // 1..9
```

先に `resize` などで要素数を作る。`reserve` だけでは書き込めない。

## V30
**vectorの参照・イテレータが無効になる場合**
検索語: vector invalidation 参照 イテレータ push_back erase 無効

```cpp
auto it = values.begin();
values.push_back(9);
// it をここで使わない。再取得する。
```

`push_back` で再配置が起こると全ての参照・イテレータが無効。`erase` でも消した位置以降は無効になり得る。

## V31
**vector<bool> の注意**
検索語: vector<bool> bool 特殊化 proxy 参照

```cpp
std::vector<bool> visited(10, false);
visited[3] = true;
bool value = visited[3];
```

`vector<bool>` の要素は普通の `bool&` と同じではない。ポインタや参照が必要な場合は `std::vector<char>` 等を検討。

## V32
**2つのvectorを比較する**
検索語: vector 比較 == 順序 等しい

```cpp
if (moves == expected) { /* 同じ長さ・同じ順序・同じ値 */ }
```

集合としての一致ではない。順序を問わないならソートしたコピー同士を比較する。

## V33
**先頭から条件に合う数を数える**
検索語: vector count_if 数える 条件 個数

```cpp
int empty = std::count_if(cells.begin(), cells.end(),
    [](const Cell& c) { return c.digit() == 0; });
```

`<algorithm>`。全件数える。途中で打ち切りたいなら通常のforや `any_of`。

## V34
**最小値・最大値の位置を得る**
検索語: vector min_element max_element 最小 最大 位置

```cpp
auto it = std::min_element(values.begin(), values.end());
if (it != values.end()) use(*it);
```

`<algorithm>`。空なら `end()` が返る。要素の値でなく位置を得られる。

## V35
**コピーを作って元を残す**
検索語: vector copy コピー 複製 元を残す シミュレーション

```cpp
auto next = current;
next.push_back(move);
```

ゲームの仮の一手を試すときに使える。大きい盤面を毎回コピーすると時間とメモリが増える。
