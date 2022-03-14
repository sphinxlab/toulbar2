# Install

## Installation from binaries

You can install toulbar2 directly using the package manager in Debian
and Debian derived Linux distributions (Ubuntu, Mint,...):

    sudo apt-get update
    sudo apt-get install toulbar2 toulbar2-doc

For the most recent binary or the Python API, compile from source.

## Python interface

An alpha-release Python interface can be tested through pip on Linux and MacOS:

    python3 -m pip install --upgrade pip
    python3 -m pip install pytoulbar2

The first line is only useful for Linux distributions that ship "old" versions of pip.

Commands for compiling the Python API on Linux/MacOS with cmake (Python module in lib/\*/pytb2.cpython\*.so):

    mkdir build
    cd build
    cmake -DPYTB2=ON ..
    make

Move the cpython library and the experimental [pytoulbar2.py](https://github.com/toulbar2/toulbar2/raw/master/pytoulbar2/pytoulbar2.py) python class wrapper in the folder of the python script that does "import pytoulbar2".

## Download

Download the latest release from GitHub
(https://github.com/toulbar2/toulbar2) or similarly use tag versions,
e.g.:

    git clone --branch 1.1.1 https://github.com/toulbar2/toulbar2.git


## Installation from sources

Compilation requires git, cmake and a C++-11 capable compiler (in C++11 mode). 

Required library:
* libgmp-dev

Recommended libraries (default use):
* libboost-graph-dev
* libboost-iostreams-dev
* libboost-serialization-dev
* zlib1g-dev
* liblzma-dev

Optional libraries:
* libxml2-dev
* libopenmpi-dev
* libboost-mpi-dev
* libjemalloc-dev

On MacOS, run ./misc/script/MacOS-requirements-install.sh to install the recommended libraries.

Commands for compiling toulbar2 on Linux/MacOS with cmake (binary in build/bin/\*/toulbar2):

    mkdir build
    cd build
    cmake ..
    make

Commands for compiling toulbar2 on Linux in directory toulbar2/src without cmake:

    bash
    cd src
    echo '#define Toulbar_VERSION "1.1.0"' > ToulbarVersion.hpp
    g++ -o toulbar2 -I. tb2*.cpp applis/*.cpp core/*.cpp globals/*.cpp incop/*.cpp search/*.cpp utils/*.cpp vns/*.cpp ToulbarVersion.cpp -std=c++11 -O3 -DNDEBUG \
     -DBOOST -DLONGDOUBLE_PROB -DLONGLONG_COST -DWCSPFORMATONLY -lboost_graph -lboost_iostreams -lboost_serialization -lgmp -lz -llzma -static

Use OPENMPI flag and MPI compiler for a parallel version of toulbar2:

    bash
    cd src
    echo '#define Toulbar_VERSION "1.1.0"' > ToulbarVersion.hpp
    mpicxx -o toulbar2 -I. tb2*.cpp applis/*.cpp core/*.cpp globals/*.cpp incop/*.cpp search/*.cpp utils/*.cpp vns/*.cpp ToulbarVersion.cpp -std=c++11 -O3 -DNDEBUG \
     -DBOOST -DLONGDOUBLE_PROB -DLONGLONG_COST -DOPENMPI -DWCSPFORMATONLY -lboost_graph -lboost_iostreams -lboost_serialization -lboost_mpi -lgmp -lz -llzma

Replace LONGLONG_COST by INT_COST to reduce memory usage by two and reduced cost range (costs must be smaller than 10^8).

## Authors

toulbar2 was originally developped by Toulouse (INRAE MIAT) and Barcelona (UPC, IIIA-CSIC) teams, hence the name of the solver. 

Additional contributions by:
* Caen University, France (GREYC) and University of Oran, Algeria for (parallel) variable neighborhood search methods
* The Chinese University of Hong Kong and Caen University, France (GREYC) for global cost functions
* Marseille University, France (LSIS) for tree decomposition heuristics
* Ecole des Ponts ParisTech, France (CERMICS/LIGM) for [INCOP][incop] local search solver
* University College Cork, Ireland (Insight) for a Python interface in [Numberjack][numberjack] and a portfolio dedicated to UAI graphical models [Proteus][proteus]
* Artois University, France (CRIL) for an XCSP 2.1 format reader of CSP and WCSP instances

[incop]: http://imagine.enpc.fr/~neveub/incop/incoppresentation.html
[numberjack]: https://github.com/eomahony/Numberjack
[proteus]: https://github.com/9thbit/uai-proteus

