#ifndef IMAGE_PNG_H
#define IMAGE_PNG_H

#include <png.h>

#define SIG_BYTES    8
#define R_IDX        0
#define G_IDX        1
#define B_IDX        2
#define A_IDX        3


#include <vector>
#include <set>

struct Coord
{
    int x;
    int y;
};

struct Color
{
    png_byte r;
    png_byte g;
    png_byte b;
    png_byte a;
};

class ImagePNG
{
private:
    const int          pixel_size_ = 4;
    png_structp        png_ptr_;
    png_infop          info_ptr_;
    png_infop          end_info_ptr_;
    png_uint_32        width_;
    png_uint_32        height_;
    png_byte           bit_depth_;
    png_byte           color_type_;
    png_byte           interlace_type_;
    png_byte           compression_type_;
    png_byte           filter_type_;
    int                number_of_passes_;
    png_bytepp         row_pointers_;
    bool**             bit_map_;
    std::vector<Coord> colored_pixels_;

    bool checkFileValidity(FILE *fin);
    bool checkCoordsValidity(int x, int y);
    void readInfoFields();
    void transformInput();
    
    void allocateMemmoryForRowPointers();
    void freeMemmoryForRowPointers();
    void clearRowPointers();

    void allocateMemmoryForBitMap();
    void freeMemmoryForBitMap();
    void clearBitMap();

    void drawSimpleLineLow(int x0, int y0, int x1, int y1, Color color);
    void drawSimpleLineHigh(int x0, int y0, int x1, int y1, Color color);
    void drawSimpleLine(int x0, int y0, int x1, int y1, Color color);

    void drawSimpleCircle(int x0, int y0, int radius, Color color);

    void drawLineHigh(int x0, int y0, int x1, int y1, 
    unsigned int thickness, Color color);
    void drawLineLow(int x0, int y0, int x1, int y1, 
    unsigned int thickness, Color color);

public:
    ImagePNG();
    ~ImagePNG();

    void readImageFromFile(const char *input_file_name);
    void writeImageToFile(const char *output_file_name);
    void setSize(png_uint_32 new_width, png_uint_32 new_height);

    png_uint_32 getWidth();
    png_uint_32 getHeight();

    Color getColor(int x, int y);
    void setColor(int x, int y, Color color);
    void drawLine(int x0, int y0, int x1, int y1, 
        unsigned int thickness, Color color);
    

    void drawCircle(int x0, int y0, int r, unsigned int thickness,     
        Color color, bool fill, Color fill_color);


    void rgbaFilter(int parameter, png_byte value);

    void floodFill(int x, int y, Color color);
};

#endif