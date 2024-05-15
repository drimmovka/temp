#include "ImagePNG.h"

#include <stdlib.h>


void epng::ImagePNG::allocateMemmoryForColoredPixels()
{
    colored_pixels_ = (bool**) malloc(sizeof(bool*) * height_);
    for (int y = 0; y < height_; y++) {
        colored_pixels_[y] = (bool*) malloc(sizeof(bool) * width_);
    }
}

void epng::ImagePNG::freeMemmoryForColoredPixels()
{
    for (int y = 0; y < height_; y++) {
        free(colored_pixels_[y]);
    }
    free(colored_pixels_);
}

void epng::ImagePNG::clearColoredPixels()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            colored_pixels_[y][x] = false;
        }
    }
}