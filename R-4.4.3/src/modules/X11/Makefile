#
# ${R_HOME}/src/modules/X11/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/modules/X11
R_HOME = $(top_builddir)

include $(top_builddir)/Makeconf

## When compiling rbitmap.c it is essential that we find the
## png.h matching BITMAP_LIBS.  Since /opt/X11 on macOS contains libpng
## and we might want our own version, we give priority to BITMAP_*
ALL_CPPFLAGS =  -I/opt/homebrew/opt/libpng/include/libpng16 -I/opt/homebrew/opt/libtiff/include -I/opt/homebrew/opt/zstd/include -I/opt/homebrew/Cellar/xz/5.8.1/include -I/opt/homebrew/opt/jpeg-turbo/include $(R_XTRA_CPPFLAGS) $(X_CFLAGS) -I/opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0 -I/opt/homebrew/Cellar/glib/2.84.2/include -I/opt/homebrew/Cellar/fribidi/1.0.16/include/fribidi -I/opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz -I/opt/homebrew/Cellar/graphite2/1.3.14/include -I/opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0 -I/opt/homebrew/Cellar/glib/2.84.2/lib/glib-2.0/include -I/opt/homebrew/opt/gettext/include -I/opt/homebrew/Cellar/pcre2/10.45/include -I/Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include/ffi -I/opt/homebrew/Cellar/cairo/1.18.4/include -I/opt/homebrew/Cellar/cairo/1.18.4/include/cairo -I/opt/homebrew/Cellar/fontconfig/2.16.0/include -I/opt/homebrew/opt/freetype/include/freetype2 -I/opt/homebrew/opt/libpng/include/libpng16 -I/opt/homebrew/Cellar/libxrender/0.9.12/include -I/opt/homebrew/Cellar/xorgproto/2024.1/include -I/opt/homebrew/Cellar/libxcb/1.17.0/include -I/opt/homebrew/Cellar/pixman/0.46.0/include/pixman-1 -I/opt/homebrew/Cellar/libxext/1.3.6/include -I/opt/homebrew/Cellar/libx11/1.8.12/include -I/opt/homebrew/Cellar/libxau/1.0.12/include -I/opt/homebrew/Cellar/libxdmcp/1.1.5/include \
  -I$(top_srcdir)/src/library/grDevices/src/cairo $(CPPFLAGS) $(DEFS)
ALL_CFLAGS = $(ALL_CFLAGS_LO)
## This relies on ld re-ordering the flags, as X_PRE_LIBS does not
## contain a -L flag but relies on that in X_LIBS.
## This comes from AC_PATH_XTRA so we have not interfered.
ALL_X_LIBS = $(X_PRE_LIBS) -L/opt/homebrew/Cellar/pango/1.56.3/lib -lpangocairo-1.0 -lm -framework CoreFoundation -framework ApplicationServices -lpangoft2-1.0 -lm -framework CoreFoundation -framework ApplicationServices -lpango-1.0 -lm -framework CoreFoundation -framework ApplicationServices -L/opt/homebrew/Cellar/glib/2.84.2/lib -lgio-2.0 -lintl -framework Foundation -framework CoreFoundation -framework AppKit -lresolv -lgmodule-2.0 -lintl -L/opt/homebrew/Cellar/fribidi/1.0.16/lib -lfribidi -L/opt/homebrew/Cellar/harfbuzz/11.2.1/lib -lharfbuzz-gobject -lharfbuzz -lm -framework ApplicationServices -L/opt/homebrew/Cellar/graphite2/1.3.14/lib -lgraphite2 -lgobject-2.0 -lglib-2.0 -L/opt/homebrew/opt/gettext/lib -lintl -liconv -lm -framework Foundation -framework CoreFoundation -framework AppKit -framework Carbon -L/opt/homebrew/Cellar/pcre2/10.45/lib -lpcre2-8 -D_THREAD_SAFE -pthread -lffi -L/opt/homebrew/Cellar/cairo/1.18.4/lib -lcairo -lm -ldl -framework CoreFoundation -framework ApplicationServices -L/opt/homebrew/Cellar/fontconfig/2.16.0/lib -lfontconfig -lexpat -L/opt/homebrew/opt/freetype/lib -lfreetype -lbz2 -L/opt/homebrew/opt/libpng/lib -lpng16 -lz -L/opt/homebrew/Cellar/libxrender/0.9.12/lib -lXrender -L/opt/homebrew/Cellar/libxcb/1.17.0/lib -lxcb-render -lxcb-shm -L/opt/homebrew/Cellar/pixman/0.46.0/lib -lpixman-1 -lm -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.12/lib -lX11 -lxcb -L/opt/homebrew/Cellar/libxau/1.0.12/lib -lXau -L/opt/homebrew/Cellar/libxdmcp/1.1.5/lib -lXdmcp $(X_LIBS) $(X_EXTRA_LIBS)

