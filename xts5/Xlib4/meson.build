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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib4')

# tuples in the form [name, in_subdir]
_test_progs = [
  ['XChangeWindowAttributes', true],
  ['XConfigureWindow', true],
  ['XCirculateSubwindows', true],
  ['XCirculateSubwindowsDown', true],
  ['XCirculateSubwindowsUp', true],
  ['XCreateSimpleWindow', true],
  ['XCreateWindow', true],
  ['XDefineCursor', false],
  ['XDestroySubwindows', false],
  ['XDestroyWindow', false],
  ['XLowerWindow', true],
  ['XMapRaised', true],
  ['XMapSubwindows', true],
  ['XMapWindow', true],
  ['XMoveResizeWindow', true],
  ['XMoveWindow', false],
  ['XRestackWindows', true],
  ['XRaiseWindow', true],
  ['XResizeWindow', true],
  ['XSetWindowBackground', false],
  ['XSetWindowBackgroundPixmap', false],
  ['XSetWindowBorder', false],
  ['XSetWindowBorderPixmap', true],
  ['XSetWindowBorderWidth', true],
  ['XSetWindowColormap', false],
  ['XUndefineCursor', false],
  ['XUnmapSubwindows', false],
  ['XUnmapWindow', false],
  ['XVisualIDFromVisual', false],
]

foreach t : _test_progs
  if t[1]
    _source = join_paths(t[0], t[0])
    _install = join_paths(_install_dir, t[0])
  else
    _source = t[0]
    _install = _install_dir
  endif
  executable(
    t[0],
    [gen_mc.process(_source + '.m')],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s],
    dependencies : [deps_xts, idep_tcmmain],
    install_rpath : '..',
    install_dir : _install,
    install : true,
  )
endforeach

foreach x : [['XChangeWindowAttributes', ['a2.dat', 'a3.dat', 'a13.dat', 'a17.dat']],
             ['XCirculateSubwindows', ['a1.dat', 'a2.dat']],
             ['XCirculateSubwindowsDown', ['a1.dat']],
             ['XCirculateSubwindowsUp', ['a1.dat']],
             ['XConfigureWindow', ['a3.dat', 'a6.dat', 'a7.dat', 'a8.dat', 'a9.dat', 'a10.dat', 'a11.dat', 'a12.dat', 'a13.dat', 'a14.dat', 'a15.dat', 'a16.dat', 'a17.dat', 'a18.dat', 'a19.dat']],
             ['XCreateSimpleWindow', ['a4.dat']],
             ['XCreateWindow', ['a11.dat', 'a15.dat']],
             ['XLowerWindow', ['a1.dat']],
             ['XMapRaised', ['a1.dat', 'a4.dat']],
             ['XMapSubwindows', ['a1.dat']],
             ['XMapWindow', ['a4.dat']],
             ['XMoveResizeWindow', ['a2.dat']],
             ['XRaiseWindow', ['a1.dat']],
             ['XResizeWindow', ['a2.dat']],
             ['XRestackWindows', ['a1.dat', 'a2.dat', 'a3.dat']],
             ['XSetWindowBorderPixmap', ['a1.dat', 'a2.dat', 'a3.dat']],
             ['XSetWindowBorderWidth', ['a1.dat']]]
  d = x[0]
  files = []
  foreach f : x[1]
    file = join_paths(d, f)
    install_data(
      file,
      install_mode : ['r--r--r--'],
      install_dir : join_paths(_install_dir, d),
    )
  endforeach
endforeach
