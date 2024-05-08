#include "ImagePNG.h"

void ImagePNG::paste(ImagePNG& src_image, int x0, int y0)
{
    for (int y = 0; y < src_image.getHeight(); y++) {
        for (int x = 0; x < src_image.getWidth(); x++) {
            setColor(x + x0, y + y0, src_image.getColor(x, y));
        }
    }
}