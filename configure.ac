
AC_PREREQ(2.68)

# Initialise autoconf and automake
AC_INIT([lua-louis],
        m4_esyscmd([build-aux/git-version-gen .tarball-version]),
        [http://github.com/louis/lua-louis])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AS_BOX([Configuring AC_PACKAGE_TARNAME AC_PACKAGE_VERSION])
echo

AM_INIT_AUTOMAKE([foreign])

# Check for programs
AC_PROG_CC

# gnulib
gl_EARLY
gl_INIT

AX_PROG_LUA(5.1, 5.4)
AX_LUA_HEADERS
AC_PROG_LIBTOOL

# Check for header files
AC_HEADER_STDC
AC_CHECK_HEADERS([liblouis/liblouis.h], [], [
    AC_MSG_ERROR([Required header 'liblouis.h' could not be found])])


# Search libs
AC_SEARCH_LIBS([lou_translateString], [louis], [], [
    AC_MSG_ERROR([Required library 'liblouis' could not be found])])

# Find out whether liblouis was compiled with UCS4, i.e. determine the
# size of widechar
AC_CHECK_SIZEOF([widechar], [], [[#include <liblouis/liblouis.h>]])

# Generate output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
	examples/Makefile
	gnulib/Makefile])
AC_OUTPUT
