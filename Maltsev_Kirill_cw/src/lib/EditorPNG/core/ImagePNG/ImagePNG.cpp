#include "ImagePNG.h"

ImagePNG::ImagePNG() :
    pixel_size_         (4),
    png_ptr_            (NULL),
    info_ptr_           (NULL),
    end_info_ptr_       (NULL),
    width_              (0),
    height_             (0),
    bit_depth_          (8),
    color_type_         (PNG_COLOR_TYPE_RGBA),
    interlace_type_     (PNG_INTERLACE_NONE),
    compression_type_   (PNG_COMPRESSION_TYPE_DEFAULT),
    filter_type_        (PNG_FILTER_TYPE_DEFAULT),
    number_of_passes_   (0),
    row_pointers_       (NULL)
{}

ImagePNG::~ImagePNG() = default;

void ImagePNG::setSize(png_uint_32 new_width, png_uint_32 new_height)
{
    width_ = new_width;
    height_ = new_height;
    allocateMemmoryForRowPointers();
    clearRowPointers();
}


png_uint_32 ImagePNG::getWidth()
{
    return width_;
}

png_uint_32 ImagePNG::getHeight()
{
    return height_;
}