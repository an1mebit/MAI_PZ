#include "parser.h"

using namespace std;

class Image
{

public:
    FILE* pFile;
    int width, height;
    uint32_t** colors;
    RGBQUAD** rgb;

	Image(const char* hentai)
	{
        pFile = fopen(hentai, "rb");

        BITMAPFILEHEADER header;

        header.bfType = read_u16(pFile);
        header.bfSize = read_u32(pFile);
        header.bfReserved1 = read_u16(pFile);
        header.bfReserved2 = read_u16(pFile);
        header.bfOffBits = read_u32(pFile);

        BITMAPINFOHEADER bmiHeader;

        bmiHeader.biSize = read_u32(pFile);
        bmiHeader.biWidth = read_s32(pFile);
        bmiHeader.biHeight = read_s32(pFile);
        bmiHeader.biPlanes = read_u16(pFile);
        bmiHeader.biBitCount = read_u16(pFile);
        bmiHeader.biCompression = read_u32(pFile);
        bmiHeader.biSizeImage = read_u32(pFile);
        bmiHeader.biXPelsPerMeter = read_s32(pFile);
        bmiHeader.biYPelsPerMeter = read_s32(pFile);
        bmiHeader.biClrUsed = read_u32(pFile);
        bmiHeader.biClrImportant = read_u32(pFile);
            
	width = bmiHeader.biWidth;
	height = bmiHeader.biHeight;



        rgb = new RGBQUAD * [width];
        for (int i = 0; i < width; i++) {
            rgb[i] = new RGBQUAD[height];
        }

        colors = new uint32_t * [width];
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

        }
        fclose(pFile);

	}

    ~Image()
    {
        delete[] colors;
        delete[] rgb;
    }
};

double operator+(Image& img1, Image& img2)
{
    unsigned int sq = 0;
    for (int i = 0; i < img1.width; i++)
    {
        for (int j = 0; j < img1.height; j++)
            sq += (img1.colors[i][j] - img2.colors[i][j]) * (img1.colors[i][j] - img2.colors[i][j]);
    }
    return sqrt(sqrt(sq));
}

static unsigned short read_u16(FILE* fp)
{
    unsigned char b0, b1;

    b0 = getc(fp);
    b1 = getc(fp);

    return ((b1 << 8) | b0);
}

static unsigned int read_u32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}

static int read_s32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((int)(((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}

int main()
{
    /*
    Image img1("D:/projects/Proga-pz-6/Proga-pz-6/apples/apple_1.bmp"),
          img2("D:/projects/Proga-pz-6/Proga-pz-6/apples/apple_2.bmp"),
          img3("D:/projects/Proga-pz-6/Proga-pz-6/apples/apple_3.bmp"), 
          img4("D:/projects/Proga-pz-6/Proga-pz-6/apples/apple_4.bmp");
    */
	
    Image img1("D:/projects/Proga-pz-6/Proga-pz-6/bmp_sailor_moon/sailor_1.bmp"),
          img2("D:/projects/Proga-pz-6/Proga-pz-6/bmp_sailor_moon/sailor_2.bmp"),
          img3("D:/projects/Proga-pz-6/Proga-pz-6/bmp_sailor_moon/sailor_3.bmp"), 
          img4("D:/projects/Proga-pz-6/Proga-pz-6/bmp_sailor_moon/sailor_4.bmp");

    cout <<"Image1 + Image1:" << img1 + img1 << endl;
    cout << "Image2 + Image2:" << img2 + img2 << endl;
    cout << "Image3 + Image3:" << img3 + img3 << endl;
    cout << "Image4 + Image4:" << img4 + img4 << endl;

    cout << "Image 1 + Image2: " << img1 + img2 << endl;
    cout << "Image 1 + Image3: " << img1 + img3 << endl;
    cout << "Image 1 + Image4: " << img1 + img4 << endl;

    cout << "Image 2 + Image3: " << img2 + img3 << endl;
    cout << "Image 2 + Image4: " << img2 + img4 << endl;

    cout << "Image 3 + Image4: " << img3 + img4 << endl;
    cout << "Image 4 + Image3: " << img4 + img3 << endl;

}
