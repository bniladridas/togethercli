#
# ${R_HOME}/share/Makefile


srcdir = .
top_srcdir = ..

top_builddir = ..
subdir = share

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = Makefile.in

## subdirectories of R_HOME/share
SUBDIRS_WITH_NO_BUILD = R dictionaries encodings licenses make sh texmf java Rd

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R: FORCE
	@if test "$(BUILDDIR_IS_SRCDIR)" = "no" ; then \
	  $(MAKE) rsharedir=$(top_builddir)/share install-sources; \
	elif test "x" = "x";  then \
          $(MAKE) rsharedir=. install-zoneinfo; \
	fi
FORCE:

docs:

install: install-message installdirs install-sources
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/R"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/dictionaries"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/encodings"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/java"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/licenses"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/make"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/Rd"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/Rd/macros"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/sh"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/texmf"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/texmf/bibtex/bib"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/texmf/bibtex/bst"
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rsharedir)/texmf/tex/latex"
install-message:
	@$(ECHO) "installing share ..."
install-sources: installdirs   install-zoneinfo
	@for f in $(srcdir)/R/*.R; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/R"; \
	done
	@for f in $(srcdir)/dictionaries/*.rds; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/dictionaries"; \
	done
	@for f in $(srcdir)/encodings/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/encodings"; \
	done
	@for f in $(srcdir)/java/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/java"; \
	done
	@for f in $(srcdir)/licenses/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/licenses"; \
	done
	@for f in $(srcdir)/make/*.mk; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/make"; \
	done
	@for f in $(srcdir)/Rd/macros/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/Rd/macros"; \
	done
	@for f in $(srcdir)/sh/*.sh; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/sh"; \
	done
	@for f in $(srcdir)/texmf/bibtex/bib/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/texmf/bibtex/bib"; \
	done
	@for f in $(srcdir)/texmf/bibtex/bst/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/texmf/bibtex/bst"; \
	done
	@for f in $(srcdir)/texmf/tex/latex/*; do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rsharedir)/texmf/tex/latex"; \
	done
install-strip: install

install-zoneinfo:
	@/usr/bin/unzip -qo $(top_srcdir)/src/extra/tzone/zoneinfo.zip -d "$(DESTDIR)$(rsharedir)"

uninstall:
	@$(ECHO) "uninstalling share ..."
	@rm -Rf "$(DESTDIR)$(rsharedir)"

## we cannot remove make/vars.mk until distclean as etc/Makeconf includes it.
mostlyclean:
clean:
	@rm -Rf locale

distclean:
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -Rf $(SUBDIRS_WITH_NO_BUILD); \
	fi
	-@rm -Rf zoneinfo
	-@rm -f Makefile
maintainer-clean: distclean

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
	@for d in $(SUBDIRS_WITH_NO_BUILD); do \
	  ((cd $(srcdir); $(TAR) -c -f - $(DISTDIR_TAR_EXCLUDE) $${d}) \
	      | (cd $(distdir); $(TAR) -x -f -)) \
	    || exit 1; \
	done
