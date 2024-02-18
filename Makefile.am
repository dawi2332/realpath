AM_CPPFLAGS = -Isrc -I$(top_srcdir)/src

CLEANFILES =
DISTCLEANFILES = compile_commands.json
MAINTAINERCLEANFILES = aclocal.m4 configure~ configure config.h.in~ config.h.in ChangeLog Makefile.in $(DIST_ARCHIVES)

EXTRA_DIST = $(top_srcdir)/.version $(srcdir)/ChangeLog $(top_srcdir)/README.md
BUILT_SOURCES = $(top_srcdir)/.version $(srcdir)/ChangeLog
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@

$(srcdir)/ChangeLog:
	$(top_srcdir)/build-aux/gitlog-to-changelog --srcdir=$(top_srcdir) > $@-t && mv $@-t $@

dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

$(top_srcdir)/compile_commands.json: clean
	$(BEAR) -- $(MAKE) all

include $(top_srcdir)/src/local.mk
include $(top_srcdir)/man/local.mk
