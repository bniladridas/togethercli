#
# ${R_HOME}/src/modules/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = src/modules

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = Makefile.in Makefile.win

SUBDIRS = X11 internet lapack

MODULES = internet lapack #X11

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R: Makefile make.internet make.lapack #make.X11

make.X11: Makefile
	@(cd X11 && $(MAKE))

make.internet: Makefile
	@(cd internet && $(MAKE))

make.lapack: Makefile
	@(cd lapack && $(MAKE))

install install-strip:
	@for d in $(MODULES); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(Rexecmodulesdir)"
uninstall:
	@rm -Rf "$(DESTDIR)$(rhome)/modules"

mostlyclean: clean
clean:
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
distclean: clean
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
	@-rm -f Makefile
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
