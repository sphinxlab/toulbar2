.. _about_toulbar2:

==============
About toulbar2
==============

**toulbar2** is an open-source C++ solver for cost function networks. It solves various combinatorial optimization problems.

The constraints and objective function are factorized in local functions on discrete variables. Each function returns a cost (a finite positive integer) for any assignment of its variables. Constraints are represented as functions with costs in {0, :math:`\infty`} where :math:`\infty` is a large integer representing forbidden assignments. toulbar2 looks for a non-forbidden assignment of all variables that minimizes the sum of all functions.

Its engine uses a hybrid best-first branch-and-bound algorithm exploiting soft arc consistencies. It incorporates a parallel variable neighborhood search method for better performances. See :ref:`publications`.

toulbar2 won several competitions on Max-CSP (`CPAI08 <http://www.cril.univ-artois.fr/CPAI08/>`_) and probabilistic graphical models (UAI `2008 <https://www.ics.uci.edu/~dechter/softwares/benchmarks/UAI08/uai08-evaluation-2008-09-15.pdf>`_, `2010 <http://www.cs.huji.ac.il/project/UAI10/summary.php>`_, `2014 <http://auai.org/uai2014/competition.shtml>`_ MAP task).

toulbar2 is now also able to collaborate with ML code that can learn an additive graphical model (with constraints) from data (see example at `cfn-learn <https://forgemia.inra.fr/thomas.schiex/cfn-learn>`_).

