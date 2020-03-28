#pragma once
struct Zoom
{
public:
	int x{ 0 }; //coordinates of pixel we want to zoom
	int y{ 0 };

	double scale{ 0.0 };
	Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};

};

