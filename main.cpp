#include "Bitmap.h"
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	Bitmap bmap(WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			bmap.SetPixel(x, y, 255, 0, 0);
		}
	}
	bmap.Write("bitmap.bmp");
	cout << "Finished";
}