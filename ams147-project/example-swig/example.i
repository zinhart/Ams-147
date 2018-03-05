%module example
%{
#include "example.h"
%}
%include "std_vector.i"
%template(IntVector) std::vector<int>;
%template(DoubleVector) std::vector<double>;
%include "example.h"
