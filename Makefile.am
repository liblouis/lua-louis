SUBDIRS = gnulib examples

ACLOCAL_AMFLAGS = -I m4 -I gnulib/m4

lib_LTLIBRARIES = liblua-louis.la

AM_CPPFLAGS =					\
	-I$(top_srcdir)/gnulib			\
	-I$(top_builddir)/gnulib		\
	$(LUA_INCLUDE)

liblua_louis_la_LDFLAGS = $(LTLIBINTL)
liblua_louis_la_LIBADD =			\
	$(top_builddir)/gnulib/libgnu.la	\
	$(LTLIBINTL)

liblua_louis_la_SOURCES = lua_louis.c

# support for git-version-gen
EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

