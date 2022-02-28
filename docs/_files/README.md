# toulbar2
## Exact optimization for cost function networks and additive graphical models 

master: [![Build Status](https://travis-ci.com/toulbar2/toulbar2.svg?branch=master)](https://travis-ci.com/toulbar2/toulbar2)
cpd: [![Build Status](https://travis-ci.com/toulbar2/toulbar2.svg?branch=cpd)](https://travis-ci.com/toulbar2/toulbar2) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/toulbar2/toulbar2.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/toulbar2/toulbar2/context:cpp)[![PyPi version](https://img.shields.io/pypi/v/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)[![PyPi wheel](https://img.shields.io/pypi/wheel/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)[![PyPi python versions](https://img.shields.io/pypi/pyversions/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)


## What is toulbar2?

toulbar2 is an open-source black-box C++ optimizer for cost function
networks and discrete additive graphical models. It can read a variety
of formats. The optimized criteria and feasibility should be provided
factorized in local cost functions on discrete variables. Constraints
are represented as functions that produce costs that exceed a
user-provided primal bound. toulbar2 looks for a non-forbidden assignment 
of all variables that optimizes the sum of all functions (a decision 
NP-complete problem).

toulbar2 won several competitions on deterministic and probabilistic
graphical models:

* Max-CSP 2008 Competition [CPAI08][cpai08] (winner on 2-ARY-EXT and N-ARY-EXT)
* Probabilistic Inference Evaluation [UAI 2008][uai2008] (winner on several MPE tasks, inra entries)
* 2010 UAI APPROXIMATE INFERENCE CHALLENGE [UAI 2010][uai2010] (winner on 1200-second MPE task)
* The Probabilistic Inference Challenge [PIC 2011][pic2011] (second place by ficolofo on 1-hour MAP task)
* UAI 2014 Inference Competition [UAI 2014][uai2014] (winner on all MAP task categories, see Proteus, Robin, and IncTb entries)

[cpai08]: http://www.cril.univ-artois.fr/CPAI08/
[uai2008]: http://graphmod.ics.uci.edu/uai08/Evaluation/Report
[uai2010]: http://www.cs.huji.ac.il/project/UAI10/summary.php
[pic2011]: http://www.cs.huji.ac.il/project/PASCAL/board.php
[uai2014]: http://www.hlt.utdallas.edu/~vgogate/uai14-competition/leaders.html 

toulbar2 is now also able to collaborate with ML code that can learn
an additive graphical model (with constraints) from data (see the
associated
[paper](https://miat.inrae.fr/schiex/Export/Pushing_Data_in_your_CP_model.pdf),
[slides](https://miat.inrae.fr/schiex/Export/Pushing_Data_in_your_CP_model-Slides.pdf)
and [video](https://www.youtube.com/watch?v=IpUr6KIEjMs) where it is
shown how it can learn user preferences or how to play the Sudoku
without knowing the rules). The current CFN learning code is available
on [GitHub](https://github.com/toulbar2/CFN-learn).

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


## Citing

Please use one of the following references for citing toulbar2:

 * Multi-Language Evaluation of Exact Solvers in Graphical Model Discrete Optimization
 Barry Hurley, Barry O'Sullivan, David Allouche, George Katsirelos, Thomas Schiex, Matthias Zytnicki, Simon de Givry
 Constraints, 21(3):413-434, 2016

 * Tractability-preserving Transformations of Global Cost Functions
 David Allouche, Christian Bessiere, Patrice Boizumault, Simon de Givry, Patricia Gutierrez, Jimmy HM. Lee, Ka Lun Leung, Samir Loudni, Jean-Philippe Métivier, Thomas Schiex, Yi Wu
 Artificial Intelligence, 238:166-189, 2016

 * Soft arc consistency revisited
 Martin Cooper, Simon de Givry, Marti Sanchez, Thomas Schiex, Matthias Zytnicki, and Thomas Werner
 Artificial Intelligence, 174(7-8):449-478, 2010 


##  What are the algorithms inside toulbar2?

* Soft arc consistency (AC): 
 Arc consistency for Soft Constraints
 T. Schiex
 Proc. of CP'2000. Singapour, September 2000.

* More soft arc consistencies (NC, DAC, FDAC):
 In the quest of the best form of local consistency for Weighted CSP
 J. Larrosa & T. Schiex
 In Proc. of IJCAI-03. Acapulco, Mexico, 2003

* Soft existential arc consistency (EDAC):
 Existential arc consistency: Getting closer to full arc consistency in weighted csps
 S. de Givry, M. Zytnicki, F. Heras, and J. Larrosa
 In Proc. of IJCAI-05, Edinburgh, Scotland, 2005

* Depth-first Branch and Bound exploiting a tree decomposition (BTD):
 Exploiting Tree Decomposition and Soft Local Consistency in Weighted CSP
 S. de Givry, T. Schiex, and G. Verfaillie
 In Proc. of AAAI-06, Boston, MA, 2006 

* Virtual arc consistency (VAC):
 Virtual arc consistency for weighted csp
 M. Cooper, S. de Givry, M. Sanchez, T. Schiex, and M. Zytnicki
 In Proc. of AAAI-08, Chicago, IL, 2008

* Soft generalized arc consistencies (GAC, FDGAC):
 Towards Efficient Consistency Enforcement for Global Constraints in Weighted Constraint Satisfaction
 J. H. M. Lee and K. L. Leung
 In Proc. of IJCAI-09, Los Angeles, USA, 2010

* Russian doll search exploiting a tree decomposition (RDS-BTD):
 Russian doll search with tree decomposition
 M Sanchez, D Allouche, S de Givry, and T Schiex
 In Proc. of IJCAI'09, Pasadena (CA), USA, 2009

* Soft bounds arc consistency (BAC):
 Bounds Arc Consistency for Weighted CSPs
 M. Zytnicki, C. Gaspin, S. de Givry, and T. Schiex
 Journal of Artificial Intelligence Research, 35:593-621, 2009

* Counting solutions in satisfaction (#BTD, Approx_#BTD):
 Exploiting problem structure for solution counting
 A. Favier, S. de Givry, and P. Jégou
 In Proc. of CP-09, Lisbon, Portugal, 2009

* Soft existential generalized arc consistency (EDGAC):
 A Stronger Consistency for Soft Global Constraints in Weighted Constraint Satisfaction
 J. H. M. Lee and K. L. Leung
 In Proc. of AAAI-10, Boston, MA, 2010 

* Preprocessing techniques (combines variable elimination and cost function decomposition):
 Pairwise decomposition for combinatorial optimization in graphical models
 A Favier, S de Givry, A Legarra, and T Schiex
 In Proc. of IJCAI-11, Barcelona, Spain, 2011

* Decomposable global cost functions (wregular, wamong, wsum):
 Decomposing global cost functions
 D Allouche, C Bessiere, P Boizumault, S de Givry, P Gutierrez, S Loudni, JP Métivier, and T Schiex
 In Proc. of AAAI-12, Toronto, Canada, 2012

* Pruning by dominance (DEE):
 Dead-End Elimination for Weighted CSP
 S de Givry, S Prestwich, and B O'Sullivan
 In Proc. of CP-13, pages 263-272, Uppsala, Sweden, 2013

* Hybrid best-first search exploiting a tree decomposition (HBFS):
 Anytime Hybrid Best-First Search with Tree Decomposition for Weighted CSP
 D Allouche, S de Givry, G Katsirelos, T Schiex, and M Zytnicki
 In Proc. of CP-15, Cork, Ireland, 2015 

* SCP branching (CPD branch):
 Fast search algorithms for Computational Protein Design.
 S Traoré, K Roberts, D Allouche, B Donald, I André, T Schiex, S Barbe.
 Journal of Computational Chemistry, 2016

* Guaranteed Free Energy computation (weighted model counting):
 Guaranteed Weighted Counting for Affinity Computation: Beyond Determinism and Structure 
 C Viricel, D Simoncini, S Barbe, T Schiex. 
 In Proc. of CP-16, Toulouse, France, 2016

* Unified parallel decomposition guided variable neighborhood search (UDGVNS/UPDGVNS):
 Iterative Decomposition Guided Variable Neighborhood Search for Graphical Model Energy Minimization
 A Ouali, D Allouche, S de Givry, S Loudni, Y Lebbah, F Eckhardt, and L Loukil
 In Proc. of UAI-17, pages 550-559, Sydney, Australia, 2017 ;
 Variable neighborhood search for graphical model energy minimization 
 A Ouali, D Allouche, S de Givry, S Loudni, Y Lebbah, L Loukil, and P Boizumault
 Artificial Intelligence, 278(103194), 2020 

* Clique cut global cost function (clique):
 Clique Cuts in Weighted Constraint Satisfaction
 S de Givry and G Katsirelos
 In Proc. of CP-17, pages 97-113, Melbourne, Australia, 2017

* Greedy sequence of diverse solutions (div):
 Guaranteed diversity & quality for the Weighted CSP
 M Ruffini, J Vucinic, S de Givry, G Katsirelos, S Barbe, and T Schiex
 In Proc. of ICTAI-19, pages 18-25, Portland, OR, USA, 2019
 
* VAC integrality based variable heuristics and initial upper-bounding (vacint and rasps):
 Relaxation-Aware Heuristics for Exact Optimization in Graphical Models
 F Trösser, S de Givry and G Katsirelos
 In Proc. of CPAIOR-20, Vienna, Austria, 2020
 
Copyright (C) 2006-2021, toulbar2 team.
toulbar2 is currently maintained by Simon de Givry, INRAE - MIAT, Toulouse, France (simon.de-givry@inrae.fr)
