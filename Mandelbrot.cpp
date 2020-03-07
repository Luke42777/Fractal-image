#include "Mandelbrot.h"
extern const int WIDTH;
extern const int HEIGHT;

static int GetIterations(int x, int y)
{
	double min = 999999;
	double max = -999999;
	double Fractal = 0;
	(x - WIDTH / 2.0) / (WIDTH / 2.0);
	double Fractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

	if (Fractal < min) { min = Fractal; }
	//whenever we encounter a value of 'xFractal' to be less then current value
	//we will set 'min' equal to that value
	//and 'min' will end up being equal to the most minimum value of 'xFractal' that we encountered
	if (Fractal > max) { max = Fractal; }
	return 0;
}
