#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <cassert> 
#include <fstream>

using namespace std;

Bitmap::Bitmap(int width, int height) : mWidth(width), mHeight(height)
{
	mptrPixels = new uint8_t[width * height * 3]{};
	assert(mptrPixels && "Bitmap constructor: cannot allocate memeory");
}

Bitmap::~Bitmap()
{
	delete  [] mptrPixels;
}


bool Bitmap::Write(std::string fileName)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader) + mWidth * mHeight * 3;//whole file size
	fileHeader.dataOffSet = sizeof(fileHeader) + sizeof(infoHeader); // here our data starts
	infoHeader.width = mWidth;
	infoHeader.height = mHeight;

	ofstream file;
	file.open(fileName, ios::out | ios::binary);
	if (!file)
	{
		return false;
	}

	file.write((const char*)&fileHeader, sizeof(fileHeader));
	file.write((const char*)&infoHeader, sizeof(infoHeader));
	file.write((const char*)mptrPixels, mWidth * mHeight * 3);

	if (!file)
	{
		return false;
	}
	file.close();

	return true;
}

void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	auto pixel = mptrPixels;
	pixel += (y*3)* mWidth + x * 3;
	/* they are in reverse order because bitmap use little-endian format
	 Little-endian is an order in which the "little end" (least significant value in the sequence) is stored first.
	 Least significant value is represented by blue
	*/
	pixel[0] = blue;
	pixel[1] = green;
	pixel[2] = red;

}


	

