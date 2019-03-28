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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xt9')

# tuple in the form [name, in_subdir, extra_sources]
_test_progs = [
  ['XtAddEventHandler', false, []],
  ['XtAddGrab', false, []],
  ['XtAddRawEventHandler', false, []],
  ['XtAppAddInput', false, []],
  ['XtAppAddTimeOut', false, []],
  ['XtAppAddWorkProc', false, []],
  ['XtAppMainLoop', false, []],
  ['XtAppNextEvent', false, []],
  ['XtAppPeekEvent', false, []],
  ['XtAppPending', false, []],
  ['XtAppProcessEvent', false, []],
  ['XtBuildEventMask', false, []],
  ['XtCallAcceptFocus', true, ['tcalafocs2.c']],
  ['XtDispatchEvent', false, []],
  ['XtGrabButton', false, []],
  ['XtGrabKeyboard', false, []],
  ['XtGrabKey', false, []],
  ['XtGrabPointer', false, []],
  ['XtInsertEventHandler', false, []],
  ['XtInsertRawEventHandler', false, []],
  ['XtIsSensitive', false, []],
  ['XtRemoveEventHandler', false, []],
  ['XtRemoveGrab', false, []],
  ['XtRemoveInput', true, []],
  ['XtRemoveRawEventHandler', false, []],
  ['XtRemoveTimeOut', false, []],
  ['XtRemoveWorkProc', false, []],
  ['XtSetKeyboardFocus', false, []],
  ['XtSetSensitive', false, []],
  ['XtUngrabButton', false, []],
  ['XtUngrabKeyboard', false, []],
  ['XtUngrabKey', false, []],
  ['XtUngrabPointer', false, []],
]

foreach t : _test_progs
  if t[1]
    _source = join_paths(t[0], t[0])
    _install = join_paths(_install_dir, t[0])
    _extra_src = []
    foreach s : t[2]
      _extra_src += join_paths(t[0], s)
    endforeach
  else
    _source = t[0]
    _install = _install_dir
    _extra_src = t[2]
  endif
  executable(
    t[0],
    [gen_mc.process(_source + '.m'), _extra_src],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s, libxttest, libxtaw],
    dependencies : [deps_xaw, idep_tcmmain],
    install_rpath : '..',
    install_dir : _install,
    install : true,
  )
endforeach

install_data(
  'XtRemoveInput/trminput.dat',
  install_dir : join_paths(_install_dir, 'XtRemoveInput'),
)
