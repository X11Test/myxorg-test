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

exe_mc = executable(
  'mc',
  [
    'main.c', 'sections.c', 'files.c', 'shortname.c', 'error.c',
    'gccomps.c', 'set.c', 'expand.c', 'code.c', 'make.c', 'ma.c',
    'cond.c', 'mas.c',
  ],
  # Not safe to be used as a subproject because of source_root()
  c_args : ['-DBUILD_TET_ROOT="@0@"'.format(meson.source_root())],
  include_directories : [inc_include, inc_tet3, inc_xts5],
  native : true,
)

gen_mc = generator(
  exe_mc,
  output : '@PLAINNAME@.c',
  arguments : ['@EXTRA_ARGS@', '-o', '@OUTPUT@', '@INPUT@'],
)
