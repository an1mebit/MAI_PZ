#include "parser.h"

using namespace std;

class Image
{

public:
    FILE* pFile;
    int width, height;
    int* collors;

	Image(FILE* pFile)
	{
		BITMAPINFOHEADER bit;
		bit.biWidth = read_u32(pFile);
		bit.biHeight = read_u32(pFile);

		width = bit.biWidth;
		height = bit.biHeight;

        RGBQUAD** rgb = new RGBQUAD * [width];
        for (int i = 0; i < width; i++) {
            rgb[i] = new RGBQUAD[height];
        }

        uint32_t** colors = new uint32_t * [height*width];
        for (int i = 0; i < width; i++) {
            colors[i] = new uint32_t[height];
        }

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                rgb[i][j].rgbBlue = getc(pFile);
                rgb[i][j].rgbGreen = getc(pFile);
                rgb[i][j].rgbRed = getc(pFile);
                colors[i][j] = rgb[i][j].rgbBlue + (rgb[i][j].rgbGreen << 8) + (rgb[i][j].rgbRed << 16);
            }

            getc(pFile);
        }
        
	}

    ~Image()
    {
        delete[] collors;
        fclose(pFile);
    }
};

double operator+(Image& img1, Image& img2)
{
    unsigned int sq = 0;
    for (int i = 0; i < img1.width * img1.height; i++)
    {
        sq += (img1.collors[i] - img2.collors[i]) * (img1.collors[i] - img2.collors[i]);
    }
    return sqrt(sqrt(sq));
}

int main()
{
    FILE* f1 = fopen("apple_1.bmp", "rb");
    FILE* f2 = fopen("apple_2.bmp", "rb");
    FILE* f3 = fopen("apple_3.bmp", "rb");
    FILE* f4 = fopen("apple_4.bmp", "rb");
    Image img1(f1), img2(f2), img3(f3), img4(f4);

    cout << "Image 1 + Image2: " << img1 + img2 << endl;
    cout << "Image 1 + Image3: " << img1 + img3 << endl; //The best result!!!!!!
    cout << "Image 1 + Image4: " << img1 + img4 << endl;

    cout << "Image 2 + Image3: " << img2 + img3 << endl;
    cout << "Image 2 + Image4: " << img2 + img4 << endl;

    cout << "Image 3 + Image4: " << img3 + img4 << endl;

}
