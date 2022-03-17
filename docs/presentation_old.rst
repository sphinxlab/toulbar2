.. _presentation_ancienne_version:

.. include:: news_home.rst

===============================
Presentation (ancienne version)
===============================

Notes temporaires
=================

- La partie "About toulbar2" de cette ancienne page "presentation" est gardée dans la nouvelle (inchangée)

- La partie "Authors" vient du README.md dans la nouvelle page "presentation" => Récupérer dans "Authors" du README.md le paragraphe* :ref:`ancien_authors` de cette ancienne page "presentation" qui disparait

- La partie "Citations" vient du README.md dans la nouvelle page "presentation" => Récupérer dans "Citing" du README.md le paragraphe* :ref:`ancien_citations` de cette ancienne page "presentation" qui disparait

- La partie "Acknowledgements" de cette ancienne page "presentation" est gardée dans la nouvelle (inchangée)

- La partie "License" de cette ancienne page "presentation" est gardée dans la nouvelle (inchangée)

- *Les parties du README.md suivantes n'apparaissent pas ailleurs que dans "Reference Manual" :* :ref:`_files/README_toulbar2:What is toulbar2?` et :ref:`_files/README_install:Install`

- La partie :ref:`_files/README_algos:What are the algorithms inside toulbar2?` du README.md est utilisée dans la page "Publications".

.. _ancien_about_toulbar2:

About toulbar2
==============

**toulbar2** is an open-source C++ solver for cost function networks. It solves various combinatorial optimization problems.

The constraints and objective function are factorized in local functions on discrete variables. Each function returns a cost (a finite positive integer) for any assignment of its variables. Constraints are represented as functions with costs in {0, :math:`\infty`} where :math:`\infty` is a large integer representing forbidden assignments. toulbar2 looks for a non-forbidden assignment of all variables that minimizes the sum of all functions.

Its engine uses a hybrid best-first branch-and-bound algorithm exploiting soft arc consistencies. It incorporates a parallel variable neighborhood search method for better performances. See :ref:`publications`.

toulbar2 won several competitions on Max-CSP (`CPAI08 <http://www.cril.univ-artois.fr/CPAI08/>`_) and probabilistic graphical models (UAI `2008 <https://www.ics.uci.edu/~dechter/softwares/benchmarks/UAI08/uai08-evaluation-2008-09-15.pdf>`_, `2010 <http://www.cs.huji.ac.il/project/UAI10/summary.php>`_, `2014 <http://auai.org/uai2014/competition.shtml>`_ MAP task).

toulbar2 is now also able to collaborate with ML code that can learn an additive graphical model (with constraints) from data (see example at `cfn-learn <https://forgemia.inra.fr/thomas.schiex/cfn-learn>`_).

.. _ancien_authors:

Authors
=======

**toulbar2** was originally developed by Toulouse (INRAE MIAT) and Barcelona (UPC, IIIA-CSIC) teams, hence the name of the solver. Additional global cost functions were provided by the *Chinese University of Hong Kong* and Caen University (GREYC). It also includes codes from Marseille University (LSIS, tree decomposition heuristics) and *Ecole des Ponts ParisTech* (CERMICS/LIGM, `INCOP <http://imagine.enpc.fr/~neveub/incop/incoppresentation.html>`_ local search solver).     

A Python interface is now available. Install it with "python3 -m pip install pytoulbar2". See examples in :ref:`tutorials` using pytoulbar2 module. An older version is part of `Numberjack <https://github.com/eomahony/Numberjack>`_ (Insight - University College Cork). A portfolio approach dedicated to UAI format instances is available `here <https://github.com/9thbit/uai-proteus>`_.

**toulbar2** is currently maintained by Simon de Givry (simon.de-givry@inrae.fr) and hosted on `GitHub <https://github.com/toulbar2/toulbar2>`_.

.. _ancien_citations:

Citations
=========


- `Multi-Language Evaluation of Exact Solvers in Graphical Model Discrete Optimization <https://miat.inrae.fr/degivry/Hurley16b.pdf>`_

  Barry Hurley, Barry O'Sullivan, David Allouche, George Katsirelos, Thomas Schiex, Matthias Zytnicki, Simon de Givry

  Constraints, 21(3):413-434, 2016

- `Tractability-preserving Transformations of Global Cost Functions <https://miat.inrae.fr/degivry/Schiex16a.pdf>`_

  David Allouche, Christian Bessiere, Patrice Boizumault, Simon de Givry, Patricia Gutierrez, Jimmy HM. Lee, Ka Lun Leung, Samir Loudni, Jean-Philippe Métivier, Thomas Schiex, Yi Wu

  Artificial Intelligence, 238:166-189, 2016

- `Soft arc consistency revisited <https://miat.inrae.fr/degivry/Cooper10a.pdf>`_

  Martin Cooper, Simon de Givry, Marti Sanchez, Thomas Schiex, Matthias Zytnicki, and Thomas Werner

  Artificial Intelligence, 174(7-8):449-478, 2010

.. _ancien_acknowledgements:

Acknowledgements
================

**toulbar2** has been partly funded by the French *Agence Nationale de la Recherche* (projects STAL-DEC-OPT from 2006 to 2008, ANR-10-BLA-0214 `Ficolofo <http://costfunction.org>`_ from 2011 to 2014, and ANR-16-CE40-0028 `DemoGraph <https://anr.fr/Projet-ANR-16-CE40-0028>`_ from 2017 to 2021) and a PHC PROCORE project number 28680VH (from 2013 to 2015). It is currently supported by ANITI ANR-19-P3IA-0004 (2019-).

License
=======

.. literalinclude:: ../LICENSE

