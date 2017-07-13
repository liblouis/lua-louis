EXTRA_DIST = louis.lua

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
