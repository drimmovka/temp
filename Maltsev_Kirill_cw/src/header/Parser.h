#ifndef PARSER_H
#define PARSER_H

#include "EditorPNG.h"

#include <string>

void parseCoords(int& x, int& y, std::string& str);
void parseNumber(int& number, std::string& str);
void parseColor(Color& color, std::string& str);
void parseComponentName(int& parameter, std::string& str);

void checkRadiusValidity(int radius);
void checkThicknessValidity(int thickness);
void checkComponentValueValidity(int component_value);
void checkNumberXValidity(int number_x);
void checkNumberYValidity(int number_y);
void checkSideSizeValidity(int side_size);

#endif