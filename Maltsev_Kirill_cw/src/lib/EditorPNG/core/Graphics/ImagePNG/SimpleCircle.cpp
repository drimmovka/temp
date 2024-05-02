#include "ImagePNG.h"

void ImagePNG::drawSimpleCircle(int x0, int y0, int radius, Color color)
{
    int D = 3 - 2 * radius;
    int x = 0;
    int y = radius;
    while (x <= y) {
        setColor(x+x0, y+y0, color);
        setColor(y+x0, x+y0, color);
        setColor(-y+x0, x+y0, color);
        setColor(-x+x0, y+y0, color);
        setColor(-x+x0, -y+y0, color);
        setColor(-y+x0, -x+y0, color);
        setColor(y+x0, -x+y0, color);
        setColor(x+x0, -y+y0, color);

        if (D < 0) {
            D += 4 * x + 6;
            x++;
        } else {
            D += 4 * (x - y) + 10;
            x++;
            y--;
        }
    }
}