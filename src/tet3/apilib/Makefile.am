AM_CPPFLAGS = -I$(srcdir)/../inc -I$(top_srcdir)/include \
	-DTET_DEFAULT_CONFIG=\"$(abs_top_builddir)/xts5/tetexec.cfg\"

# libapi_s is the shared portion of the library
xtslibdir = $(libexecdir)/xts5
xtslib_LTLIBRARIES = libapi_s.la
noinst_LTLIBRARIES = libapi.la

# If we weren't building TeT lite, this could also add inetlib, servlib
# and xtilib
libapi_s_la_LIBADD = ../tcm/libtcm_s.la ../dtet2lib/libdtet2.la
libapi_s_la_LDFLAGS = -avoid-version
libapi_s_la_SOURCES = \
		dcancel.c \
		dconfig.c \
		dresfile.c \
		errno.c \
		exit.c \
		getlist.c \
		getsys.c \
		getsysid.c \
		libvers.c \
		remexec.c \
		remkill.c \
		remtime.c \
		remwait.c \
		rtab.c \
		sync.c \
		tdiscon.c \
		tet_exec.c \
		tet_fork.c \
		tet_spawn.c
libapi_la_LIBADD = ../tcm/libtcm.la
libapi_la_SOURCES = \
		tciface.c

EXTRA_DIST = \
		version.c
