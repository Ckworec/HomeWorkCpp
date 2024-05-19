#include "Image.hpp"

int main()
{
    const int width = 640;
    const int height = 480;
    int brightness_1, brightness_2, brightness;

    Image image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image.SetColor(Color((float)x / (float)width, 1.0f - (float)x / (float)width, (float)y / (float)height), x, y);
        }
    }

    image.Export("output.bmp");

    Image im_1(0, 0), im_2(0, 0);

    im_1.Read("input_4.bmp");
    im_2.Read("input_5.bmp");

    im_1.Brightness(im_2, "result_1.bmp");

    return 0;
}