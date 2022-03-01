.. _input_formats:

=============
Input formats
=============

Overview
========

The available **file formats** (possibly compressed by gzip or xz, e.g., .cfn.gz, .wcsp.xz) are :

  - :ref:`Cost Function Network format<cfn_format>` (:download:`.cfn<../_files/CFN_format.pdf>` file extensions)
  - :ref:`Weighted Constraint Satisfaction Problem<wcsp_format>` (:download:`.wcsp<../_files/WCSP_format.pdf>` file extension)
  - Probabilistic Graphical Model (`.uai <http://www.cs.huji.ac.il/project/PASCAL/fileFormat.php>`_ / .LG file extension ; the file format .LG is identical to .UAI except that we expect log-potentials)
  - Weigthed Partial Max-SAT (`.cnf/.wcnf <http://www.maxsat.udl.cat/08/index.php?disp=requirements>`_ file extension)
  - Quadratic Unconstrained Pseudo-Boolean Optimization (:download:`.qpbo<QpboFormat.txt>` file extension)
  - Pseudo-Boolean Optimization (`.opb <http://www.cril.univ-artois.fr/PB16/format.pdf>`_ file extension)

Some examples
=============

  - A simple 2 variables maximization problem `maximization.cfn <https://github.com/toulbar2/toulbar2/raw/master/validation/default/maximization.cfn>`_ in JSON-compatible CFN format, with decimal positive and negative costs.                 
  
  - Random binary cost function network :download:`example.wcsp<../../web/EXAMPLES/example.wcsp.xz>`, with a specific variable ordering :download:`example.order<../../web/EXAMPLES/example.order>`, a tree decomposition :download:`example.cov<../../web/EXAMPLES/example.cov>`, and a cluster decomposition :download:`example.dec<../../web/EXAMPLES/example.dec>`
  
  - Latin square 4x4 with random costs on each variable :download:`latin4.wcsp<../../web/EXAMPLES/latin4.wcsp.xz>`
  
  - `Radio link frequency assignment CELAR <http://miat.inrae.fr/schiex/Doc/Export/CELAR.ps.gz>`_ instances :download:`scen06.wcsp<../../web/EXAMPLES/scen06.wcsp.xz>`, :download:`scen06.cov<../../web/EXAMPLES/scen06.cov>`, :download:`scen06.dec<../../web/EXAMPLES/scen06.dec>`, :download:`scen07.wcsp<../../web/EXAMPLES/scen07.wcsp.xz>`
  
  - `Earth observation satellite management SPOT5 <https://forgemia.inra.fr/thomas.schiex/cost-function-library/-/raw/master/real/spot5/BensanaLemaitreVerfaillieConstraints1999.pdf>`_ instances :download:`404.wcsp<../../web/EXAMPLES/404.wcsp.xz>` and :download:`505.wcsp<../../web/EXAMPLES/505.wcsp.xz>` with associated tree/cluster decompositions :download:`404.cov<../../web/EXAMPLES/404.cov>`, :download:`505.cov<../../web/EXAMPLES/505.cov>`, :download:`404.dec<../../web/EXAMPLES/404.dec>`, :download:`505.dec<../../web/EXAMPLES/505.dec>`
  
  - Linkage analysis instance :download:`pedigree9.uai<../../web/EXAMPLES/pedigree9.uai.xz>`
  
  - Computer vision superpixel-based image segmentation instance :download:`GeomSurf-7-gm256.uai<../../web/EXAMPLES/GeomSurf-7-gm256.uai.xz>`
  
  - `Protein folding <http://miat.inrae.fr/degivry/Schiex14a.pdf>`_ instance :download:`1CM1.uai<../../web/EXAMPLES/1CM1.uai.xz>`
  
  - Max-clique DIMACS instance :download:`brock200_4.clq.wcnf<../../web/EXAMPLES/brock200_4.clq.wcnf.xz>`
  
  - Graph 6-coloring instance :download:`GEOM40_6.wcsp<../../web/EXAMPLES/GEOM40_6.wcsp.xz>`

  - Many more instances available `evalgm <http://genoweb.toulouse.inra.fr/~degivry/evalgm>`_ and  `Cost Function Library <https://forgemia.inra.fr/thomas.schiex/cost-function-library>`_.

.. _inputfileformats:

Input File formats
==================

Notice that by default toulbar2 distinguishes file formats based on their extension. 
It is possible to read a file from a unix pipe using option :code:`-stdin=[format]`; *e.g.*, :code:`cat example.wcsp | toulbar2 --stdin=wcsp`

