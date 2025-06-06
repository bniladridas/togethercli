#
# ${R_HOME}/doc/html/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = doc/html

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
## logo.jpg is not used in R >= 3.3.0.
## Rlogo.pdf is only used to make NEWS.pdf
INSTFILES = \
	NEWS.2.html NEWS.3.html \
	R.css Rlogo.svg Rlogo.pdf Search.html SearchOn.html \
	favicon.ico left.jpg logo.jpg right.jpg up.jpg \
	about.html packages-head-utf8.html  \
	mathjax-config.js katex-config.js katex-check.js \
	R-nav.css prism.css prism.js \
	orcid.svg
INSTDIRS = katex
NON_SVN_INSTFILES = resources.html NEWS.html
DISTFILES = Makefile.in $(INSTFILES) index-default.html Notes
OBJECTS = index.html
## <FIXME>
## We really should not create packages.html in *this* directory.
CLEANFILES = packages.html $(OBJECTS)
## </FIXME>
DISTCLEANFILES = Makefile

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R: Makefile $(OBJECTS) svnonly
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  $(MAKE) rdocdir=$(top_builddir)/doc install-sources; \
	fi

svnonly:
	@if test -f "$(srcdir)/resources.html"; then \
	  if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	    for f in $(NON_SVN_INSTFILES); do \
	      $(INSTALL_DATA) $(srcdir)/$${f} . ; \
	    done \
	  fi \
	fi

## NB, not used on Windows, replaced by src/gnuwin32/fixed/html/rwin.html
index.html: FORCE
	@$(INSTALL_DATA) $(srcdir)/index-default.html $@
FORCE:

install: svnonly install-message installdirs install-sources
	@for f in $(OBJECTS); do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rdocdir)/html"; \
	done
	@for f in $(NON_SVN_INSTFILES); do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rdocdir)/html"; \
	done
	@for d in $(INSTDIRS); do \
	  cp -p -R $${d} "$(DESTDIR)$(rdocdir)/html"; \
	done
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rdocdir)/html"
install-message:
	@$(ECHO) "installing $(subdir) ..."
install-sources: installdirs
	@for f in $(INSTFILES); do \
	  $(INSTALL_DATA) $(srcdir)/$${f} "$(DESTDIR)$(rdocdir)/html"; \
	done
	@for d in $(INSTDIRS); do \
	  cp -p -R $(srcdir)/$${d} "$(DESTDIR)$(rdocdir)/html"; \
	done
install-strip: install
uninstall:
	@$(ECHO) "uninstalling $(subdir) ..."
	@for f in $(CLEANFILES) $(INSTFILES) $(NON_SVN_INSTFILES) $(OBJECTS); do \
	  rm -f "$(DESTDIR)$(rdocdir)/html/$${f}"; \
	done
	@for d in $(INSTDIRS); do \
	  rm -rf "$(DESTDIR)$(rdocdir)/html/$${d}"; \
	done
	@rmdir "$(DESTDIR)$(rdocdir)/html" 2>/dev/null \
	  || $(ECHO) "  subdir $(DESTDIR)$(subdir) not removed"

mostlyclean:
clean:
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -f $(INSTFILES); \
	fi
	-@test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)
distclean: clean
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -f $(NON_SVN_INSTFILES); \
	fi
	-@test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)
maintainer-clean: distclean

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
	@for f in $(NON_SVN_INSTFILES); do \
	  cp -p $${f} $(distdir)/$${f}; \
	done
	@for d in $(INSTDIRS); do \
	  cp -p -R $${d} $(distdir)/$${d}; \
	done
