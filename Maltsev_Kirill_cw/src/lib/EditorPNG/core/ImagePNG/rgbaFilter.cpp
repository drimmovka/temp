#include "ImagePNG.h"

void ImagePNG::rgbaFilter(int component_idx, int component_value)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {            
            row_pointers_[y][x * pixel_size_ + component_idx] = component_value;
        }
    }
}