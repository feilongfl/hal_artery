#!/usr/bin/env python

from black import out
import yaml
import csv
import argparse
from collections import OrderedDict
from pathlib import Path

REPO_ROOT = Path(__file__).absolute().parents[2]


def get_afid(id: int):
    if(id == 16):
        return "ANALOG"

    return id


def build_afpins(csvfile):
    pins = {}

    with open(csvfile, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',')
        for row in spamreader:
            if(row[0][0] != "P"):
                continue

            print(', '.join(row))
            for id, cell in enumerate(row[1:18]):
                if(cell == ""):
                    continue

                for func in str.split(cell, " "):
                    print("%s-%d: %s -> %s" % (row[0], id, cell, func))
                    try:
                        pins[str(row[0])]['afs'][func] = get_afid(id)
                    except:
                        pins[str(row[0])] = {'pincodes': [
                            'G', 'K', 'C', 'R'], 'afs': {func: get_afid(id)}}

    return pins


def main(indir, outdir) -> None:
    """Entry point.

    Args:
        indir: Directory with pin data files.
        outdir: Directory with pin configuration files.
    """
    if not outdir.exists():
        raise ValueError("Output Folder Not Exists.")
        return

    for entry in indir.iterdir():
        if not entry.is_file() or entry.suffix not in (".csv"):
            continue

        ymlpath = outdir / (entry.stem + ".yml")
        ymldbgpath = outdir / (entry.stem + "dbg.yml")
        print("process: %s => %s" % (entry, ymlpath))
        config = yaml.load(open(ymlpath), Loader=yaml.Loader)
        model = config["model"]
        if model == "af":
            config["pins"] = build_afpins(entry)
            pass
        else:
            pass  # ignore unsupport format

        with open(ymldbgpath, 'w') as outfile:
            yaml.dump(config, outfile)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-i",
        "--indir",
        type=Path,
        default=REPO_ROOT / "pindatas",
        help="Directory with pin data files",
    )
    parser.add_argument(
        "-o",
        "--outdir",
        type=Path,
        default=REPO_ROOT / "pinconfigs",
        help="Directory with pin configuration files",
    )
    args = parser.parse_args()

    main(args.indir, args.outdir)