SOURCES = devX11.c rotated.c rbitmap.c 
DEPENDS = $(SOURCES:.c=.d)
OBJECTS = $(SOURCES:.c=.o)
DE_SOURCES = dataentry.c
DE_OBJECTS = $(DE_SOURCES:.c=.o)
HEADERS = bitmap.h devX11.h rotated.h rlogo_icon.h

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = \
	Makefile.in $(SOURCES) $(HEADERS) $(DE_SOURCES)

R_X11_la = R_X11$(SHLIB_EXT)
## Note that this is used after LDFLAGS, which usually contains -L flags.
## AIX needs LIBM
R_X11_la_LIBADD = -L/opt/homebrew/opt/libtiff/lib -ltiff -L/opt/homebrew/opt/jpeg-turbo/lib -ljpeg -L/opt/homebrew/opt/libpng/lib -lpng16 $(ALL_X_LIBS) $(LIBR1) $(LIBM)  $(LIBINTL)

R_de_la = R_de$(SHLIB_EXT)
R_de_la_LIBADD = $(ALL_X_LIBS) $(LIBR1) $(LIBM)  $(LIBINTL)

all: R

Makefile: $(srcdir)/Makefile.in \
  $(top_builddir)/config.status \
  $(SOURCES)
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

Makedeps: Makefile $(DEPENDS)
	@cat $(DEPENDS) >> Makefile
	@touch $@

R: Makedeps
	@$(MAKE) $(R_X11_la) $(R_de_la)
	@$(MAKE) rhome="$(abs_top_builddir)" install

$(R_X11_la): $(OBJECTS)
	$(SHLIB_LINK) -o $@ $(OBJECTS) $(R_X11_la_LIBADD)

$(R_de_la): $(DE_OBJECTS)
	$(SHLIB_LINK) -o $@ $(DE_OBJECTS) $(R_de_la_LIBADD)

install: installdirs
	@$(SHELL) $(top_srcdir)/tools/copy-if-change $(R_X11_la) "$(DESTDIR)$(Rexecmodulesdir)/$(R_X11_la)"
	@$(SHELL) $(top_srcdir)/tools/copy-if-change $(R_de_la) "$(DESTDIR)$(Rexecmodulesdir)/$(R_de_la)"
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(Rexecmodulesdir)"
install-strip: installdirs
	@$(SHELL) $(top_srcdir)/tools/copy-if-change $(R_X11_la) "$(DESTDIR)$(Rexecmodulesdir)/$(R_X11_la)"
	@$(SHELL) $(top_srcdir)/tools/copy-if-change $(R_X11_la) "$(DESTDIR)$(Rexecmodulesdir)/$(R_de_la)"
	@if test -n "$(STRIP_SHARED_LIB)"; then \
	  $(STRIP_SHARED_LIB) "$(DESTDIR)$(Rexecmodulesdir)/$(R_X11_la)" ;\
	  $(STRIP_SHARED_LIB) "$(DESTDIR)$(Rexecmodulesdir)/$(R_de_la)" ;\
	fi
uninstall:
	@rm -f "$(Rexecmodulesdir)/R_X11$(SHLIB_EXT)"\
	  "$(Rexecmodulesdir)/R_de(SHLIB_EXT)"

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs
	@-rm -f Makedeps *.d *.o *.a *.lo *.la *$(SHLIB_EXT)
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

TAGS info dvi check:

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done

## Automagically generated dependencies:

