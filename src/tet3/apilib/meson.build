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

files_libapi_s = files(
  'dcancel.c',
  'dconfig.c',
  'dresfile.c',
  'errno.c',
  'exit.c',
  'getlist.c',
  'getsys.c',
  'getsysid.c',
  'libvers.c',
  'remexec.c',
  'remkill.c',
  'remtime.c',
  'remwait.c',
  'rtab.c',
  'sync.c',
  'tdiscon.c',
  'tet_exec.c',
  'tet_fork.c',
  'tet_spawn.c',
)
_install_dir = join_paths(get_option('libexecdir'), 'xts5')

libapi_s = library(
  'api_s',
  files_libapi_s,
  include_directories : [inc_include, inc_tet3],
  # XXX: this seems like it's going to break badly
  c_args : ['-DTET_DEFAULT_CONFIG="@0@"'.format(join_paths(meson.build_root(), 'xts5', 'tetexec.cfg'))],
  link_whole : [libtcm_s, libdtet2],
  override_options : ['b_lundef=false'],
  install_dir : _install_dir,
  install : get_option('default_library') == 'shared',
)

libapi = static_library(
  'api',
  ['tciface.c'],
  include_directories : [inc_include, inc_tet3],
  link_whole : [libtcm],
)

idep_tcmmain = declare_dependency(link_with : [libtcmmain, libapi])
idep_tcmchild = declare_dependency(link_with : [libtcmchild, libapi])
