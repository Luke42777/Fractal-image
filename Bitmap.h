#pragma once
#include <string>
#include <cstdint>
class Bitmap
{
public:
	Bitmap(int width, int height);
	bool Write(std::string fileName); // after creating bitmap we want to write it
	void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);



private:
	int mWidth{ 0 };
	int mHeight{ 0 };

};

