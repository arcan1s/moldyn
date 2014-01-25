#!/bin/bash
func_help() {
  echo -e "\nUsage: update_ver.sh -o OLDVER -n NEWVER"
  echo -e "\nRequired parameters:"
  echo -e "  -o  --oldver      - old version"
  echo -e "  -n  --newver      - new version"
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
COMPONENTS=(agl envir radf statgen trj trj2pdb)
for COMPONENT in ${COMPONENTS[*]}; do
# help message
  sed -i "s/Version : $OLDVER/Version : $NEWVER/g" $COMPONENT/src/main.c
# head in output
  sed -i "s/V.$OLDVER/V.$NEWVER/g" $COMPONENT/src/add_main.c
# readme
  sed -i "s/Version: $OLDVER/Version: $NEWVER/g" $COMPONENT/README
done

COMPONENT=mathmech
# about window
sed -i "s/$OLDVER/$NEWVER/g" $COMPONENT/resources/translations/eng.ts
sed -i "s/$OLDVER/$NEWVER/g" $COMPONENT/resources/translations/rus.ts
# readme
sed -i "s/Version: $OLDVER/Version: $NEWVER/g" $COMPONENT/README
