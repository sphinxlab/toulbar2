# Sphinx documentation of toulbar2 -> Local build

## Install 'pyvenv' python virtual environment

- See file docs/_local/install.txt.

## Commands to generate documentation

### Doxygen

_The build/xml folder content, built by Doxygen, will be used by Sphinx
(via breathe).

- see HowTo.build.Toulbar2 ::

      # Howto generate toulbar2 source documentation
      # first install the following package required

      sudo apt-get install texlive-latex-recommended texlive-fonts-recommended
      sudo apt-get install doxygen

      # for generating documentation use the following command:

      mkdir build ; cd build
      cmake -DBUILD_API_DOC=ON ; make doc

### Sphinx

- init and clear ::

    source _local/_pyvenv/bin/activate
    cd .. ; ./clean ; cd docs ;

- pdf then html ::

    make docs

- or : 

  - pdf with latex ::

      make files

  - html ::

      make html ;

- epub ::

    make epub ;

## Productions
    
- _build/html folder where index.html
- .pdf under _files (and _build/latex)
- .epub under _build/epub