It is also possible to read and combine multiple problem files (warning, they must be all in the same format, either wcsp, cfn, or xml). 
Variables with the same name are merged (domains must be identical), otherwise the merge is based on variable indexes (wcsp format).

cfn format (.cfn, .cfn.gz, and .cfn.xz file extension)
------------------------------------------------------

With this JSON compatible format, it is possible:

  - to give a name to variables and functions.
  - to associate a local label to every value that is accessible inside toulbar2 (among others for heuristics design purposes).
  - to use decimal and possibly negative costs.
  - to solve both minimization and maximization problems.
  - to debug  your .cfn files: the parser gives a cause and line number when it fails.
  - to use gzip'd or xz compressed files directly as input (.cfn.gz and .cfn.xz).
  - to use dense descriptions for dense cost tables.

See a full description here :

.. toctree::
   :maxdepth: 1

   cfnformat.rst

Or :download:`CFN_format.pdf<../_files/CFN_format.pdf>`

wcsp format (.wcsp file extension)
----------------------------------

.. toctree::
   :maxdepth: 1

   wcspformat.rst

Or :download:`WCSP_format.pdf<../_files/WCSP_format.pdf>`

..
.. CPD final stanza
.. ----------------
.. 
.. TODO
..

UAI and LG formats (.uai, .LG)
------------------------------

It is a simple text file format specified below to describe probabilistic graphical model instances. The format is a generalization of the Ergo file format initially developed by Noetic Systems Inc. for their Ergo software.

- **Structure**

  A file in the UAI format consists of the following two parts, in that order: ::

      <Preamble>

      <Function tables>

  The contents of each section (denoted :math:`<...>` above) are described in the following:

- **Preamble**

  The preamble starts with one line denoting the type of network. This will be either BAYES (if the network is a Bayesian network) or MARKOV (in case of a Markov network). This is followed by a line containing the number of variables. The next line specifies each variable's domain size, one at a time, separated by whitespace (note that this implies an order on the variables which will be used throughout the file).

  The fourth line contains only one integer, denoting the number of functions in the problem (conditional probability tables for Bayesian networks, general factors for Markov networks). Then, one function per line, the scope of each function is given as follows: The first integer in each line specifies the size of the function's scope, followed by the actual indexes of the variables in the scope. The order of this list is not restricted, except when specifying a conditional probability table (CPT) in a Bayesian network, where the child variable has to come last. Also note that variables are indexed starting with 0.

  For instance, a general function over variables 0, 5 and 11 would have this entry: ::

    3 0 5 11

  A simple Markov network preamble with three variables and two functions might for instance look like this: ::

    MARKOV
    3
    2 2 3
    2
    2 0 1
    3 0 1 2

  The first line denotes the Markov network, the second line tells us the problem consists of three variables, let's refer to them as X, Y, and Z. Their domain size is 2, 2, and 3 respectively (from the third line). Line four specifies that there are 2 functions. The scope of the first function is X,Y, while the second function is defined over X,Y,Z.

  An example preamble for a Belief network over three variables (and therefore with three functions) might be: ::

    BAYES
    3
    2 2 3
    3
    1 0
    2 0 1
    2 1 2

  The first line signals a Bayesian network. This example has three variables, let's call them X, Y, and Z, with domain size 2, 2, and 3, respectively (from lines two and three). Line four says that there are 3 functions (CPTs in this case). The scope of the first function is given in line five as just X (the probability P(X)), the second one is defined over X and Y (this is (Y | X)). The third function, from line seven, is the CPT P(Z | Y). We can therefore deduce that the joint probability for this problem factors as P(X,Y,Z) = P(X).P(Y | X).P(Z | Y).

- **Function tables**

  In this section each function is specified by giving its full table (i.e, specifying the function value for each tuple). The order of the functions is identical to the one in which they were introduced in the preamble.

  For each function table, first the number of entries is given (this should be equal to the product of the domain sizes of the variables in the scope). Then, one by one, separated by whitespace, the values for each assignment to the variables in the function's scope are enumerated. Tuples are implicitly assumed in ascending order, with the last variable in the scope as the 'least significant'.

  To illustrate, we continue with our Bayesian network example from above, let's assume the following conditional probability tables: ::

    X      P(X)
    0      0.436
    1      0.564

    X      Y         P(Y | X)
    0      0         0.128
    0      1         0.872
    1      0         0.920
    1      1         0.080

    Y      Z         P(Z | Y)
    0      0         0.210
    0      1         0.333
    0      2         0.457
    1      0         0.811
    1      1         0.000
    1      2         0.189

The corresponding function tables in the file would then look like this: ::

    2
     0.436 0.564

    4
     0.128 0.872
     0.920 0.080

    6
     0.210 0.333 0.457
     0.811 0.000 0.189 

