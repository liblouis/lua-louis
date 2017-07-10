SUBDIRS = gnulib examples

ACLOCAL_AMFLAGS = -I m4 -I gnulib/m4

luaexec_LTLIBRARIES = liblua-louis.la

AM_CPPFLAGS =					\
	-I$(top_srcdir)/gnulib			\
	-I$(top_builddir)/gnulib		\
	$(LUA_INCLUDE)

liblua_louis_la_LDFLAGS = $(LTLIBINTL)
liblua_louis_la_LIBADD =			\
	$(top_builddir)/gnulib/libgnu.la	\
	$(LTLIBINTL)

liblua_louis_la_SOURCES = lua_louis.c

# generate a rockspec file
MD5SUM = md5sum
ROCKSPEC = $(PACKAGE)-$(VERSION)-1.rockspec

$(ROCKSPEC): $(PACKAGE).rockspec dist
	sed -e 's/@MD5@/'`$(MD5SUM) $(distdir).tar.gz | \
	cut -d " " -f 1`'/g' < $(PACKAGE).rockspec > $@

EXTRA_DIST = $(PACKAGE).rockspec.in

DISTCLEANFILES = $(PACKAGE).rockspec

# support for git-version-gen
EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

