#
# ${R_HOME}/src/library/splines/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/splines

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

pkg = splines


RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R`

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo
DEFPKGS = NULL

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkR1 mkdesc
	@$(MAKE) mksrc
#	@$(MAKE) mklazy
	@$(MAKE) mklazycomp

mkR: mkR1

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
