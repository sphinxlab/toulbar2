#!/bin/bash

set -x

# deploy.sh

# Builds the documentation using sphinx (and doxygen + breathe for C++ code)
# and updates GitHub Pages.
# In deployment case by default, in development case if INPUT "devel".
 
# .github/workflows/docs-deploy.yml -> "deploy.sh"       -> build.sh
# .github/workflows/docs-devel.yml  -> "deploy.sh devel" -> build.sh           

# usecase available values : "devel" or none
usecase=$1

###############################################################################
# Install depends
 
# required for tzdata
TZ=Europe/Paris
ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

apt-get update -y
apt-get -y install git rsync python3-stemmer python3-git python3-pip
 
# Required to build doxygen docs (xml used by breathe)
apt-get -y install cmake g++ libgmp-dev libboost-graph-dev libboost-iostreams-dev zlib1g-dev liblzma-dev libxml2-dev libopenmpi-dev libboost-mpi-dev libjemalloc-dev pkg-config texlive-latex-recommended  texlive-fonts-recommended graphviz doxygen

python3 -m pip install --upgrade sphinx sphinx_rtd_theme rinohtype pygments breathe

###############################################################################
# Declare variables
 
pwd
ls -lah
export SOURCE_DATE_EPOCH=$(git log -1 --pretty=%ct)
 
# make a new temp dir which will be our GitHub Pages docroot
docroot=`mktemp -d`

export REPO_NAME="${GITHUB_REPOSITORY##*/}"
 
###############################################################################
# Build docs

if [[ ${usecase} == "devel" ]]; then

    # get a list of branches, excluding 'HEAD' and 'gh-pages'
    #versions="`git for-each-ref '--format=%(refname:lstrip=-1)' refs/remotes/origin/ | grep -viE '^(HEAD|gh-pages)$'`"

    # manual selection of a list of branches . Must always contain master
    ###versions="master sphinx-nr sphinx-usr"
    versions="master sphinx-nr"

    for current_version in ${versions}; do
       git checkout ${current_version}
       docs/_cicd/build.sh ${docroot} ${current_version}
       git checkout master # return to master branch
    done

else
    # main master branch
    current_version="master" 
    git checkout ${current_version}
    docs/_cicd/build.sh ${docroot} ${current_version}
    git checkout master # return to master branch
fi
 
###############################################################################
# Update GitHub Pages
 
git config --global user.name "${GITHUB_ACTOR}"
git config --global user.email "${GITHUB_ACTOR}@users.noreply.github.com"
 
pushd "${docroot}"
 
# don't bother maintaining history; just generate fresh
git init
git remote add deploy "https://token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git checkout -b gh-pages
 
# add .nojekyll to the root so that github won't 404 on content added to dirs
# that start with an underscore (_), such as our "_content" dir..
touch .nojekyll
 
if [[ ${usecase} == "devel" ]]; then

# add devel.html
cat > devel.html <<EOF
<!DOCTYPE html>
<html>
  <head>
    <title>toulbar2 docs (by devel.sh) </title>
  </head>
  <body>
    <p> ... language/branchname ...</p>
  </body>
</html>

EOF

else

# add index.html (redirection to default docs language/version)
cat > index.html <<EOF
<!DOCTYPE html>
<html>
  <head>
    <title>toulbar2 docs (by deploy.sh) </title>
    <meta http-equiv = "refresh" content="0; url='/${REPO_NAME}/en/master/'" />
  </head>
  <body>
    <p>Redirection to <a href="/${REPO_NAME}/en/master/">toulbar2 main documentation</a>...</p>
  </body>
</html>
EOF

fi
 
# add README.md
cat > README.md <<EOF
# GitHub Pages Cache

Branch not intended to be viewed on github.com, for more see docs/README.md.

EOF
 
git add .

#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
git status
 
msg="Updating Docs for commit ${GITHUB_SHA} made on `date -d"@${SOURCE_DATE_EPOCH}" --iso-8601=seconds` from ${GITHUB_REF} by ${GITHUB_ACTOR}"
git commit -am "${msg}"
 
git push deploy gh-pages --force
 
popd
 
exit 0

