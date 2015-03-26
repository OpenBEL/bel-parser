AM_CFLAGS                   = -I$(top_builddir)/src $(CHECK_CFLAGS)
AM_LDFLAGS                  = $(CHECK_LIBS)

TESTS                       = check_libbel
check_PROGRAMS              = check_libbel

.tc.c:
	checkmk $< > $@ || rm -f $@

check_libbel_SOURCES        = check_libbel.tc
check_libbel_LDADD          = $(top_builddir)/src/libbel.la @CHECK_LIBS@

CLEANFILES = check_libbel.c
