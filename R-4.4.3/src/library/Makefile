#
# ${R_HOME}/src/library/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = src/library

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = Makefile.in Makefile.win

SUBDIRS = profile $(R_PKGS_BASE) translations Recommended

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

.SUFFIXES: .inn .Rdts .Rdh

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

#R_NO_BASE_COMPILE = true

## FIXME: do some of this in parallel?
## Beware there is a bootstrapping problem here: tools uses tools to
## dump its namespace. So it works initially, but not to update.
## When base is made we need to use 'date' to set the timestamp in
## its DESCRIPTION, so we remake it before dumping the DESCRIPTION files.

R:
	@$(MKINSTALLDIRS) $(top_builddir)/library
	@for pkg in profile translations base tools compiler; do \
	  (cd $${pkg} && $(MAKE) all) || exit 1; \
	done
	@if test -z "$(R_NO_BASE_COMPILE)"; then \
	  for pkg in base tools; do \
	    (cd $${pkg} && $(MAKE) mklazycomp) || exit 1; \
	  done; \
	else \
	  for pkg in base tools; do \
	    (cd $${pkg} && $(MAKE) Rlazy) || exit 1; \
	  done; \
	fi
	@for pkg in $(R_PKGS_BASE1); do \
	  (cd $${pkg} && $(MAKE) all) || exit 1; \
	done
	@(cd base && $(MAKE) mkdesc)
	@$(ECHO) "tools:::.vinstall_package_descriptions_as_RDS(\"$(top_builddir)/library\", \"$(R_PKGS_BASE)\")" | \
	  R_DEFAULT_PACKAGES=tools LC_ALL=C $(R_EXE) > /dev/null
	@$(ECHO) "installing parsed NAMESPACE files"
	@rm -f $(top_builddir)/library/tools/Meta/nsInfo.rds
	@$(ECHO) "tools:::.vinstall_package_namespaces_as_RDS(\"$(top_builddir)/library\", \"$(R_PKGS_BASE)\")" | \
	  R_DEFAULT_PACKAGES=tools LC_ALL=C $(R_EXE) > /dev/null

## do Rdobjects before metadata before help indices
docs:
	@$(MAKE) Rdobjects
	@$(MAKE) metadata
	@$(MAKE) help-indices
	@#$(MAKE) Rdfiles
	@touch stamp-docs

# fix the order to make best use of parallel builds
RD-TS = base.Rdts stats.Rdts utils.Rdts methods.Rdts graphics.Rdts grDevices.Rdts datasets.Rdts grid.Rdts tools.Rdts tcltk.Rdts splines.Rdts stats4.Rdts compiler.Rdts parallel.Rdts
# RD-TS = $(R_PKGS_BASE:=.Rdts)

.inn.Rdts:
	@$(ECHO) "options(warn=1);tools:::.install_package_Rd_objects('$(srcdir)/$*',\
	   '$(top_builddir)/library/$*')" | \
	    R_DEFAULT_PACKAGES=NULL $(R_EXE) || exit 1
	@$(ECHO) "  $*"

Rdobjects:
	@$(ECHO) "installing parsed Rd"
	@for pkg in $(R_PKGS_BASE); do touch $${pkg}.inn; done
	@$(MAKE) $(RD-TS)

.inn.Rdh:
	@$(ECHO) "tools:::.writePkgIndices(\"$(srcdir)/$*\", \"$(top_builddir)/library/$*\")" | R_DEFAULT_PACKAGES=utils LC_ALL=C $(R_EXE) || exit 1

RD-H = $(R_PKGS_BASE:=.Rdh)

help-indices:
	@$(ECHO) "writing package indices"
	@for pkg in $(R_PKGS_BASE); do touch $${pkg}.inn; done
	@$(MAKE) $(RD-H)

## FIXME: do this in parallel (but avoid interleaving output)
Rdfiles:
	@$(ECHO) "building all R object docs"
	@for pkg in $(R_PKGS_BASE); do \
	  $(ECHO) "tools:::.convertRdfiles(\"$(srcdir)/$${pkg}\", \"$(top_builddir)/library/$${pkg}\", silent = TRUE)" | LC_ALL=C $(R_EXE) || exit 1; \
	done

PDFLATEX = 

vignettes:
	@if test -z "$(PDFLATEX)"; then \
	  $(ECHO) "'pdflatex' is needed to make vignettes but is missing on your system."; \
	else \
	  for pkg in grid parallel utils stats; do \
	    $(ECHO) "building/updating vignettes for package '$${pkg}' ..."; \
	    ($(ECHO) "tools:::.install_package_vignettes(\"$(srcdir)/$${pkg}\", \"$(top_builddir)/library/$${pkg}\")") | \
	        R_DEFAULT_PACKAGES="utils,tools" LC_ALL=C \
		  R_LIBS_USER=NULL R_LIBS_SITE=NULL \
	          $(R_EXE) > /dev/null; \
	  done \
	fi

