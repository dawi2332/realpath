man1_MANS = man/realpath.1
CLEANFILES += $(man1_MANS)
EXTRA_DIST += $(man1_MANS)

distclean-local:
	test x$(srcdir) = x$(builddir) || rm -f $(man1_MANS)

man/realpath.1: $(top_srcdir)/README.md
	$(AM_V_GEN)$(RONN) -r $<
