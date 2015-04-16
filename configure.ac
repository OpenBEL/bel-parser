AC_PREREQ([2.61])
AC_INIT([libbel], [0.1.0], [abargnesi@selventa.com])
AC_CONFIG_SRCDIR(src/bel-parser.c, src/bel-parser.h)
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE

AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_LIBTOOL
AC_LANG(C)

#CFLAGS="-ggdb -Wall -Werror -Wextra -Wno-unused-parameter -Wno-parentheses -Wno-long-long -Wno-missing-field-initializers -Wpointer-arith -Wwrite-strings -Wdeclaration-after-statement -Wimplicit-function-declaration -Wmaybe-uninitialized -fPIC -fstack-protector"
CFLAGS="-ggdb -fPIC -fstack-protector"
AC_CONFIG_MACRO_DIR([m4])
LT_PREREQ([2.2])
LT_INIT
AC_CONFIG_FILES([libbel.pc
		 Makefile
		 src/Makefile
		 tests/Makefile])

# Configure check
PKG_CHECK_MODULES(CHECK, check >= 0.9.4, have_check="yes", have_check="no")
if test x"$have_check" = "xyes"; then
  AC_CHECK_PROG(have_checkmk, [checkmk], [yes], [no])
  if test x"$have_checkmk" = "xyes"; then
    AC_DEFINE([HAVE_CHECK], 1, [Define to 1 if check library is available])
	else
    AC_MSG_WARN([Command 'checkmk' not found.])
    AC_MSG_WARN([Download it here: http://micah.cowan.name/projects/checkmk/])
  fi
fi
AM_CONDITIONAL(HAVE_CHECK, test x"$have_check" = "xyes" &&
                           test x"$have_checkmk" = "xyes")

AC_CHECK_PROG(RAGEL, ragel, ragel)
AC_OUTPUT
