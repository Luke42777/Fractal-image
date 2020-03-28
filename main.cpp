#include <iostream>
#include <memory>
#include <math.h> 
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"


using namespace std;



int main()
{
	int  const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]);
	unique_ptr<int[]> ptr_fractal(new int[WIDTH * HEIGHT]);//this array will store informations about how many iterations has every single pixel

	// fill arrays with 0
	fill(histogram.get(), histogram.get() + Mandelbrot::MAX_ITERATIONS, 0);
	fill(ptr_fractal.get(), ptr_fractal.get() + WIDTH * HEIGHT, 0);


	for (int y = 0; y < HEIGHT; y++) //this first nested loop simply store information we need
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//the fractal algorithm would expect values from -1 to 1( not in the coordinate system of the bitmap
			//but it expects x and y to range from minus 1 to 1 if we want to be able to see fractal
			double xFractal = (x - WIDTH / 2 - 200) / (HEIGHT / 2.0) ;
			double yFractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

			int iterations = Mandelbrot::GetIterations(xFractal, yFractal);
			ptr_fractal[y * WIDTH + x] = iterations;
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}

			
		}	
	}
	int total = 0; // to improve image we need to have total number of iterations
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++)//this second nested loop simply draw fractal
	{
		for (int x = 0; x < WIDTH; x++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = ptr_fractal[y * WIDTH + x];
			
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0; // this should be between zero and 1

					for (int i = 0; i <= iterations; i++)
					{
						hue += ((double)histogram[i]) / total;
					}

				 green = pow(255, hue);

			}

			bmap.SetPixel(x, y, red, green, blue);

		}
	}
	
	bmap.Write("bitmap.bmp");
	cout << "Finished";
	
}