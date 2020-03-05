#pragma once
#include <cstdint>

#pragma pack(2)
/*We use pragma because we need the data in  our program's memory to correspond to the format of a bitmap file. 
This requires the data in the struct to be laid out in a particular way, with the filesize member immediately after the header member. 
By default, the compiler will lay out the data in the most efficient format and insert some padding between these two members.
if we accept this, then the bitmap files we produce will not be correct and we will either get weird images or an error when we try to view them.
The correct way to do this is to force the compiler to put each data member at an address into the struct
which is a multiple of 2 bytes from the start of the struct,
instead of the default multiple of 4 or 8 (depending on whether the system is 32-bit or 64-bit).*/

struct BitmapFileHeader
{
	//first thing we gonna need are 2 bytes containg a letters 'B' and 'M' so that the system knows is bitmap file
	char header[2]{ 'B','M' }; // that goes on the top of the file

	std::int32_t fileSize; // it must be 32 bits object of data(info will be stored on 32bits)
	std::int32_t reserved{0}; // we are not going to use it
	std::int32_t dataOffSet; // that will be set later,

};
