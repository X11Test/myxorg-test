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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xt13')

# tuple in the form [name, in_subdir]
_test_progs = [
  ['XtAddExposureToRegion', false],
  ['XtAllocateGC', false],
  ['XtAppError', false],
  ['XtAppErrorMsg', false],
  ['XtAppGetErrorDatabase', false],
  ['XtAppGetErrorDatabaseText', false],
  ['XtAppGetSelectionTimeout', false],
  ['XtAppSetErrorHandler', false],
  ['XtAppSetErrorMsgHandler', false],
  ['XtAppSetSelectionTimeout', false],
  ['XtAppSetWarningHandler', false],
  ['XtAppSetWarningMsgHandler', false],
  ['XtAppWarning', false],
  ['XtAppWarningMsg', false],
  ['XtCalloc', false],
  ['XtDisownSelection', false],
  ['XtFindFile', true],
  ['XtFree', false],
  ['XtGetApplicationNameAndClass', false],
  ['XtGetGC', false],
  ['XtGetSelectionRequest', false],
  ['XtGetSelectionValueIncremental', false],
  ['XtGetSelectionValue', false],
  ['XtGetSelectionValuesIncremental', false],
  ['XtGetSelectionValues', false],
  ['XtLastTimestampProcessed', false],
  ['XtMalloc', false],
  ['XtNameToWidget', false],
  ['XtNew', false],
  ['XtNewString', false],
  ['XtNumber', false],
  ['XtOwnSelectionIncremental', false],
  ['XtOwnSelection', false],
  ['XtRealloc', false],
  ['XtReleaseGC', false],
  ['XtResolvePathname', true],
  ['XtSetWMColormapWindows', false],
  ['XtTranslateCoords', false],
  ['XtWindowToWidget', false],
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
    link_with : [libxts5, libapi_s, libxttest, libxtaw],
    dependencies : [deps_xaw, idep_tcmmain],
    install_rpath : '..',
    install_dir : _install,
    install : true,
  )
endforeach

install_data(
  'XtFindFile/data1',
  install_dir : join_paths(_install_dir, 'XtFindFile'),
)
install_data(
  'XtResolvePathname/data1',
  install_dir : join_paths(_install_dir, 'XtResolvePathname'),
)
