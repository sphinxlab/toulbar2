.. _refman:

================
Reference Manual
================

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

  See also
    :download:`src/toulbar2test.cpp<../../src/toulbar2test.cpp>`.

.. toctree::
   :maxdepth: 1

   ../_files/README.md

.. toctree::
   :maxdepth: 1

   modules.rst

.. only:: html

  .. toctree::
     :maxdepth: 1

     ../api_ref/api_ref_toulbar2.rst

  .. toctree::
     :maxdepth: 1

     ../api_ref/api_ref_pytoulbar2.rst

.. class WeightedCSP NOK for LaTeX there (LaTeX Error: Too deeply nested)

.. warning : '@mainpage' text (from src/toulbar2lib.hpp) has been copied there
   manually and modified/adapted

