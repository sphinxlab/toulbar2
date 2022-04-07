.. _resources:

=========
Resources
=========

Software
========

.. _downloads:

Binaries
--------

- **Latest release toulbar2 binaries**

  `Linux 64bit <https://github.com/toulbar2/toulbar2/releases/download/v1.1.1/toulbar2>`_ |
  `MacOs 64bit <https://github.com/toulbar2/toulbar2/releases/download/v1.1.1/toulbar2mac>`_ |
  `Windows 64bit <https://github.com/toulbar2/toulbar2/releases/download/v1.1.1/toulbar2.exe>`_

Python package
--------------

- pytoulbar2 module for Linux and MacOS on `PyPI <https://pypi.org/project/pytoulbar2>`_ 

Open-source code
----------------

- `toulbar2 on GitHub <https://github.com/toulbar2/toulbar2>`_

Docker images
-------------

- In `Toulbar2 Packages <https://github.com/toulbar2?tab=packages&repo_name=toulbar2>`_ :

  - **toulbar2** : 
    Docker image containing toulbar2 and its pytoulbar2 Python API
    *(installed from sources with cmake options -DPYTB2=ON and -DXML=ON)*.
    Install from the command line: ::

      docker pull ghcr.io/toulbar2/toulbar2/toulbar2:master

  - **pytoulbar2** :
    Docker image containing pytoulbar2 the Python API of toulbar2
    *(installed with python3 -m pip install pytoulbar2)*.
    Install from the command line: ::

      docker pull ghcr.io/toulbar2/toulbar2/pytoulbar2:master

Benchmarks
==========

- `evalgm <http://genoweb.toulouse.inra.fr/~degivry/evalgm>`_ 
- `Cost Function Library <https://forgemia.inra.fr/thomas.schiex/cost-function-library>`_

Manuals
=======

- Main documentation : :download:`toulbar2<_files/toulbar2.pdf>`

- API Reference : 
  :download:`Class Diagram<../../misc/doc/toulbar2-class.pdf>` |
  :download:`C++ Library of toulbar2<_files/cpp_library.pdf>` |
  :download:`Python Library of toulbar2<_files/python_library.pdf>`

- Some extracts :
  :download:`User manual<_files/userdoc.pdf>` |
  :download:`Reference manual<_files/refman.pdf>` |
  :download:`Tutorials<_files/tutorials.pdf>` |
  :download:`WCSP format<_files/WCSP_format.pdf>` |
  :download:`CFN format<_files/CFN_format.pdf>` 

Other productions
=================

- ANITI webinar on toulbar2 for industrial applications :
  `slides <https://miat.inrae.fr/degivry/GivryANITI2021.pdf>`_ in English |
  `talk <https://youtu.be/lH04asuheo8>`_ in French

- tutorial `materials <https://forgemia.inra.fr/thomas.schiex/acpaior20>`_ on
  cost function networks at `ACP/ANITI/GDR-IA/RO Autumn School 2020
  <https://acp-iaro-school.sciencesconf.org>`_.

- tutorial on cost function networks at CP2020 (`teaser <https://www.youtube.com/watch?v=g8lgoR4XufU>`_, `part1 <https://www.youtube.com/watch?v=HHsqdVSJL8g>`_, `part2 <https://youtu.be/BYhhyiPFPGw>`_ videos, and `script <https://github.com/toulbar2/toulbar2/blob/master/web/TUTORIALS/tutorialCP2020.md>`_

- tutorial on cost function networks at PFIA 2019 (`part1 <http://miat.inrae.fr/degivry/talkPFIA2019part1.pdf>`_, `part2 <http://miat.inrae.fr/degivry/talkPFIA2019part2.pdf>`_, `demo <https://miat.inrae.fr/degivry/talkPFIA2019demo.pdf>`_), Toulouse, France, July 4th, 2019.

- talk on toulbar2 latest algorithmic features at `ISMP 2018 <http://miat.inrae.fr/degivry/GivryISMP2018.pdf>`_, Bordeaux, France, July 6, 2018.

- toulbar2 projects meeting at `CP 2016 <https://cp2016.sched.org/event/89xl>`_, Toulouse, France, September 5, 2016.

