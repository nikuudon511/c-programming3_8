# 集合と対応表

`std::set` は重複なし・順序あり。`std::map` はキーから値を探す。小さい盤面ならvectorや配列の方が簡単なことも多い。

## M01
**重複のない座標を記録する**
検索語: set 重複 座標 訪問 visited

```cpp
#include <set>
std::set<std::pair<int, int>> visited;
visited.insert({row, col});
bool seen = visited.find({row, col}) != visited.end();
```

`std::pair` は `<utility>`。同じ座標を再挿入しても1件。

## M02
**setへ挿入し新規か判定する**
検索語: set insert 新規 重複 判定

```cpp
auto [it, inserted] = visited.insert({row, col});
if (inserted) { /* 初めて訪問 */ }
```

C++17の構造化束縛。`it` を使わなければ `visited.insert(...).second` でもよい。

## M03
**mapに数を蓄積する**
検索語: map count 回数 頻度 対応表

```cpp
#include <map>
std::map<int, int> counts;
++counts[digit];
```

`counts[digit]` はキーが無ければ値0を作る。読むだけで新規キーを作りたくない場合は `find`。

## M04
**mapから安全に読む**
検索語: map find at キー 存在 読む

```cpp
auto it = counts.find(digit);
int count = (it == counts.end()) ? 0 : it->second;
```

`it->first` はキー、`it->second` は値。`at()` はキーがなければ例外。

## M05
**mapを全件走査する**
検索語: map range for key value 全件 走査

```cpp
for (const auto& [key, value] : counts) {
    std::cout << key << ':' << value << '\n';
}
```

`<iostream>` が必要。C++17の構造化束縛。`std::map` はキー順。

## M06
**unordered_setで高速な存在判定**
検索語: unordered_set hash 存在 重複 高速

```cpp
#include <unordered_set>
std::unordered_set<int> tried;
tried.insert(move);
bool already = tried.find(move) != tried.end();
```

順序を保証しない。独自の座標型にはハッシュ定義が必要なので、試験では `std::set<std::pair<int,int>>` が簡単な場合もある。

## M07
**キーと値を同時に追加する**
検索語: map emplace insert 対応 追加

```cpp
parents.emplace(child, parent);
```

同じキーが既にあると値は上書きされない。上書きしたいなら `parents[child] = parent;`。

## M08
**setから削除する**
検索語: set erase remove 削除 訪問履歴

```cpp
visited.erase({row, col});
```

存在しなければ何も起きない。戻り値は削除した要素数。
