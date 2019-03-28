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

libfont = static_library(
  'libfont',
  files('xtfont0.c', 'xtfont1.c', 'xtfont2.c', 'xtfont3.c', 'xtfont4.c', 'xtfont5.c', 'xtfont6.c'),
  include_directories : [inc_include, inc_tet3, inc_xts5],
  dependencies : [deps_xts_args],
)

_fontdir = join_paths(get_option('datadir'), 'xts5', 'fonts')
_fonts = []
foreach n : ['0', '1', '2', '3', '4', '5', '6', '7', '8']
  _input = 'xtfont@0@.bdf'.format(n)
  _output = 'xtfont@0@.pcf'.format(n)
  _fonts += custom_target(
    _output,
    command : [prog_bdftopcf, '-t', '-o', '@OUTPUT@', '@INPUT@'],
    input : _input,
    output: _output,
    install: true,
    install_dir : _fontdir,
  )
endforeach

# Because meson makes no guarantees about the layout of the source directory we
# cannot generate the fonts.dir file until install time, when files are layed
# out as we expect them. Scripts are guaranteed to run after all normal install
# targets.
meson.add_install_script('mkfontdir.sh', _fontdir)
