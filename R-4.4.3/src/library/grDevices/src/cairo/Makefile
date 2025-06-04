#
# ${R_HOME}/src/library/grDevices/src/cairo/Makefile


srcdir = .
top_srcdir = ../../../../..

top_builddir = ../../../../..
subdir = src/library/grDevices/src/cairo
R_HOME = $(top_builddir)

pkg = grDevices

## Although this is in a package,
## it uses the top-level Makeconf and not etc/Makeconf
include $(top_builddir)/Makeconf

## need to find bitmap.h
ALL_CPPFLAGS = $(R_XTRA_CPPFLAGS) -I/opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0 -I/opt/homebrew/Cellar/glib/2.84.2/include -I/opt/homebrew/Cellar/fribidi/1.0.16/include/fribidi -I/opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz -I/opt/homebrew/Cellar/graphite2/1.3.14/include -I/opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0 -I/opt/homebrew/Cellar/glib/2.84.2/lib/glib-2.0/include -I/opt/homebrew/opt/gettext/include -I/opt/homebrew/Cellar/pcre2/10.45/include -I/Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include/ffi -I/opt/homebrew/Cellar/cairo/1.18.4/include -I/opt/homebrew/Cellar/cairo/1.18.4/include/cairo -I/opt/homebrew/Cellar/fontconfig/2.16.0/include -I/opt/homebrew/opt/freetype/include/freetype2 -I/opt/homebrew/Cellar/libxext/1.3.6/include -I/opt/homebrew/Cellar/xorgproto/2024.1/include -I/opt/homebrew/Cellar/libxrender/0.9.12/include -I/opt/homebrew/Cellar/libx11/1.8.12/include -I/opt/homebrew/Cellar/libxcb/1.17.0/include -I/opt/homebrew/Cellar/libxau/1.0.12/include -I/opt/homebrew/Cellar/libxdmcp/1.1.5/include -I/opt/homebrew/Cellar/pixman/0.46.0/include/pixman-1 -I/opt/homebrew/opt/libpng/include/libpng16 \
  -I$(top_srcdir)/src/modules/X11 $(CPPFLAGS) $(DEFS)
ALL_CFLAGS = $(ALL_CFLAGS_LO)

## the X11 module is not made at all if BUILD_X11 is false.
SOURCES = cairoBM.c
DEPENDS = $(SOURCES:.c=.d)
OBJECTS = $(SOURCES:.c=.o) $(top_builddir)/src/modules/X11/rbitmap.o

cairo_la = cairo$(SHLIB_EXT)
## This order has to be consistent with the other use of rbitmap.o
## AIX needs LIBM
cairo_la_LIBADD = -L/opt/homebrew/opt/libtiff/lib -ltiff -L/opt/homebrew/opt/jpeg-turbo/lib -ljpeg -L/opt/homebrew/opt/libpng/lib -lpng16 -L/opt/homebrew/Cellar/pango/1.56.3/lib -lpangocairo-1.0 -lm -framework CoreFoundation -framework ApplicationServices -lpangoft2-1.0 -lm -framework CoreFoundation -framework ApplicationServices -lpango-1.0 -lm -framework CoreFoundation -framework ApplicationServices -L/opt/homebrew/Cellar/glib/2.84.2/lib -lgio-2.0 -lintl -framework Foundation -framework CoreFoundation -framework AppKit -lresolv -lgmodule-2.0 -lintl -L/opt/homebrew/Cellar/fribidi/1.0.16/lib -lfribidi -L/opt/homebrew/Cellar/harfbuzz/11.2.1/lib -lharfbuzz-gobject -lharfbuzz -lm -framework ApplicationServices -L/opt/homebrew/Cellar/graphite2/1.3.14/lib -lgraphite2 -lgobject-2.0 -lglib-2.0 -L/opt/homebrew/opt/gettext/lib -lintl -liconv -lm -framework Foundation -framework CoreFoundation -framework AppKit -framework Carbon -L/opt/homebrew/Cellar/pcre2/10.45/lib -lpcre2-8 -D_THREAD_SAFE -pthread -lffi -L/opt/homebrew/Cellar/cairo/1.18.4/lib -lcairo -lm -ldl -framework CoreFoundation -framework ApplicationServices -L/opt/homebrew/Cellar/fontconfig/2.16.0/lib -lfontconfig -lexpat -L/opt/homebrew/opt/freetype/lib -lfreetype -lbz2 -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libxrender/0.9.12/lib -lXrender -L/opt/homebrew/Cellar/libx11/1.8.12/lib -lX11 -L/opt/homebrew/Cellar/libxcb/1.17.0/lib -lxcb-render -lxcb-shm -lxcb -L/opt/homebrew/Cellar/libxau/1.0.12/lib -lXau -L/opt/homebrew/Cellar/libxdmcp/1.1.5/lib -lXdmcp -L/opt/homebrew/Cellar/pixman/0.46.0/lib -lpixman-1 -lm -L/opt/homebrew/opt/libpng/lib -lpng16 -lz $(LIBR) $(LIBM)  $(LIBINTL)

all: Makedeps
	@$(MAKE) R

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

Makedeps: Makefile $(DEPENDS)
	@cat $(DEPENDS) >> Makefile
	@touch $@

