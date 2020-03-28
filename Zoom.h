#pragma once
struct Zoom
{
public:
	int mX{ 0 }; //coordinates of pixel we want to zoom
	int mY{ 0 };

	double mScale{ 0.0 };
	Zoom(int x, int y, double scale) : mX(x), mY(y), mScale(scale) {};

};

