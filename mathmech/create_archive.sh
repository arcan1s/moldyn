#!/bin/bash

FILES="docs mathmech mm_agl mm_envir mm_radf mm_statgen mm_trj mm_trj2pdb AUTHORS CMakeLists.txt COPYING docs.cmake INSTALL"
ARCHIVE="mathmech"
VERSION=`grep -m1 PROJECT_VERSION_MAJOR CMakeLists.txt | awk '{print $3}' | cut -c 1`.\
`grep -m1 PROJECT_VERSION_MINOR CMakeLists.txt | awk '{print $3}' | cut -c 1`.\
`grep -m1 PROJECT_VERSION_PATCH CMakeLists.txt | awk '{print $3}' | cut -c 1`

# create archive
if [ -e ${ARCHIVE}-${VERSION}-src.zip ]; then
  rm -f ${ARCHIVE}-${VERSION}-src.zip
fi
zip -9 -y -r -q ${ARCHIVE}-${VERSION}-src.zip ${FILES}

# update md5sum
MD5SUMS=`md5sum ${ARCHIVE}-${VERSION}-src.zip | awk '{print $1}'`
sed -i "/md5sums=('[0-9A-Fa-f]*/s/[^'][^)]*/md5sums=('${MD5SUMS}'/" PKGBUILD
sed -i "s/pkgver=[0-9.]*/pkgver=${VERSION}/" PKGBUILD
