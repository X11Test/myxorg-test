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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib9')

# tuple in the form [name, in_subdir]
_test_progs = [
  ['XClearArea', false],
  ['XClearWindow', false],
  ['XCopyArea', true],
  ['XCopyPlane', true],
  ['XDrawArc', true],
  ['XDrawArcs', true],
  ['XDrawImageString16', true],
  ['XDrawImageString', true],
  ['XDrawLine', true],
  ['XDrawLines', true],
  ['XDrawPoint', true],
  ['XDrawPoints', true],
  ['XDrawRectangle', true],
  ['XDrawRectangles', true],
  ['XDrawSegments', true],
  ['XDrawString', true],
  ['XDrawString16', true],
  ['XDrawText', true],
  ['XDrawText16', true],
  ['XFillArc', true],
  ['XFillArcs', true],
  ['XFillPolygon', true],
  ['XFillRectangle', true],
  ['XFillRectangles', true],
  ['XFreeFont', false],
  ['XFreeFontInfo', false],
  ['XFreeFontNames', false],
  ['XFreeFontPath', false],
  ['XGetFontProperty', false],
  ['XGetFontPath', false],
  ['XGetImage', false],
  ['XGetSubImage', false],
  ['XLoadFont', true],
  ['XLoadQueryFont', true],
  ['XListFonts', false],
  ['XListFontsWithInfo', false],
  ['XPutImage', true],
  ['XQueryFont', false],
  ['XQueryTextExtents16', false],
  ['XQueryTextExtents', false],
  ['XSetFontPath', false],
  ['XTextExtents16', false],
  ['XTextExtents', false],
  ['XTextWidth', false],
  ['XTextWidth16', false],
  ['XUnloadFont', false],
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

foreach x : [['XCopyArea', ['a27.dat', 'a30.dat']],
             ['XDrawArc', ['a1.dat', 'a5.dat', 'a6.dat', 'a34.dat', 'a42.dat', 'a49.dat', 'a50.dat', 'a51.dat', 'a52.dat', 'a53.dat', 'a54.dat', 'a55.dat', 'a64.dat', 'a66.dat', 'a68.dat', 'a73.dat', 'a76.dat', 'a77.dat', 'a78.dat', 'a79.dat', 'a83.dat', 'a86.dat', 'a88.dat', 'a90.dat', 'a92.dat', 'a93.dat', 'a94.dat', 'a95.dat']],
             ['XDrawArcs', ['a1.dat', 'a5.dat', 'a6.dat', 'a7.dat', 'a12.dat','a37.dat', 'a45.dat', 'a52.dat', 'a53.dat', 'a54.dat', 'a55.dat', 'a56.dat', 'a57.dat', 'a58.dat','a67.dat', 'a69.dat', 'a71.dat', 'a76.dat', 'a79.dat', 'a80.dat', 'a81.dat', 'a82.dat', 'a86.dat', 'a87.dat', 'a88.dat', 'a89.dat', 'a93.dat', 'a96.dat', 'a98.dat', 'a100.dat', 'a102.dat', 'a103.dat', 'a104.dat', 'a105.dat']],
             ['XDrawImageString', ['a1.dat', 'a3.dat', 'a11.dat', 'a14.dat', 'a16.dat', 'a18.dat']],
             ['XDrawImageString16', ['a1.dat', 'a3.dat', 'a11.dat', 'a14.dat', 'a16.dat', 'a18.dat']],
             ['XDrawLine', ['a1.dat', 'a2.dat', 'a3.dat', 'a4.dat', 'a23.dat', 'a31.dat', 'a38.dat', 'a39.dat', 'a40.dat', 'a41.dat', 'a42.dat', 'a43.dat', 'a44.dat', 'a53.dat', 'a55.dat', 'a57.dat', 'a62.dat', 'a65.dat', 'a66.dat', 'a67.dat', 'a68.dat', 'a72.dat', 'a75.dat', 'a77.dat', 'a79.dat', 'a81.dat', 'a82.dat', 'a83.dat', 'a84.dat']],
             ['XDrawLines', ['a1.dat', 'a3.dat', 'a4.dat', 'a5.dat', 'a7.dat', 'a9.dat', 'a28.dat', 'a36.dat', 'a43.dat', 'a44.dat', 'a45.dat', 'a46.dat', 'a47.dat', 'a48.dat', 'a49.dat', 'a58.dat', 'a60.dat', 'a62.dat', 'a67.dat', 'a70.dat', 'a71.dat', 'a72.dat', 'a73.dat', 'a77.dat', 'a78.dat', 'a79.dat', 'a80.dat', 'a81.dat', 'a87.dat', 'a89.dat', 'a91.dat', 'a93.dat', 'a94.dat', 'a95.dat', 'a96.dat']],
             ['XDrawPoint', ['a20.dat', 'a25.dat', 'a28.dat']],
             ['XDrawPoints', ['a1.dat', 'a3.dat', 'a23.dat', 'a28.dat', 'a31.dat']],
             ['XDrawRectangle', ['a1.dat', 'a4.dat', 'a23.dat', 'a31.dat', 'a38.dat', 'a39.dat', 'a40.dat', 'a41.dat', 'a42.dat', 'a43.dat', 'a44.dat', 'a50.dat', 'a51.dat', 'a52.dat', 'a53.dat', 'a54.dat', 'a57.dat', 'a58.dat', 'a59.dat', 'a60.dat', 'a64.dat', 'a67.dat', 'a69.dat', 'a71.dat', 'a73.dat', 'a74.dat', 'a75.dat', 'a76.dat']],
             ['XDrawRectangles', ['a1.dat', 'a5.dat', 'a6.dat', 'a25.dat', 'a33.dat', 'a40.dat', 'a41.dat', 'a42.dat', 'a43.dat', 'a44.dat', 'a45.dat', 'a46.dat', 'a52.dat', 'a53.dat', 'a54.dat', 'a55.dat', 'a56.dat', 'a59.dat', 'a60.dat', 'a61.dat', 'a62.dat', 'a66.dat', 'a69.dat', 'a71.dat', 'a73.dat', 'a75.dat', 'a76.dat', 'a77.dat', 'a78.dat']],
             ['XDrawSegments', ['a1.dat', 'a3.dat', 'a4.dat', 'a5.dat', 'a24.dat', 'a32.dat', 'a39.dat', 'a40.dat', 'a41.dat', 'a42.dat', 'a43.dat', 'a44.dat', 'a45.dat', 'a54.dat', 'a56.dat', 'a58.dat', 'a63.dat', 'a66.dat', 'a67.dat', 'a68.dat', 'a69.dat', 'a73.dat', 'a76.dat', 'a78.dat', 'a80.dat', 'a82.dat', 'a83.dat', 'a84.dat', 'a85.dat']],
             ['XDrawString', ['a1.dat', 'a3.dat', 'a23.dat', 'a24.dat', 'a25.dat', 'a26.dat', 'a30.dat', 'a33.dat', 'a35.dat', 'a37.dat', 'a39.dat']],
             ['XDrawString16', ['a1.dat', 'a3.dat', 'a23.dat', 'a24.dat', 'a25.dat', 'a26.dat', 'a30.dat', 'a33.dat', 'a35.dat', 'a37.dat', 'a39.dat']],
             ['XDrawText', ['a1.dat', 'a3.dat', 'a5.dat', 'a27.dat', 'a28.dat', 'a29.dat', 'a30.dat', 'a34.dat', 'a37.dat', 'a39.dat', 'a41.dat', 'a43.dat']],
             ['XDrawText16', ['a1.dat', 'a3.dat', 'a4.dat', 'a27.dat', 'a28.dat', 'a29.dat', 'a30.dat', 'a34.dat', 'a37.dat', 'a39.dat', 'a41.dat', 'a43.dat']],
             ['XFillArc', ['a1.dat', 'a2.dat', 'a3.dat', 'a23.dat', 'a24.dat', 'a25.dat', 'a26.dat', 'a30.dat', 'a33.dat', 'a35.dat', 'a37.dat', 'a39.dat']],
             ['XFillArcs', ['a1.dat', 'a2.dat', 'a3.dat', 'a6.dat', 'a25.dat', 'a26.dat', 'a27.dat', 'a28.dat', 'a32.dat', 'a35.dat', 'a37.dat', 'a39.dat', 'a41.dat']],
             ['XFillPolygon', ['a1.dat', 'a8.dat', 'a9.dat', 'a28.dat', 'a29.dat', 'a30.dat', 'a31.dat', 'a35.dat', 'a38.dat', 'a40.dat', 'a42.dat', 'a44.dat', 'a45.dat', 'a46.dat']],
             ['XFillRectangle', ['a22.dat', 'a24.dat', 'a25.dat', 'a29.dat', 'a32.dat', 'a34.dat', 'a36.dat', 'a38.dat']],
             ['XFillRectangles', ['a1.dat', 'a23.dat', 'a24.dat', 'a25.dat', 'a26.dat', 'a30.dat', 'a33.dat', 'a35.dat', 'a37.dat', 'a39.dat']],
             ['XLoadFont', ['a2.dat']],
             ['XLoadQueryFont', ['a2.dat']],
             ['XPutImage', ['a24.dat', 'a27.dat', 'a29.dat', 'a31.dat']]]
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
