#
# ${R_HOME}/src/library/translations/Makefile


srcdir = .
top_srcdir = ../../..

top_builddir = ../../..
subdir = src/library/translations

include $(top_builddir)/Makeconf

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
DISTFILES = DESCRIPTION.in Makefile.in Makefile.win

pkg = translations

all: Makefile
	@$(ECHO) "building package '$(pkg)'"
	@$(MKINSTALLDIRS) $(top_builddir)/library/$(pkg)
	@$(MAKE) mkdesc
	@cp -R `ls -d $(srcdir)/inst/*` $(top_builddir)/library/$(pkg)
	@find "$(top_builddir)/library/$(pkg)" -name .svn -type d -prune \
            -exec rm -Rf \{\} \; 2>/dev/null
	@cp DESCRIPTION $(top_builddir)/library/$(pkg)

include $(top_srcdir)/share/make/basepkg.mk
