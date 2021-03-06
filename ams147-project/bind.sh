#A simple script to automate the creation of language bindings with swig
MODULE=""
INTERFACE_EXT="i"
if [ $# -eq 0 ]
then
  printf "USAGE:$0 <language to generate bindings in> <name of octfile>\n"
fi

if [[ $# -eq 2 && "$1" == "octave" ]] ; then
  MODULE="$2"
  OCTFILE="$MODULE.oct"
  OLD_WRAPPER="$MODULE""_wrap.cxx"
  NEW_WRAPPER="$MODULE""_wrap.cpp"
  printf "creating $OCTFILE\n"
  swig -$1 -c++ -o $OLD_WRAPPER $MODULE.$INTERFACE_EXT
  mv $OLD_WRAPPER $NEW_WRAPPER
  mkoctfile $MODULE.cpp $NEW_WRAPPER
  printf "done\n"
fi

if [[ $# -eq 2 && "$1" == "python" ]] ; then
  #to do
  printf "done\n"
fi

if [[ $# -eq 2 && "$1" == "java" ]] ; then
  #to do
  printf "done\n"
fi

printf "Written by Arom Zinhart DeGraca\n"
