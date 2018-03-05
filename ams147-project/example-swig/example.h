#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <vector>
#include <octave/oct.h>
class Example
{
//  private:
 public:
   std::vector<int> test;
    const double * y;
	Example()
	{

	}
	Example(std::vector<int> a_matrix)
	{
	  test = a_matrix;
	}
    std::vector<int> get_int()
    {
      return test;
    }    
};
#endif
