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
# also get and adapt toulbar2/README.md (without lines beginning with
# 'master:' and 'cpd:' that are not ok for LaTeX)
files:
	rm -f $(FILESDIR)/*.*
	cp ../README.md $(FILESDIR)/.
	sed '/^master:/d' $(FILESDIR)/README.md > $(FILESDIR)/tmp.md
	sed '/^cpd:/d' $(FILESDIR)/tmp.md > $(FILESDIR)/README.md
	rm -f $(FILESDIR)/tmp.md
	make latexpdf
	cp $(BUILDDIR)/latex/*.pdf $(FILESDIR)/.

# builds pdf, html files; pdf into html/pdf
docs:
	make clean
	make files
	make html
	make files
	mkdir $(BUILDDIR)/html/pdf
	cp $(FILESDIR)/*.pdf $(BUILDDIR)/html/pdf/.

# epub not ok => not done :
# builds epub file; epub into html/epub
#   make epub
#   mkdir $(BUILDDIR)/html/epub
#   cp $(BUILDDIR)/epub/toulbar2.epub $(BUILDDIR)/html/epub/.

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
