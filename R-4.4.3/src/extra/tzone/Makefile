#
# ${R_HOME}/src/extra/tzone/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/extra/tzone

include $(top_builddir)/Makeconf

SOURCES = localtime.c strftime.c
SOURCES_WIN = registryTZ.c
HEADERS = tzfile.h

DEPENDS = $(SOURCES:.c=.d)
OBJECTS = $(SOURCES:.c=.o)
#ALL_CFLAGS = $(R_XTRA_CFLAGS) $(CPICFLAGS) $(SHLIB_CFLAGS) $(CFLAGS) 

ALL_CPPFLAGS=$(R_XTRA_CPPFLAGS) -I$(srcdir) -I$(top_srcdir)/src/main $(CPPFLAGS) $(DEFS) -I/System/Library/Frameworks/CoreFoundation.framework/Headers

R all: Makefile 
	@$(MAKE) Makedeps
	@$(MAKE) libtz.a

libtz.a: $(OBJECTS)
	@rm -f $@
	$(AR) -cr $@ $(OBJECTS)
	@$(RANLIB) $@


Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

Makedeps: Makefile $(DEPENDS)
	@cat $(DEPENDS) >> Makefile
	@touch $@

mostlyclean: clean
clean:
	@-rm -f Makedeps *.d *.o *.lo *.a
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

install install-strip uninstall TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = Makefile.in Makefile.win \
  Make.zi Notes zoneinfo.zip \
  $(SOURCES) $(SOURCES_WIN) $(HEADERS)

## Automagically generated dependencies:
localtime.o: localtime.c ../../../src/include/config.h \
  ../../../src/main/datetime.h tzfile.h
strftime.o: strftime.c ../../../src/include/config.h tzfile.h \
  ../../../src/main/datetime.h
