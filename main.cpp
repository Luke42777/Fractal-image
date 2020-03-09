#include "Bitmap.h"
#include <iostream>
#include "Mandelbrot.h"
#include <cstdint>


using namespace std;



int main()
{
	int  const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bmap(WIDTH, HEIGHT); 

	double min = 999999;
	double max = -999999;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//the fractal algorithm would expect values from -1 to 1( not in the coordinate system of the bitmap
			//but it expects x and y to range from minus 1 to 1 if we want to be able to see fractal
			double xFractal = (x - WIDTH / 2) * 2.0/WIDTH ;
			double yFractal = (y - HEIGHT / 2) * 2.0/HEIGHT;

			int iterations = Mandelbrot::GetIterations(xFractal, yFractal);
			uint8_t red = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			bmap.SetPixel(x, y, red, red, red);

			if (red < min) 
			{ 
				min = red;
			}
			if (red > max) 
			{ 
				max = red; 
			}

		}
		
	}

	cout << "min: " << min << ", max: " << max << endl;
	bmap.Write("bitmap.bmp");
	cout << "Finished";
}