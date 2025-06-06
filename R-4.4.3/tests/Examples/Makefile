#
# ${R_HOME}/tests/Examples/Makefile


srcdir = .
top_srcdir = ../..

top_builddir = ../..
subdir = tests/Examples

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
INSTFILES = \
  datasets-Ex.Rout.save grDevices-Ex.Rout.save graphics-Ex.Rout.save \
  grid-Ex.Rout.save splines-Ex.Rout.save \
  stats-Ex.Rout.save stats4-Ex.Rout.save tools-Ex.Rout.save
DISTFILES = Makefile.in  Makefile.win $(INSTFILES)

## R_LIBS_SITE has to be non-empty or it is ignored
## Note that this does not set LC_COLLATE.  The collation of examples
## is done in C order in massageExamples(), but we want to test the
## orderings users use.
R_EXE = LANGUAGE=en LC_TIME=C R_LIBS= R_LIBS_USER=NULL R_LIBS_SITE=NULL \
  $(top_builddir)/bin/R --vanilla --no-echo

all: Makefile test-Examples-Base

Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

test-Examples: test-Examples-Base

TEST_DONTTEST = FALSE
## Who does make check but not make? -- maybe better to check what was made.
test-Examples-Base: Makefile
	@$(ECHO) "tools::testInstalledPackages(scope='base', types='examples', srcdir=if(!$(TEST_DONTTEST)) \"$(srcdir)\", commentDonttest=!$(TEST_DONTTEST))" | $(R_EXE)


## <NOTE>
## We do *not* want this to be added to test-Examples conditional on
## .
## 'make check-all' is used for running test-Examples-Recommended in
## addition to 'make check'.
## nlme suggests 'Hmisc'
test-Examples-Recommended: test-Examples-Base
	@$(ECHO) "tools::testInstalledPackages(scope='recommended', types='examples')" | _R_CHECK_FORCE_SUGGESTS_=FALSE $(R_EXE)
## </NOTE>

mostlyclean: clean
clean:
	-@rm -f *.R *.R-cnt *.Rout *.Rd* *.pdf *.tex *.dat* data foo* ex*.gz Makedeps
distclean: clean
	-@rm -f *.R*prev .RData sink-examp.txt Makefile
maintainer-clean: distclean

install-tests:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rhome)/tests/Examples"
	@for f in $(INSTFILES); do \
	  $(INSTALL_DATA) $(srcdir)/$${f} "$(DESTDIR)$(rhome)/tests/Examples"; \
	done


distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
