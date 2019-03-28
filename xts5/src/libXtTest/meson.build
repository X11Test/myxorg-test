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

libxttest = static_library(
  'XtTest',
  [
    'avs_def.c', 'avs_func.c', 'avs_hier.c', 'avs_hierd.c', 'avs_init.c',
    'avs_tree.c', 'avs_widget.c', 'avs_xext.c', 'AvsComp.c', 'AvsComp2.c',
    'AvsForm.c', 'AvsForm2.c', 'AvsForm3.c', 'AvsRectObj.c', 'AvsWid.c',
    'AvsObj.c', 'check.c', 'eventname.c', 'sendevent.c', 'sendmask.c',
    'xhandler.c', 'xthandler.c', 'xunexperr.c', 'errlook.c', 'event.c',
    'misc.c', 'pshpop.c', 'signals.c', 'waitfor.c',
  ],
  include_directories : [inc_include, inc_tet3, inc_xts5],
  dependencies : [deps_xt_args],
)
