#include "Output.h"

#include <stdio.h>

Output::Output() = default;

Output::~Output() = default;

void Output::show_author_info(const char *option, const char *name, const char *surname)
{
    printf("Course work for option %s, created by %s %s\n", option, name, surname);
}

void Output::help()
{
    printf("--help (-h)            Prints the help\n");
    printf("--input (-i)           Sets the name of the input image. If the flag is omitted, it is assumed that the name of the input image is passed as the last argument\n");
    printf("--output (-o)          Sets the name of the output image. If the flag is omitted, it is assumed that the name of the input image is out.png\n");
    printf("--info                 Prints information about the image\n");
    printf("\n");

    printf("Basic flags:\n");
    printf("--thickness            Line thickness. Format: Format: NUMBER\n");
    printf("--color                Line color. Format: RED.GREEN.BLUE\n");
    printf("--fill                 Works as a binary value: there is a flag - true, there is no flag - false\n");
    printf("--fill_color           Fill color. Format: RED.GREEN.BLUE\n");
    printf("\n");


    printf("--circle               Drawing a circle. Required: --center, --radius, --thickness, --color. Optional: --fill, --fill_color\n");
    printf("--center               Coordinates of the center. Format: x.y\n");
    printf("--radius               Radius. Format: NUMBER\n");
    printf("\n");

    printf("--rgbfilter            RGB filter component\n");
    printf("--component_name       Which component needs to be changed. Format: {red || green || blue}\n");
    printf("--component_value      To which value it needs to be changed. Format: NUMBER\n");
    printf("\n");
    
    printf("--split                Divides the image into number_y*number_x parts. Required: --thickness, --color\n");
    printf("--number_x             The number of parts along the Y-axis. Format: NUMBER\n");
    printf("--number_y             The number of parts along the X-axis. Format: NUMBER\n");
    printf("\n");
    
    printf("--squared_lines        Drawing a square with diagonals. Required: --thickness, --color. Optional: --fill, --fill_color\n");
    printf("--left_up              Coordinates of the upper-left corner. Format: left.up\n");
    printf("--side_size            The size of the side. Format: NUMBER\n");
}