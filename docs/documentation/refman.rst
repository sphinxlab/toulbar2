.. _refman:

================
Reference Manual
================

Overview
========

  ================================  =====================================
  **Cost Function Network Solver**  toulbar2
  **Copyright**                     toulbar2 team
  **Source**                        https://github.com/toulbar2/toulbar2
  ================================  =====================================

  toulbar2 can be used as a stand-alone solver reading various problem file formats (wcsp, uai, wcnf, qpbo) or as a C++ library.

  This document describes the WCSP native file format and the toulbar2 C++ library API.

  Note
    Use cmake flags LIBTB2=ON and TOULBAR2_ONLY=OFF to get the toulbar2 C++
    library libtb2.so and toulbar2test executable example.

  **See also** : :download:`src/toulbar2test.cpp<../../src/toulbar2test.cpp>`.

Exact optimization for cost function networks and additive graphical models
===========================================================================

  .. toctree::
     :maxdepth: 3

     ../_files/README.md

.. _modules:

Modules
=======

.. Weighted Constraint Satisfaction Problem file format (wcsp)
.. -----------------------------------------------------------

.. .. doxygengroup:: wcspformat

Variable and cost function modeling
-----------------------------------

.. doxygengroup:: modeling

Solving cost function networks
------------------------------

.. doxygengroup:: solving

Output messages, verbosity options and debugging
------------------------------------------------

.. doxygengroup:: verbosity

Preprocessing techniques
------------------------

.. doxygengroup:: preprocessing

Variable and value search ordering heuristics
---------------------------------------------

.. doxygengroup:: heuristics

Soft arc consistency and problem reformulation
----------------------------------------------

.. doxygengroup:: softac

Virtual Arc Consistency enforcing
---------------------------------

.. doxygengroup:: VAC

NC bucket sort
--------------

.. doxygengroup:: ncbucket

Variable elimination
--------------------

.. doxygengroup:: varelim

Propagation loop
----------------

.. doxygengroup:: propagation

Backtrack management
--------------------

.. doxygengroup:: backtrack

Libraries
=========

.. only:: latex

    - C++ Library : see "C++ Library of toulbar2" document.
    - Python Library : see "Python Library of toulbar2" document.

.. only:: html

    .. toctree::
       :maxdepth: 3

       ../api_ref/api_ref_toulbar2.rst

    .. toctree::
       :maxdepth: 3

       ../api_ref/api_ref_pytoulbar2.rst

.. class WeightedCSP NOK for LaTeX there (LaTeX Error: Too deeply nested)

.. warning : '@mainpage' text (from src/toulbar2lib.hpp) has been copied there
   manually and modified/adapted

