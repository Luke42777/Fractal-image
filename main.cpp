#include "Bitmap.h"
#include <iostream>
#include "Mandelbrot.h"
#include <cstdint>
#include <memory>


using namespace std;



int main()
{
	int  const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bmap(WIDTH, HEIGHT); 

	double min = 999999;
	double max = -999999;

	int* histogram = new int[Mandelbrot::MAX_ITERATIONS + 1]{};
	//this will be our color histogram
	//we need to know how many times certain iterations occours
	//at the beginning is set to Zero
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//the fractal algorithm would expect values from -1 to 1( not in the coordinate system of the bitmap
			//but it expects x and y to range from minus 1 to 1 if we want to be able to see fractal
			double xFractal = (x - WIDTH / 2 - 150) / (HEIGHT / 2.0) ;
			double yFractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

			int iterations = Mandelbrot::GetIterations(xFractal, yFractal);
			histogram[iterations]++;
			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
			color = color * color * color;

			bmap.SetPixel(x, y, 0, color, 0);

			if (color < min) 
			{ 
				min = color;
			}
			if (color > max) 
			{ 
				max = color; 
			}

		}
		
	}

	cout << "min: " << min << ", max: " << max << endl;
	bmap.Write("bitmap.bmp");
	cout << "Finished";
	delete[] histogram;
}