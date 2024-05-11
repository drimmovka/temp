#include "EditorPNG.h"
#include "Parser.h"

#include <string>
#include <regex>
#include <functional>


void psr::throwError(const char *error_massage, int exit_code)
{
    printf("%s\n", error_massage);
    exit(exit_code);
}

void psr::parseCoords(int& x, int& y, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("(-?[0-9]+)\\.(-?[0-9]+)");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        throwError("Error: coords parsing failed.", PARSER_ERROR);
    }
    
    x = stoi(groups[1]);
    y = stoi(groups[2]);
}

void psr::parseNumber(int& number, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("-?[0-9]+");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        throwError("Error: number parsing failed.", PARSER_ERROR);
    }

    number = stoi(groups[0]);
}


void psr::parseColor(epng::Color& color, std::string& str)
{
    std::cmatch groups;
    std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)");

    if ( !std::regex_match(str.c_str(), groups, pattern) ) {
        throwError("Error: color parsing failed.", PARSER_ERROR);
    }

    color.r = stoi(groups[1]);
    color.g = stoi(groups[2]);
    color.b = stoi(groups[3]);
    color.a = 255;

    if (color.r < 0 || color.r > 255) {
        throwError("Error: color parsing failed.", PARSER_ERROR);
    }
    if (color.g < 0 || color.g > 255) {
        throwError("Error: color parsing failed.", PARSER_ERROR);
    }
    if (color.b < 0 || color.b > 255) {
        throwError("Error: color parsing failed.", PARSER_ERROR);
    }
}

void psr::parseComponentName(int& parameter, std::string& str)
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
    throwError("Error: component parsing failed.", PARSER_ERROR);    
}

void psr::checkValueValidity(int value, std::function<bool(int)> check_func)
{
    if (!check_func(value)) {
        throwError("Error: value parsing failed.", PARSER_ERROR);
    }
}