R: Makefile
	@$(MAKE) $(cairo_la)
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)/libs
	@cp $(cairo_la) $(top_builddir)/library/$(pkg)/libs

$(top_builddir)/src/modules/X11/rbitmap.o:
	(cd $(top_builddir)/src/modules/X11; $(MAKE) rbitmap.o)

$(cairo_la): $(OBJECTS)
	$(SHLIB_LINK) -o $@ $(OBJECTS) $(cairo_la_LIBADD)

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs Makedeps *.d *.o $(cairo_la)
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

## Automagically generated dependencies:
cairoBM.o: cairoBM.c ../../../../../src/include/config.h \
  ../../../../../src/include/Defn.h \
  ../../../../../src/include/R_ext/Complex.h \
  ../../../../../src/include/R_ext/Print.h \
  ../../../../../src/include/Rinternals.h \
  ../../../../../src/include/R_ext/Arith.h \
  ../../../../../src/include/R_ext/libextern.h \
  ../../../../../src/include/R_ext/Boolean.h \
  ../../../../../src/include/R_ext/Error.h \
  ../../../../../src/include/R_ext/Memory.h \
  ../../../../../src/include/R_ext/Utils.h \
  ../../../../../src/include/R_ext/Rdynload.h \
  ../../../../../src/include/Rinlinedfuns.h \
  ../../../../../src/include/Errormsg.h \
  ../../../../../src/include/libintl.h \
  ../../../../../src/include/R_ext/GraphicsEngine.h \
  ../../../../../src/include/R_ext/GraphicsDevice.h \
  ../../../../../src/include/Fileio.h cairoBM.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-attributes.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-font.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-coverage.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib-object.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gbinding.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/galloca.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtypes.h \
  /opt/homebrew/Cellar/glib/2.84.2/lib/glib-2.0/include/glibconfig.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmacros.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gversionmacros.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/glib-visibility.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/garray.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gasyncqueue.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gthread.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gatomic.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/glib-typeof.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gerror.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gquark.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gutils.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gbacktrace.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gbase64.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gbitlock.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gbookmarkfile.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gdatetime.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtimezone.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gbytes.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gcharset.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gchecksum.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gconvert.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gdataset.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gdate.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gdir.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/genviron.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gfileutils.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/ggettext.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/ghash.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/glist.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmem.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gnode.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/ghmac.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/ghook.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/ghostutils.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/giochannel.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmain.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gpoll.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gslist.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gstring.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gunicode.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gstrfuncs.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gkeyfile.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmappedfile.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmarkup.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gmessages.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gvariant.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gvarianttype.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/goption.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gpathbuf.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gpattern.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gprimes.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gqsort.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gqueue.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/grand.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/grcbox.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/grefcount.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/grefstring.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gregex.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gscanner.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gsequence.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gshell.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gslice.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gspawn.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gstringchunk.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gstrvbuilder.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtestutils.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gthreadpool.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtimer.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtrashstack.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gtree.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/guri.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/guuid.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/gversion.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/gallocator.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/gcache.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/gcompletion.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/gmain.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/grel.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/deprecated/gthread.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/glib/glib-autocleanups.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gobject.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gtype.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gobject-visibility.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gvalue.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gparam.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gclosure.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gsignal.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gmarshal.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gboxed.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/glib-types.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gbindinggroup.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/genums.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/glib-enumtypes.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gparamspecs.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gsignalgroup.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gsourceclosure.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gtypemodule.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gtypeplugin.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gvaluearray.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gvaluetypes.h \
  /opt/homebrew/Cellar/glib/2.84.2/include/glib-2.0/gobject/gobject-autocleanups.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-version-macros.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-features.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-blob.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-common.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-script-list.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-buffer.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-unicode.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-font.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-face.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-map.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-set.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-draw.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-paint.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-deprecated.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-shape.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-shape-plan.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-style.h \
  /opt/homebrew/Cellar/harfbuzz/11.2.1/include/harfbuzz/hb-version.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-types.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-gravity.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-matrix.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-script.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-language.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-bidi-type.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-direction.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-color.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-break.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-item.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-context.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-fontmap.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-fontset.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-engine.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-glyph.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-enum-types.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-fontset-simple.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-glyph-item.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-layout.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-tabs.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-markup.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-renderer.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pango-utils.h \
  /opt/homebrew/Cellar/pango/1.56.3/include/pango-1.0/pango/pangocairo.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-version.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-features.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-deprecated.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-svg.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-pdf.h \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-ps.h cairoFns.c \
  /opt/homebrew/Cellar/cairo/1.18.4/include/cairo/cairo-ft.h \
  /opt/homebrew/opt/freetype/include/freetype2/ft2build.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/ftheader.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/freetype.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/ftconfig.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/ftoption.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/ftstdlib.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/integer-types.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/public-macros.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/config/mac-support.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/fttypes.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/ftsystem.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/ftimage.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/fterrors.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/ftmoderr.h \
  /opt/homebrew/opt/freetype/include/freetype2/freetype/fterrdef.h \
  /opt/homebrew/Cellar/fontconfig/2.16.0/include/fontconfig/fontconfig.h \
  ../../../../../src/modules/X11/bitmap.h
