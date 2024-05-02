#include "ImagePNG.h"

void ImagePNG::drawCircle(int x0, int y0, int radius, unsigned int thickness, 
    Color color, bool fill, Color fill_color)
{
    clearBitMap();
    drawSimpleCircle(x0, y0, radius-thickness/2, color);
    drawSimpleCircle(x0, y0, radius+thickness/2, color);


    for (int y = y0-radius-thickness/2; y <= y0-radius+thickness/2; y++) {
        setColor(x0, y, color);
    }
    for (int y = y0+radius-thickness/2; y <= y0+radius+thickness/2; y++) {
        setColor(x0, y, color);
    }

    // add checking for getting away from bit_map_
    // idea 1: bit_map_ class + overload [][] (isColored or getPixel) <-- mb better
    // idea 2: check func ???
    for (int y = y0-radius-thickness/2; y <= y0+radius+thickness/2; y++) {
        
        std::pair<int, int> borders1 = {x0-radius-thickness/2, x0};
        while (borders1.first <= x0+radius+thickness/2) {
            if (bit_map_[y][borders1.first]) { 
                break;
            }
            borders1.first++;
        }
        while (borders1.second >= x0-radius-thickness/2) {
            if (bit_map_[y][borders1.second]) { 
                break;
            }
            borders1.second--;
        }

        std::pair<int, int> borders2 = {x0, x0+radius+thickness/2};
        while (borders2.first <= x0+radius+thickness/2) {
            if (bit_map_[y][borders2.first]) { 
                break;
            }
            borders2.first++;
        }
        while (borders2.second >= x0-radius-thickness/2) {
            if (bit_map_[y][borders2.second]) { 
                break;
            }
            borders2.second--;
        }

        for (int x = borders1.first; x <= borders1.second; x++) {
            setColor(x, y, color);
        }
        for (int x = borders2.second; x >= borders2.first; x--) {
            setColor(x, y, color);
        }

    }

    if (fill) {
        floodFill(x0, y0, fill_color);
    }

}