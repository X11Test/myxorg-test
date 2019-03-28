# Copyright © 2019 Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# on the rights to use, copy, modify, merge, publish, distribute, sub
# license, and/or sell copies of the Software, and to permit persons to whom
# the Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
# ADAM JACKSON BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

files_libxtest = files(
  'badcmap.c',
  'badfont.c',
  'badgc.c',
  'badpixm.c',
  'badvis.c',
  'badwin.c',
  'bitcount.c',
  'block.c',
  'buildtree.c',
  'checkarea.c',
  'checkevent.c',
  'checkfont.c',
  'checkgc.c',
  'checkimg.c',
  'checkpixel.c',
  'checktile.c',
  'config.c',
  'crechild.c',
  'cursor.c',
  'delete.c',
  'devcntl.c',
  'dset.c',
  'dumpimage.c',
  'environ.c',
  'err.c',
  'events.c',
  'exposechk.c',
  'ex_startup.c',
  'extenavail.c',
  'gcflush.c',
  'gcinclude.c',
  'getevent.c',
  'getsize.c',
  'gettime.c',
  'iponlywin.c',
  'issuppvis.c',
  'lookupname.c',
  'makecolmap.c',
  'makecur.c',
  'makegc.c',
  'makeimg.c',
  'makepixm.c',
  'makeregion.c',
  'makewin2.c',
  'makewin.c',
  'maxsize.c',
  'nextvclass.c',
  'nextvinf.c',
  'nondpth1pix.c',
  'notmember.c',
  'opendisp.c',
  'openfonts.c',
  'outfile.c',
  'pattern.c',
  'pfcount.c',
  'pointer.c',
  'regid.c',
  'report.c',
  'rpt.c',
  'savimage.c',
  'setline.c',
  'settimeout.c',
  'stackorder.c',
  'startcall.c',
  'startup.c',
  'tpstartup.c',
  'verimage.c',
  'winh.c',
  'XInput.c',
  'XTestExt.c',
  'xthost.c',
)

libxtest = static_library(
  'xtest',
  files_libxtest,
  include_directories : [inc_include, inc_tet3, inc_xts5],
)
