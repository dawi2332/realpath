AC_PREREQ([2.69])
AC_INIT([realpath],
	m4_esyscmd([build-aux/git-version-gen .tarball-version]),
	[dawi2332@gmail.com])
AC_CONFIG_SRCDIR([src/realpath.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([color-tests parallel-tests subdir-objects foreign])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([RONN],[ronn],[${am_missing_run}ronn])
AC_PATH_PROG([BEAR],[bear],[${am_missing_run}bear])
AC_PROG_MKDIR_P

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([limits.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_CHECK_DECLS([PATH_MAX], [], AC_DEFINE([PATH_MAX], [8192], [Define PATH_MAX if not declared by standard headers]), [#include <limits.h>])

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([realpath strrchr], [], [AC_MSG_FAILURE(
		[required library function not availaible])])

AC_DEFINE([_DARWIN_BETTER_REALPATH], [1], [Define to 1 for better realpath on Darwin hosts])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
