#include "Handler.h"
#include "Parser.h"

#include <getopt.h>
#include <map>
#include <string>
#include <set>
#include <iostream>

Handler::Handler() :
    flags_{
        {HELP_IDX,               {0, ""}},
        {INPUT_IDX,              {0, ""}},
        {OUTPUT_IDX,             {0, ""}},
        {INFO_IDX,               {0, ""}},

        {THICKNESS_IDX,          {0, ""}},
        {COLOR_IDX,              {0, ""}},
        {FILL_IDX,               {0, ""}},
        {FILL_COLOR_IDX,         {0, ""}},
        
        {CIRCLE_IDX,             {0, ""}},
        {CENTER_IDX,             {0, ""}},
        {RADIUS_IDX,             {0, ""}},
        
        {RGBFILTER_IDX,          {0, ""}},
        {COMPONENT_NAME_IDX,     {0, ""}},
        {COMPONENT_VALUE_IDX,    {0, ""}},
        
        {SPLIT_IDX,              {0, ""}},
        {NUMBER_X_IDX,           {0, ""}},
        {NUMBER_Y_IDX,           {0, ""}},
        
        {SQUARED_LINES_IDX,      {0, ""}},
        {LEFT_UP_IDX,            {0, ""}},
        {SIDE_SIZE_IDX,          {0, ""}}
    },
    short_options_("hi:o:"),
    long_options_{
        {"help",            no_argument,          NULL,    HELP_IDX},
        {"input",           required_argument,    NULL,    INPUT_IDX},
        {"output",          required_argument,    NULL,    OUTPUT_IDX},
        {"info",            no_argument,          NULL,    INFO_IDX},

        {"thickness",       required_argument,    NULL,    THICKNESS_IDX},
        {"color",           required_argument,    NULL,    COLOR_IDX},
        {"fill",            no_argument,          NULL,    FILL_IDX},
        {"fill_color",      required_argument,    NULL,    FILL_COLOR_IDX},
        
        {"circle",          no_argument,          NULL,    CIRCLE_IDX},
        {"center",          required_argument,    NULL,    CENTER_IDX},
        {"radius",          required_argument,    NULL,    RADIUS_IDX},
        
        {"rgbfilter",       no_argument,          NULL,    RGBFILTER_IDX},
        {"component_name",  required_argument,    NULL,    COMPONENT_NAME_IDX},
        {"component_value", required_argument,    NULL,    COMPONENT_VALUE_IDX},
        
        {"split",           no_argument,          NULL,    SPLIT_IDX},
        {"number_x",        required_argument,    NULL,    NUMBER_X_IDX},
        {"number_y",        required_argument,    NULL,    NUMBER_Y_IDX},
        
        {"squared_lines",   no_argument,          NULL,    SQUARED_LINES_IDX},
        {"left_up",         required_argument,    NULL,    LEFT_UP_IDX},
        {"side_size",       required_argument,    NULL,    SIDE_SIZE_IDX},
        {NULL,              0,                    NULL,    0}
    }
{}

Handler::~Handler() = default;



void Handler::getFlags(int argc, char **argv)
{    
    int option;
    while ((option = getopt_long(argc, argv, short_options_, long_options_, NULL)) != -1) {
        if (flags_.find(option) != flags_.end()) {
            flags_[option].entered = true;
            if (optarg) {
                flags_[option].parameter = optarg;
            }
        } else {
            std::cout << "WRONG FLAG!\n";
            exit(0);
        }
    }
    last_argument = argv[argc-1];
}

std::set<int> Handler::getRedundantFlags(std::set<int>& required_flags, 
    std::set<int>& optional_flags)
{
    std::set<int> redundant_flags;

    for (auto i : flags_) {
        if (required_flags.find(i.first) == required_flags.end() && 
            optional_flags.find(i.first) == optional_flags.end()) {
            redundant_flags.insert(i.first);
        }
    }

    return redundant_flags;
}

bool Handler::checkFlagCompliance(std::set<int>& required_flags, std::set<int>& redundant_flags) {
    bool all_required_entered = true;
    for (auto i : required_flags) {
        all_required_entered &= flags_[i].entered;
    }

    bool all_redundant_not_entered = true;
    for (auto i : redundant_flags) {
        all_redundant_not_entered &= !flags_[i].entered;
    }
    return all_required_entered && all_redundant_not_entered;
}

bool Handler::isHelp()
{
    std::set<int> required_flags = {};
    std::set<int> optional_flags = {HELP_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags);
}

bool Handler::isInfo()
{
    std::set<int> required_flags = {INFO_IDX};
    std::set<int> optional_flags = {INPUT_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags);
}

bool Handler::isCircle()
{
    std::set<int> required_flags = {CIRCLE_IDX, CENTER_IDX, RADIUS_IDX, THICKNESS_IDX, COLOR_IDX};
    std::set<int> optional_flags = {INPUT_IDX, OUTPUT_IDX, FILL_IDX, FILL_COLOR_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags) && (flags_[FILL_IDX].entered == flags_[FILL_COLOR_IDX].entered);
}

bool Handler::isRGBFilter()
{
    std::set<int> required_flags = {RGBFILTER_IDX, COMPONENT_NAME_IDX, COMPONENT_VALUE_IDX};
    std::set<int> optional_flags = {INPUT_IDX, OUTPUT_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags);
}

bool Handler::isSplit()
{
    std::set<int> required_flags = {SPLIT_IDX, NUMBER_X_IDX, NUMBER_Y_IDX, THICKNESS_IDX, COLOR_IDX};
    std::set<int> optional_flags = {INPUT_IDX, OUTPUT_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags);
}

bool Handler::isSquaredLines()
{
    std::set<int> required_flags = {SQUARED_LINES_IDX, LEFT_UP_IDX, SIDE_SIZE_IDX, THICKNESS_IDX, COLOR_IDX};
    std::set<int> optional_flags = {INPUT_IDX, OUTPUT_IDX, FILL_IDX, FILL_COLOR_IDX};
    std::set<int> redundant_flags = getRedundantFlags(required_flags, optional_flags);
    return checkFlagCompliance(required_flags, redundant_flags) && (flags_[FILL_IDX].entered == flags_[FILL_COLOR_IDX].entered);
}

void Handler::getFinFoutNames(std::string &input_file_name, std::string &output_file_name)
{
    if (flags_[INPUT_IDX].entered) {
        input_file_name = flags_[INPUT_IDX].parameter;
    } else {
        input_file_name = last_argument;
    }

    if (flags_[OUTPUT_IDX].entered) {
        output_file_name = flags_[OUTPUT_IDX].parameter;
    }
}

void Handler::handleFlags()
{
    if (isHelp()) {
        std::cout << "isHelp\n";
    } else if (isInfo()) {
        std::cout << "isInfo\n";
    } else if (isCircle()) {
        CircleFunc();
    } else if (isRGBFilter()) {
        RGBFilterFunc();
    } else if (isSplit()) {
        SplitFunc();
    } else if (isSquaredLines()) {
        SquaredLinesFunc();
    } else {
        std::cout << "flags bruh\n";
    }
}

void Handler::CircleFunc()
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

void Handler::RGBFilterFunc()
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

void Handler::SplitFunc()
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

void Handler::SquaredLinesFunc()
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

    image_png.drawRectangle(left, up, left+side_size, up+side_size, thickness, color, fill, fill_color);

    image_png.drawLine(left, up, left+side_size, up+side_size, thickness, color);
    image_png.drawLine(left+side_size, up, left, up+side_size, thickness, color);

    image_png.writeImageToFile(output_file_name.c_str());

}