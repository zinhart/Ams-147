#include "hw1.h"
namespace hw1
{
								unsigned int compute_factorial(unsigned int n)
								{
																if(n > 1)
																								return n * compute_factorial(n - 1);
																else
																								return 1;
								}
								Matrix test_compute_Euclidean_norm(Matrix v)
								{
															
								}
}
