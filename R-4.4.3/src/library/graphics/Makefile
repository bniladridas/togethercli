#
# ${R_HOME}/src/library/graphics/Makefile
pkg = graphics


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/$(pkg)

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R`
DEFPKGS = NULL

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkR1 mkdesc mkdemos mkfigs
	@$(MAKE) mksrc
#	@$(MAKE) mklazy
	@$(MAKE) mklazycomp

mkR: mkR1

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
