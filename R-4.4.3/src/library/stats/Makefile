#
# ${R_HOME}/src/library/stats/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/stats

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = COPYRIGHTS.modreg COPYRIGHTS.portsrc DESCRIPTION.in Makefile.in \
  Makefile.win NAMESPACE SOURCES.ts loess-README splines-README

pkg = stats

FRONTFILES = COPYRIGHTS.modreg SOURCES.ts

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R`
DEFPKGS = NULL

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkR1 front mkdesc mkdemos
	@$(MAKE) mksrc
#	@$(MAKE) mklazy
	@$(MAKE) mklazycomp

mkR: mkR1

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
