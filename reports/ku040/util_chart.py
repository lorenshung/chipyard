#!/usr/bin/env python3
"""
util_chart.py - Add a column of bars from a Vivado hierarchical
utilization.txt to reports/ku040/util_chart.png.

Usage:
    util_chart.py <path/to/utilization.txt> <label>   # record + redraw
    util_chart.py --list                              # list recorded labels
    util_chart.py --rm <label>                        # drop one label
    util_chart.py --reset                             # wipe everything
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np

ROOT = Path(__file__).resolve().parent
DATA = ROOT / "util_data.json"
CHART = ROOT / "util_chart.png"

# XCKU040-FFVA1156 device capacities.
CAPS = {
    "Logic LUTs": 242_400,
    "LUTRAMs":    112_800,
    "SRLs":       162_400,
    "Total LUTs": 242_400,
    "FFs":        484_800,
    "RAMB36":         600,
    "RAMB18":       1_200,
    "DSP Blocks":   1_920,
}

# X-axis order, left to right. LUT breakdown first, then totals.
CATEGORIES = [
    "Logic LUTs",
    "LUTRAMs",
    "SRLs",
    "Total LUTs",
    "FFs",
    "RAMB36",
    "RAMB18",
    "DSP Blocks",
]


def parse_util(path: Path) -> dict[str, int]:
    """Return resource->count from the top row of the hierarchy table."""
    text = path.read_text()
    header_re = re.compile(
        r"\|\s*Instance\s*\|\s*Module\s*\|\s*Total LUTs\s*\|"
        r"\s*Logic LUTs\s*\|\s*LUTRAMs\s*\|\s*SRLs\s*\|\s*FFs\s*\|"
        r"\s*RAMB36\s*\|\s*RAMB18\s*\|\s*URAM\s*\|\s*DSP Blocks\s*\|"
    )
    m = header_re.search(text)
    if not m:
        raise RuntimeError(
            f"Could not locate hierarchy-utilization header in {path}. "
            "Was the report produced with `report_utilization -hierarchical`?"
        )
    for line in text[m.end():].splitlines():
        s = line.strip()
        if not s or s.startswith("+"):
            continue
        cells = [c.strip() for c in s.strip("|").split("|")]
        if len(cells) < 11:
            continue
        return {
            "Total LUTs": int(cells[2]),
            "Logic LUTs": int(cells[3]),
            "LUTRAMs":    int(cells[4]),
            "SRLs":       int(cells[5]),
            "FFs":        int(cells[6]),
            "RAMB36":     int(cells[7]),
            "RAMB18":     int(cells[8]),
            "DSP Blocks": int(cells[10]),
        }
    raise RuntimeError(f"No data rows found after header in {path}")


def load() -> dict:
    if DATA.exists():
        return json.loads(DATA.read_text())
    return {"strategies": {}}


def save(d: dict) -> None:
    DATA.write_text(json.dumps(d, indent=2))


# Stack order, bottom-to-top. LUT breakdown grouped first, then other
# resource families. "Total LUTs" is excluded since Logic+LUTRAM+SRL is
# the full LUT breakdown (segments would double-count otherwise).
SEGMENTS = [
    "Logic LUTs",   # LUT breakdown
    "LUTRAMs",
    "SRLs",
    "FFs",          # other resources
    "RAMB36",
    "RAMB18",
    "DSP Blocks",
]

# Distinct colors: blues for LUT family, then orange/green/red/purple.
SEGMENT_COLORS = {
    "Logic LUTs": "#1f77b4",
    "LUTRAMs":    "#5fa0d8",
    "SRLs":       "#9fc8e8",
    "FFs":        "#ff7f0e",
    "RAMB36":     "#2ca02c",
    "RAMB18":     "#7fd07f",
    "DSP Blocks": "#9467bd",
}


def render(data: dict) -> None:
    strategies = list(data["strategies"].keys())
    if not strategies:
        print("No strategies recorded.")
        return

    x = np.arange(len(strategies))
    width = 0.55
    fig, ax = plt.subplots(figsize=(max(8.0, 2.5 + 1.5 * len(strategies)), 8.5))

    bottoms = np.zeros(len(strategies))
    for seg in SEGMENTS:
        heights = np.array([
            100.0 * data["strategies"][s].get(seg, 0) / CAPS[seg]
            for s in strategies
        ])
        bars = ax.bar(
            x, heights, width, bottom=bottoms,
            label=seg, color=SEGMENT_COLORS[seg],
            edgecolor="black", linewidth=0.4,
        )
        for i, bar in enumerate(bars):
            h = bar.get_height()
            raw = data["strategies"][strategies[i]].get(seg, 0)
            if h < 0.8:  # too thin to annotate inside; skip
                continue
            ax.text(
                bar.get_x() + bar.get_width() / 2,
                bar.get_y() + h / 2,
                f"{seg}: {raw:,} ({h:.1f}%)",
                ha="center", va="center",
                fontsize=8, color="black",
            )
        bottoms += heights

    # Top-of-bar totals (sum of stacked %s).
    for i, total in enumerate(bottoms):
        ax.text(x[i], total + 1, f"Σ {total:.1f}%",
                ha="center", va="bottom", fontsize=9, fontweight="bold")

    ax.set_xticks(x)
    ax.set_xticklabels(strategies, rotation=10, ha="right")
    ax.set_ylabel("% of XCKU040 device cap (stacked per resource)")
    ax.set_title(
        "KU040 utilization by iteration\n"
        "(each segment = that resource's % of device cap; raw count inside)"
    )
    ax.grid(axis="y", linestyle="--", alpha=0.4)
    # Reverse legend order so top segment appears first.
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles[::-1], labels[::-1],
              loc="center left", bbox_to_anchor=(1.01, 0.5),
              framealpha=0.95, title="Resource")
    ax.set_ylim(0, max(bottoms.max() * 1.15, 10))
    plt.tight_layout()
    fig.savefig(CHART, dpi=140, bbox_inches="tight")
    print(f"Wrote {CHART}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("util", nargs="?", help="Path to utilization.txt")
    ap.add_argument("label", nargs="?", help="Label for this run (legend entry)")
    ap.add_argument("--reset", action="store_true", help="Wipe stored data + chart")
    ap.add_argument("--list", action="store_true", help="List recorded labels")
    ap.add_argument("--rm", metavar="LABEL", help="Drop one recorded label")
    args = ap.parse_args()

    if args.reset:
        for p in (DATA, CHART):
            if p.exists():
                p.unlink()
                print(f"Removed {p}")
        return

    data = load()

    if args.list:
        for name, counts in data["strategies"].items():
            print(name)
            for k, v in counts.items():
                print(f"  {k:12s} {v}")
        return

    if args.rm:
        if args.rm in data["strategies"]:
            del data["strategies"][args.rm]
            save(data)
            render(data)
        else:
            print(f"No label {args.rm!r} in {DATA}", file=sys.stderr)
            sys.exit(1)
        return

    if not (args.util and args.label):
        ap.print_usage()
        sys.exit(1)

    counts = parse_util(Path(args.util))
    data["strategies"][args.label] = counts
    save(data)
    print(f"Recorded {args.label!r}:")
    for k, v in counts.items():
        cap = CAPS[k]
        print(f"  {k:12s} {v:>8,d}   ({100*v/cap:5.2f}% of {cap:,})")
    render(data)


if __name__ == "__main__":
    main()
