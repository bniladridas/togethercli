#
# ${R_HOME}/src/library/stats/src/Makefile

pkg = stats


srcdir = .
top_srcdir = ../../../..

top_builddir = ../../../..
subdir = src/library/$(pkg)/src
R_HOME = $(top_builddir)
## for $(R_HOME)/etc${R_ARCH}/Makeconf
R_SHARE_DIR = $(R_HOME)/share
R_INCLUDE_DIR = $(R_HOME)/include

SOURCES_C = init.c kmeans.c \
  ansari.c bandwidths.c chisqsim.c d2x2xk.c fexact.c kendall.c ks.c \
  line.c smooth.c \
  prho.c swilk.c \
  ksmooth.c loessc.c monoSpl.c isoreg.c Srunmed.c \
  dblcen.c distance.c hclust-utils.c \
  nls.c rWishart.c \
  HoltWinters.c PPsum.c arima.c burg.c filter.c \
  mAR.c pacf.c starma.c port.c family.c sbart.c \
  approx.c loglin.c lowess.c massdist.c splines.c lm.c \
  complete_cases.c cov.c deriv.c fft.c fourier.c model.c optim.c optimize.c \
  integrate.c random.c distn.c zeroin.c rcont.c influence.c

SOURCES_F = bsplvd.f bvalue.f bvalus.f loessf.f ppr.f qsbart.f \
  sgram.f sinerp.f sslvrg.f stxwx.f \
  hclust.f kmns.f \
  eureka.f stl.f portsrc.f lminfl.f
DEPENDS = $(SOURCES_C:.c=.d)
OBJECTS = $(SOURCES_C:.c=.o) $(SOURCES_F:.f=.o)
# need config.h
PKG_CPPFLAGS = -I../../../include -I$(top_srcdir)/src/include -DHAVE_CONFIG_H
PKG_CFLAGS =  $(C_VISIBILITY)
PKG_FFLAGS = $(F_VISIBILITY)

SHLIB = $(pkg).so

## <FIXME>
## We should really add FLIBS to SHLIB_LIBADD, but we need to include
## the shlib Makeconf at a later stage, and its default value would
## override our setting.
PKG_LIBS =  $(LAPACK_LIBS) $(BLAS_LIBS) $(FLIBS)
## </FIXME>


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
LTO_FC = 

## Meeded with i386 gcc 4.5.0 -- PR#14427
## (SHLIB_FFLAGS is apparently currently unused)
portsrc_FFLAGS=$(FPICFLAGS) $(SHLIB_FFLAGS) -g -O2 $(LTO_FC)
portsrc.o: portsrc.f
	$(FC) $(portsrc_FFLAGS) -c $< -o $@

mostlyclean: clean
clean:
	@-rm -Rf .libs _libs
	@-rm -f Makedeps *.d *.o *$(SHLIB_EXT)
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

## Automagically generated dependencies:
init.o: init.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h nls.h port.h stats.h statsR.h ts.h \
  ../../../../include/R_ext/Visibility.h
kmeans.o: kmeans.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
ansari.o: ansari.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rmath.h stats.h ../../../../include/libintl.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
bandwidths.o: bandwidths.c ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h ../../../../include/libintl.h
chisqsim.o: chisqsim.c ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h stats.h ../../../../include/libintl.h
d2x2xk.o: d2x2xk.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rmath.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Rdynload.h
fexact.o: fexact.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  stats.h ../../../../include/libintl.h ../../../../include/Rmath.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
kendall.o: kendall.c ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rmath.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Rdynload.h
ks.o: ks.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h stats.h ../../../../include/libintl.h
line.o: line.c ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Rdynload.h ../../../../include/Rconfig.h \
  statsR.h
smooth.o: smooth.c ../../../include/config.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
prho.o: prho.c ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h
swilk.o: swilk.c ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h
ksmooth.o: ksmooth.c ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
loessc.o: loessc.c ../../../include/config.h ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
monoSpl.o: monoSpl.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
isoreg.o: isoreg.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h
Srunmed.o: Srunmed.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h Trunmed.c
dblcen.o: dblcen.c ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h
distance.o: distance.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rmath.h stats.h ../../../../include/libintl.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
hclust-utils.o: hclust-utils.c ../../../../include/R_ext/Boolean.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h statsR.h
nls.o: nls.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  nls.h ../../../../include/libintl.h
rWishart.o: rWishart.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rmath.h ../../../../include/R_ext/Lapack.h \
  ../../../../include/R_ext/BLAS.h stats.h ../../../../include/libintl.h \
  statsR.h
