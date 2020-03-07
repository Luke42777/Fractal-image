#include "Mandelbrot.h"
#include <complex>

using namespace  std;

extern const int WIDTH;
extern const int HEIGHT;

 int Mandelbrot::GetIterations(int x, int y)
{
	complex <double> z = 0;
	complex <double> c(x, y);

	int iterations = 0;

	//we will apply algorithm involving numbers above
	//it's going to be different for each particular pixel
	//and we are going to see how many loops we have to do before number starts to shoot to infinity
	while (iterations < MAX_ITERATIONS)
	{
		z = z * z + c;
		//there is also a notion of abolute value of complex numbers or (magnitude)
		if (abs(z) > 2)
		{
			break;
		}
	}

	return 0;
}
