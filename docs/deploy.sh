#!/bin/bash

set -x

# deploy.sh

# Builds the documentation in deployment case
 
# .github/workflows/docs-deploy.yml |-> cicd.sh ->| deploy.sh |-> build.sh
# .github/workflows/docs-devel.yml  |             | devel.sh  |

docroot=$1

###############################################################################
 
# get a list of branches, excluding 'HEAD' and 'gh-pages'
#versions="`git for-each-ref '--format=%(refname:lstrip=-1)' refs/remotes/origin/ | grep -viE '^(HEAD|gh-pages)$'`"
# manual selection of a list of branches
###versions="master sphinx-nr sphinx-usr"
versions="sphinx-nr"
for current_version in ${versions}; do
 
   git checkout ${current_version}

   docs/_cicd/build.sh ${docroot} ${current_version}
 
   git checkout master # return to master branch
 
done
 
exit 0

