#  Copyright 2009 Red Hat, Inc.
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  on the rights to use, copy, modify, merge, publish, distribute, sub
#  license, and/or sell copies of the Software, and to permit persons to whom
#  the Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice (including the next
#  paragraph) shall be included in all copies or substantial portions of the
#  Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
#  ADAM JACKSON BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
#  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Process this file with autoconf to produce a configure script

AC_PREREQ(2.57)
AC_INIT([X Test Suite],
        [0.99.1],
        [https://gitlab.freedesktop.org/xorg/test/xts/issues],
        [xts])

AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_AUX_DIR(.)
AM_INIT_AUTOMAKE([dist-xz foreign])

# Initialize X.Org macros
m4_ifndef([XORG_MACROS_VERSION],
          [m4_fatal([must install xorg-macros 1.3 or later before running autoconf/autogen])])
XORG_MACROS_VERSION(1.3)
XORG_DEFAULT_OPTIONS

AC_CONFIG_HEADERS([config.h])

# Directory setup
AX_DEFINE_DIR([DEFAULT_TET_ROOT], [datadir], [Default TET root directory])
AC_SUBST([DEFAULT_TET_ROOT], ['${datadir}'])
AX_DEFINE_DIR([DEFAULT_TET_EXEC_ROOT], [libexecdir],
    [Default TET root execution directory])
AC_SUBST([DEFAULT_TET_EXEC_ROOT], ['${libexecdir}'])

# Checks for programs.
AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AC_PROG_CC
AM_PROG_CC_C_O

# Set up the build system compiler, if we're cross-compiling.  This is used for
# building tools like mc that are executed during the build.
if test x"$CC_FOR_BUILD" = x; then
        if test x"$cross_compiling" = xyes; then
                AC_CHECK_PROGS(CC_FOR_BUILD, gcc cc)
        else
                CC_FOR_BUILD="$CC"
        fi
fi
AC_SUBST([CC_FOR_BUILD])
CFLAGS_FOR_BUILD=${CFLAGS_FOR_BUILD-${CFLAGS}}
AC_SUBST(CFLAGS_FOR_BUILD)
LDFLAGS_FOR_BUILD=${LDFLAGS_FOR_BUILD-${LDFLAGS}}
AC_SUBST(LDFLAGS_FOR_BUILD)

PKG_CHECK_MODULES([XTS], [x11 xext xi xtst xau])
PKG_CHECK_MODULES([XT], [x11 xext xt xtst xtrans])
PKG_CHECK_MODULES([XAW], [x11 xext xt xtst xmu xaw7])

dnl Checks for header files.
AC_HEADER_STDC

dnl Setup common macros
AC_DEFINE([TET_LITE], [1], [Use a smaller subset of the TET API])
AC_DEFINE([XT_X_RELEASE], [6], [The X11 Release, e.g. 6 for X11R6])
AC_DEFINE([XTESTEXTENSION], [1], [Build tests using the XTEST extension])
AC_DEFINE([INPUTEXTENSION], [1], [Build tests using the XI extension])

m4_pattern_forbid([XTRANS_CONNECTION_FLAGS])

# Transport selection macro from xtrans.m4
XTRANS_CONNECTION_FLAGS

# Preferred order to try transports for local connections
AC_MSG_CHECKING([what order to try transports in for local connections])
case $host_os in
	solaris*)
		# On Solaris 2.6 through 9, named pipes (LOCAL_TRANS) were
		# faster than Unix domain sockets, but on Solaris 10 & later,
		# Unix domain sockets are faster now.
		DEFAULT_LOCAL_TRANS="UNIX_TRANS,LOCAL_TRANS,TCP_TRANS"
		;;
	*)
		if test "$LOCALCONN" = "yes"; then
			DEFAULT_LOCAL_TRANS="LOCAL_TRANS,UNIX_TRANS,TCP_TRANS"
		else
			DEFAULT_LOCAL_TRANS="UNIX_TRANS,TCP_TRANS"
		fi
		;;
esac

