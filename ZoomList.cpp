#include "ZoomList.h"


ZoomList::ZoomList(int width, int height) : mWidth(width), mHeight(height) {}

void ZoomList::Add(const Zoom& z)
{
	mZooms.push_back(z);
}

std::pair<double, double> 	ZoomList::DoZoom(int x, int y)
{

	return std::pair<double, double>{0, 0};
}

