#
# ${R_HOME}/tests/Embedding/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = tests/Embedding

R_HOME=$(top_builddir)
R_SHARE_DIR=$(R_HOME)/share
R_INCLUDE_DIR=$(R_HOME)/include
include $(top_builddir)/etc/Makeconf
BUILDDIR_IS_SRCDIR = yes
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

PACKAGE = R
VERSION = 4.4.3
distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

SOURCES_R = error.R foo.R
SOURCES_C = \
  RNamedCall.c \
  RParseEval.c \
  Rerror.c \
  Rpackage.c \
  Rplot.c \
  Rpostscript.c \
  Rtest.c \
  embeddedRCall.c \
  tryEval.c

HEADERS = embeddedRCall.h
PROGRAMS = Rtest Rplot Rpostscript Rerror RNamedCall RParseEval Rpackage tryEval

## <FIXME>
## Currently Rshutdown.c is not used.
DISTFILES = Makefile.in Makefile.win index.html \
  $(SOURCES_R) $(SOURCES_C) $(HEADERS) \
  Rshutdown.c
## </FIXME>

## need LD_LIBRARY_PATH to include ../../lib for e.g. libRblas.so
R_CMD_LINK = $(top_builddir)/bin/R CMD $(MAIN_LINK)
#MY_LIBR = $(LIBR)
#MY_LIBR = $(STATIC_LIBR)

all: Makefile R-sources tests

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

R-sources:
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  for f in $(SOURCES_R); \
	    do $(INSTALL_DATA) $(srcdir)/$${f} .; \
	  done; \
	fi

R_EXE=../../bin/R CMD

tests: $(PROGRAMS)
	$(R_EXE) ./Rtest --silent
	$(R_EXE) ./RNamedCall --silent
	$(R_EXE) ./RParseEval --silent
	$(R_EXE) ./Rpackage --silent
	$(R_EXE) ./Rerror --silent
	$(R_EXE) ./Rplot --silent
	$(R_EXE) ./Rpostscript --silent --no-save
	$(R_EXE) ./tryEval --silent

Rtest: Rtest.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ Rtest.o embeddedRCall.o $(MY_LIBR)
Rplot: Rplot.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ Rplot.o embeddedRCall.o $(MY_LIBR)
Rpostscript: Rpostscript.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ Rpostscript.o embeddedRCall.o $(MY_LIBR)
Rerror: Rerror.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ Rerror.o embeddedRCall.o $(MY_LIBR)
Rpackage: Rpackage.o  embeddedRCall.o
	$(R_CMD_LINK) -o $@ Rpackage.o embeddedRCall.o $(MY_LIBR)
RNamedCall: RNamedCall.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ RNamedCall.o embeddedRCall.o $(MY_LIBR)
RParseEval: RParseEval.o embeddedRCall.o
	$(R_CMD_LINK) -o $@ RParseEval.o embeddedRCall.o $(MY_LIBR)

tryEval: tryEval.o
	$(R_CMD_LINK) -o $@ tryEval.o $(MY_LIBR)	

R.so: showArgs.o
	$(SHLIB_LINK) -o $@ showArgs.o

mostlyclean: clean
clean:
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -f $(SOURCES_R); \
	fi
	@-rm -Rf .libs _libs
	@-rm -f *.o $(PROGRAMS) Rplots.pdf Rplots.ps
distclean: clean
	@-rm -f Makefile
maintainer-clean: distclean

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
