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

libtcm_s = static_library(
  'tcm_s',
  ['ictp.c'],
  include_directories : [inc_include, inc_tet3],
)

libtcm = static_library(
  'tcm',
  ['child.c', 'ckversion.c', 'dynlink.c', 'tcmfuncs.c'],
  include_directories : [inc_include, inc_tet3],
)

# Don't link either of these directly, as you also need libapi. Instad
# use the idep versions that already do that for you:
# idep_tccmain and idep_tcmchild
libtcmmain = static_library(
  'tcmmain',
  ['tcm.c', 'dtcm.c'],
  include_directories : [inc_include, inc_tet3],
)

libtcmchild = static_library(
  'tcmchild',
  ['tcmchild.c'],
  include_directories : [inc_include, inc_tet3],
)
