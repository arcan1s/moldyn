#!/bin/bash
func_help() {
  echo -e "\nUsage: update_ver.sh -o OLDVER -n NEWVER"
  echo -e "\nRequired parameters:"
  echo -e "  -o  --oldver      - path to GIT repository"
  echo -e "  -n  --newver      - time to sleep"
  echo -e "\nAdditional parametrs:"
  echo -e "  -h  --help        - show this help and exit"
  exit 1
}

until [ -z $1 ]; do
  if [ "$1" = "-h" ]; then
    func_help; fi
  if [ "$1" = "--help" ]; then
    func_help; fi
  if [ "$1" = "-o" ]; then
    OLDVER="$2"
    shift; fi
  if [ "$1" = "--oldver" ]; then
   OLDVER="$2"
    shift; fi
  if [ "$1" = "-n" ]; then
    NEWVER="$2"
    shift; fi
  if [ "$1" = "--newver" ]; then
    NEWVER="$2"
    shift; fi
  shift
done

if [[ -z "$OLDVER" || -z "$NEWVER" ]]; then
  echo "Parametrs aren't set"
  echo "Usage: update_ver.sh -o OLDVER -n NEWVER" 
  exit 1
fi

# work block
COMPONENTS=(mm_agl mm_envir mm_radf mm_statgen mm_trj mm_trj2pdb)
for COMPONENT in ${COMPONENTS[*]}; do
  sed -i "s/Version : $OLDVER/Version : $NEWVER/g" $COMPONENT/src/main.c
  sed -i "s/Version: $OLDVER/Version: $NEWVER/g" $COMPONENT/README
  sed -i "s/V.$OLDVER/V.$NEWVER/g" $COMPONENT/$COMPONENT.doxygen
done

COMPONENT=mathmech
sed -i "s/Version: $OLDVER/Version: $NEWVER/g" $COMPONENT/README
