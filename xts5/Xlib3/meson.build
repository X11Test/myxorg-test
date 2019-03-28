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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib3')

# List of tuples in the form (name, _m variant)
_test_progs = [
  ['XAllPlanes', false],
  ['XBitmapBitOrder', true],
  ['XBitmapPad', true],
  ['XBitmapUnit', true],
  ['XBlackPixel', true],
  ['XBlackPixelOfScreen', true],
  ['XCellsOfScreen', true],
  ['XCloseDisplay', false],
  ['XConnectionNumber', true],
  ['XDefaultColormap', true],
  ['XDefaultColormapOfScreen', true],
  ['XDefaultDepth', true],
  ['XDefaultDepthOfScreen', true],
  ['XDefaultGC', true],
  ['XDefaultGCOfScreen', true],
  ['XDefaultRootWindow', true],
  ['XDefaultScreen', true],
  ['XDefaultScreenOfDisplay', true],
  ['XDefaultVisual', true],
  ['XDefaultVisualOfScreen', true],
  ['XDisplayCells', true],
  ['XDisplayHeight', true],
  ['XDisplayHeightMM', true],
  ['XDisplayOfScreen', true],
  ['XDisplayPlanes', true],
  ['XDisplayWidth', true],
  ['XDisplayWidthMM', true],
  ['XDoesBackingStore', true],
  ['XDoesSaveUnders', true],
  ['XEventMaskOfScreen', true],
  ['XFree', false],
  ['XHeightMMOfScreen', true],
  ['XHeightOfScreen', true],
  ['XImageByteOrder', true],
  ['XLastKnownRequestProcessed', true],
  ['XListDepths', false],
  ['XListPixmapFormats', false],
  ['XMaxCmapsOfScreen', true],
  ['XMinCmapsOfScreen', true],
  ['XNextRequest', true],
  ['XNoOp', false],
  ['XPlanesOfScreen', true],
  ['XProtocolRevision', true],
  ['XProtocolVersion', true],
  ['XQLength', true],
  ['XRootWindow', true],
  ['XRootWindowOfScreen', true],
  ['XScreenCount', true],
  ['XScreenNumberOfScreen', false],
  ['XScreenOfDisplay', true],
  ['XServerVendor', true],
  ['XSetCloseDownMode', false],
  ['XVendorRelease', true],
  ['XWhitePixel', true],
  ['XWhitePixelOfScreen', true],
  ['XWidthMMOfScreen', true],
  ['XWidthOfScreen', true],
]

foreach t : _test_progs
  args = [[[], t[0]]]
  if t[1]
    args += [['-m', t[0] + '_m']]
  endif
  foreach p : args
    _extra = p[0]
    _name = p[1]
    executable(
      _name,
      [gen_mc.process(t[0] + '.m', extra_args : _extra)],
      include_directories : [inc_include, inc_tet3, inc_xts5],
      link_with : [libxts5, libapi_s],
      dependencies : [deps_xts, idep_tcmmain],
      install_rpath : '..',
      install_dir : _install_dir,
      install : true,
    )
  endforeach
endforeach

subdir('XDisplayString')
subdir('XOpenDisplay')
