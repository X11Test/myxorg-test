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

_test_progs = [
   'XAllocNamedColor',
   'cursorfont',
   'XCreateFontCursor',
   'XLookupColor',
]

_install_dir = join_paths(get_option('libexecdir'), 'xts5', 'Xopen')

# Just handle the files that need to be processed from .m here
foreach t : _test_progs
  executable(
    t,
    [gen_mc.process(t + '.m')],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s],
    dependencies : [deps_xts, idep_tcmmain],
    install_dir : _install_dir,
    install : true,
  )
endforeach

_test_progs = [
    ['keysym', [
        gen_mc.process('keysym/keysym.m'), 'keysym/Test0.c',
        'keysym/Test1.c', 'keysym/Test2.c', 'keysym/Test3.c',
        'keysym/Test4.c', 'keysym/TestG.c', 'keysym/TestM.c',
    ]],
    ['keysymdef', [
        gen_mc.process('keysymdef/keysymdef.m'),
        'keysymdef/Test0.c',
        'keysymdef/Test1.c',
        'keysymdef/Test2.c',
        'keysymdef/Test3.c',
        'keysymdef/Test4.c',
        'keysymdef/TestA.c',
        'keysymdef/TestC.c',
        'keysymdef/TestG.c',
        'keysymdef/TestH.c',
        'keysymdef/TestK.c',
        'keysymdef/TestL.c',
        'keysymdef/TestM.c',
        'keysymdef/TestP.c',
        'keysymdef/TestS.c',
        'keysymdef/TestT.c',
    ]],
    ['XKeysymToKeycode', [
        gen_mc.process('XKeysymToKeycode/XKeysymToKeycode.m'),
        'XKeysymToKeycode/Test1.c',
        'XKeysymToKeycode/Test2.c',
        'XKeysymToKeycode/Test3.c',
        'XKeysymToKeycode/Test4.c',
        'XKeysymToKeycode/TestA.c',
        'XKeysymToKeycode/TestC.c',
        'XKeysymToKeycode/TestG.c',
        'XKeysymToKeycode/TestH.c',
        'XKeysymToKeycode/TestK.c',
        'XKeysymToKeycode/TestL.c',
        'XKeysymToKeycode/TestM.c',
        'XKeysymToKeycode/TestP.c',
        'XKeysymToKeycode/TestS.c',
        'XKeysymToKeycode/TestT.c',
    ]],
    ['XStringToKeysym', [
        gen_mc.process('XStringToKeysym/XStringToKeysym.m'),
        'XStringToKeysym/Test1.c',
        'XStringToKeysym/Test2.c',
        'XStringToKeysym/Test3.c',
        'XStringToKeysym/Test4.c',
        'XStringToKeysym/TestA.c',
        'XStringToKeysym/TestC.c',
        'XStringToKeysym/TestG.c',
        'XStringToKeysym/TestH.c',
        'XStringToKeysym/TestK.c',
        'XStringToKeysym/TestL.c',
        'XStringToKeysym/TestM.c',
        'XStringToKeysym/TestP.c',
        'XStringToKeysym/TestS.c',
        'XStringToKeysym/TestT.c',
    ]],
]

foreach t : _test_progs
  executable(
    t[0],
    t[1],
    include_directories : [inc_include, inc_tet3, inc_xts5],
    link_with : [libxts5, libapi_s],
    dependencies : [deps_xts, idep_tcmmain],
    install_rpath : '..',
    install_dir : join_paths(_install_dir, t[0]),
    install : true,
  )
endforeach
