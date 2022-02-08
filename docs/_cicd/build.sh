#!/bin/bash

set -x

# build.sh

# Builds the documentation for one branch

# .github/workflows/docs-deploy.yml -> "deploy.sh"       -> build.sh
# .github/workflows/docs-devel.yml  -> "deploy.sh devel" -> build.sh           

docroot=$1
current_version=$2

###############################################################################

./clean # cleanup
#make -C docs clean

export current_version # for conf.py
 
echo "INFO: Building sites for ${current_version}"
 
if [ ! -e 'docs/conf.py' ]; then
    echo -e "\tINFO: Can not find 'docs/conf.py' (skipped)"
    continue
fi

# Build doxygen docs (xml used by breathe)
mkdir build
pushd build 
#cmake -DBUILD_API_DOC=ON -DBUILD_API_DOC_LATEX=ON ..
cmake -DBUILD_API_DOC=ON ..
make doc #make (for help ?)
popd
 
languages="en `find docs/locales/ -mindepth 1 -maxdepth 1 -type d -exec basename '{}' \;`"
    for current_language in ${languages}; do
 
      export current_language # for conf.py
 
      echo "INFO: Building for ${current_language}"
 
      # html
      sphinx-build -b html docs/ docs/_build/html/${current_language}/${current_version} -D language="${current_language}"
 
      # pdf
      sphinx-build -b rinoh docs/ docs/_build/rinoh -D language="${current_language}"
      mkdir -p "${docroot}/${current_language}/${current_version}"
      cp "docs/_build/rinoh/toulbar2.pdf" "${docroot}/${current_language}/${current_version}/toulbar2_${current_language}_${current_version}.pdf"

      # epub
      sphinx-build -b epub docs/ docs/_build/epub -D language="${current_language}"
      mkdir -p "${docroot}/${current_language}/${current_version}"
      cp "docs/_build/epub/toulbar2.epub" "${docroot}/${current_language}/${current_version}/toulbar2_${current_language}_${current_version}.epub"
 
      # copy into docroot the static assets produced by the above build
      rsync -av "docs/_build/html/" "${docroot}/"
 
    done

exit 0

