#include "ImagePNG.h"

void ImagePNG::rgbaFilter(int parameter, png_byte value)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            row_pointers_[y][x * pixel_size_ + parameter] = value;
        }
    }
}