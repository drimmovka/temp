#include "Handler.h"
#include "Parser.h"
#include "EditorPNG.h"


void Handler::doCircle()
{
    int x0, y0, radius, thickness;
    bool fill;
    Color color, fill_color;
    std::string input_file_name;
    std::string output_file_name = "output.png";

    parseCoords(x0, y0, flags_[CENTER_IDX].parameter);
    parseNumber(radius, flags_[RADIUS_IDX].parameter);
    parseNumber(thickness, flags_[THICKNESS_IDX].parameter);
    parseColor(color, flags_[COLOR_IDX].parameter);
    fill = flags_[FILL_IDX].entered;
    if (fill) {
        parseColor(fill_color, flags_[FILL_COLOR_IDX].parameter);
    }
    getFinFoutNames(input_file_name, output_file_name);
    

    checkRadiusValidity(radius);
    checkThicknessValidity(thickness);

    ImagePNG image_png;
    image_png.readImageFromFile(input_file_name.c_str());
    image_png.drawCircle(x0, y0, radius, thickness, color, fill, fill_color);
    image_png.writeImageToFile(output_file_name.c_str());
}

void Handler::doRGBFilter()
{
    int component_idx, component_value;
    std::string input_file_name;
    std::string output_file_name = "output.png";

    parseComponentName(component_idx, flags_[COMPONENT_NAME_IDX].parameter);
    parseNumber(component_value, flags_[COMPONENT_VALUE_IDX].parameter);
    getFinFoutNames(input_file_name, output_file_name);

    checkComponentValueValidity(component_value);
    
    ImagePNG image_png;
    image_png.readImageFromFile(input_file_name.c_str());
    image_png.rgbaFilter(component_idx, component_value);
    image_png.writeImageToFile(output_file_name.c_str());
}

void Handler::doSplit()
{
    int number_x, number_y, thickness;
    Color color;
    std::string input_file_name;
    std::string output_file_name = "output.png";
    
    parseNumber(number_x, flags_[NUMBER_X_IDX].parameter);
    parseNumber(number_y, flags_[NUMBER_Y_IDX].parameter);
    parseNumber(thickness, flags_[THICKNESS_IDX].parameter);
    parseColor(color, flags_[COLOR_IDX].parameter);
    getFinFoutNames(input_file_name, output_file_name);

    checkNumberXValidity(number_x);
    checkNumberYValidity(number_y);
    checkThicknessValidity(thickness);

    ImagePNG image_png;
    image_png.readImageFromFile(input_file_name.c_str());

    for (int y = image_png.getHeight() / number_y; y < image_png.getHeight(); y += image_png.getHeight() / number_y) {
        image_png.drawLine(0, y, image_png.getWidth(), y, thickness, color);
    }
    for (int x = image_png.getWidth() / number_x; x < image_png.getWidth(); x += image_png.getWidth() / number_x) {
        image_png.drawLine(x, 0, x, image_png.getHeight(), thickness, color);
    }

    image_png.writeImageToFile(output_file_name.c_str());
}

void Handler::doSquaredLines()
{
    int left, up, side_size, thickness;
    bool fill;
    Color color, fill_color;

    std::string input_file_name;
    std::string output_file_name = "output.png";

    parseCoords(left, up, flags_[LEFT_UP_IDX].parameter);
    parseNumber(side_size, flags_[SIDE_SIZE_IDX].parameter);
    parseNumber(thickness, flags_[THICKNESS_IDX].parameter);
    parseColor(color, flags_[COLOR_IDX].parameter);
    fill = flags_[FILL_IDX].entered;
    if (fill) {
        parseColor(fill_color, flags_[FILL_COLOR_IDX].parameter);
    }
    getFinFoutNames(input_file_name, output_file_name);

    checkSideSizeValidity(side_size);
    checkThicknessValidity(thickness);


    ImagePNG image_png;
    image_png.readImageFromFile(input_file_name.c_str());

    image_png.drawPolygon(
        {
            {left, up},
            {left+side_size, up},
            {left+side_size, up+side_size},
            {left, up+side_size},
        },
        thickness, color, fill, fill_color);

    image_png.drawLine(left, up, left+side_size, up+side_size, thickness, color);
    image_png.drawLine(left+side_size, up, left, up+side_size, thickness, color);

    image_png.writeImageToFile(output_file_name.c_str());

}