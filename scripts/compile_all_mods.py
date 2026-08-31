#!/usr/bin/env python3
"""Compile NEURON .mod files in every lesson folder that ships mechanisms."""

from __future__ import annotations

import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# (working directory for nrnivmodl, argument passed to nrnivmodl)
MOD_JOBS = [
    (ROOT / "Lesson-1-What-is-Fear", "modfiles"),
    (ROOT / "Lesson-2-How-do-Tone-Shock-pair", "modfiles"),
    (ROOT / "Lesson-3-How-Ca-impacts-learning", "modfiles"),
    (ROOT / "Lesson-4-1.4", "modfiles"),
    (ROOT / "Lesson-5-D2", "modfiles"),
    (ROOT / "Lesson-7-12-Cell" / "biophys_components" / "mechanisms", "modfiles"),
]

BUILD_DIR_NAMES = ("x86_64", "arm64", "aarch64")


def clear_build_dirs(directory: Path) -> None:
    for name in BUILD_DIR_NAMES:
        build_dir = directory / name
        if build_dir.is_dir():
            shutil.rmtree(build_dir)
            print(f"  removed {build_dir.relative_to(ROOT)}")


def compile_mods(directory: Path, mod_arg: str) -> int:
    print(f"\n=== {directory.relative_to(ROOT)} ({mod_arg}) ===")
    if not directory.is_dir():
        print("  ERROR: directory missing")
        return 1

    mod_dir = directory / mod_arg
    if not mod_dir.is_dir():
        print(f"  ERROR: {mod_arg} directory missing")
        return 1
    if not any(mod_dir.glob("*.mod")):
        print(f"  ERROR: no .mod files found in {mod_arg}")
        return 1

    clear_build_dirs(directory)
    result = subprocess.run(
        ["nrnivmodl", mod_arg],
        cwd=directory,
        capture_output=True,
        text=True,
    )
    if result.stdout.strip():
        print(result.stdout.rstrip())
    if result.returncode != 0:
        if result.stderr.strip():
            print(result.stderr.rstrip(), file=sys.stderr)
        print(f"  FAILED (return code {result.returncode})")
        return result.returncode

    print("  OK")
    return 0


def main() -> int:
    failures: list[str] = []
    for directory, mod_arg in MOD_JOBS:
        code = compile_mods(directory, mod_arg)
        if code != 0:
            failures.append(str(directory.relative_to(ROOT)))

    print()
    if failures:
        print("Compilation failed in:")
        for path in failures:
            print(f"  - {path}")
        return 1

    print("All mechanism folders compiled successfully.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
