#include "Bitmap.h"
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	Bitmap bmap(WIDTH, HEIGHT);
	bmap.FillScreen(WIDTH, HEIGHT, 0, 0, 255);
	bmap.Write("bitmap.bmp");
	cout << "Finished";
}