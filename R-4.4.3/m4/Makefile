#
# ${R_HOME}/m4/Makefile


srcdir = .
top_srcdir = ..

top_builddir = ..
subdir = m4

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = Makefile.in README \
	R.m4 \
	bigendian.m4 \
	cairo.m4 \
	clibs.m4 \
	codeset.m4 \
	cxx.m4 \
	gettext.m4 gettext-lib.m4 \
	libtool.m4 ltoptions.m4 ltsugar.m4 ltversion.m4 lt~obsolete.m4 \
	openmp.m4 \
	stat-time.m4

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R: Makefile

mostlyclean: clean
clean:
distclean: clean
	-@rm -f Makefile
maintainer-clean: distclean

install install-strip uninstall TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
