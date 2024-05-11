#ifndef IMAGE_PNG_H
#define IMAGE_PNG_H

#include "Structures.h"

#include <png.h>
#include <vector>

#define SIG_BYTES                 8
#define TURN_180                  0
#define TURN_90_CLOCKWISE         1
#define TURN_90_COUNTERCLOCKWISE  2
#define VERTICAL                  0
#define HORIZONTAL                1
#define FILE_ERROR                40
#define PNG_PROCESSING_ERROR      41


namespace epng
{

void throwError(const char *error_massage, int exit_code);
bool checkFileValidity(FILE *fin);

void showImageInfo(const char *input_file_name);

class ImagePNG
{
private:
    const int     pixel_size_;
    png_structp   png_ptr_;
    png_infop     info_ptr_;
    png_infop     end_info_ptr_;
    int           width_;
    int           height_;
    png_byte      bit_depth_;
    png_byte      color_type_;
    png_byte      interlace_type_;
    png_byte      compression_type_;
    png_byte      filter_type_;
    int           number_of_passes_;
    png_bytepp    row_pointers_;
    bool          **colored_pixels_;

    void allocateMemmoryForRowPointers();
    void freeMemmoryForRowPointers();
    void clearRowPointers();

    void allocateMemmoryForColoredPixels();
    void freeMemmoryForColoredPixels();
    void clearColoredPixels();

    void readInfoFields();
    void transformInput();

    bool checkCoordsValidity(int x, int y);
    bool isColored(int x, int y);
    

    void drawBresenhamLineLow(int x0, int y0, int x1, int y1, Color color);
    void drawBresenhamLineHigh(int x0, int y0, int x1, int y1, Color color);
    void drawLineHigh(int x0, int y0, int x1, int y1, 
        int thickness, Color color);
    void drawLineLow(int x0, int y0, int x1, int y1, 
        int thickness, Color color);
    


    void fillPolygon(std::vector<Coord>& vertices, Color& fill_color);
    
    void floodFill(int x, int y, Color color);

public:
    ImagePNG();
    ~ImagePNG();

    int getWidth();
    int getHeight();

    void readImageFromFile(const char *input_file_name);
    void writeImageToFile(const char *output_file_name);

    void setSize(int width, int height);
    void resize(int new_width, int new_height, int x0, int y0);
    ImagePNG copy(int x0, int y0, int x1, int y1);
    void paste(ImagePNG& src_image, int x0, int y0);
    void rotate(int rotation_type);
    void reflect(int reflection_type);

    
    void clear();
    Color getColor(int x, int y);
    void setColor(int x, int y, Color color);

    void drawBresenhamLine(int x0, int y0, int x1, int y1, Color color);

    void drawLine(int x0, int y0, int x1, int y1, 
        int thickness, Color color);

    void drawBresenhamCircle(int x0, int y0, int radius, Color color);

    void drawCircle(int x0, int y0, int radius, int thickness, 
        Color color, bool fill, Color fill_color);

    void drawPolygon(std::vector<Coord> coords, int thickness, 
        Color color, bool fill, Color fill_color);
    bool inPolygon(int x, int y, std::vector<Coord>& vertices);
    

    void colorReplace(Color old_color, Color new_color);
    void rgbaFilter(int component_idx, int component_value);
    void inverseColors();
    void grayColors();

    void fill(int x, int y, Color color);
};

}
#endif