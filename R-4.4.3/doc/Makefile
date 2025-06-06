#
# ${R_HOME}/doc/Makefile


srcdir = .
top_srcdir = ..

top_builddir = ..
subdir = doc

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
INSTFILES = AUTHORS COPYING COPYRIGHTS CRAN_mirrors.csv BioC_mirrors.csv \
	KEYWORDS KEYWORDS.db THANKS NEWS.0 NEWS.1 NEWS.2 NEWS.3
DISTFILES = Makefile.in Makefile.win $(INSTFILES) R.aux \
  NEWS.Rd NEWS.2.Rd NEWS.3.Rd
INSTFILES2 = NEWS.rds NEWS NEWS.pdf NEWS.2.rds NEWS.3.rds
NON_SVN_INSTFILES = FAQ RESOURCES NEWS NEWS.pdf
## generated later.
SUBDIRS = html manual
INSTDIRS = notes

HELP2MAN = perl $(top_srcdir)/tools/help2man.pl

R_EXE = $(top_builddir)/bin/R --vanilla --no-echo

all: Makefile R docs
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

## FIXME:  NEWS.rds is needed by news() and hence in principle part of 'R', but
##  it can only be built by R_EXE which at this point does not exist (if built from scratch)
R: Makefile svnonly
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  $(MAKE) rdocdir=$(top_builddir)/doc install-sources; \
	fi

## man pages last: currently needs perl (which is *not* checked at configure time);
## NB: need NEWS.rds for 'news()' which is run in 'make check'
docs: NEWS.rds NEWS html/NEWS.html NEWS.pdf NEWS.2.rds NEWS.3.rds R.1 Rscript.1
	@(cd manual && $(MAKE) $@)

R.1:
	@$(HELP2MAN) --include=$(srcdir)/R.aux --no-info --output=R.1 \
	  --name="a language for data analysis and graphics" \
	  $(top_builddir)/bin/R

Rscript.1:
	@$(HELP2MAN) --no-info --output=Rscript.1 \
	  --name="front end for scripting with R" \
	  $(top_builddir)/bin/Rscript

NEWS.rds: $(srcdir)/NEWS.Rd
	@$(ECHO) "options(warn=1);saveRDS(tools:::prepare_Rd(tools::parse_Rd(\"$(srcdir)/NEWS.Rd\", \
	  macros = \"../share/Rd/macros/system.Rd\"), stages = 'install', warningCalls = FALSE), \
	  'NEWS.rds')" | $(R_EXE)

NEWS: NEWS.rds
	@$(ECHO) "creating doc/NEWS"
	@$(ECHO) 'options(warn=1);tools:::Rd2txt_NEWS_in_Rd("NEWS.rds", "NEWS")' |  $(R_EXE)

html/NEWS.html: NEWS.rds
	@$(ECHO) 'options(warn=1);tools:::Rd2HTML_NEWS_in_Rd("NEWS.rds", "html/NEWS.html")' |  $(R_EXE)

PDFLATEX = 
## needs pdflatex (and more)
NEWS.pdf: NEWS.rds
	@if test -z "$(PDFLATEX)"; then \
	  $(ECHO) "'pdflatex' is needed to make NEWS.pdf but is missing on your system."; \
	else \
	 $(ECHO) "creating doc/NEWS.pdf"; \
	 $(ECHO) 'options(warn=1);tools:::Rd2pdf_NEWS_in_Rd("NEWS.rds", "NEWS.pdf")' | \
	 TEXINPUTS="$(top_srcdir)/share/texmf/tex/latex:$$TEXINPUTS" $(R_EXE); \
	fi

docs3: NEWS.3.rds NEWS.3.html NEWS.3.pdf

NEWS.3.rds: $(srcdir)/NEWS.3.Rd
	@$(ECHO) "options(warn=1);saveRDS(tools:::prepare_Rd(tools::parse_Rd(\"$(srcdir)/NEWS.3.Rd\", \
	  macros = \"../share/Rd/macros/system.Rd\"), stages = 'install', warningCalls = FALSE), \
	  'NEWS.3.rds')" | $(R_EXE)

NEWS.3: NEWS.3.rds
	@$(ECHO) "creating NEWS.3"
	@$(ECHO) 'options(warn=1);tools:::Rd2txt_NEWS_in_Rd("NEWS.3.rds", "NEWS.3")' |  $(R_EXE)

NEWS.3.html: NEWS.3.rds
	@$(ECHO) "creating NEWS.3.html"
	@$(ECHO) 'options(warn=1);tools:::Rd2HTML_NEWS_in_Rd("NEWS.3.rds", "NEWS.3.html")' |  $(R_EXE)

NEWS.3.pdf: NEWS.3.rds
	@if test -z "$(PDFLATEX)"; then \
	  $(ECHO) "'pdflatex' is needed to make NEWS.3.pdf but is missing on your system."; \
	else \
	 $(ECHO) "creating NEWS.3.pdf"; \
	 $(ECHO) 'options(warn=1);tools:::Rd2pdf_NEWS_in_Rd("NEWS.3.rds", "NEWS.3.pdf")' | \
	 TEXINPUTS="$(top_srcdir)/share/texmf/tex/latex:$$TEXINPUTS" $(R_EXE); \
	fi

## NEWS.2.html ships as doc/html/NEWS.2.html in the sources.
docs2: NEWS.2.rds NEWS.2.html NEWS.2.pdf

NEWS.2.rds: $(srcdir)/NEWS.2.Rd
	@$(ECHO) "options(warn=1);saveRDS(tools:::prepare_Rd(tools::parse_Rd(\"$(srcdir)/NEWS.2.Rd\", \
	  macros = \"../share/Rd/macros/system.Rd\"), stages = 'install', warningCalls = FALSE), \
	  'NEWS.2.rds')" | $(R_EXE)

