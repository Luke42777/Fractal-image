#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height) : mWidth(width), mHeight(height), mptrPixels(new uint8_t[width * height * 3]{}) {}

bool Bitmap::Write(std::string fileName)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader) + mWidth * mHeight * 3;//whole file size
	fileHeader.dataOffSet = sizeof(fileHeader) + sizeof(infoHeader); // here our data starts
	infoHeader.width = mWidth;
	infoHeader.height = mHeight;

	return true;

}

void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{


}
