#A simple script to clean up files created by swig

if [ $# -eq 0 ]
then
  printf "USAGE:$0 <language to remove swig files for\n"
fi

if [[ $# -eq 1 && "$1" -eq "octave" ]] ; then
  rm -f *.o  *.oct  *_wrap.cpp  *_wrap.o
fi
printf "Written by Arom Zinhart DeGraca\n"
