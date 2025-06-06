#
# ${R_HOME}/src/library/grid/src/Makefile

pkg = grid


srcdir = .
top_srcdir = ../../../..

top_builddir = ../../../..
subdir = src/library/$(pkg)/src
R_HOME = $(top_builddir)
R_SHARE_DIR = $(R_HOME)/share
R_INCLUDE_DIR = $(R_HOME)/include

SOURCES_C = clippath.c gpar.c grid.c just.c layout.c mask.c matrix.c path.c \
  register.c state.c typeset.c unit.c util.c viewport.c

SOURCES_F =
DEPENDS = $(SOURCES_C:.c=.d)
OBJECTS = $(SOURCES_C:.c=.o) $(SOURCES_F:.f=.o)

PKG_CFLAGS=$(C_VISIBILITY)

SHLIB = $(pkg).so

all: Makedeps
	@$(MAKE) shlib

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

include $(R_HOME)/etc${R_ARCH}/Makeconf
include $(top_srcdir)/share/make/shlib.mk
## override to use LTO for linking with --enable-lto=R
LTO = 

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs
	@-rm -f Makedeps *.d *.o *$(SHLIB_EXT)
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

## Automagically generated dependencies:
clippath.o: clippath.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
gpar.o: gpar.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
grid.o: grid.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
just.o: just.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
layout.o: layout.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
mask.o: mask.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
matrix.o: matrix.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
path.o: path.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
register.o: register.c ../../../../include/R_ext/Visibility.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/Boolean.h grid.h ../../../../include/R.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/Rmath.h \
  ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
state.o: state.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
typeset.o: typeset.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
unit.o: unit.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
util.o: util.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
viewport.o: viewport.c grid.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/GraphicsEngine.h \
  ../../../../include/R_ext/GraphicsDevice.h \
  ../../../../include/libintl.h
