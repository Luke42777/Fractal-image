#include "Bitmap.h"

Bitmap::Bitmap(int width, int height) : mWidth(width), mHeight(height), mptrPixels(new uint8_t[width * height * 3]){}

bool Bitmap::Write(std::string fileName)
{

	return true;

}

void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{


}
