#pragma once
#include "Zoom.h"
#include "vector"
#include "utility" // for pair
class ZoomList
{
public:
	ZoomList(int width, int height);
	void Add(const Zoom&);

	//we need a method to map bitmap coordinates to actual fractal coordinates
	std::pair<double, double> 	DoZoom(int x, int y);
	


private:
	int mWidth{ 0 };
	int mHeight{ 0 };
	std::vector<Zoom> mZooms;

};

