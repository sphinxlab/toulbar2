# Sphinx documentation of toulbar2 -> Creation

## Install/init

### Sphinx

- Install sphinx

      sudo apt-get install -y python3-sphinx
      sudo apt-get install -y python3-sphinx-rtd-theme

- setup sphinx site  :

      cd docs
      sphinx-quickstart
      ...answers... (follow [Method](method.md)).

- conf.py :

  - change theme from 'alabaster' to 'sphinx_rtd_theme'
  - python code path

### Add C++ documentation

Use of Doxygen and breathe : the build/xml folder content, built by Doxygen,
will be used by Sphinx (via breathe).

- add 'breathe' into toulbar2/docs/_local/requirement.txt and
  into docs/conf.py (extensions, breathe_projects).

- add into toulbar2/Doxyfile.in ::

      GENERATE_XML = YES

## [Local build](local_build.md)

## Initial content at creation

At creation :
The .rst pages have been created from 'toulbar2/web' .html pages that have been renamed .html.old (.html pages being now redirections to Sphinx online documentation).

Now installed :
Documentation of toulbar2 python code (toulbar2/pytoulbar2) and of
toulbar2 C++ code (toulbar2/src).

## [CI/CD](CICD.md)

