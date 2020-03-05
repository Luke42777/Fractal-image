#include "Bitmap.h"
#include <iostream>

using namespace std;

int main()
{
	Bitmap bmap(800, 600);
	bmap.Write("bitmap.bmp");
	cout << "Finished";
}