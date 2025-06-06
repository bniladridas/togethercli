#
# ${R_HOME}/src/unix/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = src/unix

include $(top_builddir)/Makeconf
# see note in src/main/Makefile.in
LIBINTL= #   -Wl,-framework -Wl,CoreFoundation
R_HOME=$(rhome)
STATIC_LIBR_PC = # $(BLAS_LIBS) $(FLIBS)  $(LIBINTL) -lreadline  $(LIBS)

ALL_CPPFLAGS = $(R_XTRA_CPPFLAGS) $(X_CFLAGS) $(CPPFLAGS) $(DEFS)

## Rscript should not be linked to OpenMP
## MAIN_CFLAGS is used on some systems when profiling R.
ALL_CFLAGS0 = $(R_XTRA_CFLAGS) $(MAIN_CFLAGS) $(CFLAGS)

SOURCES_C_BASE = Rembedded.c dynload.c system.c sys-unix.c sys-std.c X11.c
SOURCES = $(SOURCES_C_BASE)
DEPENDS = $(SOURCES:.c=.d)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = Runix.h

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = \
  Makefile.in $(SOURCES_C_BASE) Rscript.c \
  $(HEADERS) libR.pc.in system.txt

#ALL_CFLAGS = $(ALL_CFLAGS_LO)

all: R

Makefile: $(srcdir)/Makefile.in \
  $(top_builddir)/config.status \
  ../include/Rversion.h \
  $(SOURCES)
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

Makedeps: Makefile $(DEPENDS)
	@cat $(DEPENDS) >> Makefile
	@touch $@

R: Makedeps
	@$(MAKE) libunix.a
	@$(MAKE) rhome="$(abs_top_builddir)" install-Rscript

## Intel's icx, at least version 2023.2.0, needs -O0
## or CPU times will all be zero.
## https://community.intel.com/t5/Intel-C-Compiler/Troubles-with-getrusage-when-using-icx/m-p/1509374#M41116
INTEL_ICX_FIX = 
sys-unix.o: $(srcdir)/sys-unix.c
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) $(INTEL_ICX_FIX) -c $< -o $@

## is this portable?
../include/Rversion.h:
	(cd ../include; $(MAKE) $(@F))

libunix.a: $(OBJECTS)
	@rm -Rf $@
	$(AR) -cr $@ $(OBJECTS)
	$(RANLIB) $@

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs Rscript.dSYM
	@-rm -f Makedeps *.d *.o *.a *.lo *.la stamp-lo
distclean: clean
	@-rm -f Makefile Rscript
maintainer-clean: distclean

## we need to build at install time to capture the correct 'rhome'
install-Rscript:
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS0) $(LDFLAGS) -DR_HOME='"$(rhome)"' \
	  -o Rscript $(srcdir)/Rscript.c
	@$(MKINSTALLDIRS) "$(DESTDIR)$(Rexecbindir)"
	@$(INSTALL_PROGRAM) Rscript "$(DESTDIR)$(Rexecbindir)/Rscript"
## substitute at install time to allow 'prefix' to be overridden
install-pc:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(libdir)/pkgconfig"
	-@$(SED) -e "s:@rhome:$(rhome):" \
	  -e "s:@rincludedir:$(rincludedir):" \
	  -e "s:@rarch:$(R_ARCH):" \
	  -e 's:@libsprivate:$(STATIC_LIBR_PC):' \
	  -e 's:@others:$(MAIN_LDFLAGS) $(LDFLAGS):' \
	  -e 's/@VERSION/$(VERSION)/' $(srcdir)/libR.pc.in \
	  > "$(DESTDIR)$(libdir)/pkgconfig/libR.pc"

install: install-main
install: # install-pc
install: # install-pc

install-main: install-Rscript
	@$(MKINSTALLDIRS) "$(DESTDIR)$(bindir)"
	@$(INSTALL_PROGRAM) Rscript "$(DESTDIR)$(bindir)/Rscript"
	@if test -n "${R_ARCH}"; then \
	  $(MKINSTALLDIRS) "$(DESTDIR)$(Rexecbindir2)"; \
	  $(INSTALL_PROGRAM) Rscript "$(DESTDIR)$(Rexecbindir2)/Rscript"; \
	fi

uninstall:
	@rm -f "$(DESTDIR)$(bindir)/Rscript" "$(DESTDIR)$(Rexecbindir)/Rscript" \
	  "$(DESTDIR)$(Rexecbindir2)/Rscript" \
	  "$(DESTDIR)$(libdir)/pkgconfig/libR.pc"

install-strip:
	@$(MAKE) INSTALL_PROGRAM="${INSTALL_PROGRAM} -s" install

TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done

## Automagically generated dependencies:

