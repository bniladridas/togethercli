#
# ${R_HOME}/src/library/utils/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/utils

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

pkg = utils

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R $(srcdir)/R/$(R_OSTYPE)/*.R`
INSTDIRS = Sweave doc misc
DEFPKGS = NULL

.PHONY: iconvlist

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)/doc
	@$(MAKE) mkR1 mkdesc instdirs iconvlist
	@$(MAKE) mksrc
	@$(MAKE) sysdata
#	@$(MAKE) mklazy
	@$(MAKE) mklazycomp

mkR: mkR1

iconvlist: $(top_builddir)/library/$(pkg)/iconvlist

$(top_builddir)/library/$(pkg)/iconvlist:
	-@iconv -l > $@ 2> /dev/null || touch $@

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
