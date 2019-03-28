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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib14')

# tuple in the form [name, in_subdir]
_test_progs = [
  ['XBaseFontNameListOfFontSet', false],
  ['XCloseIM', false],
  ['XContextDependentDrawing', false],
  ['XCreateFontSet', false],
  ['XCreateIC', false],
  ['XDestroyIC', false],
  ['XDisplayOfIM', false],
  ['XExtentsOfFontSet', false],
  ['XFilterEvent', false],
  ['XFontsOfFontSet', false],
  ['XFreeFontSet', false],
  ['XGetICValues', false],
  ['XGetIMValues', false],
  ['XIMOfIC', false],
  ['XLocaleOfFontSet', false],
  ['XLocaleOfIM', false],
  ['XmbDrawImageString', true],
  ['XmbDrawString', true],
  ['XmbDrawText', true],
  ['XmbLookupString', false],
  ['XmbResetIC', false],
  ['XmbSetWMProperties', false],
  ['XmbTextEscapement', false],
  ['XmbTextExtents', false],
  ['XmbTextListToTextProperty', false],
  ['XmbTextPerCharExtents', false],
  ['XmbTextPropertyToTextList', false],
  ['XOpenIM', false],
  ['XSetICFocus', false],
  ['XSetICValues', false],
  ['XSupportsLocale', false],
  ['XSetLocaleModifiers', false],
  ['XUnsetICFocus', false],
  ['XVaCreateNestedList', false],
  ['XwcDrawImageString', true],
  ['XwcDrawString', true],
  ['XwcDrawText', true],
  ['XwcFreeStringList', false],
  ['XwcLookupString', false],
  ['XwcResetIC', false],
  ['XwcTextEscapement', false],
  ['XwcTextListToTextProperty', false],
  ['XwcTextPerCharExtents', false],
  ['XwcTextPropertyToTextList', false],
  ['XwcTextExtents', false],
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
    link_with : [libxts5, libapi_s, libxr5],
    dependencies : [deps_xts, idep_tcmmain],
    install_rpath : join_paths(get_option('prefix'), get_option('libexecdir'), 'xts5'),
    install_dir : _install,
    install : true,
  )
endforeach

foreach d : ['XmbDrawImageString', 'XmbDrawString', 'XmbDrawText', 'XwcDrawImageString', 'XwcDrawString', 'XwcDrawText']
  install_data(
    join_paths(d, 'a1.C.dat'),
    join_paths(d, 'a1.ko.dat'),
    install_mode : ['r--r--r--'],
    install_dir : join_paths(_install_dir, d),
  )
endforeach
