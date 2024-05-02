#include "ImagePNG.h"

#include <stdlib.h>

void ImagePNG::allocateMemmoryForBitMap()
{
    bit_map_ = (bool**) malloc(sizeof(bool*) * height_);
    for (int y = 0; y < height_; y++) {
        bit_map_[y] = (bool*) malloc(sizeof(bool) * width_);
    }
}

void ImagePNG::freeMemmoryForBitMap()
{
    for (int y = 0; y < height_; y++) {
        free(bit_map_[y]);
    }
    free(bit_map_);
    colored_pixels_.clear();
}


void ImagePNG::clearBitMap()
{
    for (int i = 0; i < colored_pixels_.size(); i++) {
        bit_map_[colored_pixels_[i].y][colored_pixels_[i].x] = false;
    }
    colored_pixels_.clear();
}