#!/usr/bin/env python3
"""
inject_resource_attrs.py — Idempotent Vivado attribute injection for
Chipyard gen-collateral SystemVerilog.

Driven by a JSON config with named categories (dsp, bram, cdc, ...).
On every run the script first strips any prior injection, then re-applies
the categories selected via --only. Re-runs converge deterministically and
toggling --only between calls needs no manual cleanup.

Marker:
    Each injected attribute line ends with `// __CYRA__` (Chipyard Resource
    Attribute). Strip removes any line that matches the marker pattern.

Pattern targets (regex, attribute family):
    RAM_RE   "reg [W:0] X [0:D];"            ram_style, rw_addr_collision
    MUL_RE   "assign io_out_data = ... * ..." use_dsp48, use_dsp
    SYNC_RE  "reg [..] sync_N;"              async_reg, shreg_extract, srl_style

Module matching:
    Each "modules" key is an fnmatch pattern. A file matches if its stem OR
    any `module NAME(` decl inside it matches the pattern. First matching
    pattern per category wins; auto rules fire only when no explicit pattern
    matched.

Usage:
    inject_resource_attrs.py --collateral <dir> --config <attrs.json>
                             [--only LIST] [--dry-run] [--quiet]

    --only LIST   comma-separated categories, "all" (default), or "none"
                    "none"  strip-only (clean baseline)
                    "all"   apply every category in the config
    --dry-run     classify + report; do not modify files
    --quiet       suppress per-file output

Examples:
    inject_resource_attrs.py ... --only dsp
    inject_resource_attrs.py ... --only bram
    inject_resource_attrs.py ... --only dsp,bram
    inject_resource_attrs.py ... --only none
"""
from __future__ import annotations
import argparse, fnmatch, json, re, sys
from pathlib import Path

MARKER = "// __CYRA__"
INJ_RE = re.compile(r"^[ \t]*\(\*[^*]+\*\)[ \t]*" + re.escape(MARKER) + r"\n", re.M)

RAM_RE    = re.compile(r"^(?P<i>[ \t]*)(?P<d>reg\s+\[\d+:\d+\]\s+\w+\s*\[\d+:\d+\]\s*;)", re.M)
# Per-signal multiply: any `assign LHS = ... * ... ;` OR `wire [W:0] LHS = ... * ... ;`.
# Operand char-class includes `{`/`}` so concatenations (`{...} * {...}`) match too.
MUL_RE    = re.compile(
    r"^(?P<i>[ \t]*)"
    r"(?P<d>(?:assign\s+\w+|wire\s+(?:\[\d+:\d+\]\s+)?\w+)"
    r"\s*=[^;]*[\w\)\]\}]\s*\*\s*[\w\(\[\{][^;]*;)",
    re.M,
)
SYNC_RE   = re.compile(r"^(?P<i>[ \t]*)(?P<d>reg\s+(?:\[\d+:\d+\]\s+)?sync_\w+\s*;)", re.M)
MODULE_RE = re.compile(r"^module\s+(\w+)\s*\(", re.M)
# Module decl start (for module-scope attribute injection above the line).
MODULE_DECL_RE = re.compile(r"(?P<head>^module\s+(?P<name>\w+)\s*\()", re.M)
MODULE_END_RE  = re.compile(r"^endmodule\b", re.M)
# Multiply operator anywhere in code text (after attribute/comment strip).
# Includes `{`/`}` for concatenation operands.
MULT_OP_RE = re.compile(r"[\w\)\]\}]\s*\*\s*[\w\(\[\{]")

# Tag name in attrs.json -> (declaration regex, Vivado attribute name).
TAGS = {
    "ram_style":         (RAM_RE,  "ram_style"),
    "rw_addr_collision": (RAM_RE,  "rw_addr_collision"),
    "use_dsp48":         (MUL_RE,  "use_dsp48"),
    "use_dsp":           (MUL_RE,  "use_dsp"),
    "async_reg":         (SYNC_RE, "ASYNC_REG"),
    "shreg_extract":     (SYNC_RE, "shreg_extract"),
    "srl_style":         (SYNC_RE, "srl_style"),
}


