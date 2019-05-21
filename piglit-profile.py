#!/usr/bin/python3
# Copyright © 2019 Intel Corporation

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

"""Script to build an Piglit compatible XML profile."""


import argparse
import gzip
import itertools
import os
import xml.etree.ElementTree as ET

ENV = ET.Element('environment')
ET.SubElement(ENV, 'env', name='XT_RESET_DELAY', value='0')
ET.SubElement(ENV, 'env', name='XT_FONTPATH_GOOD', value='/usr/share/fonts/X11/misc')
ET.SubElement(ENV, 'env', name='XT_LOCAL', value='Yes')
ET.SubElement(ENV, 'env', name='XT_TCP', value='No')
ET.SubElement(ENV, 'env', name='XT_DISPLAYHOST', value='')


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('source_root')
    parser.add_argument('install_dir', help='the absolute path that test binaries are installed into')
    parser.add_argument('outfile')
    args = parser.parse_args()

    tests = []

    for dirpath, _, filenames in os.walk(os.path.join(args.source_root, 'xts5')):
        for fname in filenames:
            testname, ext = os.path.splitext(fname)
            if ext != '.m':
                continue

            counts = itertools.count(start=1)
            with open(os.path.join(dirpath, fname), 'r') as f:
                for line in f:
                    if line.startswith('>>ASSERTION'):
                        reldir = os.path.relpath(dirpath, args.source_root)
                        num = next(counts)
                        group = '@'.join(reldir.split(os.path.sep))
                        # OSes like windows that have two path separators
                        if os.path.altsep:
                            group = '@'.join(reldir.split(os.path.altsep))
                        group = '@'.join([group, testname, str(num)])

                        tests.append((group, {
                            'command': ['./{}'.format(os.path.basename(os.path.join(dirpath, testname))), '-i', str(num)],
                            'testname': '{}-{}'.format(testname, num),
                            'testdir': os.path.relpath(dirpath, args.source_root),
                            'run_concurrent': False,
                            'cwd': os.path.join(args.install_dir, reldir)
                        }))

    root = ET.Element('TestProfile', count=str(len(tests)), name='xts')
    for t in tests:
        test = ET.SubElement(root, 'Test', name=t[0], type='xts')
        for k, v in t[1].items():
            ET.SubElement(test, 'option', name=k, value=repr(v))
        test.append(ENV)

    tree = ET.ElementTree(root)
    with gzip.open(args.outfile, 'wb') as f:
        tree.write(f, encoding='utf-8')


if __name__ == '__main__':
    main()
