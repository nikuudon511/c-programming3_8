#!/usr/bin/env python3
"""Build offline C++ dictionary indexes from entries/*.md (stdlib only)."""
from __future__ import annotations

import argparse
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ENTRY = re.compile(r"^## ([A-Z]\d{2})$")
TITLE = re.compile(r"^\*\*(.+)\*\*$")


def entries():
    seen = set()
    result = []
    for path in sorted((ROOT / "entries").glob("*.md")):
        lines = path.read_text(encoding="utf-8").splitlines()
        for i, line in enumerate(lines):
            match = ENTRY.fullmatch(line)
            if not match:
                continue
            ident = match.group(1)
            if ident in seen:
                raise ValueError(f"duplicate ID: {ident}")
            seen.add(ident)
            if i + 2 >= len(lines):
                raise ValueError(f"missing title/keywords: {path}:{i+1}")
            title = TITLE.fullmatch(lines[i + 1])
            keywords = lines[i + 2]
            if not title or not keywords.startswith("検索語: "):
                raise ValueError(f"missing title/keywords: {path}:{i+1}")
            result.append((ident, path.stem, title.group(1),
                           keywords.removeprefix("検索語: "), path.name))
    if not result:
        raise ValueError("no entries found")
    return result


def render(rows):
    catalog = "id\tcategory\ttitle\tkeywords\tfile\n"
    catalog += "".join("\t".join(row) + "\n" for row in rows)
    out = ["# C++17 辞書索引", "", f"{len(rows)}項目。全てオフライン。詳細検索は `python3 tools/search.py 語句`。", ""]
    by_id = {row[0]: row for row in rows}
    intents = [
        ("vectorに追加・候補を列挙", "V04 V05 P01"),
        ("vectorから1個・全部を消す", "V13 V14 V15 V27"),
        ("vectorのサイズと容量", "V02 V18 V19"),
        ("末尾の手を読む・戻す", "V06 V07 P03"),
        ("値や条件で探す", "V11 V12 A01 A02"),
        ("全件・一件・個数を判定", "A03 A04 A05 A06"),
        ("並べ替え・重複除去", "V21 V22 A10"),
        ("2次元盤面・添字・境界", "G01 G02 G03 G06 G07"),
        ("上下左右・斜めの隣接", "G04 G05"),
        ("勝敗・終了条件", "G08 G09 P04 P05"),
        ("不正手・状態更新・巻き戻し", "P02 P03 P12"),
        ("AIの手選び・確定手", "P07 P08 P10"),
        ("再帰・候補の復元", "P06 P11"),
        ("入力・表示・ファイル", "S07 S08 S09 S10 S12"),
        ("クラス・const・参照", "C01 C02 C03 C04 C06"),
        ("コンパイル・テスト・停止", "D01 D02 D03 D06 D07 D11"),
    ]
    out += ["## 目的から探す", "", "| やりたいこと | 項目 |", "|---|---|"]
    for goal, ids in intents:
        links = []
        for ident in ids.split():
            if ident not in by_id:
                raise ValueError(f"unknown ID in intent index: {ident}")
            filename = by_id[ident][4]
            links.append(f"[{ident}](entries/{filename}#{ident.lower()})")
        out.append(f"| {goal} | {', '.join(links)} |")
    out += ["", "## 分野別に探す", ""]
    by_category = {}
    for row in rows:
        by_category.setdefault(row[1], []).append(row)
    for category, group in by_category.items():
        out += [f"## {category}", ""]
        for ident, _, title, keywords, filename in group:
            out.append(f"- [{ident} {title}](entries/{filename}#{ident.lower()}) — {keywords}")
        out.append("")
    return catalog, "\n".join(out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="fail if generated indexes are stale")
    args = parser.parse_args()
    rows = entries()
    catalog, index = render(rows)
    outputs = {ROOT / "catalog.tsv": catalog, ROOT / "INDEX.md": index}
    if args.check:
        stale = [str(path) for path, content in outputs.items()
                 if not path.exists() or path.read_text(encoding="utf-8") != content]
        if stale:
            raise SystemExit("stale index: " + ", ".join(stale))
    else:
        for path, content in outputs.items():
            path.write_text(content, encoding="utf-8")
    print(f"{len(rows)} entries; indexes {'valid' if args.check else 'written'}")


if __name__ == "__main__":
    main()
