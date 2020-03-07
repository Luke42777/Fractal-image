#include "Bitmap.h"
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	Bitmap bmap(WIDTH, HEIGHT); 

	double min = 999999;
	double max = -999999;
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			//the fractal algorithm would expect values from -1 to 1( not in the coordinate system of the bitmap
			//but it expects x and y to range from minus 1 to 1 if we want to be able to see fractal
			double xFractal = (x - WIDTH / 2.0) / (WIDTH / 2.0);
			double yFractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

			if (xFractal < min) { min = xFractal; }
			//whenever we encounter a value of 'xFractal' to be less then current value
			//we will set 'min' equal to that value
			//and 'min' will end up being equal to the most minimum value of 'xFractal' that we encountered
			if (xFractal > max) { max = xFractal; }

			if (yFractal < min) { min = yFractal; }
			if (yFractal > max) { max = yFractal; }
		}
		
	}

	cout << "min: " << min << ", max: " << max << endl;
	bmap.Write("bitmap.bmp");
	cout << "Finished";
}