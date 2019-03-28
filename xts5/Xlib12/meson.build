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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib12')

_test_progs = [
  'XCheckIfEvent',
  'XCheckMaskEvent',
  'XCheckTypedEvent',
  'XCheckTypedWindowEvent',
  'XCheckWindowEvent',
  'XDisplayMotionBufferSize',
  'XEventsQueued',
  'XFlush',
  'XGetErrorDatabaseText',
  'XGetErrorText',
  'XGetMotionEvents',
  'XIfEvent',
  'XMaskEvent',
  'XNextEvent',
  'XPeekEvent',
  'XPeekIfEvent',
  'XPending',
  'XPutBackEvent',
  'XSelectInput',
  'XSendEvent',
  'XSetAfterFunction',
  'XSetErrorHandler',
  'XSetIOErrorHandler',
  'XSync',
  'XSynchronize',
  'XWindowEvent',
]

foreach t : _test_progs
  executable(
    t,
    [gen_mc.process(t + '.m')],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s, libxr5],
    dependencies : [deps_xts, idep_tcmmain],
    install_rpath : '..',
    install_dir : _install_dir,
    install : true,
  )
endforeach

subdir('XDisplayName')
