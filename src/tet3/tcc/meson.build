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

exe_tcc = executable(
  'tcc',
  [
    'cleanup.c',
    'config.c',
    'copysave.c',
    'dirtab.c',
    'dtcc.c',
    'environ.c',
    'error.c',
    'exec.c',
    'fake.c',
    'global.c',
    'jnlproc.c',
    'journal.c',
    'keys.c',
    'lock.c',
    'procdir.c',
    'proctab.c',
    'proctc.c',
    'proctcd.c',
    'rescode.c',
    'resdir.c',
    'rrproc.c',
    'scen1.c',
    'scen2.c',
    'scen3.c',
    'scenario.c',
    'scentab.c',
    'service.c',
    'sigtrap.c',
    'syscall.c',
    'systab.c',
    'tcc.c',
    'tcname.c',
    'tool.c',
    'utils.c',
    'ynstr.c',
  ],
  include_directories : [inc_tet3, inc_include],
  link_with : [libtcc],
  install : true,
)
