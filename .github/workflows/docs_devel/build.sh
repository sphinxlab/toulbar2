#!/bin/bash

set -x

# build.sh

# Builds the documentation for one branch

# .github/workflows/docs-devel.yml -> devel.sh -> build.sh           

docroot=$1
current_version=$2

./clean # cleanup
#make -C docs clean

export current_version # for conf.py
 
echo "INFO: Building for ${current_version}"
 
if [ ! -e 'docs/source/conf.py' ]; then
    echo -e "\tINFO: Can not find 'docs/source/conf.py' (skipped)"
    continue
fi

# Install Sphinx
python -m pip install --upgrade pip
pip install -r docs/requirements.txt

# Build doxygen docs (xml used by breathe)
mkdir build
pushd build 
cmake -DBUILD_API_DOC=ON ..
make doc
popd
 
# Build Sphinx docs

pushd docs
make docs
popd

# epub (not ok)
#nok sphinx-build -b epub docs/ docs/_build/epub
#nok mkdir -p "${docroot}/${current_version}"
#nok cp "docs/_build/epub/toulbar2.epub" "${docroot}/${current_version}/toulbar2_${current_version}.epub"
 
# copy into docroot the static assets produced by the above build
rsync -av "docs/_build/html/" "${docroot}/${current_version}/"
 
exit 0

