#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"


using namespace std;



	Bitmap::Bitmap(int width, int height) :
		mWidth(width), mHeight(height), m_pPixels(
			new uint8_t[width * height * 3]{ }) {

	}

	bool Bitmap::Write(string filename) {

		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ mWidth * mHeight * 3;
		fileHeader.dataOffSet = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = mWidth;
		infoHeader.height = mHeight;

		ofstream file;
		file.open(filename, ios::out | ios::binary);

		if (!file) {
			return false;
		}

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), mWidth * mHeight * 3);

		file.close();

		if (!file) {
			return false;
		}

		return true;
	}

	void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = m_pPixels.get();

		pPixel += (y * 3) * mWidth + (x * 3);

		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	Bitmap::~Bitmap() {
		// TODO Auto-generated destructor stub
	}

