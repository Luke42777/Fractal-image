#include <cstdint>
#pragma pack(2)

struct BitmapInfoHeader
{
	std::int32_t headerSize{ 40 };// contains how many bytes is in whole  bitmapInfoHeader struct
	std::int32_t width;//width of bitmap
	std::int32_t hight;
	std::int16_t planes{ 1 };
	std::int16_t bitsPerPixel{ 24 };// we gonna use 1 byte for each color 3 * 8 = 24
	std::int32_t compression{ 0 };//we are not going to use this 
	std::int32_t datSize{ 0 }; //that will be set later
	std::int32_t horizontalResolution{ 2400 };
	std::int32_t verticalResolution{ 2400 };
	std::int32_t colors{ 0 };
	std::int32_t importantColors{ 0 };
};

