# C++17 辞書索引

128項目。全てオフライン。詳細検索は `python3 tools/search.py 語句`。

## 目的から探す

| やりたいこと | 項目 |
|---|---|
| vectorに追加・候補を列挙 | [V04](entries/01_vector.md#v04), [V05](entries/01_vector.md#v05), [P01](entries/07_game_patterns.md#p01) |
| vectorから1個・全部を消す | [V13](entries/01_vector.md#v13), [V14](entries/01_vector.md#v14), [V15](entries/01_vector.md#v15), [V27](entries/01_vector.md#v27) |
| vectorのサイズと容量 | [V02](entries/01_vector.md#v02), [V18](entries/01_vector.md#v18), [V19](entries/01_vector.md#v19) |
| 末尾の手を読む・戻す | [V06](entries/01_vector.md#v06), [V07](entries/01_vector.md#v07), [P03](entries/07_game_patterns.md#p03) |
| 値や条件で探す | [V11](entries/01_vector.md#v11), [V12](entries/01_vector.md#v12), [A01](entries/02_algorithm.md#a01), [A02](entries/02_algorithm.md#a02) |
| 全件・一件・個数を判定 | [A03](entries/02_algorithm.md#a03), [A04](entries/02_algorithm.md#a04), [A05](entries/02_algorithm.md#a05), [A06](entries/02_algorithm.md#a06) |
| 並べ替え・重複除去 | [V21](entries/01_vector.md#v21), [V22](entries/01_vector.md#v22), [A10](entries/02_algorithm.md#a10) |
| 2次元盤面・添字・境界 | [G01](entries/03_grid.md#g01), [G02](entries/03_grid.md#g02), [G03](entries/03_grid.md#g03), [G06](entries/03_grid.md#g06), [G07](entries/03_grid.md#g07) |
| 上下左右・斜めの隣接 | [G04](entries/03_grid.md#g04), [G05](entries/03_grid.md#g05) |
| 勝敗・終了条件 | [G08](entries/03_grid.md#g08), [G09](entries/03_grid.md#g09), [P04](entries/07_game_patterns.md#p04), [P05](entries/07_game_patterns.md#p05) |
| 不正手・状態更新・巻き戻し | [P02](entries/07_game_patterns.md#p02), [P03](entries/07_game_patterns.md#p03), [P12](entries/07_game_patterns.md#p12) |
| AIの手選び・確定手 | [P07](entries/07_game_patterns.md#p07), [P08](entries/07_game_patterns.md#p08), [P10](entries/07_game_patterns.md#p10) |
| 再帰・候補の復元 | [P06](entries/07_game_patterns.md#p06), [P11](entries/07_game_patterns.md#p11) |
| 入力・表示・ファイル | [S07](entries/04_string_io.md#s07), [S08](entries/04_string_io.md#s08), [S09](entries/04_string_io.md#s09), [S10](entries/04_string_io.md#s10), [S12](entries/04_string_io.md#s12) |
| クラス・const・参照 | [C01](entries/06_cpp_core.md#c01), [C02](entries/06_cpp_core.md#c02), [C03](entries/06_cpp_core.md#c03), [C04](entries/06_cpp_core.md#c04), [C06](entries/06_cpp_core.md#c06) |
| コンパイル・テスト・停止 | [D01](entries/09_debug_build.md#d01), [D02](entries/09_debug_build.md#d02), [D03](entries/09_debug_build.md#d03), [D06](entries/09_debug_build.md#d06), [D07](entries/09_debug_build.md#d07), [D11](entries/09_debug_build.md#d11) |

## 分野別に探す

## 01_vector

- [V01 vectorを作る・初期化する](entries/01_vector.md#v01) — vector 宣言 初期化 作成 constructor
- [V02 要素数と空判定](entries/01_vector.md#v02) — vector size empty 長さ 空か 個数
- [V03 添字で読む・書く](entries/01_vector.md#v03) — vector [] at 添字 アクセス 読む 書く 範囲外
- [V04 末尾に追加する](entries/01_vector.md#v04) — vector push_back 追加 append 末尾 候補
- [V05 末尾に直接構築する](entries/01_vector.md#v05) — vector emplace_back 追加 構築 Point 座標
- [V06 最後を取り除く](entries/01_vector.md#v06) — vector pop_back 削除 最後 undo 履歴
- [V07 先頭・末尾を読む](entries/01_vector.md#v07) — vector front back 先頭 末尾
- [V08 全要素を読む（範囲for）](entries/01_vector.md#v08) — vector range for 全件 走査 const 参照
- [V09 全要素を変更する（参照）](entries/01_vector.md#v09) — vector range for 変更 auto& 参照 コピー
- [V10 添字も必要なときのfor](entries/01_vector.md#v10) — vector index 添字 for 座標 位置
- [V11 値を1個探す](entries/01_vector.md#v11) — vector std::find find 検索 含む 存在 iterator
- [V12 条件に合う要素を探す](entries/01_vector.md#v12) — vector find_if 条件 検索 lambda
- [V13 指定した値を最初の1個だけ消す](entries/01_vector.md#v13) — vector erase find 削除 1個 候補
- [V14 指定した値を全部消す（erase-remove）](entries/01_vector.md#v14) — vector erase remove 全削除 重複 削除
- [V15 条件に合う要素を全部消す](entries/01_vector.md#v15) — vector remove_if erase_if 条件 削除
- [V16 途中に挿入する](entries/01_vector.md#v16) — vector insert 途中 挿入 位置
- [V17 全要素を消す](entries/01_vector.md#v17) — vector clear クリア 空にする リセット
- [V18 要素数を変更する](entries/01_vector.md#v18) — vector resize サイズ 変更 追加 要素数
- [V19 容量だけ予約する](entries/01_vector.md#v19) — vector reserve capacity 容量 予約 高速化
- [V20 全要素を同じ値にする](entries/01_vector.md#v20) — vector assign fill 埋める 初期化 リセット
- [V21 昇順・降順に並べる](entries/01_vector.md#v21) — vector sort 並べ替え 昇順 降順
- [V22 重複を消して一意にする](entries/01_vector.md#v22) — vector unique 重複 取り除く dedupe
- [V23 順序を逆にする](entries/01_vector.md#v23) — vector reverse 逆順 反転
- [V24 関数へコピーせず渡す](entries/01_vector.md#v24) — vector const& 引数 参照 コピー 関数
- [V25 vectorを戻り値として返す](entries/01_vector.md#v25) — vector return 戻り値 返す 関数
- [V26 2次元vectorを作る](entries/01_vector.md#v26) — vector 二次元 grid 盤面 行列 rows cols
- [V27 走査しながら要素を消す](entries/01_vector.md#v27) — vector erase iterator 走査中 削除 イテレータ
- [V28 合計を取る](entries/01_vector.md#v28) — vector accumulate sum 合計 数える 数値
- [V29 連番を作る](entries/01_vector.md#v29) — vector iota 連番 候補 1から9
- [V30 vectorの参照・イテレータが無効になる場合](entries/01_vector.md#v30) — vector invalidation 参照 イテレータ push_back erase 無効
- [V31 vector<bool> の注意](entries/01_vector.md#v31) — vector<bool> bool 特殊化 proxy 参照
- [V32 2つのvectorを比較する](entries/01_vector.md#v32) — vector 比較 == 順序 等しい
- [V33 先頭から条件に合う数を数える](entries/01_vector.md#v33) — vector count_if 数える 条件 個数
- [V34 最小値・最大値の位置を得る](entries/01_vector.md#v34) — vector min_element max_element 最小 最大 位置
- [V35 コピーを作って元を残す](entries/01_vector.md#v35) — vector copy コピー 複製 元を残す シミュレーション

## 02_algorithm

- [A01 指定値が存在するか](entries/02_algorithm.md#a01) — algorithm find 含む 存在 値 探す
- [A02 条件に合う最初の要素を探す](entries/02_algorithm.md#a02) — algorithm find_if 条件 最初 探す ラムダ
- [A03 全て条件を満たすか](entries/02_algorithm.md#a03) — algorithm all_of 全件 全部 満杯 完了
- [A04 1件でも条件を満たすか](entries/02_algorithm.md#a04) — algorithm any_of どれか 存在 一件 地雷
- [A05 どれも条件を満たさないか](entries/02_algorithm.md#a05) — algorithm none_of ひとつもない 禁止
- [A06 値または条件に合う個数を数える](entries/02_algorithm.md#a06) — algorithm count count_if 個数 数える
- [A07 比較関数で最小の要素を選ぶ](entries/02_algorithm.md#a07) — algorithm min_element 比較候補 最適 最小
- [A08 条件で新しいvectorへ選別する](entries/02_algorithm.md#a08) — algorithm copy_if filter 抽出 フィルタ
- [A09 各要素を変換して新しいvectorへ](entries/02_algorithm.md#a09) — algorithm transform map 変換
- [A10 並べ替えの比較関数](entries/02_algorithm.md#a10) — algorithm sort comparator 降順 比較
- [A11 ソート済み範囲で値を探す](entries/02_algorithm.md#a11) — algorithm binary_search lower_bound ソート済み 二分探索
- [A12 値を範囲に収める](entries/02_algorithm.md#a12) — algorithm clamp 範囲 制限 min max
- [A13 隣り合う同じ値を見つける](entries/02_algorithm.md#a13) — algorithm adjacent_find 隣接 重複 連続
- [A14 2つの値を交換する](entries/02_algorithm.md#a14) — algorithm swap 交換 手番 状態
- [A15 並びを逆にする](entries/02_algorithm.md#a15) — algorithm reverse 経路 逆順 バックトラック
- [A16 条件に合う範囲を探す前に空確認](entries/02_algorithm.md#a16) — algorithm begin end empty dereference 参照 外す

## 03_grid

- [G01 固定サイズの2次元盤面を作る](entries/03_grid.md#g01) — array 盤面 二次元 固定長 初期化
- [G02 全マスを走査する](entries/03_grid.md#g02) — grid 全マス 走査 row col 二重ループ
- [G03 盤面内か判定する](entries/03_grid.md#g03) — grid bounds 境界 範囲外 row col 添字
- [G04 上下左右の4近傍を列挙する](entries/03_grid.md#g04) — grid neighbors 4方向 上下左右 隣接
- [G05 斜めを含む8近傍を列挙する](entries/03_grid.md#g05) — grid neighbors 8方向 斜め マインスイーパー 隣接
- [G06 1次元配列と行列座標を変換する](entries/03_grid.md#g06) — grid flat index row col 1次元 変換
- [G07 x,yとrow,colを読み替える](entries/03_grid.md#g07) — grid x y row col 座標 画像 迷路
- [G08 勝ち筋の3マスが同じか](entries/03_grid.md#g08) — grid winner 勝利 三目並べ 同じ 空き 0
- [G09 方向に沿って連続マスを調べる](entries/03_grid.md#g09) — grid 連続 4目並べ 五目並べ 方向 勝敗
- [G10 盤面をコピーして仮の手を試す](entries/03_grid.md#g10) — grid copy simulation 仮の手 AI シミュレーション
- [G11 幅優先探索の基本形](entries/03_grid.md#g11) — grid BFS queue 迷路 最短経路 探索
- [G12 マスを開くときの分岐順](entries/03_grid.md#g12) — grid reveal マインスイーパー 開封 状態更新 範囲外

## 04_string_io

- [S01 文字列を作り、長さを得る](entries/04_string_io.md#s01) — string 文字列 長さ size empty
- [S02 文字を1個読む・変更する](entries/04_string_io.md#s02) — string 添字 char 文字 変更
- [S03 部分文字列を取る](entries/04_string_io.md#s03) — string substr 切り出し 部分
- [S04 文字列内を探す](entries/04_string_io.md#s04) — string find 検索 npos 含む
- [S05 文字列を連結する](entries/04_string_io.md#s05) — string append + 連結 追加
- [S06 整数に変換する](entries/04_string_io.md#s06) — string stoi to_string 数値 変換
- [S07 空白区切りの値を読む](entries/04_string_io.md#s07) — cin 入力 整数 空白
- [S08 1行を丸ごと読む](entries/04_string_io.md#s08) — getline 行 入力 空白 スペース
- [S09 結果を表示する](entries/04_string_io.md#s09) — cout 出力 改行 print
- [S10 ファイルを1行ずつ読む](entries/04_string_io.md#s10) — ifstream ファイル 読む 行 オフライン
- [S11 文字列を整数ごとに分割する](entries/04_string_io.md#s11) — istringstream parse 分割 空白 数列
- [S12 盤面を行として表示する](entries/04_string_io.md#s12) — 盤面 表示 rows cols cout 二重ループ

## 05_map_set

- [M01 重複のない座標を記録する](entries/05_map_set.md#m01) — set 重複 座標 訪問 visited
- [M02 setへ挿入し新規か判定する](entries/05_map_set.md#m02) — set insert 新規 重複 判定
- [M03 mapに数を蓄積する](entries/05_map_set.md#m03) — map count 回数 頻度 対応表
- [M04 mapから安全に読む](entries/05_map_set.md#m04) — map find at キー 存在 読む
- [M05 mapを全件走査する](entries/05_map_set.md#m05) — map range for key value 全件 走査
- [M06 unordered_setで高速な存在判定](entries/05_map_set.md#m06) — unordered_set hash 存在 重複 高速
- [M07 キーと値を同時に追加する](entries/05_map_set.md#m07) — map emplace insert 対応 追加
- [M08 setから削除する](entries/05_map_set.md#m08) — set erase remove 削除 訪問履歴

## 06_cpp_core

- [C01 ヘッダー宣言に対応するメソッドを定義する](entries/06_cpp_core.md#c01) — class メソッド 定義 :: header cpp const
- [C02 コンストラクタでメンバーを初期化する](entries/06_cpp_core.md#c02) — constructor 初期化リスト メンバー コンストラクタ
- [C03 読み取り専用メソッドのconst](entries/06_cpp_core.md#c03) — const member method 読み取り専用 メソッド
- [C04 値・参照・const参照を使い分ける](entries/06_cpp_core.md#c04) — 引数 value reference const& コピー 変更
- [C05 ポインタのメンバーにアクセスする](entries/06_cpp_core.md#c05) — pointer -> * ポインタ セル 隣接
- [C06 参照で要素を変更する](entries/06_cpp_core.md#c06) — reference auto& for 参照 vector 変更
- [C07 enum classを比較し返す](entries/06_cpp_core.md#c07) — enum class 列挙型 戻り値 状態
- [C08 structで座標をまとめる](entries/06_cpp_core.md#c08) — struct Point Coord 座標 初期化 比較
- [C09 ラムダで外側の値を使う](entries/06_cpp_core.md#c09) — lambda capture [&] [=] ラムダ キャプチャ
- [C10 ヘッダーの多重読み込みを防ぐ](entries/06_cpp_core.md#c10) — include guard header #ifndef #define ヘッダー
- [C11 optionalで「値なし」を表す](entries/06_cpp_core.md#c11) — optional nullopt 値なし find 戻り値
- [C12 例外を投げる・受ける](entries/06_cpp_core.md#c12) — exception throw runtime_error try catch エラー

## 07_game_patterns

- [P01 合法手を列挙する](entries/07_game_patterns.md#p01) — game AvailableMoves legal moves 候補 列挙 vector
- [P02 不正手を拒否してから状態を変更する](entries/07_game_patterns.md#p02) — game MakeMove play 不正手 状態変更
- [P03 最後の手を巻き戻す](entries/07_game_patterns.md#p03) — game CancelMove undo 戻す 履歴 vector
- [P04 勝者を返す](entries/07_game_patterns.md#p04) — game Winner 勝敗 勝者 三目並べ
- [P05 終了条件と勝者を分ける](entries/07_game_patterns.md#p05) — game Over finished 終了 引き分け 勝者
- [P06 バックトラックの基本形](entries/07_game_patterns.md#p06) — game backtracking 再帰 試す 戻す Sudoku
- [P07 AIの候補を評価して最善を選ぶ](entries/07_game_patterns.md#p07) — game AI best move 評価 score 最大
- [P08 minimaxの手番による最大化・最小化](entries/07_game_patterns.md#p08) — game minimax alpha beta 最大 最小 AI 対戦
- [P09 マインスイーパーの周囲地雷数](entries/07_game_patterns.md#p09) — game minesweeper 地雷 8近傍 数える
- [P10 数字から安全・地雷を確定する](entries/07_game_patterns.md#p10) — game minesweeper AI clue flag hidden 推論 安全
- [P11 複数の制約で禁止された候補を戻す](entries/07_game_patterns.md#p11) — game Sudoku prune restore 候補 禁止 回数
- [P12 マスの状態を先に検査する](entries/07_game_patterns.md#p12) — game state 盤面 開封 重複 範囲外 return
- [P13 幅優先で連鎖的にマスを開く](entries/07_game_patterns.md#p13) — game flood fill 連鎖 開封 queue BFS
- [P14 変更前後の不変条件を確認する](entries/07_game_patterns.md#p14) — game invariant 不変条件 状態 整合性 デバッグ

## 08_numeric

- [N01 小さい方・大きい方を選ぶ](entries/08_numeric.md#n01) — min max 最小 最大 上限 下限
- [N02 絶対値・マンハッタン距離](entries/08_numeric.md#n02) — abs distance 距離 Manhattan 座標
- [N03 偶数・奇数を判定する](entries/08_numeric.md#n03) — modulo % 偶数 奇数 手番
- [N04 プレイヤー1と2を切り替える](entries/08_numeric.md#n04) — player 手番 切り替え 1 2
- [N05 整数除算と余り](entries/08_numeric.md#n05) — division modulo / % 行列 3x3 ブロック
- [N06 charの数字とintの数字を変換する](entries/08_numeric.md#n06) — char digit int ASCII 数字 文字 変換
- [N07 符号なしと符号付きの比較を避ける](entries/08_numeric.md#n07) — size_t int signed unsigned warning 添字
- [N08 数値の十分小さい初期値](entries/08_numeric.md#n08) — numeric_limits min 最大化 AI 初期値

## 09_debug_build

- [D01 1個のC++課題を直接コンパイルする](entries/09_debug_build.md#d01) — g++ compile コンパイル C++17 ビルド
- [D02 CMake課題をビルドする](entries/09_debug_build.md#d02) — cmake build CMakeLists Qt Creator ビルド
- [D03 CTestで指定の問題だけ試す](entries/09_debug_build.md#d03) — ctest test assert テスト 失敗
- [D04 最初のコンパイルエラーを読む](entries/09_debug_build.md#d04) — compile error not declared matching function コンパイルエラー
- [D05 リンクエラーを読む](entries/09_debug_build.md#d05) — linker undefined reference リンク 定義 ない
- [D06 assert失敗とSIGABRTを読む](entries/09_debug_build.md#d06) — assert SIGABRT abort テスト 止まる
- [D07 Qt Creatorでブレークポイントを使う](entries/09_debug_build.md#d07) — Qt Creator breakpoint F9 F5 F10 Locals デバッグ
- [D08 gdbで停止箇所を調べる](entries/09_debug_build.md#d08) — gdb backtrace bt run crash デバッグ
- [D09 境界外アクセスを検出する](entries/09_debug_build.md#d09) — sanitizer ASan undefined 範囲外 メモリ
- [D10 変更したファイルだけ確認する](entries/09_debug_build.md#d10) — git diff status 提出 変更ファイル
- [D11 古い実行ファイルを疑う](entries/09_debug_build.md#d11) — stale binary 古い 実行ファイル ビルド 更新されない
