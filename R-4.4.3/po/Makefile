#-*- Makefile -*-

## Copyright (C) 2005-2023 R Core Team


srcdir = .
top_srcdir = ..

subdir = po
top_builddir = ..

include $(top_builddir)/Makeconf

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

# LANGS=`ls -1 src/library/*/po/*.po | grep -F -v RGui | sed -e 's/.*[/]po[/]//; s/R-//; s/\.po//' | sort -u`
# echo $LANGS
# bn da de en en_GB es fa fr hi id it ja ko lt ne nn pl pt_BR ru sq tr ur zh_CN zh_TW

## datasets does not have any translations
R_PKGS_PO = base compiler grDevices graphics grid methods parallel splines stats stats4 tcltk tools utils

.SUFFIXES:

all:

R:
	@$(MAKE) install Rsharedir=${top_builddir}/share

install:
install-exec:
install-data:
installdirs:
installdirs-exec:
installdirs-data:

uninstall:
uninstall-exec:
uninstall-data:

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

clean mostlyclean:

distclean:
	@rm -f Makefile

maintainer-clean: distclean

Makefile: Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

update-RGui:
	@$(ECHO) "tools:::update_RGui_po(\"$(top_srcdir)\", mergeOpts=\"--no-wrap\")" | \
	  R_DEFAULT_PACKAGES=NULL LC_ALL=C $(R_EXE)

## en@quot has to be done in a UTF-8 locale
update-pkg-po:
	@for pkg in $(R_PKGS_PO); do \
	   $(ECHO) "updating translations for $${pkg}"; \
	   $(ECHO) "tools:::update_pkg_po(\"$(top_srcdir)/src/library/$${pkg}\", mergeOpts=\"--no-wrap\")" | \
	     R_DEFAULT_PACKAGES=NULL LC_COLLATE=C $(R_EXE); \
	done
