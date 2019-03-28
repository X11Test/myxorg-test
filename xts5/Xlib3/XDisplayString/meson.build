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

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xlib3', 'XDisplayString')

foreach t : [['XDisplayString', [gen_mc.process('XDisplayString.m')]],
             ['XDisplayString_m', [gen_mc.process('XDisplayString.m', extra_args : ['-m'])]]]
  executable(
    t[0],
    t[1],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s, libximtest, libfont, libxtest],
    dependencies : [deps_xts, idep_tcmmain],
    install_rpath : '../..',
    install_dir : _install_dir,
    install : true,
  )
endforeach

_e = executable(
  'XDisplayString_Test1',
  ['Test1.c'],
  include_directories : [inc_include, inc_tet3, inc_xts5],
  link_with : [libxts5, libapi_s, libximtest, libxtest, libfont],
  dependencies : [deps_xts, idep_tcmchild],
  install_rpath : '../..',
  install_dir : _install_dir,
  install : true,
)

meson.add_install_script(fix_install_script, _install_dir, _e.full_path())
