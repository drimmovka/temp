#include "ImagePNG.h"

#include <stdlib.h>


void epng::ImagePNG::allocateMemmoryForRowPointers()
{
    row_pointers_ = (png_bytepp) malloc(sizeof(png_bytep) * height_);
    for (int y = 0; y < height_; y++) {
        row_pointers_[y] = (png_bytep) malloc(sizeof(png_byte) * pixel_size_ * width_);
    }
}

void epng::ImagePNG::freeMemmoryForRowPointers()
{
    for (int y = 0; y < height_; y++) {
        free(row_pointers_[y]);
    }
    free(row_pointers_);
    
}

void epng::ImagePNG::clearRowPointers()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            row_pointers_[y][x * pixel_size_ + R_IDX] = 0;
            row_pointers_[y][x * pixel_size_ + B_IDX] = 0;
            row_pointers_[y][x * pixel_size_ + G_IDX] = 0;
            row_pointers_[y][x * pixel_size_ + A_IDX] = 0;
        }
    }
}