AC_ARG_WITH(local-transport-order,
	AC_HELP_STRING([--with-local-transport-order=LIST], [preference sorted list of transport types to try for local connections]),
	[LOCAL_TRANSPORT_LIST=$withval],
	[LOCAL_TRANSPORT_LIST=$DEFAULT_LOCAL_TRANS])
AC_DEFINE_UNQUOTED([LOCAL_TRANSPORT_LIST], [$LOCAL_TRANSPORT_LIST],
   [preference sorted list of transport types to try for local connections])
AC_MSG_RESULT([$LOCAL_TRANSPORT_LIST])

dnl Needed for generating fonts
AC_PATH_PROG([BDFTOPCF], [bdftopcf])
AC_PATH_PROG([MKFONTDIR], [mkfontdir])
if test "x$BDFTOPCF" = x || test "x$MKFONTDIR" = x; then
    AC_MSG_ERROR([bdftopcf and mkfontdir are required to build the test fonts])
fi

dnl Needed for generating tetexec.cfg with xts-config
AC_PATH_PROG([PERL], [perl])
AC_PATH_PROG([XSET], [xset])
AC_PATH_PROG([XDPYINFO], [xdpyinfo])
if test "x$PERL" = x || test "x$XSET" = x || test "x$XDPYINFO" = x; then
    AC_MSG_ERROR([perl, xset and xdpyinfo are required to run xts-config])
fi

XORG_WITH_ASCIIDOC
XORG_WITH_XMLTO
AM_CONDITIONAL(HAVE_DOCTOOLS, [test "x$XMLTO" != "x" && test "x$ASCIIDOC" != "x"])
if test "x$XMLTO" = "x" || test "x$ASCIIDOC" = "x"; then
    AC_MSG_WARN([xmlto or asciidoc not found - cannot create man pages without it])
fi

AC_CONFIG_FILES([
Makefile
check.sh
src/Makefile
src/tet3/Makefile
src/tet3/apilib/Makefile
src/tet3/dtet2lib/Makefile
src/tet3/tcm/Makefile
src/tet3/tcc/Makefile
src/tet3/tcclib/Makefile
xts5/Makefile
xts5/scenarios/Makefile
xts5/src/Makefile
xts5/src/lib/Makefile
xts5/src/libproto/Makefile
xts5/src/libXR5/Makefile
xts5/src/libXtaw/Makefile
xts5/src/libXtTest/Makefile
xts5/src/xim/Makefile
xts5/src/bin/Makefile
xts5/src/bin/blowup/Makefile
xts5/src/bin/mc/Makefile
xts5/src/bin/reports/Makefile
xts5/fonts/Makefile
xts5/Xproto/Makefile
xts5/Xopen/Makefile
xts5/Xlib3/Makefile
xts5/Xlib4/Makefile
xts5/Xlib5/Makefile
xts5/Xlib6/Makefile
xts5/Xlib7/Makefile
xts5/Xlib8/Makefile
xts5/Xlib9/Makefile
xts5/Xlib10/Makefile
xts5/Xlib11/Makefile
xts5/Xlib12/Makefile
xts5/Xlib13/Makefile
xts5/Xlib14/Makefile
xts5/Xlib15/Makefile
xts5/Xlib16/Makefile
xts5/Xlib17/Makefile
xts5/Xt3/Makefile
xts5/Xt4/Makefile
xts5/Xt5/Makefile
xts5/Xt6/Makefile
xts5/Xt7/Makefile
xts5/Xt8/Makefile
xts5/Xt9/Makefile
xts5/Xt10/Makefile
xts5/Xt11/Makefile
xts5/Xt12/Makefile
xts5/Xt13/Makefile
xts5/Xt14/Makefile
xts5/Xt15/Makefile
xts5/XtC/Makefile
xts5/XtE/Makefile
xts5/SHAPE/Makefile
xts5/XIproto/Makefile
xts5/XI/Makefile
])

AC_CONFIG_COMMANDS([mode],[
chmod +x check.sh
])

AC_OUTPUT
