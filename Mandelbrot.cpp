#include "Mandelbrot.h"
#include <complex>

using namespace  std;



 int Mandelbrot::GetIterations(double x, double y)
{
	complex <double> z = 0;
	complex <double> c(x, y);

	int iterations = 0;

	//we will apply algorithm involving numbers above
	//it's going to be different for each particular pixel
	//and we are going to see how many loops we have to do before number starts to shoot to infinity
	while (iterations < MAX_ITERATIONS)
	{
		z = z * z + c;//for some numbers this will never exceeed 2(these numbers is what we call a Mandelbrot set)
		if(abs(z) > 2)// some values z = z * z + c will exceed 2
		{
			break;
		}
		iterations++;
	}

	return iterations;//we gonna return a number of iterations we have to do, that could be MAX_ITERATIONS
}
