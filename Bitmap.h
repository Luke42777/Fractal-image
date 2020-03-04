#pragma once
class Bitmap
{
public:
	Bitmap(int width, int height);
	bool write(); // after creating bitmap we want to write it



private:
	int mWidth{ 0 };
	int mHeight{ 0 };

};

