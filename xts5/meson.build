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

fix_install_script = join_paths(meson.current_source_dir(), 'fix_test_install.py')

foreach s : ['xts-config', 'xts-run']
  _e = custom_target(
    s,
    command : [
      prog_sed,
      '-e', 's,%bindir%,@0@,g'.format(get_option('bindir')),
      '-e', 's,%libexecdir%,@0@,g'.format(get_option('libexecdir')),
      '-e', 's,%DEFAULT_TET_ROOT%,@0@,g'.format(conf.get_unquoted('DEFAULT_TET_ROOT')),
      '-e', 's,%PACKAGE_VERSION%,@0@,g'.format(meson.project_version()),
      '@INPUT@',
    ],
    capture : true,
    input : [join_paths('bin', s + '.in')],
    output : [s],
    build_by_default : true,
    install : true,
    install_dir : get_option('bindir'),
  )
  set_variable('script_' + s.underscorify(), _e)
endforeach

prog_sh = find_program('sh')

custom_target(
  'tetexec.cfg',
  command : [prog_sh, files('xts-config.sh'), prog_perl, script_xts_config, '@INPUT@', '@OUTPUT@'],
  input : ['tetexec.cfg.in'],
  output : ['tetexec.cfg'],
  build_by_default : true,
)

inc_xts5 = include_directories('include')

install_subdir(
  'scenarios',
  install_dir : join_paths(get_option('datadir'), 'xts5'),
  exclude_files : ['Makefile.am', 'Makefile.in'],
)

subdir('fonts')
subdir('src')
subdir('Xproto')
subdir('Xopen')
subdir('Xlib3')
subdir('Xlib4')
subdir('Xlib5')
subdir('Xlib6')
subdir('Xlib7')
subdir('Xlib8')
subdir('Xlib9')
subdir('Xlib10')
subdir('Xlib11')
subdir('Xlib12')
subdir('Xlib13')
subdir('Xlib14')
subdir('Xlib15')
subdir('Xlib16')
subdir('Xlib17')
subdir('SHAPE')
subdir('XIproto')
subdir('XI')
subdir('Xt3')
subdir('Xt4')
subdir('Xt5')
subdir('Xt6')
subdir('Xt7')
subdir('Xt8')
subdir('Xt9')
subdir('Xt10')
subdir('Xt11')
subdir('Xt12')
subdir('Xt13')
subdir('Xt14')
subdir('Xt15')
subdir('XtC')
subdir('XtE')
