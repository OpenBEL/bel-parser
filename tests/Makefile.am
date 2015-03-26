AM_CFLAGS                   = -I$(top_builddir)/src $(CHECK_CFLAGS)
AM_LDFLAGS                  = $(CHECK_LIBS)

TESTS                       = check_term
check_PROGRAMS              = check_term

.tc.c:
	checkmk $< > $@ || rm -f $@

check_term_SOURCES          = check_term.tc
check_term_LDADD            = $(top_builddir)/src/libbel.la @CHECK_LIBS@

CLEANFILES = check_term.c
