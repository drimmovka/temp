#include "EditorPNG.h"
#include "Output.h"
#include "Handler.h"

// #include <png.h>

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    Output::show_info_author("5.17", "Kirill", "Maltsev");

    // Handler::handleFlags(argc, argv);
    
    ImagePNG image_png;
    // image_png.readImageFromFile("test/13.png");
    image_png.setSize(500, 500);
    image_png.drawLine(100, 300, 250, 100, 10, {255, 0, 0, 255});

    // int l = 40;
    // double fi = 0;
    // for (int k = 0; k < 20; k++) {
    //     image_png.drawLine(50, 50, 50 + (int) l*cos(fi), 50 + (int) l*sin(fi), {255, 255, 255, 255});
    //     image_png.drawLine(50 + (int) l*cos(fi), 50 + (int) l*sin(fi), 50, 50, {255, 255, 255, 255});

    //     fi += M_PI/10;
    // }
    
    image_png.drawLine(300, 300, 300, 350, 1, {255, 0, 0, 255});
    image_png.setColor(300, 300, {255, 255, 255, 255});
    // image_png.drawLine(300, 300, 350, 300);
    // image_png.drawLine(350, 350, 300, 350);
    // image_png.drawLine(350, 350, 350, 300);

    // image_png.drawLine(300, 300, 325, 275);
    // image_png.drawLine(325, 275, 350, 300);


    // image_png.drawCircle(250, 250, 0);
    // for (int r = 20; r<200; r+=10) {
        // image_png.drawCircle(250, 250, r, {0, 0, 255, 255});
    // }


    // image_png.floodFill(250, 250, {0, 255, 0, 255});
    // image_png.floodFill(271, 250, {0, 255, 0, 255});
    // image_png.setColor(271, 250, {255, 0, 0, 255});

    // image_png.drawCircle(250, 250, 40, 50, {255, 0, 0, 255}, true, {0, 255, 0, 255});

    image_png.drawCircle(250, 250, 50, 10, {255, 0, 0, 255}, true, {0, 255, 0, 255});

    // Color color = {128, 0, 0, 255};
    // for (int r = 1; r < 100; r+=10) {

    //     image_png.drawCircle(250, 250, r, 4, color, false, {0, 255, 0, 255});
    //     color.g += 10;
    // }

    // image_png.setSize(500, 500);


    image_png.writeImageToFile("output.png");


    return 0;
}