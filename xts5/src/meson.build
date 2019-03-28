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

subdir('lib')
subdir('libproto')
subdir('libXR5')
subdir('libXtaw')
subdir('libXtTest')
subdir('xim')
subdir('bin')

_install_dir = join_paths(get_option('libexecdir'), 'xts5')

# Niether of these work with lundef of course, like everything else in XTS, the
# code quiality is poop
libxts5 = library(
  'xts5',
  link_whole : [libxtest, libfont, libximtest],
  dependencies : [deps_xt],
  override_options : ['b_lundef=false'],
  install_dir : _install_dir,
  install : get_option('default_library') == 'shared',
)

libxts5proto = library(
  'xts5proto',
  link_with : [libxts5],
  link_whole : [libxst],
  override_options : ['b_lundef=false'],
  install_dir : _install_dir,
  install : get_option('default_library') == 'shared',
)
