#include <cstdint>
#pragma pack(2)
using namespace std;
struct
{
	int32_t headerSize{ 40 };// contains how many bytes is in whole  bitmapInfoHeader struct
	int32_t width;//width of bitmap
	int32_t hight;
	int16_t planes{ 1 };
	int16_t bitsPerPixel{ 24 };// we gonna use 1 byte for each color 3 * 8 = 24
	int32_t compression{ 0 };//we are not going to use this 
	int32_t datSize{ 0 }; //that will be set later
	int32_t horizontalResolution{ 2400 };
	int32_t verticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantColors{ 0 };
};

