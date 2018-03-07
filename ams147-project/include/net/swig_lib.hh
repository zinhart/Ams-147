#ifndef SWIG_LIB_HH
#define SWIG_LIB_HH
#include<octave/oct.h>
#include<vector>
namespace zinhart
{
  std::string zstring()
  {
    return std::string();
  } 
  std::string zstring(std::string str)
  {
    return std::string(str);
  }
}
#endif
