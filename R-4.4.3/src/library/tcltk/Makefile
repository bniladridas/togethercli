#
# ${R_HOME}/src/library/tcltk/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/tcltk

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win NAMESPACE

pkg = tcltk

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

RSRC = `LC_COLLATE=C ls $(srcdir)/R/*.R $(srcdir)/R/$(R_OSTYPE)/zzz.R`
DEFPKGS = NULL
# MKLAZY = mklazy
  MKLAZY = mklazycomp

all: Makefile DESCRIPTION
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)/R
	@(f=$${TMPDIR:-/tmp}/R$$$$; \
	  if test no = yes; then \
	    cat $(RSRC) > "$${f}"; \
	    $(SHELL) $(top_srcdir)/tools/move-if-change "$${f}" all.R ; \
	  else \
	    $(SHELL) $(top_srcdir)/tools/copy-if-change \
	      $(srcdir)/R/unix/zzzstub.R \
	      $(top_builddir)/library/$(pkg)/R/$(pkg) ; \
	  fi)
	@$(INSTALL_DATA) $(srcdir)/NAMESPACE $(top_builddir)/library/$(pkg)
	@rm -f $(top_builddir)/library/$(pkg)/Meta/nsInfo.rds
	@$(MAKE) mkdesc mkexec mkdemos
	@if test -d src -a no = yes; then \
	  (cd src && $(MAKE)) || exit 1; \
	fi
	@if test no = yes; then \
	  $(MAKE) $(MKLAZY); \
	fi

mkR:
	@(f=$${TMPDIR:-/tmp}/R$$$$; \
	  if test no = yes; then \
	    cat $(RSRC) > $${f}; \
	    $(SHELL) $(top_srcdir)/tools/move-if-change $${f} all.R ; \
	  else \
	    $(SHELL) $(top_srcdir)/tools/copy-if-change \
	      $(srcdir)/R/unix/zzzstub.R \
	      $(top_builddir)/library/$(pkg)/R/$(pkg) ; \
	  fi)

include $(top_srcdir)/share/make/basepkg.mk
include $(top_srcdir)/share/make/lazycomp.mk
