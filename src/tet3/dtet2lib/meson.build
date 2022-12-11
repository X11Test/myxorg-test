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

files_libdtet2 = files(
  'addarg.c',
  'alarm.c',
  'amsg.c',
  'avmsg.c',
  'basename.c',
  'btmsg.c',
  'bufchk.c',
  'buftrace.c',
  'dtmsg.c',
  'dtsize.c',
  'eaccess.c',
  'equindex.c',
  'errmap.c',
  'errname.c',
  'fappend.c',
  'fcopy.c',
  'fgetargs.c',
  'fioclex.c',
  'fork.c',
  'ftoa.c',
  'generror.c',
  'genfatal.c',
  'getargs.c',
  'getcwd.c',
  'getopt.c',
  'globals.c',
  'hexdump.c',
  'iswin.c',
  'ldst.c',
  'llist.c',
  'ltoa.c',
  'ltoo.c',
  'ltox.c',
  'madir.c',
  'maperr.c',
  'mapsig.c',
  'mapstat.c',
  'mkdir.c',
  'optarg.c',
  'prerror.c',
  'ptflags.c',
  'ptspid.c',
  'ptstate.c',
  'ptstype.c',
  'pttype.c',
  'ptype.c',
  'putenv.c',
  'remvar.c',
  'repcode.c',
  'reqcode.c',
  'rescode.c',
  'rtoa.c',
  'sigmap.c',
  'sigsafe.c',
  'strstore.c',
  'svote.c',
  'sysbyid.c',
  'sysent.c',
  'systate.c',
  'targs.c',
  'tdump.c',
  'tetdir.c',
  'tetfcntl.c',
  'tetsleep.c',
  'tetspawn.c',
  'tetstat.c',
  'tetterm.c',
  'tetunlnk.c',
  'tfname.c',
  'trace.c',
  'unmaperr.c',
  'unmapsig.c',
  'valmsg.c',
  'w32err.c',
  'wait3.c',
  'wsaerr.c',
)

libdtet2 = static_library(
  'dtet2',
  files_libdtet2,
  include_directories : [inc_include, inc_tet3],
)
