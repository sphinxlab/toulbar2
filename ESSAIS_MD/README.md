# toulbar2
## Exact optimization for cost function networks and additive graphical models 

master: [![Build Status](https://travis-ci.com/toulbar2/toulbar2.svg?branch=master)](https://travis-ci.com/toulbar2/toulbar2)
cpd: [![Build Status](https://travis-ci.com/toulbar2/toulbar2.svg?branch=cpd)](https://travis-ci.com/toulbar2/toulbar2) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/toulbar2/toulbar2.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/toulbar2/toulbar2/context:cpp)[![PyPi version](https://img.shields.io/pypi/v/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)[![PyPi wheel](https://img.shields.io/pypi/wheel/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)[![PyPi python versions](https://img.shields.io/pypi/pyversions/pytoulbar2.svg)](https://pypi.org/project/pytoulbar2)


## debut mesessais

- [lien vers INSTALL.md](INSTALL.md).
- [lien vers ALGOS.md](ALGOS.md).

### essai1

```{include} docs/presentation.rst
```
### essai2

```{eval-rst}
.. include:: docs/presentation.rst
```

## fin mesessais


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

## SUITE

- [Install](INSTALL.md)
- [Authors](AUTHORS.md)
- [Citing](CITING.md)
- [Algos](ALGOS.md)
 
Copyright (C) 2006-2021, toulbar2 team.
toulbar2 is currently maintained by Simon de Givry, INRAE - MIAT, Toulouse, France (simon.de-givry@inrae.fr)
