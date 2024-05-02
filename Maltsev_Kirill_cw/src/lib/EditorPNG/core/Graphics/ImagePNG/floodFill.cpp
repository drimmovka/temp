#include "ImagePNG.h"

void ImagePNG::floodFill(int x, int y, Color color)
{
    if (!checkCoordsValidity(x, y)) {
        return;
    }
    if (bit_map_[y][x]) {
        return;
    }
    setColor(x, y, color);
    floodFill(x + 1, y, color);
    floodFill(x - 1, y, color);
    floodFill(x, y + 1, color);
    floodFill(x, y - 1, color);
}