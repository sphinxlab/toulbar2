# Sphinx documentation of toulbar2

## step3

Livraison d’une version :

- (succédant à step1, step2) prenant en compte sous Sphinx (docs) la documentation qui existait précédemment sous Doxygen (doc).
- réorganisant le plan de la documentation (regroupements…), étant donnée la réécriture/insertion de nouvelles pages .rst.
- prenant en compte une grande partie de ce qui a été vu/dit en réunion jeudi 10 mars 2022, mais pas fini.

- utilisant toulbar2/README.md ("découpé" pour authors, citing, what are the algos...) en remplacement de texte du site (presentation.rst, publications.rst). **La partie "Authors" du README.md** est à adapter/modifier pour ne pas perdre l'ancien texte "Authors" de presentation.rst.  
- contient des parties temporaires : ref_cpp.rst, presentation.rst.

Voir document NotesReunions.odt pour plus de details.


## General

The **'toulbar2/docs'** folder is dedicated to the **Sphinx** documentation of toulbar2.

This documentation replaces the previous .html pages of **'toulbar2/web'** folder.

This documentation **uses files of some other folders**, such as 'toulbar2/web'.

This documentation is **hosted on GitHub Pages**, built with **GitHub free CI/CD tool** ; with a **redirection** of current toulbar2 site to those GitHub Pages.

## [Method](README/method.md)

## [Creation](README/creation.md)

## [Local build](README/local_build.md)

## Deploy ([CI/CD](README/CICD.md))

The documentation is hosted on GitHub Pages **toulbar2.github.io/toulbar2** where installed by [CI/CD](README/CICD.md).

Redirections from the toulbar2 site main URL **miat.inrae.fr/toulbar2** to the documentation on GitHub Pages **toulbar2.github.io/toulbar2**.

## Misc

- Documentation (.rst) uses **'HELP'** file (result of command
  'toulbar2 --help').  This **'HELP'** file has to be updated when toulbar2
  modifications.

