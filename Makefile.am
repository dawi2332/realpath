AM_CPPFLAGS = -Isrc -I$(top_srcdir)/src

MAINTAINERCLEANFILES = aclocal.m4 configure config.h.in~ config.h.in Makefile.in $(DIST_ARCHIVES)

include $(top_srcdir)/src/local.mk

EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version
