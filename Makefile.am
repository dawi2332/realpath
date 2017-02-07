AM_CPPFLAGS = -Isrc -I$(top_srcdir)/src

CLEANFILES =
DISTCLEANFILES =
MAINTAINERCLEANFILES = aclocal.m4 configure config.h.in~ config.h.in ChangeLog Makefile.in $(DIST_ARCHIVES)

EXTRA_DIST = $(top_srcdir)/.version $(srcdir)/ChangeLog $(top_srcdir)/README.md
BUILT_SOURCES = $(top_srcdir)/.version $(srcdir)/ChangeLog
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@

$(srcdir)/ChangeLog:
	$(top_srcdir)/build-aux/gitlog-to-changelog --srcdir=$(top_srcdir) > $@-t && mv $@-t $@

dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

include $(top_srcdir)/src/local.mk
include $(top_srcdir)/man/local.mk
