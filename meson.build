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

project(
  'X Test Suite',
  ['c'],
  version : '0.99.1',
  license : ['MIT', 'Artistic'],
  meson_version : '>=0.49.1',  # Arbitrary
  default_options : ['buildtype=debugoptimized', 'warning_level=0'],
)


# TODO: Does anyone even compile this code with these?

# The C and ObjC compilers take the same set of arguments
# cc = meson.get_compiler('c')
# add_project_arguments(
#   cc.get_supported_arguments(
#     [
#       '-Werror=unknown-warning-option',
#       '-Werror=unused-command-line-argument',
#       '-Wpointer-arith',
#       '-Wmissing-declarations',
#       '-Wformat2',
#       '-Wstrict-prototypes',
#       '-Wmissing-prototypes',
#       '-Wnested-externs',
#       '-Wbad-function-cast',
#       '-Wold-style-definition',
#       '-Wdeclaration-after-statement',
#       '-Wunused',
#       '-Wuninitialized',
#       '-Wshadow',
#       '-Wmissing-noreturn',
#       '-Wmissing-format-attribute',
#       '-Wredundant-decls',
#       '-Wlogical-op',
#       '-Werror=implicit',
#       '-Werror=nonnull',
#       '-Werror=init-self',
#       '-Werror=main',
#       '-Werror=missing-braces',
#       '-Werror=sequence-point',
#       '-Werror=return-type',
#       '-Werror=trigraphs',
#       '-Werror=array-bounds',
#       '-Werror=write-strings',
#       '-Werror=address',
#       '-Werror=int-to-pointer-cast',
#       '-Werror=attributes',
#     ],
#   ),
#   language : ['c'],
# )

# This code is such a pile of shit that we just don't want any warnings, and
# setting warn_level=0 at the meson level is not enough, we need to just set -w
# or /w to make it shut up.
cc = meson.get_compiler('c')
add_project_arguments(cc.first_supported_argument(['-w', '/w']), language: ['c'])

conf = configuration_data()
conf.set_quoted('DEFAULT_TET_ROOT', get_option('datadir'))
conf.set_quoted('DEFAULT_TET_EXEC_ROOT', get_option('libexecdir'))
conf.set('TET_LITE', 1)
conf.set('XT_X_RELEASE', 6)
conf.set('XTESTEXTENSION', 1)
conf.set('INPUTEXTENSION', 1)

dep_x11 = dependency('x11')
dep_xext = dependency('xext')
dep_xi = dependency('xi')
dep_xtst = dependency('xtst')
dep_xau = dependency('xau')
dep_xtrans = dependency('xtrans')
dep_xmu = dependency('xmu')
dep_xaw7 = dependency('xaw7')

deps_xts = [dep_x11, dep_xext, dep_xi, dep_xtst, dep_xau]
deps_xt = [dep_x11, dep_xext, dep_xi, dep_xtst, dep_xtrans]
deps_xaw = [dep_x11, dep_xext, dep_xi, dep_xtst, dep_xmu, dep_xaw7]

# Get just the compiler/preprocessor args and includes for each dependency
# they well be written to a variable called deps_<foo>_args
foreach t : ['xts', 'xt', 'xaw']
  _f = []
  foreach d : get_variable('deps_' + t)
    _f += d.partial_dependency(compile_args : true, includes : true)
  endforeach
  set_variable('deps_@0@_args'.format(t), _f)
endforeach

_trans = []
foreach t : get_option('transport-order')
  _trans += '@0@_TRANS'.format(t.to_upper())
endforeach
conf.set('LOCAL_TRANSPORT_LIST', ','.join(_trans))
conf.set('UNIXCONN', 1)
conf.set('TCPCONN', 1)

# Needed for generating fonts
prog_bdftopcf = find_program('bdftopcf')
prog_mkfontdir = find_program('mkfontdir')

# Needed for generating tetexec.cfg with xts-config
prog_sed = find_program('sed')
prog_perl = find_program('perl')
prog_xset = find_program('xset')
prog_xdpyinfo = find_program('xdpyinfo')
prog_python = import('python').find_installation('python3')

# For generating man pages
prog_asciidoc = find_program('asciidoc', required : get_option('manpages'))
prog_xmlto = find_program('xmlto', required : get_option('manpages'))

# TODO: putting config.h in the root is kinda a bad idea
config_h = configure_file(
  configuration : conf,
  output : 'config.h',
)
add_project_arguments('-DHAVE_CONFIG_H', language : ['c'])

inc_include = include_directories('include', '.') # Add . for config.h

# This could be made to depend on every .m file and then wouldn't need to be
# always stale. However, that would be tedious or involve a script, which
# would need to be always stale...
custom_target(
  'piglit-profile',
  command : [
    prog_python, '@INPUT@', meson.source_root(),
    join_paths(get_option('prefix'), get_option('libexecdir')),
    '@OUTPUT@',
    ],
  input : ['piglit-profile.py'],
  output : ['xts.xml.gz'],
  build_always_stale : true,
  install : true,
  install_dir : get_option('libexecdir'),
)

subdir('src/tet3')
subdir('xts5')

if prog_asciidoc.found() and prog_xmlto.found()
  # XXX: Meson dones't currently support sunos/solaris, so free pass!
  man_suffix = host_machine.system() == 'sunos' ? '5' : '7'

  xts_txt_xml = custom_target(
    'xts.txt.xml',
    command : [
      prog_asciidoc, '-b', 'docbook', '-d', 'manpage', '-o', '@OUTPUT@', '@INPUT@'
    ],
    input : files('README'),
    output : 'xts.txt.xml',
  )

  xts_xml_man = custom_target(
    'XTS.miscmansuffix',
    command : [prog_xmlto, 'man', '-o', '@OUTDIR@', '@INPUT@'],
    input : [xts_txt_xml],
    output : 'XTS.miscmansuffix',
  )

  xts_man = custom_target(
    'XTS.@0@'.format(man_suffix),
    command : [
      'sed', '-e', 's|miscmansuffix|@0@|'.format(man_suffix), '@INPUT@'
    ],
    input : [xts_xml_man],
    output : 'XTS.@0@'.format(man_suffix),
    install : true,
    install_dir : get_option('prefix') / get_option('mandir') / man_suffix,
    capture : true,
  )
endif
