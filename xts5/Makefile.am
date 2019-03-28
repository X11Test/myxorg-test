include common.mk

SUBDIRS = . fonts src scenarios Xproto Xopen Xlib3 Xlib4 Xlib5 Xlib6 \
	Xlib7 Xlib8 Xlib9 Xlib10 Xlib11 Xlib12 Xlib13 Xlib14 Xlib15 \
	Xlib16 Xlib17 SHAPE XIproto XI Xt3 Xt4 Xt5 Xt6 Xt7 Xt8 Xt9 \
	Xt10 Xt11 Xt12 Xt13 Xt14 Xt15 XtC XtE
noinst_HEADERS = include

CLEANFILES = */*/tet_lock bin/xts-config bin/xts-run tetexec.cfg
LOGFILES = */*/*.log
DISTCLEANFILES = $(LOGFILES) */*/*.log.tmp
EXTRA_DIST = bin/xts-config.in bin/xts-run.in lib

bin_SCRIPTS = bin/xts-config bin/xts-run
dist_xts5_DATA = tetexec.cfg.in tet_scen tet_code
xts5dir = $(datadir)/xts5
noinst_DATA = tetexec.cfg

xts5docdir = $(xts5dir)/doc
dist_xts5doc_DATA = doc/release_notes doc/VSW_RELEASE doc/VSW_SPEC

# Script substitutions
EDIT = $(SED) -e 's,%bindir%,$(bindir),g' \
	-e 's,%libexecdir%,$(libexecdir),g' \
	-e 's,%DEFAULT_TET_ROOT%,$(DEFAULT_TET_ROOT),g' \
	-e 's,%PACKAGE_VERSION%,$(PACKAGE_VERSION),g'
bin/xts-config: $(srcdir)/bin/xts-config.in
	$(AM_V_at)$(MKDIR_P) bin
	$(AM_V_GEN)$(EDIT) < $< > $@
bin/xts-run: $(srcdir)/bin/xts-run.in
	$(AM_V_at)$(MKDIR_P) bin
	$(AM_V_GEN)$(EDIT) < $< > $@

# Config file generation for in-tree testing
XTS_CONFIG = TET_ROOT='$(top_srcdir)' XSET='$(XSET)' XDPYINFO='$(XDPYINFO)' \
	$(PERL) -p $(builddir)/bin/xts-config
tetexec.cfg: tetexec.cfg.in $(builddir)/bin/xts-config
	$(AM_V_GEN)$(XTS_CONFIG) < $< > $@.tmp && mv -f $@.tmp $@ || rm -f $@.tmp

