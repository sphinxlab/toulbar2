.. _vs:

=============
Visual Sudoku
=============

An example
----------

A simple case mixing **Deep Learning** and **Graphical models**.

You can run it directly from your browser as a `Jupyter Notebook <https://colab.research.google.com/drive/1ew7IceldcAhyZZ0bHvaHynZyM-s-ne0l#scrollTo=tBwwmI21cFVZ>`_
|colab_logo_visualsudoku|

.. |colab_logo_visualsudoku| image:: /_static/img/logo-colab.png
   :width: 30
   :alt: `colab_url_visualsudoku`_
   :target: `colab_url_visualsudoku`_

.. _colab_url_visualsudoku: https://colab.research.google.com/drive/1ew7IceldcAhyZZ0bHvaHynZyM-s-ne0l#scrollTo=tBwwmI21cFVZ


.. _vsudoku:
  
Another example
---------------

An automatic Sudoku puzzle **solver** using **OpenCV**, **Deep Learning**, and **Optical Character Recognition** (**OCR**).

Software adapted by Simon de Givry (@ INRAE, 2022)
in order to use **toulbar2** solver, from a
`tutorial <https://pyimagesearch.com/2020/08/10/opencv-sudoku-solver-and-ocr>`_
by Adrian Rosebrock (@ PyImageSearch, 2022).

`GitHub code <https://forgemia.inra.fr/thomas.schiex/cost-function-library/-/tree/master/crafted/visualsudoku>`_
|github_logo_vsudoku|

Available as a web service :

  - You can `try it <http://147.100.179.250/api/ui/vsudoku>`_
    directly from your browser as a `web service <http://147.100.179.250/api/ui/vsudoku>`_
    |qrcode_ui_vsudoku| 

  - Other ways to call the web service :

    The visual sudoku web service is hosted by the `ws <http://147.100.179.250>`_ web services that are based on HTTP protocol, so it can be called by many ways : from a browser (like above), or any softwares written in a language supporting HTTP protocol (Python, R, C++, Java, Php...), or command line tools (cURL...)...

    Example from a terminal by cURL (*replace mygridfilename.jpg by your own image file name*) : ::

      curl --output mysolutionfilename.jpg -F 'file=@mygridfilename.jpg' -F 'keep=40' -F 'border=15' http://147.100.179.250/api/tool/vsudoku

.. |github_logo_vsudoku| image:: /_static/img/logo-github.png
   :width: 30
   :alt: https://forgemia.inra.fr/thomas.schiex/cost-function-library/-/tree/master/crafted/visualsudoku
   :target: https://forgemia.inra.fr/thomas.schiex/cost-function-library/-/tree/master/crafted/visualsudoku

.. |qrcode_ui_vsudoku| image:: /_static/img/qr-code_ui-vsudoku.png
   :width: 100
   :alt: `url_ui_vsudoku`_
   :target: `url_ui_vsudoku`_

.. _url_ui_vsudoku: http://147.100.179.250/api/ui/vsudoku

