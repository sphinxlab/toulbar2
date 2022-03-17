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

# Get and adapt toulbar2/README.md :
# - delete lines 'master:...' and 'cpd:...' that are not ok for LaTeX
# - change some titles
# - extract subfiles README_..
readme:
	cat ../README.md > $(FILESDIR)/README.md
	sed -i '/^master:/d' $(FILESDIR)/README.md
	sed -i '/^cpd:/d' $(FILESDIR)/README.md
	sed -i '1,10 s/# toulbar2//' $(FILESDIR)/README.md
	sed -i '1,10 s/## Exact optimization/# Exact optimization/' $(FILESDIR)/README.md
	sed -n "/## What is toulbar2/,/## Installation from binaries/p" $(FILESDIR)/README.md > $(FILESDIR)/README_toulbar2.md
	sed -i "/## Installation from binaries/d" $(FILESDIR)/README_toulbar2.md
	sed -n "/## Installation from binaries/,/## Authors/p" $(FILESDIR)/README.md > $(FILESDIR)/README_install.md
	sed -i "/## Authors/d" $(FILESDIR)/README_install.md
	sed -i '1 i # Install' $(FILESDIR)/README_install.md
	sed -n "/## Authors/,/## Citing/p" $(FILESDIR)/README.md > $(FILESDIR)/README_authors.md
	sed -i "/## Citing/d" $(FILESDIR)/README_authors.md
	sed -n "/## Citing/,/## What are the algorithms inside toulbar2/p" $(FILESDIR)/README.md > $(FILESDIR)/README_citing.md
	sed -i "/## What are the algorithms inside toulbar2/d" $(FILESDIR)/README_citing.md
	sed -n "/## What are the algorithms inside toulbar2/,/de-givry/p" $(FILESDIR)/README.md > $(FILESDIR)/README_algos.md

# build pdf files, get and adapt toulbar2/README.md
# and install them into FILESDIR
# Note : has to be done before html pages
files:
	rm -f $(FILESDIR)/*.*
	make readme
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
