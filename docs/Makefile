# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line.
SPHINXOPTS    =
SPHINXBUILD   = sphinx-build
SOURCEDIR     = .
BUILDDIR      = _build
FILESDIR    = _files

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
	@echo "  pdfdocs     to delete $(FILESDIR) folder, generate pdf and save them into $(FILESDIR)"

.PHONY: help Makefile

# builds pdf files and install them into FILESDIR
# has to be done before html pages
files:
	rm -f $(FILESDIR)/*.*
	cp ../README.md $(FILESDIR)/.
	make latexpdf
	cp $(BUILDDIR)/latex/*.pdf $(FILESDIR)/.

# builds pdf, html, epub files; pdf and epub into html/pdf and html/epub
docs:
	make clean
	make files
	make html
	make files
	make epub
	mkdir $(BUILDDIR)/html/epub
	cp $(BUILDDIR)/epub/toulbar2.epub $(BUILDDIR)/html/epub/.
	mkdir $(BUILDDIR)/html/pdf
	cp $(FILESDIR)/*.pdf $(BUILDDIR)/html/pdf/.

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
