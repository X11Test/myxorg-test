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

files_libxst = files(
  'ShowReq.c',
  'ShowExtReq.c',
  'SendReq.c',
  'SendXIReq.c',
  'SendEvt.c',
  'ShowRep.c',
  'ShowExtRep.c',
  'MakeReq.c',
  'MakeXIReq.c',
  'RcvRep.c',
  'RcvExtRep.c',
  'RcvEvt.c',
  'RcvExtEvt.c',
  'RcvErr.c',
  'RcvExtErr.c',
  'ShowEvt.c',
  'ShowExtEvt.c',
  'ShowErr.c',
  'ShowExtErr.c',
  'DfltVals.c',
  'ResMng.c',
  'Log.c',
  'ClientMng.c',
  'ConnDis.c',
  'x11_trans.c',
  'Expect.c',
  'XlibXtst.c',  # autotools has a variable for this, but if you have that old of an XServer...
  'ValListMng.c',
  'Timer.c',
  'XstIO.c',
  'DataMove.c',
  'TestMng.c',
  'Utils.c',
  'SendSup.c',
  'ShowSup.c',
  'TestSup.c',
  'Validate.c',
  'tpstartup.c',
  'startup.c',
  'delete.c',
)

libxst = static_library(
  'Xst',
  files_libxst,
  include_directories : [inc_include, inc_tet3, inc_xts5],
  dependencies : [deps_xts_args, deps_xt_args],
)
