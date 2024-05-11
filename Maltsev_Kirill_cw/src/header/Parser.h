#ifndef PARSER_H
#define PARSER_H

#include "EditorPNG.h"

#include <string>
#include <functional>

#define PARSER_ERROR 46


namespace psr
{
void throwError(const char *error_massage, int exit_code);

void parseCoords(int& x, int& y, std::string& str);
void parseNumber(int& number, std::string& str);
void parseColor(epng::Color& color, std::string& str);
void parseComponentName(int& parameter, std::string& str);

void checkValueValidity(int value, std::function<bool(int)> check_func);
}

#endif