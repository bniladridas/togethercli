#
# ${R_HOME}/src/library/tools/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/tools

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

pkg = tools

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R`

## avoid bootstrapping issue with internal tzcode.
R_EXE = R_ENABLE_JIT=0 TZ=UTC $(top_builddir)/bin/R --vanilla --no-echo

## For people who do make -C ../src/library/tools
update:
	@$(MAKE) all
	@R_SYSTEM_ABI='macos,gcc,gxx,gfortran,gfortran' $(MAKE) mklazycomp

## This is deliberately conservative: -nt seems to work differently in some shells
## We first use mkdesc2 (with date) to install the DESCRIPTION, then re-install
all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkR1 mkdesc2
	@$(MAKE) mksrc
	@if ! test -f $(top_builddir)/library/$(pkg)/R/$(pkg); then \
	  $(INSTALL_DATA) all.R $(top_builddir)/library/$(pkg)/R/$(pkg); \
	else if test all.R -nt $(top_builddir)/library/$(pkg)/R/$(pkg); then \
	  $(INSTALL_DATA) all.R $(top_builddir)/library/$(pkg)/R/$(pkg); \
	  fi \
	fi
	@$(MAKE) sysdata
	@$(ECHO) "tools:::.install_package_description('.', '"$(top_builddir)/library/${pkg}"')" | \
	  R_DEFAULT_PACKAGES=NULL $(R_EXE) > /dev/null

mkR: mkR1

include $(top_srcdir)/share/make/basepkg.mk

## Note that R_COMPILER_SUPPRESS_ALL is now on by default
## Depends on Makefile for macos,gcc,gxx,gfortran,gfortran
$(top_builddir)/library/$(pkg)/R/$(pkg).rdb: Makefile all.R $(top_srcdir)/share/licenses/license.db
	@$(ECHO) "byte-compiling package '$(pkg)'"
	@$(INSTALL_DATA) all.R $(top_builddir)/library/$(pkg)/R/$(pkg)
	@(cat $(srcdir)/R/makeLazyLoad.R; \
	  $(ECHO) "makeLazyLoading(\"$(pkg)\")") | \
	  _R_COMPILE_PKGS_=1 R_COMPILER_SUPPRESS_ALL=1 \
	  R_SYSTEM_ABI='macos,gcc,gxx,gfortran,gfortran' \
	  R_DEFAULT_PACKAGES=NULL LC_ALL=C $(R_EXE) > /dev/null

Rsimple: mkR mkRsimple

Rlazy: mkR mkRsimple
	@$(INSTALL_DATA) all.R $(top_builddir)/library/$(pkg)/R/$(pkg)
	@(cat $(srcdir)/R/makeLazyLoad.R; \
	  $(ECHO) "makeLazyLoading(\"$(pkg)\")") | \
	  R_SYSTEM_ABI='macos,gcc,gxx,gfortran,gfortran' \
	  R_DEFAULT_PACKAGES=NULL LC_ALL=C $(R_EXE) > /dev/null

Rlazycomp: mkR mkRsimple mklazycomp
