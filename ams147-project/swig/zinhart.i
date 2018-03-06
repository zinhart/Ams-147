%module zinhart
%{
#include "net/net.hh"
#include "net/common.hh"
%}
%include "std_string.i"
%include "std_vector.i"
%template(IntVector) std::vector<int>;
%template(UIntVector) std::vector<unsigned int>;
%template(DoubleVector) std::vector<double>;
%include "net/net.hh"
%include "net/common.hh"
