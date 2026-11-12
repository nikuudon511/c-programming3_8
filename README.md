# C++ 模擬試験問題（Qt Creator用）

このブランチには自作の模擬問題を置いています。元の授業教材や解答済みの練習ファイルは含めていません。問題05は `practice/05_code_lock/README.md` を参照。

## VMで取得

```bash
git clone --branch cpp-exam-practice --single-branch https://github.com/nikuudon511/c-programming3_8.git cpp-exam-practice
```

Qt Creator で `cpp-exam-practice/CMakeLists.txt` を開く。各問題の `README.md` を読み、TODOを埋める。解く問題のターゲット（`practice04` または `practice05`）をビルド・実行して確認する。

ターミナルなら次のコマンドでも確認できる。

```bash
cmake -S cpp-exam-practice -B cpp-exam-practice/build
cmake --build cpp-exam-practice/build --target practice04
ctest --test-dir cpp-exam-practice/build --output-on-failure
```

問題が追加されたらVM内で `git pull` する。自分の解答を保存している場合は、先にコミットするか別の場所へコピーしてから更新する。試験当日は完全オフラインなので、事前にクローンとビルドを済ませる。
