SUBDIRS = gnulib src examples

if HAVE_LUADOC
SUBDIRS += doc
endif

ACLOCAL_AMFLAGS = -I m4 -I gnulib/m4

# generate a rockspec file
MD5SUM = md5sum
ROCKSPEC = $(PACKAGE)-$(VERSION)-1.rockspec

$(ROCKSPEC): $(PACKAGE).rockspec dist
	sed -e 's/@MD5@/'`$(MD5SUM) $(distdir).tar.gz | \
	cut -d " " -f 1`'/g' < $(PACKAGE).rockspec > $@

EXTRA_DIST = $(PACKAGE).rockspec.in

DISTCLEANFILES = $(PACKAGE).rockspec