def attr_line(name: str, value: str) -> str:
    return f'(* {name} = "{value}" *) {MARKER}'


def prepend(text: str, regex: re.Pattern, name: str, value: str) -> tuple[str, int]:
    count = 0
    line  = attr_line(name, value)

    def repl(m):
        nonlocal count
        count += 1
        return f"{m.group('i')}{line}\n{m.group('i')}{m.group('d')}"

    return regex.sub(repl, text), count


def ram_dims(text: str):
    m = re.search(r"reg\s+\[(\d+):0\]\s+\w+\s*\[0:(\d+)\]", text)
    return (int(m.group(1)) + 1, int(m.group(2)) + 1) if m else None


def has_sync_read(text: str) -> bool:
    return "_r_addr_pipe_0" in text


def module_names(text: str) -> list[str]:
    return MODULE_RE.findall(text)


def matches_any(file_stem: str, modules: list[str], pattern: str) -> bool:
    return (fnmatch.fnmatch(file_stem, pattern)
            or any(fnmatch.fnmatch(m, pattern) for m in modules))


def strip_attrs_and_comments(s: str) -> str:
    """Remove (* ... *), // ... \\n, and /* ... */ so operator scans don't false-fire on attribute syntax."""
    s = re.sub(r"\(\*[^*]*\*\)", "", s)
    s = re.sub(r"//[^\n]*", "", s)
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.DOTALL)
    return s


def iter_modules(text: str):
    """Yield (name, decl_start_pos, body_text) for each module..endmodule pair."""
    decls = list(MODULE_DECL_RE.finditer(text))
    ends  = list(MODULE_END_RE.finditer(text))
    for d in decls:
        e = next((e for e in ends if e.start() > d.start()), None)
        if e is None:
            continue
        yield d.group("name"), d.start(), text[d.end():e.start()]


def inject_module_level(text: str, positions: list[int], line: str) -> str:
    """Insert `line` + newline above each position (sorted, applied left-to-right)."""
    if not positions:
        return text
    out, cursor = [], 0
    for pos in sorted(positions):
        out.append(text[cursor:pos])
        out.append(line + "\n")
        cursor = pos
    out.append(text[cursor:])
    return "".join(out)


