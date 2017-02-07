man1_MANS = man/realpath.1
CLEANFILES += $(man1_MANS)
EXTRA_DIST += $(man1_MANS:.1=.1.ronn)

distclean-local:
	test x$(srcdir) = x$(builddir) || rm -f $(man1_MANS)

SUFFIXES = .1 .1.ronn

.1.ronn.1:
	$(AM_V_GEN)$(MKDIR_P) $(@D)
	echo ".ad l" > $@-t
	$(RONN) -r < $< >> $@-t && mv $@-t $@
