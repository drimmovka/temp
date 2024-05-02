#include "ImagePNG.h"

ImagePNG::ImagePNG()
{
    png_ptr_            = NULL;
    info_ptr_           = NULL;
    end_info_ptr_       = NULL;
    width_              = 0;
    height_             = 0;
    bit_depth_          = 8;
    color_type_         = PNG_COLOR_TYPE_RGBA;
    interlace_type_     = PNG_INTERLACE_NONE;
    compression_type_   = PNG_COMPRESSION_TYPE_DEFAULT;
    filter_type_        = PNG_FILTER_TYPE_DEFAULT;
    number_of_passes_   = 0;
    row_pointers_       = NULL;
    bit_map_            = NULL;
}

ImagePNG::~ImagePNG() = default;