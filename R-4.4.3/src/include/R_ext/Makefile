#
# ${R_HOME}/src/include/R_ext/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/include/R_ext

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

## Partially included by the API (1) headers in .., but not part of the
## API per se. 
R_EXT_HEADERS = \
  Altrep.h \
  Applic.h Arith.h BLAS.h Boolean.h Callbacks.h Complex.h Connections.h \
  Constants.h Error.h GetX11Image.h \
  GraphicsDevice.h GraphicsEngine.h Itermacros.h \
  Lapack.h Linpack.h MathThreads.h Memory.h QuartzDevice.h \
  Parse.h Print.h PrtUtil.h RS.h Rallocators.h Random.h \
  Rdynload.h Riconv.h RStartup.h Utils.h eventloop.h libextern.h \
  stats_package.h stats_stubs.h Visibility.h

DISTFILES = Makefile.in $(R_EXT_HEADERS)
TIMESTAMPS = $(R_EXT_HEADERS:.h=.ts)

CLEANFILES = stamp-R $(TIMESTAMPS)
DISTCLEANFILES = Makefile

.SUFFIXES:
.SUFFIXES: .h .ts

.h.ts: 
	@$(INSTALL_DATA) $< $(top_builddir)/include/R_ext/`basename $<`
	@touch $@

all: Makefile R

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R: Makefile stamp-R $(TIMESTAMPS)
stamp-R: 
	@$(MKINSTALLDIRS) $(top_builddir)/include/R_ext
	@touch $@
$(TIMESTAMPS): stamp-R

install: installdirs
	@for f in $(R_EXT_HEADERS); do \
	  $(INSTALL_DATA) $(srcdir)/$${f} "$(DESTDIR)$(rincludedir)/R_ext"; \
	done
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rincludedir)/R_ext"
install-strip:
	$(MAKE) INSTALL_PROGRAM="${INSTALL_PROGRAM} -s" install
uninstall:
	@rm -Rf "$(DESTDIR)$(rincludedir)/R_ext"

mostlyclean: clean
clean:
	-@test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)
distclean: clean
	-@test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)
maintainer-clean: distclean

TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
