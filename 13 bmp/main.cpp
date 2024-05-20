#include "Image.hpp"

int main()
{
    Image im_1(0, 0, 0), im_2(0, 0, 0);

    im_1.Read("input_1.bmp");
    im_2.Read("input_2.bmp");

    im_1.Brightness(im_2, "result_1.bmp");

    im_1.Read("input_4.bmp");
    im_2.Read("input_7.bmp");

    im_1.Brightness(im_2, "result_2.bmp");

    im_1.Read("input_4.bmp");
    im_2.Read("input_5.bmp");

    im_1.Brightness(im_2, "result_3.bmp");

    return 0;
}
