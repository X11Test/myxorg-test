#!/usr/bin/env python3
# Copyright © 2019 Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

"""Fix the name of install test binaries.

XTS expects to have many test files called TestN (where N is a number),
however meson has a limitation that a no two targets may have the same name,
even if they will not conflict at install time. This script fixes that in the
install directory by removing the prefix and reducing the test from
${name}_TestN to TestN.
"""

import argparse
import os
import shutil

PREFIX = os.environ['MESON_INSTALL_DESTDIR_PREFIX']


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('install_dir')
    parser.add_argument('filenames', nargs='*')
    args = parser.parse_args()

    for f in args.filenames:
        filename = os.path.basename(f)
        new_filename = filename.split('_')[1]
        shutil.move(os.path.join(PREFIX, args.install_dir, filename),
                    os.path.join(PREFIX, args.install_dir, new_filename))


if __name__ == "__main__":
    main()
