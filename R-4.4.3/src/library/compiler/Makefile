#
# ${R_HOME}/src/library/compiler/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/compiler

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

pkg = compiler

## avoid bootstrapping issue with internal tzcode.
R_EXE = R_ENABLE_JIT=0 TZ=UTC $(top_builddir)/bin/R --vanilla --no-echo

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R`
DEFPKGS = NULL

all: Makefile DESCRIPTION # from-noweb
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkR1 mkdesc
#	@$(MAKE) mklazy
	@$(MAKE) mklazycomp

NOTANGLE = notangle
from-noweb: $(srcdir)/R/cmp.R
$(srcdir)/R/cmp.R: $(srcdir)/noweb/compiler.nw
	@echo "re-making 'R/cmp.R'"
	@$(NOTANGLE) -Rcmp.R $(srcdir)/noweb/compiler.nw > $(srcdir)/R/cmp.R || \
	  (mv $(srcdir)/R/cmp.R $(srcdir)/R/cmp.fail && exit 1)

mkR: mkR1

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