## NB: this is only the top part of NEWS.2 in the sources.
NEWS.2: NEWS.2.rds
	@$(ECHO) "creating NEWS.2"
	@$(ECHO) 'options(warn=1);tools:::Rd2txt_NEWS_in_Rd("NEWS.2.rds", "NEWS.2")' |  $(R_EXE)

NEWS.2.html: NEWS.2.rds
	@$(ECHO) "creating NEWS.2.html"
	@$(ECHO) 'options(warn=1);tools:::Rd2HTML_NEWS_in_Rd("NEWS.2.rds", "NEWS.2.html")' |  $(R_EXE)

NEWS.2.pdf: NEWS.2.rds
	@if test -z "$(PDFLATEX)"; then \
	  $(ECHO) "'pdflatex' is needed to make NEWS.2.pdf but is missing on your system."; \
	else \
	 $(ECHO) "creating NEWS.2.pdf"; \
	 $(ECHO) 'options(warn=1);tools:::Rd2pdf_NEWS_in_Rd("NEWS.2.rds", "NEWS.2.pdf")' | \
	 TEXINPUTS="$(top_srcdir)/share/texmf/tex/latex:$$TEXINPUTS" $(R_EXE); \
	fi


install: install-message installdirs install-sources install-sources2 install-man
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
installdirs:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rdocdir)"
	@$(MKINSTALLDIRS) $(DESTDIR)$(mandir)/man1
install-man: installdirs R.1 Rscript.1
	@rm -f $(DESTDIR)$(mandir)/man1/R.1
	@$(INSTALL_DATA) R.1 $(DESTDIR)$(mandir)/man1
	@rm -f $(DESTDIR)$(mandir)/man1/Rscript.1
	@$(INSTALL_DATA) Rscript.1 $(DESTDIR)$(mandir)/man1
install-message:
	@$(ECHO) "installing $(subdir) ..."
## installed from srcdir, including to builddir
install-sources:
	@$(MKINSTALLDIRS) "$(DESTDIR)$(rdocdir)"
	@for f in $(INSTFILES); do \
	  $(INSTALL_DATA) $(srcdir)/$${f} "$(DESTDIR)$(rdocdir)"; \
	done
## installed from builddir
install-sources2: installdirs
	@for f in $(NON_SVN_INSTFILES) $(INSTFILES2); do \
	  $(INSTALL_DATA) $${f} "$(DESTDIR)$(rdocdir)"; \
	done
install-strip: install

uninstall:
	@$(ECHO) "uninstalling $(subdir) ..."
	@if test -d "$(DESTDIR)$(rdocdir)" \
	  && test "`cd \"$(DESTDIR)$(rhome)\"; $(GETWD)`" \
	       != "`cd $(top_builddir); $(GETWD)`"; then \
	  for d in $(SUBDIRS); do \
	    (cd $${d} && $(MAKE) $@) || exit 1; \
	  done; \
	  for f in $(INSTFILES) $(NON_SVN_INSTFILES) $(INSTFILES2); do \
	    rm -f "$(DESTDIR)$(rdocdir)"/$${f}; \
	  done; \
	  rmdir "$(DESTDIR)$(rdocdir)" 2>/dev/null \
	    || $(ECHO) "  subdir $(DESTDIR)$(subdir) not removed"; \
	fi
	@rm -f $(DESTDIR)$(mandir)/man1/R.1 $(DESTDIR)$(mandir)/man1/Rscript.1

info pdf:
	@(cd manual && $(MAKE) $@)

mostlyclean:
clean:
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@); \
	done
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -f $(INSTFILES) R.1 Rscript.1; \
	fi
	-@rm -f $(INSTFILES2) NEWS.2.rds NEWS.2.html NEWS.2.pdf \
	  NEWS.3.rds NEWS.3.html NEWS.3.pdf
distclean: clean
	@for d in $(SUBDIRS); do \
	  (cd $${d} && $(MAKE) $@) || exit 1; \
	done
	@if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	  rm -f $(NON_SVN_INSTFILES); \
	fi
	-@rm -f Makefile R.1 Rscript.1
maintainer-clean: distclean


svnonly:
	@if test -f "$(srcdir)/FAQ" ; then \
	  if test "$(BUILDDIR_IS_SRCDIR)" = no ; then \
	    for f in $(NON_SVN_INSTFILES); do \
	      $(INSTALL_DATA) $(srcdir)/$${f} .; \
	    done \
	  fi \
	fi

distdir: $(DISTFILES)
	@for f in $(DISTFILES); do \
	  test -f $(distdir)/$${f} \
	    || ln $(srcdir)/$${f} $(distdir)/$${f} 2>/dev/null \
	    || cp -p $(srcdir)/$${f} $(distdir)/$${f}; \
	done
	@for f in $(NON_SVN_INSTFILES) ; do \
	  cp -p $${f} $(distdir)/$${f}; \
	done
	@for d in $(SUBDIRS); do \
	  test -d $(distdir)/$${d} \
	    || mkdir $(distdir)/$${d} \
	    || exit 1; \
	  chmod 755 $(distdir)/$${d}; \
	  (cd $${d} && $(MAKE) distdir) \
	    || exit 1; \
	done
	@for d in $(INSTDIRS); do \
	  cp -pr $(srcdir)/$${d} $(distdir) || exit 1; \
	  chmod 755 $(distdir)/$${d}; \
	  chmod 644 $(distdir)/$${d}/*; \
	done
