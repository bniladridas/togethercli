#
# ${R_HOME}/src/library/grDevices/src/Makefile

pkg = grDevices


srcdir = .
top_srcdir = ../../../..

top_builddir = ../../../..
subdir = src/library/$(pkg)/src
R_HOME = $(top_builddir)
R_SHARE_DIR = $(R_HOME)/share
R_INCLUDE_DIR = $(R_HOME)/include

SOURCES_C = axis_scales.c chull.c devices.c init.c stubs.c colors.c \
  clippath.c patterns.c mask.c group.c \
  devCairo.c devPicTeX.c devPS.c \
  devQuartz.c  qdBitmap.c qdPDF.c
SOURCES_M =  qdCocoa.m

DEPENDS = $(SOURCES_C:.c=.d) $(SOURCES_M:.m=.d)
OBJECTS = $(SOURCES_C:.c=.o) $(SOURCES_M:.m=.o)

SHLIB = $(pkg).so

# need Defn.h etc, and config.h
PKG_CPPFLAGS =-I../../../include -I$(top_srcdir)/src/include -DHAVE_CONFIG_H

AQUA_LIBS = -framework AppKit
PKG_LIBS = $(AQUA_LIBS) -lz

all: Makedeps
	@$(MAKE) shlib  cairodevice

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

Makedeps: Makefile $(DEPENDS)
	@cat $(DEPENDS) >> Makefile
	@touch $@

shlib: $(SHLIB)
	@$(MKINSTALLDIRS) \
	  $(top_builddir)/library/$(pkg)/libs
	@$(SHELL) $(top_srcdir)/tools/copy-if-change $(SHLIB) \
	  $(top_builddir)/library/$(pkg)/libs/$(SHLIB)

cairodevice:
	@(cd cairo && $(MAKE))

include $(R_HOME)/etc${R_ARCH}/Makeconf
include $(top_srcdir)/share/make/shlib.mk
## override to use LTO for linking with --enable-lto=R
LTO = 

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs
	@-rm -f Makedeps *.d *.o *$(SHLIB_EXT)
	@(cd cairo && $(MAKE) clean)
distclean: clean
	@-rm -f Makefile
	@(cd cairo && $(MAKE) distclean)
maintainer-clean: distclean

## Automagically generated dependencies:
axis_scales.o: axis_scales.c ../../../include/config.h \
  ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h \
  ../../../../include/libintl.h
chull.o: chull.c ../../../include/config.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h
devices.o: devices.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../include/Graphics.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../include/Rgraphics.h ../../../include/GraphicsBase.h
init.o: init.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h \
  ../../../../include/libintl.h ../../../../include/R_ext/Visibility.h
stubs.o: stubs.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../include/Internal.h grDevices.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h
colors.o: colors.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h
clippath.o: clippath.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h
patterns.o: patterns.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h
mask.o: mask.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h
group.o: group.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h grDevices.h
devCairo.o: devCairo.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h
devPicTeX.o: devPicTeX.c ../../../include/config.h \
  ../../../include/Defn.h ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Print.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../include/rlocale.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h ../../../include/Fileio.h \
  grDevices.h
devPS.o: devPS.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/Riconv.h ../../../../include/Rmath.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/R_ext/RS.h ../../../../include/Rconfig.h \
  ../../../include/Fileio.h grDevices.h ../../../include/rlocale.h \
  ../../../../include/Rversion.h
devQuartz.o: devQuartz.c ../../../include/config.h \
  ../../../include/Defn.h ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Print.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/R_ext/QuartzDevice.h grDevices.h qdCocoa.h \
  ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Random.h ../../../../include/R_ext/RS.h \
  qdBitmap.h qdPDF.h
qdBitmap.o: qdBitmap.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h qdBitmap.h \
  ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Random.h ../../../../include/R_ext/RS.h \
  ../../../../include/R_ext/QuartzDevice.h
qdPDF.o: qdPDF.c qdPDF.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/R_ext/QuartzDevice.h ../../../include/config.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
qdCocoa.o: qdCocoa.m qdCocoa.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/R_ext/QuartzDevice.h ../../../include/config.h \
  qdPDF.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/eventloop.h
