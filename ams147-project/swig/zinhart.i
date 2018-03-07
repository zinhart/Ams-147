%module zinhart
%{
#include "net/common.hh"
#include "net/net.hh"
#include "net/swig_lib.hh"
/*using zinhart::i_type;
using zinhart::s_type;
using zinhart::p_type;
using zinhart::i_vect;
using zinhart::s_vect;
using zinhart::p_vect;*/
%}
%include "std_string.i"
%include "std_vector.i"
%include "stdint.i"
%template(vec_i) std::vector<std::int32_t>;
%template(vec_ui) std::vector<std::uint32_t>; 
%template(vec_d) std::vector<double>; 
%include "net/common.hh"
%include "net/net.hh"
%include "net/swig_lib.hh"