(Note that line breaks and empty lines are effectively just whitespace, exactly like plain spaces " ". They are used here to improve readability.)

In the LG format, probabilities are replaced by their logarithm.

- **Summary**

  To sum up, a problem file consists of 2 sections: the preamble and the full the function tables, the names and the labels.

  For our Markov network example above, the full file could be: ::

    MARKOV
    3
    2 2 3
    2
    2 0 1
    3 0 1 2

    4
     4.000 2.400
     1.000 0.000

    12
     2.2500 3.2500 3.7500
     0.0000 0.0000 10.0000
     1.8750 4.0000 3.3330
     2.0000 2.0000 3.4000

Here is the full Bayesian network example from above: ::

    BAYES
    3
    2 2 3
    3
    1 0
    2 0 1
    2 1 2

    2
     0.436 0.564

    4
     0.128 0.872
     0.920 0.080

    6
     0.210 0.333 0.457
     0.811 0.000 0.189 

- **Expressing evidence**

  Evidence is specified in a separate file. This file has the same name as the original problems file but an added .evid extension at the end. For instance, problem.uai will have evidence in problem.uai.evid.

  The file simply starts with a line specifying the number of evidence variables. This is followed by the pairs of variable and value indexes for each observed variable, one pair per line. The indexes correspond to the ones implied by the original problem file.

  If, for our above example, we want to specify that variable Y has been observed as having its first value and Z with its second value, the file example.uai.evid would contain the following: ::

    2
     1 0
     2 1

Partial Weighted MaxSAT format
------------------------------

  **Max-SAT input format (.cnf)}**

  The input file format for Max-SAT will be in DIMACS format: ::

    c
    c comments Max-SAT
    c
    p cnf 3 4
    1 -2 0
    -1 2 -3 0
    -3 2 0
    1 3 0

  - The file can start with comments, that is lines beginning with the character 'c'.
  - Right after the comments, there is the line "p cnf nbvar nbclauses" indicating that the instance is in CNF format; nbvar is the number of variables appearing in the file; nbclauses is the exact number of clauses contained in the file.
  - Then the clauses follow. Each clause is a sequence of distinct non-null numbers between -nbvar and nbvar ending with 0 on the same line. Positive numbers denote the corresponding variables. Negative numbers denote the negations of the corresponding variables.

  **Weighted Max-SAT input format (.wcnf)**

  In Weighted Max-SAT, the parameters line is "p wcnf nbvar nbclauses". The weights of each clause will be identified by the first integer in each clause line. The weight of each clause is an integer greater than or equal to 1.

  Example of Weighted Max-SAT formula: ::

    c
    c comments Weighted Max-SAT
    c
    p wcnf 3 4
    10 1 -2 0
    3 -1 2 -3 0
    8 -3 2 0
    5 1 3 0

  **Partial Max-SAT input format (.wcnf)**

  In Partial Max-SAT, the parameters line is "p wcnf nbvar nbclauses top". We associate a weight with each clause, which is the first integer in the clause. Weights must be greater than or equal to 1. Hard clauses have weight top and soft clauses have weight 1. We assume that top is a weight always greater than the sum of the weights of violated soft clauses.

  Example of Partial Max-SAT formula: ::

    c
    c comments Partial Max-SAT
    c
    p wcnf 4 5 15
    15 1 -2 4 0
    15 -1 -2 3 0
    1 -2 -4 0
    1 -3 2 0
    1 1 3 0

  **Weighted Partial Max-SAT input format (.wcnf)**

  In Weighted Partial Max-SAT, the parameters line is "p wcnf nbvar nbclauses top". We associate a weight with each clause, which is the first integer in the clause. Weights must be greater than or equal to 1. Hard clauses have weight top and soft clauses have a weight smaller than top. We assume that top is a weight always greater than the sum of the weights of violated soft clauses.

  Example of Weighted Partial Max-SAT formula: ::

    c
    c comments Weighted Partial Max-SAT
    c
    p wcnf 4 5 16
    16 1 -2 4 0
    16 -1 -2 3 0
    8 -2 -4 0
    4 -3 2 0
    3 1 3 0

QPBO format (.qpbo)
-------------------

In the quadratic pseudo-Boolean optimization (unconstrained quadratic programming) format, the goal is to minimize or maximize the quadratic function:

:math:`X' * W * X = \sum_{i=1}^N \sum_{j=1}^N  W_{ij} * X_i * X_j`

