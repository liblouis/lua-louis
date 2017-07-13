EXTRA_DIST = ldoc.css index.html
BUILT_SOURCES = $(EXTRA_DIST)

$(EXTRA_DIST): $(top_srcdir)/src/lua_louis.c
	$(LUADOC) -d . $<


