# Sphinx documentation of toulbar2 -> Local build

## Install 'pyvenv' python virtual environment

- Some required basic tools to be installed if not already installed :

  - python 3 :

        apt-get install python3

  - pip3 :

        apt-get install python3-pip

  - python3 virtual environment tool :

        apt-get install python3-venv

- Install _pyvenv virtual environment

  Commands to create, activate, then install from requirement.txt :

        python3 -m venv _pyvenv
        source _pyvenv/bin/activate
        pip3 install -r requirement.txt

- Use _pyvenv virtual environment

  - activate :

        source _pyvenv/bin/activate

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
      cmake -DBUILD_API_DOC=ON .. ; make doc

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

