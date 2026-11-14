#!/usr/bin/env python3
"""Search the offline C++ dictionary by ID or keywords (stdlib only)."""
from __future__ import annotations

import argparse
import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def show_card(row):
    lines = (ROOT / "entries" / row["file"]).read_text(encoding="utf-8").splitlines()
    start = next(i for i, line in enumerate(lines) if line == "## " + row["id"])
    end = next((i for i in range(start + 1, len(lines)) if re.fullmatch(r"## [A-Z]\d{2}", lines[i])), len(lines))
    return "\n".join(lines[start:end]).strip()


def main():
    parser = argparse.ArgumentParser(description="Search C++17 exam dictionary")
    parser.add_argument("terms", nargs="*", help="all words must match ID, title, category or keywords")
    parser.add_argument("--show", metavar="ID", help="print one full entry, e.g. V14")
    args = parser.parse_args()
    with (ROOT / "catalog.tsv").open(encoding="utf-8", newline="") as f:
        rows = list(csv.DictReader(f, delimiter="\t"))
    if args.show:
        row = next((row for row in rows if row["id"].casefold() == args.show.casefold()), None)
        if row is None:
            raise SystemExit("unknown ID: " + args.show)
        print(show_card(row))
        return
    if not args.terms:
        parser.error("enter a word or use --show ID")
    terms = [term.casefold() for term in args.terms]
    matches = [row for row in rows if all(term in " ".join(row.values()).casefold() for term in terms)]
    for row in matches:
        print(f"{row['id']}  {row['title']}  [{row['file']}#{row['id'].lower()}]")
    print(f"{len(matches)} result(s)")


if __name__ == "__main__":
    main()