HoltWinters.o: HoltWinters.c ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h
PPsum.o: PPsum.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
arima.o: arima.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h statsR.h
burg.o: burg.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h
filter.o: filter.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h
mAR.o: mAR.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/R_ext/Applic.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h
pacf.o: pacf.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h
starma.o: starma.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h ts.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  stats.h ../../../../include/libintl.h
port.o: port.c port.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/RS.h \
  ../../../../include/libintl.h ../../../../include/R_ext/BLAS.h
family.o: family.c ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Constants.h \
  stats.h ../../../../include/libintl.h ../../../../include/R_ext/RS.h \
  statsR.h
sbart.o: sbart.c modreg.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/libintl.h ../../../../include/Rmath.h
approx.o: approx.c ../../../include/config.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Applic.h ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/RS.h ../../../../include/Rconfig.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../../include/libintl.h \
  statsR.h
loglin.o: loglin.c ../../../include/config.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Applic.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Random.h ../../../../include/R_ext/Utils.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  statsR.h ../../../../include/libintl.h
lowess.o: lowess.c ../../../include/config.h \
  ../../../../include/libintl.h ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Applic.h \
  ../../../../include/R_ext/RS.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Complex.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Rdynload.h
massdist.o: massdist.c ../../../include/config.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h
splines.o: splines.c ../../../include/config.h ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/R_ext/Applic.h ../../../include/Defn.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../include/Rinlinedfuns.h ../../../include/Errormsg.h \
  ../../../../include/libintl.h statsR.h
lm.o: lm.c ../../../../include/R.h ../../../../include/Rconfig.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/Applic.h statsR.h \
  ../../../../include/libintl.h
complete_cases.o: complete_cases.c ../../../include/config.h \
  ../../../include/Defn.h ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Print.h ../../../../include/Rinternals.h \
  ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h
cov.o: cov.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/Rmath.h statsR.h
deriv.o: deriv.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h
fft.o: fft.c ../../../include/config.h ../../../../include/Rmath.h \
  ../../../../include/R_ext/Boolean.h
fourier.o: fourier.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h statsR.h
model.o: model.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h statsR.h
optim.o: optim.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/Applic.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h statsR.h
optimize.o: optimize.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/R_ext/Applic.h \
  ../../../../include/R_ext/RS.h ../../../../include/Rconfig.h statsR.h \
  stats.h ../../../../include/libintl.h ../../../../include/Rmath.h
integrate.o: integrate.c ../../../include/config.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Memory.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/Rdynload.h \
  ../../../../include/R_ext/Applic.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h ../../../../include/libintl.h
random.o: random.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/R_ext/Random.h ../../../../include/Rmath.h \
  statsR.h stats.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h
distn.o: distn.c ../../../include/config.h ../../../include/Defn.h \
  ../../../../include/R_ext/Complex.h ../../../../include/R_ext/Print.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Rdynload.h ../../../include/Rinlinedfuns.h \
  ../../../include/Errormsg.h ../../../../include/libintl.h \
  ../../../../include/Rmath.h statsR.h
zeroin.o: zeroin.c ../../../../include/R_ext/Applic.h \
  ../../../../include/R_ext/Boolean.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h
rcont.o: rcont.c ../../../include/config.h ../../../../include/libintl.h \
  ../../../../include/R_ext/Random.h ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Applic.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Error.h \
  ../../../../include/R_ext/Print.h ../../../../include/R_ext/Utils.h \
  ../../../../include/R_ext/Complex.h stats.h
influence.o: influence.c ../../../../include/R.h \
  ../../../../include/Rconfig.h ../../../../include/R_ext/Arith.h \
  ../../../../include/R_ext/libextern.h \
  ../../../../include/R_ext/Boolean.h \
  ../../../../include/R_ext/Complex.h \
  ../../../../include/R_ext/Constants.h \
  ../../../../include/R_ext/Error.h ../../../../include/R_ext/Print.h \
  ../../../../include/R_ext/Memory.h ../../../../include/R_ext/Random.h \
  ../../../../include/R_ext/Utils.h ../../../../include/R_ext/RS.h \
  ../../../../include/Rinternals.h ../../../../include/R_ext/Rdynload.h \
  statsR.h stats.h ../../../../include/libintl.h