def apply_category(text: str, cat_name: str, rules: dict,
                   file_stem: str, mods: list[str],
                   notes: list[str]) -> str:
    defaults = rules.get("defaults", {})

    # 1. Explicit module patterns — first match wins per category.
    explicit_hit = False
    for pat, spec in rules.get("modules", {}).items():
        if matches_any(file_stem, mods, pat):
            explicit_hit = True
            for tag, value in spec.items():
                if tag not in TAGS:
                    notes.append(f"[{cat_name}] unknown tag {tag!r}")
                    continue
                regex, vivado = TAGS[tag]
                text, n = prepend(text, regex, vivado, value)
                if n:
                    notes.append(f"[{cat_name}/{pat}] {tag}={value} x{n}")
            break

    # 2. Auto RAM — fires when no explicit pattern matched. Picks per-signal
    #    ram_style based on dims + read pattern.
    if not explicit_hit and defaults.get("auto_ram") and RAM_RE.search(text):
        dims = ram_dims(text)
        if dims:
            w, d = dims
            bits = w * d
            if not has_sync_read(text):
                style = "distributed"          # async read cannot map to BRAM
            elif bits >= defaults.get("bram_min_bits", 2048):
                style = "block"
            else:
                style = "auto"
            text, n = prepend(text, RAM_RE, "ram_style", style)
            if n:
                notes.append(f"[{cat_name}] auto ram_style={style} "
                             f"({w}x{d}={bits}b) x{n}")

    # 3. Auto DSP per-signal — tag every `assign|wire X = ... * ... ;`.
    #    Skipped when an explicit pattern hit so explicit opt-outs (e.g.
    #    Multiplier_4 use_dsp48="no") aren't shadowed by an auto "yes".
    if not explicit_hit and defaults.get("auto_dsp") and MUL_RE.search(text):
        text, n = prepend(text, MUL_RE, "use_dsp48", "yes")
        if n:
            notes.append(f"[{cat_name}] auto use_dsp48 x{n}")

    # 4. Auto DSP module-scope — for every module whose body contains `*`,
    #    inject `(* use_dsp48 = "yes" *)` above its module decl. Skipped
    #    when explicit pattern hit (same reason as #3).
    if not explicit_hit and defaults.get("auto_dsp_module"):
        scrubbed = strip_attrs_and_comments(text)
        # Re-scan from the cleaned text to get module bodies; positions match
        # because the substitutions all kept text length neutral or grew it.
        positions = []
        for name, start, body in iter_modules(scrubbed):
            if MULT_OP_RE.search(body):
                # find the corresponding position in `text` (module decl line)
                m = re.search(r"^module\s+" + re.escape(name) + r"\s*\(",
                              text, re.M)
                if m:
                    positions.append(m.start())
        if positions:
            line = attr_line("use_dsp48", "yes")
            text = inject_module_level(text, positions, line)
            notes.append(f"[{cat_name}] auto_dsp_module x{len(positions)}")

    # 5. Blanket DSP — inject `(* use_dsp48 = "yes" *)` above EVERY module
    #    decl regardless of body content. Vivado silently ignores the
    #    attribute on modules with no multiply structure, so this is safe
    #    but maximally aggressive.
    if defaults.get("module_all_dsp"):
        positions = [m.start() for m in MODULE_DECL_RE.finditer(text)]
        if positions:
            line = attr_line("use_dsp48", "yes")
            text = inject_module_level(text, positions, line)
            notes.append(f"[{cat_name}] module_all_dsp x{len(positions)}")

    # 6. Blanket RAM_STYLE — inject `(* ram_style = <value> *)` above EVERY
    #    module decl. Vivado ignores when no array is present, and falls
    #    back to distributed when "block" is incompatible (async-read, etc.)
    if defaults.get("module_all_ram"):
        style = defaults["module_all_ram"]
        positions = [m.start() for m in MODULE_DECL_RE.finditer(text)]
        if positions:
            line = attr_line("ram_style", style)
            text = inject_module_level(text, positions, line)
            notes.append(f"[{cat_name}] module_all_ram={style} x{len(positions)}")

    return text


def main():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--collateral", required=True, type=Path,
                    help="path to gen-collateral directory")
    ap.add_argument("--config", required=True, type=Path,
                    help="path to attrs.json")
    ap.add_argument("--only", default="all",
                    help="comma-separated categories | 'all' | 'none'")
    ap.add_argument("--dry-run", action="store_true",
                    help="report changes without modifying files")
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args()

    if not args.collateral.is_dir():
        sys.exit(f"error: {args.collateral} is not a directory")

    cfg = json.loads(args.config.read_text())
    categories = {k: v for k, v in cfg.get("categories", {}).items()
                  if not k.startswith("_")}
    real_cats = set(categories.keys())

    selected = {s.strip() for s in args.only.split(",") if s.strip()}
    if "none" in selected:
        enabled = set()
    elif "all" in selected:
        enabled = real_cats
    else:
        unknown = selected - real_cats
        if unknown:
            sys.exit(f"error: unknown categories {sorted(unknown)} "
                     f"(known: {sorted(real_cats)})")
        enabled = selected

    print(f"inject_resource_attrs: --only={args.only}  "
          f"enabled={sorted(enabled) or 'none'}")

    touched = 0
    for path in sorted(args.collateral.iterdir()):
        if path.suffix not in (".sv", ".v"):
            continue
        original = path.read_text()
        text     = INJ_RE.sub("", original)              # strip prior
        notes: list[str] = []
        mods = module_names(text)
        for cat_name, rules in categories.items():
            if cat_name in enabled:
                text = apply_category(text, cat_name, rules,
                                      path.stem, mods, notes)
        if text != original:
            touched += 1
            if not args.quiet:
                summary = " | ".join(notes) if notes else "stripped"
                print(f"  {path.name:55s} {summary}")
            if not args.dry_run:
                path.write_text(text)

    suffix = " (dry-run)" if args.dry_run else ""
    print(f"{touched} file(s) modified{suffix}")


if __name__ == "__main__":
    main()
