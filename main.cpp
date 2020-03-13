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

	int* histogram = new int[Mandelbrot::MAX_ITERATIONS]{};
	//this will be our color histogram
	//we need to know how many times certain iterations occours
	//at the beginning is set to Zero

	int* ptr_Fractal = new int[HEIGHT*WIDTH]{};//this array will store informations about how many iterations has every single pixel

	for (int y = 0; y < HEIGHT; y++) //this first nested loop simply store information we need
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//the fractal algorithm would expect values from -1 to 1( not in the coordinate system of the bitmap
			//but it expects x and y to range from minus 1 to 1 if we want to be able to see fractal
			double xFractal = (x - WIDTH / 2 - 150) / (HEIGHT / 2.0) ;
			double yFractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

			int iterations = Mandelbrot::GetIterations(xFractal, yFractal);
			if (iterations < Mandelbrot::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}

			ptr_Fractal[y*WIDTH +x] = iterations;	
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
			int iterations = ptr_Fractal[y * WIDTH + x];
	
			double hue = 0.0; // this should be between zero and 1

			for (int i = 0; i <= iterations; i++)
			{
				hue += ((double)histogram[i]) / total;
			}

			uint8_t red = 0;
			uint8_t green = hue * 255;
			uint8_t blue = 0;


			bmap.SetPixel(x, y, red, green, blue);

		}
	}
	
	bmap.Write("bitmap.bmp");
	cout << "Finished";
	delete[] histogram;
}