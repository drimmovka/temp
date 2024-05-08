#include "EditorPNG.h"

#include <string>
#include <regex>

#include <iostream>

void parseCoords(int& x, int& y, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("(-?[0-9]+)\\.(-?[0-9]+)");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
    
    x = stoi(groups[1]);
    y = stoi(groups[2]);
}

void parseNumber(int& number, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("-?[0-9]+");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }

    number = stoi(groups[0]);
}


void parseColor(Color& color, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }

    color.r = stoi(groups[1]);
    color.g = stoi(groups[2]);
    color.b = stoi(groups[3]);
    color.a = 255;

    if (color.r < 0 || color.r > 255) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
    if (color.g < 0 || color.g > 255) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
    if (color.b < 0 || color.b > 255) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void parseComponentName(int& parameter, std::string& str)
{
    if (str == "red") {
        parameter = R_IDX;
        return;
    }
    if (str == "green") {
        parameter = G_IDX;
        return;
    }
    if (str == "blue") {
        parameter = B_IDX;
        return;
    }
    std::cout << "PARSING ERROR" << std::endl;
    exit(40);   
}

void checkRadiusValidity(int radius)
{   
    if (radius <= 0) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void checkThicknessValidity(int thickness)
{
    if (thickness <= 0) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void checkComponentValueValidity(int component_value)
{
    if (component_value < 0 || component_value > 255) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void checkNumberXValidity(int number_x)
{
    if (number_x < 1) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void checkNumberYValidity(int number_y)
{
    if (number_y < 1) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

void checkSideSizeValidity(int side_size)
{
    if (side_size <= 0) {
        std::cout << "PARSING ERROR" << std::endl;
        exit(40);
    }
}

// make func like isPositive(int num, std::string error_message)...