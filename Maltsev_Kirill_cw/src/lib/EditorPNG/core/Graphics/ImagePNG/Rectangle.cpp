#include "ImagePNG.h"

#include <algorithm>

void ImagePNG::drawRectangle(int x0, int y0, int x1, int y1, 
    int thickness, Color color, bool fill, Color fill_color)
{
    if (x0 >= x1) {
        std::swap(x0, x1);
    }

    if (y0 >= y1) {
        std::swap(y0, y1);
    }
    
    if (fill) {
        for (int y = y0+1; y <= y1; y++) {
            for (int x = x0+1; x <= x1; x++) {
                setColor(x, y, fill_color);
            }
        }
    }

    drawLine(x0, y0, x1, y0, thickness, color);
    drawLine(x0, y0, x0, y1, thickness, color);
    drawLine(x0, y1, x1, y1, thickness, color);
    drawLine(x1, y0, x1, y1, thickness, color);
}