where :math:`W` is a symmetric squared :math:`N \times N` matrix expressed by all its non-zero half (:math:`i \leq j`) squared matrix coefficients, :math:`X` is a vector of :math:`N` binary variables with domain values in :math:`\{0,1\}` or :math:`\{1,-1\}`, and :math:`X'` is the transposed vector of :math:`X`.

Note that for two indices :math:`i \neq j`, coefficient :math:`W_{ij} = W_{ji}` (symmetric matrix) and it appears twice in the previous sum.
It can be controled by the option {\tt -qpmult=[double]} which defines a coefficient multiplier for quadratic terms (default value is 2).

Note also that coefficients can be positive or negative and are real float numbers. They are converted to fixed-point real numbers by multiplying them by :math:`10^{precision}` (see option {\em -precision} to modify it, default value is 7).  Infinite coefficients are forbidden.

Notice that depending on the sign of the number of variables in the first text line, the domain of all variables is either :math:`\{0,1\}` or :math:`\{1,-1\}`.

Warning! The encoding in Weighted CSP of variable domain :math:`\{1,-1\}` associates for each variable value the following index: value 1 has index 0 and value -1 has index 1 in the solutions found by toulbar2.
The encoding  of variable domain :math:`\{0,1\}` is direct.

Qpbo is a file text format:

  - First line contains the number of variables :math:`N` and the number of non-zero coefficients :math:`M`.

    If :math:`N` is negative then domain values are in :math:`\{1, -1\}`, otherwise :math:`\{0, 1\}`.
    If :math:`M` is negative then it will maximize the quadratic function, otherwise it will minimize it.

  - Followed by :math:`|M|` lines where each text line contains three values separated by spaces:
    position index :math:`i` (integer belonging to :math:`[1,|N|]`),
    position index :math:`j` (integer belonging to :math:`[1,|N|]`),
    coefficient :math:`W_{ij}` (float number)
    such that :math:`i \leq j` and :math:`W_{ij} \neq 0`.

OPB format (.opb)
-----------------

The OPB file format is used to express pseudo-Boolean satisfaction and optimization models. 
These models may only contain :math:`0/1` Boolean variables. The format is defined by an optional objective function followed by a set of linear constraints.
Variables may be multiplied together in the objective function, but currently not in the constraints due to some restriction in the reader.
The objective function must start with the **min:** or **max:** keyword followed by **coef_1 varname_1_1 varname_1_2 ... coef2 varname_2_1 ...** and end with a **;**.
Linear constraints are composed in the same way, ended by a comparison operator (**<=**, **>=**, or **!=**) followed by the right-hand side coefficient and **;**.
Each coefficient must be an integer beginning with its sign (**+** or **-** with no extra space).
Comment lines start with a \*.

An example with a quadratic objective and 7 linear constraints is: ::

  max: +1 x1 x2 +2 x3 x4;
  +1 x2 +1 x1 >= 1;
  +1 x3 +1 x1 >= 1;
  +1 x4 +1 x1 >= 1;
  +1 x3 +1 x2 >= 1;
  +1 x4 +1 x2 >= 1;
  +1 x4 +1 x3 >= 1;
  +2 x1 +2 x2 +2 x3 +2 x4 <= 7;

Internally, all integer costs are multiplied by a power of ten depending on the -precision option. 
For problems with big integers, try to reduce the precision (*e.g.*, use option -precision 0).

XCSP2.1 format (.xml)
---------------------

CSP and weighted CSP in XML format XCSP 2.1, with constraints in extension only, can be read. See a description of this deprecated format here `http://www.cril.univ-artois.fr/CPAI08/XCSP2_1.pdf <http://www.cril.univ-artois.fr/CPAI08/XCSP2_1.pdf>`_.

Warning, toulbar2 must be compiled with a specific option XML in the cmake.

Linkage format (.pre)
---------------------

See **mendelsoft** companion software at http://miat.inrae.fr/MendelSoft for pedigree correction. See also https://carlit.toulouse.inra.fr/cgi-bin/awki.cgi/HaplotypeInference for haplotype inference in half-sib families.

.. %\subsection{BEP format}

Misc
====

:download:`HaplotypeHalfSib.txt<HaplotypeHalfSib.txt>`

.. literalinclude:: HaplotypeHalfSib.txt

:download:`MendelSoft.txt<MendelSoft.txt>`

.. literalinclude:: MendelSoft.txt

:download:`QpboFormat.txt<QpboFormat.txt>`

.. literalinclude:: QpboFormat.txt

:download:`UAI08Format.txt<UAI08Format.txt>`

.. literalinclude:: UAI08Format.txt

:download:`WcnfFormats.txt<WcnfFormats.txt>`

.. literalinclude:: WcnfFormats.txt

