#!/bin/bash

COMPONENTS=( mm_agl mm_envir mm_radf mm_statgen mm_trj mm_trj2pdb )
for COMPONENT in ${COMPONENTS[*]}; do
  cd $COMPONENT
  doxygen $COMPONENT.doxygen
  cp logo.png docs/latex
  cd docs/latex && make && cd ../../../
  mv $COMPONENT/docs/latex/refman.pdf $COMPONENT/$COMPONENT.pdf
  rm -rf $COMPONENT/docs
done
