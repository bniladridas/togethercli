#
# ${R_HOME}/src/library/base/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/base

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win baseloader.R makebasedb.R

pkg = base

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R $(srcdir)/R/$(R_OSTYPE)/*.R`

## avoid bootstrapping issue with internal tzcode.
R_EXE = TZ=UTC $(top_builddir)/bin/R --vanilla --no-echo

## For people who do make -C ../src/library/base
update:
	@$(MAKE) all
	@$(MAKE) mklazycomp

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@WHICH="/usr/bin/which" $(MAKE) mkRbase mkdesc2 mkdemos2
	@$(INSTALL_DATA) $(srcdir)/inst/CITATION $(top_builddir)/library/$(pkg)

include $(top_srcdir)/share/make/basepkg.mk

## Note that R_COMPILER_SUPPRESS_ALL is now on by default
$(top_builddir)/library/$(pkg)/R/$(pkg).rdb: all.R
	@$(ECHO) "byte-compiling package '$(pkg)'"
	@cat $(srcdir)/makebasedb.R | \
	  _R_COMPILE_PKGS_=1 R_COMPILER_SUPPRESS_ALL=1 \
	  R_DEFAULT_PACKAGES=NULL LC_ALL=C $(R_EXE) > /dev/null
	@$(INSTALL_DATA) $(srcdir)/baseloader.R \
	  $(top_builddir)/library/$(pkg)/R/$(pkg)

mkR: mkRbase

Rsimple:
	@WHICH="/usr/bin/which" $(MAKE) mkRbase mkRsimple

## Remove files to allow this to be done repeatedly
Rlazy:
	-@rm -f  $(top_builddir)/library/$(pkg)/R/$(pkg)*
	@WHICH="/usr/bin/which" $(MAKE) mkRbase
	@cat $(srcdir)/makebasedb.R | \
	  R_DEFAULT_PACKAGES=NULL LC_ALL=C $(R_EXE) > /dev/null
	@$(INSTALL_DATA) $(srcdir)/baseloader.R \
	  $(top_builddir)/library/$(pkg)/R/$(pkg)

Rlazycomp:
	@WHICH="/usr/bin/which" $(MAKE) mkRbase mklazycomp