Rembedded.o: Rembedded.c ../../src/include/config.h \
  ../../src/include/Defn.h ../../src/include/R_ext/Complex.h \
  ../../src/include/R_ext/Print.h ../../src/include/Rinternals.h \
  ../../src/include/R_ext/Arith.h ../../src/include/R_ext/libextern.h \
  ../../src/include/R_ext/Boolean.h ../../src/include/R_ext/Error.h \
  ../../src/include/R_ext/Memory.h ../../src/include/R_ext/Utils.h \
  ../../src/include/R_ext/Rdynload.h ../../src/include/Rinlinedfuns.h \
  ../../src/include/Errormsg.h ../../src/include/libintl.h
dynload.o: dynload.c ../../src/include/config.h ../../src/include/Defn.h \
  ../../src/include/R_ext/Complex.h ../../src/include/R_ext/Print.h \
  ../../src/include/Rinternals.h ../../src/include/R_ext/Arith.h \
  ../../src/include/R_ext/libextern.h ../../src/include/R_ext/Boolean.h \
  ../../src/include/R_ext/Error.h ../../src/include/R_ext/Memory.h \
  ../../src/include/R_ext/Utils.h ../../src/include/R_ext/Rdynload.h \
  ../../src/include/Rinlinedfuns.h ../../src/include/Errormsg.h \
  ../../src/include/libintl.h ../../src/include/Rdynpriv.h
system.o: system.c ../../src/include/config.h ../../src/include/Defn.h \
  ../../src/include/R_ext/Complex.h ../../src/include/R_ext/Print.h \
  ../../src/include/Rinternals.h ../../src/include/R_ext/Arith.h \
  ../../src/include/R_ext/libextern.h ../../src/include/R_ext/Boolean.h \
  ../../src/include/R_ext/Error.h ../../src/include/R_ext/Memory.h \
  ../../src/include/R_ext/Utils.h ../../src/include/R_ext/Rdynload.h \
  ../../src/include/Rinlinedfuns.h ../../src/include/Errormsg.h \
  ../../src/include/libintl.h ../../src/include/Fileio.h \
  ../../src/include/Rinterface.h ../../src/include/R_ext/RStartup.h \
  Runix.h
sys-unix.o: sys-unix.c ../../src/include/config.h \
  ../../src/include/Defn.h ../../src/include/R_ext/Complex.h \
  ../../src/include/R_ext/Print.h ../../src/include/Rinternals.h \
  ../../src/include/R_ext/Arith.h ../../src/include/R_ext/libextern.h \
  ../../src/include/R_ext/Boolean.h ../../src/include/R_ext/Error.h \
  ../../src/include/R_ext/Memory.h ../../src/include/R_ext/Utils.h \
  ../../src/include/R_ext/Rdynload.h ../../src/include/Rinlinedfuns.h \
  ../../src/include/Errormsg.h ../../src/include/libintl.h \
  ../../src/include/Internal.h ../../src/include/Fileio.h \
  ../../src/include/Rmath.h Runix.h ../../src/include/R_ext/RStartup.h \
  ../../src/include/R_ext/eventloop.h ../../src/include/Rinterface.h
sys-std.o: sys-std.c ../../src/include/config.h ../../src/include/Defn.h \
  ../../src/include/R_ext/Complex.h ../../src/include/R_ext/Print.h \
  ../../src/include/Rinternals.h ../../src/include/R_ext/Arith.h \
  ../../src/include/R_ext/libextern.h ../../src/include/R_ext/Boolean.h \
  ../../src/include/R_ext/Error.h ../../src/include/R_ext/Memory.h \
  ../../src/include/R_ext/Utils.h ../../src/include/R_ext/Rdynload.h \
  ../../src/include/Rinlinedfuns.h ../../src/include/Errormsg.h \
  ../../src/include/libintl.h ../../src/include/Internal.h \
  ../../src/include/Fileio.h Runix.h ../../src/include/R_ext/RStartup.h \
  ../../src/include/Startup.h ../../src/include/R_ext/Riconv.h \
  ../../src/include/R_ext/RS.h ../../src/include/Rconfig.h \
  ../../src/include/R_ext/eventloop.h ../../src/include/R_ext/Parse.h
X11.o: X11.c ../../src/include/config.h ../../src/include/Defn.h \
  ../../src/include/R_ext/Complex.h ../../src/include/R_ext/Print.h \
  ../../src/include/Rinternals.h ../../src/include/R_ext/Arith.h \
  ../../src/include/R_ext/libextern.h ../../src/include/R_ext/Boolean.h \
  ../../src/include/R_ext/Error.h ../../src/include/R_ext/Memory.h \
  ../../src/include/R_ext/Utils.h ../../src/include/R_ext/Rdynload.h \
  ../../src/include/Rinlinedfuns.h ../../src/include/Errormsg.h \
  ../../src/include/libintl.h ../../src/include/Internal.h \
  ../../src/include/Rconnections.h ../../src/include/R_ext/Connections.h \
  ../../src/include/Rdynpriv.h
