%module mymod
%{
#include "net/Net.h"
%}
%include "std_vector.i"
%template(IntVector) std::vector<int>;
%template(UIntVector) std::vector<unsigned int>;
%template(DoubleVector) std::vector<double>;
%include "net/Net.h"