metadata:
	@$(ECHO) "building/updating package metadata ..."
	@$(ECHO) "tools:::.vinstall_package_indices(\"$(srcdir)\", \"$(top_builddir)/library\", \"$(R_PKGS_BASE)\")" | \
	  R_DEFAULT_PACKAGES=tools LC_ALL=C $(R_EXE) > /dev/null

install: installdirs
	@$(ECHO) "installing packages ..."
	@cp -R $(top_builddir)/library "$(DESTDIR)$(rhome)" || \
	  (cd $(top_builddir)/library; \
	    $(TAR) cf - . | (cd "$(DESTDIR)$(rhome)/library"; $(TAR) xmof -))
	@$(ECHO) "  building HTML index ..."
	@$(ECHO) "utils:::make.packages.html(.Library, verbose=FALSE, docdir=\"$(DESTDIR)${rdocdir}\")" | \
          R_DEFAULT_PACKAGES=NULL LC_ALL=C ${R_EXE} >/dev/null
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rhome)/library"
install-strip:
	@$(MAKE) install
	@if test -n "$(STRIP_SHARED_LIB)"; then \
	  $(STRIP_SHARED_LIB) "$(DESTDIR)$(rhome)/library"/*/libs/*${SHLIB_EXT}; \
	fi
uninstall:
	@$(ECHO) "uninstalling packages ..."
	@(cd "$(DESTDIR)$(rhome)/library"; \
	  for p in $(R_PKGS) translations; do rm -Rf $${p}; done)
	@rmdir "$(DESTDIR)$(rhome)/library" 2>/dev/null \
          || $(ECHO) "  subdir $(DESTDIR)$(rhome)/library not removed"

install-tests:
	@$(ECHO) "installing package tests ..."
	@for pkg in $(R_PKGS_BASE); do \
	  if test -d "$(srcdir)/$${pkg}/tests"; then \
	    $(MKINSTALLDIRS) "$(DESTDIR)$(rhome)/library/$${pkg}/tests" ; \
	    cp -R  $(srcdir)/$${pkg}/tests/* "$(DESTDIR)$(rhome)/library/$${pkg}/tests"; \
	  fi; \
	done
	@(cd Recommended && $(MAKE) $@)

uninstall-tests:
	@$(ECHO) "uninstalling package tests"
	@for pkg in $(R_PKGS_BASE); do \
	 rm -Rf "$(DESTDIR)$(rhome)/library/$${pkg}/tests" ; \
	done
	@(cd Recommended && $(MAKE) $@)

mostlyclean: clean
clean:
	@(for d in $(SUBDIRS); do rsd="$${d} $${rsd}"; done; \
	  for d in $${rsd}; do (cd $${d} && $(MAKE) $@); done)
	-@rm -Rf .vignettes
	-@rm -f stamp-* *.inn
distclean:
	@(for d in $(SUBDIRS); do rsd="$${d} $${rsd}"; done; \
	  for d in $${rsd}; do (cd $${d} && $(MAKE) $@); done)
	-@rm -f Makefile
maintainer-clean: distclean

TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
	@for d in $(SUBDIRS); do \
	  test -d $(distdir)/$${d} \
	    || mkdir $(distdir)/$${d} \
	    || exit 1; \
	  chmod 755 $(distdir)/$${d}; \
	  (cd $${d} && $(MAKE) distdir) \
	    || exit 1; \
	done

### ----------- targets for R-core use ----------
### These are intended to be run on an already-built R, possibly after
### editing the code in a standard package.
### Targets of the same name can be run in individual package directories.
### These do not change datasets (no R code)
### R_PKGS_BASE2 is all except datasets and methods.

### They are not currently safe for a parallel make.

## methods needs to be dumped, so is omitted here.
Rsimple:
	@for pkg in $(R_PKGS_BASE2); do \
	  (cd $${pkg} && $(MAKE) Rsimple) || exit 1; \
	done

## Lazy-loaded, not compiled
Rlazy:
	@for pkg in $(R_PKGS_BASE2) methods; do \
	  (cd $${pkg} && $(MAKE) Rlazy) || exit 1; \
	done

## Lazy-loaded, compiled
Rlazycomp:
	@for pkg in $(R_PKGS_BASE2) methods; do \
	  (cd $${pkg} && $(MAKE) Rlazycomp) || exit 1; \
	done

