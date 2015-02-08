AC_PREREQ([2.61])
AC_INIT([libbel], [0.1], [abargnesi@selventa.com])
AC_CONFIG_AUX_DIR(aux-dist)
AM_INIT_AUTOMAKE

AC_PROG_MAKE_SET
AC_PROG_CC
AC_LANG(C)

CFLAGS="-ggdb -Wall -Werror"
AC_CONFIG_MACRO_DIR([m4])
LT_PREREQ([2.2])
LT_INIT
AC_CONFIG_FILES([Makefile src/Makefile])

AC_CHECK_PROG(RAGEL, ragel, ragel)
AC_OUTPUT
