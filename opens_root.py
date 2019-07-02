#!/usr/bin/env python
"""Inspect ROOT files."""
from __future__ import print_function

import argparse
import sys

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('files', metavar='file', nargs='+',
                    help='ROOT file to inspect (ending in .root)')
parser.add_argument('-v', '--verbose', action='store_true',
                    help='Log more startup information')
args = parser.parse_args()

import logging as log

import ROOT

if args.verbose:
    log.getLogger().setLevel(log.INFO)

nfailed = 0
for i, fname in enumerate(args.files):
    gname = 'f{0}'.format(i)
    tfile = ROOT.TFile(fname)
    if not tfile.IsZombie():
        # Print this, rather than log it, so users know what the file's called
        print('Loaded {0!r} as {1!r}'.format(fname, gname))
        globals()[gname] = ROOT.TFile(fname)
    else:
        print('Could not load file {0!r}'.format(fname))
        nfailed += 1

if nfailed == len(args.files):
    print('Could not load any input files, exiting')
    sys.exit(1)

_tbrowser = ROOT.TBrowser()

try:
    from IPython import embed
    embed(display_banner=False)
except ImportError:
    log.error('Could not load IPython shell, falling back to Python shell')
    # Taken from http://stackoverflow.com/a/5597918/596068
    import readline  # noqa
    import code
    vars = globals().copy()
    vars.update(locals())
    shell = code.InteractiveConsole(vars)
shell.interact(banner='')
